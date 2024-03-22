#ifndef _TWOLINESINTERSECTIONCHECKER_HPP
#define _TWOLINESINTERSECTIONCHECKER_HPP

#include "ComputationalGeometryCore/Entities/vector3d.hpp"

#include <optional>

namespace computationalgeometry::core::algorithms {

    class twoLinesIntersectionCalculator {
    public:

        twoLinesIntersectionCalculator(const computationalgeometry::core::entities::line3d& line1, const computationalgeometry::core::entities::line3d& line2);

        twoLinesIntersectionCalculator() = delete;

        std::optional<computationalgeometry::core::entities::point> getIntersection() const;

    private:

        const computationalgeometry::core::entities::line3d& m_line1;
        const computationalgeometry::core::entities::line3d& m_line2;

        bool areScalarMultiples() const;
        std::optional<computationalgeometry::core::entities::line3d> isContained() const;
    };
}


#endif
