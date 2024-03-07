#include "ComputationalGeometryCore/Algorithms/sweepLineIntersectionCalculator.hpp"

unsigned long computationalgeometry::core::algorithms::sweepLineIntersectionCalculator::addLine(
    const computationalgeometry::core::entities::line3d& line)
{
    ++m_lastId;
    m_idToLines.try_emplace(m_lastId, line);
    return m_lastId;
}

unsigned long computationalgeometry::core::algorithms::sweepLineIntersectionCalculator::addLines(
    const std::vector<computationalgeometry::core::entities::line3d>& lines) 
{
    for (const computationalgeometry::core::entities::line3d& line : lines)
        addLine(line);
    
    return m_lastId;
}

bool computationalgeometry::core::algorithms::sweepLineIntersectionCalculator::removeLine(unsigned long lineId) {
    bool result = false;
    if (m_idToLines.end() != m_idToLines.find(lineId))
    {
        result = true;
        m_idToLines.erase(lineId);
    }
    
    return result;
}

unsigned long computationalgeometry::core::algorithms::sweepLineIntersectionCalculator::getLineCount() const {
    return m_idToLines.size();
}

std::vector<computationalgeometry::core::entities::point> 
    computationalgeometry::core::algorithms::sweepLineIntersectionCalculator::getIntersectionPoints() const
{
    std::map<double, std::vector<std::pair<unsigned long, bool>>, std::greater<double>> eventQueue = createEventQueue();

    for (auto it = eventQueue.cbegin(); it != eventQueue.cend();)
    {

        it = eventQueue.erase(it);
    }



    return { };
}

std::map<double, std::vector<std::pair<unsigned long, bool>>, std::greater<double>>
    computationalgeometry::core::algorithms::sweepLineIntersectionCalculator::createEventQueue() const {

    std::map<double, std::vector<std::pair<unsigned long, bool>>, std::greater<double>> eventQueue;

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


