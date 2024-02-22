#include "ComputationalGeometryCore/Entities/point.hpp"

#include "ComputationalGeometryUtilities/maths.hpp"

#include <cmath>

namespace computationalgeometry::core::entities {

    point::point(double xCoord, double yCoord, double zCoord)
        : x(xCoord), y(yCoord), z(zCoord) { }

    point::point(const std::array<double, 3>& coords)
        : x(coords[0]), y(coords[1]), z(coords[2]) { }
    

    bool point::operator==(const point& other) const {
        for (unsigned int i = 0; i < 3; ++i)
            if (false == computationalgeometry::utilities::areEqual(getCoordinates()[i], other.getCoordinates()[i]))
                return false;
        return true;
    }

    point point::operator-(const point& other) const {
        const double newX = x - other.x;
        const double newY = y - other.y;
        const double newZ = z - other.z;
        point newPt(newX, newY, newZ);
        return newPt;
    }

    point point::operator+(const point& other) const {
        const double newX = x + other.x;
        const double newY = y + other.y;
        const double newZ = z + other.z;
        point newPt(newX, newY, newZ);
        return newPt;
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

    std::array<double, 3> point::getCoordinates() const {
        return { x, y, z };
    }

    void point::setX(double xCoord) {
        this->x = xCoord;
    }

    void point::setY(double yCoord) {
        this->y = yCoord;
    }

    void point::setZ(double zCoord) {
        this->z = zCoord;
    }
}
