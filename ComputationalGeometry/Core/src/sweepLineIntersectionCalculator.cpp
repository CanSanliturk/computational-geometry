#include "ComputationalGeometryCore/Algorithms/sweepLineIntersectionCalculator.hpp"
#include "ComputationalGeometryCore/Algorithms/twoLinesIntersectionCalculator.hpp"

#include <cmath>
#include <vector>
#include <algorithm>
#include <functional>
#include <unordered_set>

using namespace computationalgeometry::core::entities;
using namespace computationalgeometry::core::algorithms;

using EventQueue_t = std::map<double, std::vector<std::pair<unsigned long, bool>>, std::greater<double>>;

// structure to maintain status of sweepline
class status {
public:

    void setElevation(double elevation) {
        m_elevation = elevation;
    }

    void addLine(const line3d& line) {
        m_lines.push_back(line);
    }

    void removeLine(const line3d& line) {
        // find line, move it to the end of the vector, and pop-it
        for (unsigned int i = 0; i < m_lines.size(); ++i) {
            if (m_lines[i] == line) {
                std::iter_swap(m_lines.begin() + i, m_lines.begin() + m_lines.size() - 1);
                m_lines.pop_back();
                break;
            }
        }
    }

    void sortLines() {
        std::ranges::sort(m_lines, m_statusLineSorter);
    }

    std::vector<point> getIntersections() {

        std::vector<point> intersections;

        for (unsigned int i = 1; i < m_lines.size(); ++i) {
            twoLinesIntersectionCalculator calculator(m_lines[i], m_lines[i - 1]);
            std::optional<point> optPt = calculator.getIntersection();
            if (true == optPt.has_value())
                intersections.push_back(optPt.value());
        }

        return intersections;
    }

private:
    std::vector<line3d> m_lines;
    
    double m_elevation = 0;
    
    // status structure to keep record of lines coinciding with status line, in order from left-to-right
    // (whose x-value is smaller, it will be the first to appear)
    std::function<bool(const line3d&, const line3d&)> m_statusLineSorter = [this](const line3d& line1, const line3d& line2) {
        // find left and right borders to find extents of the sweep line
        double leftBorder = std::min(line1.getStart().getX(), std::min(line1.getEnd().getX(), std::min(line2.getStart().getX(), line2.getEnd().getX())));
        double rightBorder = std::max(line1.getStart().getX(), std::max(line1.getEnd().getX(), std::max(line2.getStart().getX(), line2.getEnd().getX())));
        line3d sweepLine({ leftBorder - 1, this->m_elevation, 0 }, {rightBorder + 1, this->m_elevation, 0});

        twoLinesIntersectionCalculator calculator1(line1, sweepLine);
        twoLinesIntersectionCalculator calculator2(line2, sweepLine);

        point intersection1 = calculator1.getIntersection().value();
        point intersection2 = calculator2.getIntersection().value();

        return intersection1.getX() < intersection2.getX(); 
    };    
};

unsigned long sweepLineIntersectionCalculator::addLine(const line3d& line)
{
    ++m_lastId;
    m_idToLines.try_emplace(m_lastId, line);
    return m_lastId;
}

unsigned long sweepLineIntersectionCalculator::addLines(const std::vector<line3d>& lines) 
{
    for (const computationalgeometry::core::entities::line3d& line : lines)
        addLine(line);
    
    return m_lastId;
}

bool sweepLineIntersectionCalculator::removeLine(unsigned long lineId) {
    bool result = false;
    if (true == m_idToLines.contains(lineId))
    {
        result = true;
        m_idToLines.erase(lineId);
    }
    
    return result;
}

unsigned long sweepLineIntersectionCalculator::getLineCount() const {
    return m_idToLines.size();
}

std::vector<point> sweepLineIntersectionCalculator::getIntersectionPoints() const
{
    // event points
    EventQueue_t eventQueue = createEventQueue();

    // sweep line status
    status s;

    std::unordered_map<unsigned int, point> intersectionPoints;

    // for each event point
    for (const auto& [elevation, lines] : eventQueue) {
        // we are at new elevation
        s.setElevation(elevation);
        
        // see if any new segment should be inserted
        for (const auto& [line, isTop] : lines)
            if (true == isTop)
                s.addLine(m_idToLines.at(line));

        // order segments according to their intersection location with sweep line
        s.sortLines();

        // get intersection points and place them to an unordered_set for uniqueness
        for (point p : s.getIntersections())
            intersectionPoints[p.hash()] = p;

        // remove segments who will be above sweep line
        for (const auto& [line, isTop] : lines)
            if (false == isTop)
                s.removeLine(m_idToLines.at(line));
    }

    std::vector<point> ret;
    for (const auto& [id, pt] : intersectionPoints)
        ret.push_back(pt);
    
    return ret;
}

EventQueue_t sweepLineIntersectionCalculator::createEventQueue() const {

    EventQueue_t eventQueue;

    for (const auto& [id, line] : m_idToLines)
    {
        computationalgeometry::core::entities::point upperPoint
            = (line.getStart().getY() < line.getEnd().getY()) ? line.getEnd() : line.getStart();

        computationalgeometry::core::entities::point lowerPoint
            = (line.getStart().getY() < line.getEnd().getY()) ? line.getStart() : line.getEnd();

        eventQueue[upperPoint.getY()].push_back({ id, true });
        eventQueue[lowerPoint.getY()].push_back({ id, false });
    }

    return eventQueue;
}
