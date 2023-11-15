#include "ComputationalGeometryUtilities/maths.hpp"

#include <cmath>

namespace computationalgeometry::utilities {
    bool areEqual(double num1, double num2, double tol) {
        return abs(num1 - num2) <= abs(tol);
    }
}
