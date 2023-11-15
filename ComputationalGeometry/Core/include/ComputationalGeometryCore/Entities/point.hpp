#ifndef _POINT_HPP
#define _POINT_HPP

#include <array>

namespace computationalgeometry::core::entities {
    class point {

    public:
        point() = default;

        point(double xCoord, double yCoord, double zCoord = 0);

        point(const point& other) = default;

        point& operator=(const point& other) = default;

        point(point&& other) = default;

        point& operator=(point&& other) noexcept = default;
        
        ~point() = default;

        bool operator==(const point& other) const;

        double getDistanceTo(const point& other) const;

        double getX() const;

        double getY() const;

        double getZ() const;

        std::array<double, 3> getCoordinates() const;

        void setX(double xCoord);

        void setY(double yCoord);

        void setZ(double zCoord);

    private:
        double x;
        double y;
        double z;
    };
}

#endif
