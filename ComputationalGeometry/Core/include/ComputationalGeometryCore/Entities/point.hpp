#ifndef _POINT_HPP
#define _POINT_HPP

#include <array>

namespace computationalgeometry::core::entities {
    class point {

    public:
        point() = default;

        point(double x, double y, double z = 0);

        point(const point& other) = default;

        point& operator=(const point& other) = default;

        point(point&& other) = default;

        point& operator=(point&& other) noexcept = default;
        
        ~point() = default;

        bool operator==(const point& other) const;

        bool operator!=(const point& other) const;

        double getDistanceTo(const point& other) const;

        double getX() const;

        double getY() const;

        double getZ() const;

        const std::array<const double, 3> getCoordinates() const;

        void setX(double x);

        void setY(double y);

        void setZ(double z);

    private:
        double x;
        double y;
        double z;
    };
}

#endif
