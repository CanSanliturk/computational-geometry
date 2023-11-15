#include "ComputationalGeometryCore/Entities/point.hpp"

#include "ComputationalGeometryUtilities/maths.hpp"

#include <cmath>

namespace computationalgeometry::core::entities {

    point::point(double x, double y, double z)
        : x(x), y(y), z(z) { }

    bool point::operator==(const point& other) const {
        for (unsigned int i = 0; i < 3; ++i)
            if (false == computationalgeometry::utilities::areEqual(getCoordinates()[i], other.getCoordinates()[i]))
                return false;
        return true;
    }

    bool point::operator!=(const point& other) const {
        return !((*this) == other);
    }

    double point::getDistanceTo(const point& other) const {

        if (other == *this)
            return 0;

        double sumOfSquares = 0;
        for (unsigned int i = 0; i < 3; ++i)
            sumOfSquares += pow(getCoordinates()[i] - other.getCoordinates()[i], 2);

        return sqrt(sumOfSquares);
    }

    double point::getX() const {
        return x;
    }

    double point::getY() const {
        return y;
    }

    double point::getZ() const {
        return z;
    }

    const std::array<const double, 3> point::getCoordinates() const {
        return { x, y, z };
    }

    void point::setX(double x) {
        this->x = x;
    }

    void point::setY(double y) {
        this->y = y;
    }

    void point::setZ(double z) {
        this->z = z;
    }
}
