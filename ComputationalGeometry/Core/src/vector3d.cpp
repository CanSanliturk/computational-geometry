#include "ComputationalGeometryCore/Entities/vector3d.hpp"

#include "ComputationalGeometryUtilities/maths.hpp"

#include <cmath>

namespace computationalgeometry::core::entities {

    vector3d::vector3d() : start(), end() { }

    vector3d::vector3d(const point& startCoord, const point& endCoord) : start(startCoord), end(endCoord) { }

    vector3d::vector3d(const vector3d& other) : start(other.start), end(other.end) { }

    vector3d& vector3d::operator=(const vector3d& other) {
        if (this != &other) {
            start = other.start;
            end = other.end;
        }
        return *this;
    }

    vector3d& vector3d::operator=(vector3d&& other) noexcept {
        if (this != &other) {
            start = std::move(other.start);
            end = std::move(other.end);
        }
        return *this;
    }

    double vector3d::length() const {
        return start.distanceTo(end);
    }

    double vector3d::dotProduct(const vector3d& other) const {
        point delta = end - start;
        point otherDelta = other.end - other.start;

        return delta.getX() * otherDelta.getX() + 
            delta.getY() * otherDelta.getY() +
            delta.getZ() * otherDelta.getZ();
    }

    vector3d vector3d::crossProduct(const vector3d& other) const {
        point delta = end - start;
        point otherDelta = other.end - other.start;

        double newX = delta.getY() * otherDelta.getZ() - delta.getZ() * otherDelta.getY();
        double newY = delta.getZ() * otherDelta.getX() - delta.getX() * otherDelta.getZ();
        double newZ = delta.getX() * otherDelta.getY() - delta.getY() * otherDelta.getX();

        return vector3d(point(0.0, 0.0, 0.0), point(newX, newY, newZ));
    }

    double vector3d::getAngleTo(const vector3d& other) const {
        double dot = dotProduct(other);
        double len1 = length();
        double len2 = other.length();

        // Ensure denominators are not zero
        if (len1 == 0.0 || len2 == 0.0) {
            return 0.0; // Angle is undefined
        }

        // Calculate the cosine of the angle
        double cosAngle = dot / (len1 * len2);

        // Ensure the value is within the valid range for acos
        cosAngle = std::max(-1.0, std::min(1.0, cosAngle));

        // Calculate the angle in radians
        return std::acos(cosAngle);
    }

    point vector3d::getStart() const {
        return start;
    }

    point vector3d::getEnd() const {
        return end;
    }

    void vector3d::setStart(const point& start) {
        this->start = start;
    }

    void vector3d::setEnd(const point& end) {
        this->end = end;
    }
}