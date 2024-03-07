#ifndef _SWEEPLINEINTERSECTIONCALCULATOR_HPP
#define _SWEEPLINEINTERSECTIONCALCULATOR_HPP

#include "ComputationalGeometryCore/Entities/vector3d.hpp"

#include <map>
#include <vector>
#include <unordered_map>

namespace computationalgeometry::core::algorithms {

    // works with lines lie on x-y plane (x, y, z = 0)
    class sweepLineIntersectionCalculator {
    public:
 
        // adds the line to the collection, and returns related id
        unsigned long addLine(const computationalgeometry::core::entities::line3d& line);
       
        // returns the last id of the added line
        unsigned long addLines(const std::vector<computationalgeometry::core::entities::line3d>& lines);
        
        // returns true if there exists a line with given line id after removing it from line collection
        // returns false if there does not exist such a line
        bool removeLine(unsigned long lineId);

        // returns the count of lines stored at the collection
        unsigned long getLineCount() const;
        
        // calculates intersection points of given lines and returns intersection points in
        // std::vector
        std::vector<computationalgeometry::core::entities::point> getIntersectionPoints() const;

    private:

        // returns a map of y-coordinates that denote event points. 
        // key is y-coordinate of the event point
        // value is a vector of pairs of line id and boolean flag
        //      line id denotes the line whose upper or lower points y-coordinate is same as event point
        //      true for boolean flag denotes that the UPPER point of the line with provided id coincides with event point
        //      false for boolean flag denotes that the LOWER point of the line with provided id coincides with event point
        std::map<double, std::vector<std::pair<unsigned long, bool>>, std::greater<double>> createEventQueue() const;

        std::unordered_map<unsigned long, computationalgeometry::core::entities::line3d> m_idToLines;
        unsigned long m_lastId = 0;

    };
}

#endif
