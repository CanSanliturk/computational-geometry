#ifndef _VECTOR3D_HPP
#define _VECTOR3D_HPP

#include "point.hpp"

namespace computationalgeometry::core::entities {
    class vector3d {
        
    public:

        vector3d() = default;

        vector3d(const point& startPoint, const point& endPoint);

        bool operator==(const vector3d& other) const;

        point getStart() const;
        point getEnd() const;

        void setStart(const point& startPoint);
        void setEnd(const point& endPoint);

        // method to calculate the length (magnitude) of the vector
        double length() const;

        // method to calculate the dot product with another vector
        double dotProduct(const vector3d& other) const;

        // method to calculate the cross product with another vector
        vector3d crossProduct(const vector3d& other) const;

        // method to get the angle between this vector and another vector in radians
        double getAngleTo(const vector3d& other) const;

        vector3d getDirectionVector() const;

    private:
        point start;
        point end;
    };

    using line3d = vector3d;
};

#endif
