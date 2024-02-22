#include "ComputationalGeometryCore/Algorithms/twoLinesIntersectionCalculator.hpp"

#include "ComputationalGeometryUtilities/maths.hpp"

#include <cmath>

using namespace computationalgeometry::core::entities;
using namespace computationalgeometry::core::algorithms;

computationalgeometry::core::algorithms::twoLinesIntersectionCalculator::twoLinesIntersectionCalculator(const line3d& line1, const line3d& line2)
    : m_line1(line1), m_line2(line2) { }

std::optional<point> twoLinesIntersectionCalculator::getIntersection() const {
    const point& p1 = m_line1.getStart();
    const point& p2 = m_line1.getEnd();
    const point& p3 = m_line2.getStart();
    const point& p4 = m_line2.getEnd();

    // Direction vectors of the lines
    line3d dir1(p1, p2);
    line3d dir2(p3, p4);

    // Vector between the start points of the lines
    line3d p1p3(p1, p3);

    // Compute denominator for the parametric equations
    double denom = dir1.crossProduct(dir2).length();

    // Check if the lines are parallel (denominator is close to zero)
    if (computationalgeometry::utilities::areEqual(denom, 0)) {
        // Lines are parallel, no intersection
        return std::nullopt;
    }

    // Compute parameters for the lines' parametric equations
    double t = p1p3.crossProduct(dir2).length() / denom;
    double s = p1p3.crossProduct(dir1).length() / denom;

    // Check if the intersection point lies within the line segments
    if (t >= 0 && t <= 1 && s >= 0 && s <= 1) {
        // Calculate intersection point
        double x = p1.getX() + t * (dir1.getEnd().getX() - dir1.getStart().getX());
        double y = p1.getY() + t * (dir1.getEnd().getY() - dir1.getStart().getY());
        double z = p1.getZ() + t * (dir1.getEnd().getZ() - dir1.getStart().getZ());
        return point(x, y, z);
    }

    // No intersection point found within line segments
    return std::nullopt;
}
