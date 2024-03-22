#include "ComputationalGeometryCore/Entities/vector3d.hpp"

#include <boost/test/unit_test.hpp>
#include <boost/math/constants/constants.hpp>

using computationalgeometry::core::entities::point;
using computationalgeometry::core::entities::vector3d;
using computationalgeometry::core::entities::line3d;

BOOST_AUTO_TEST_SUITE(Vector3dTests)

BOOST_AUTO_TEST_CASE(testVectorLength) {
    point start(1.0, 2.0, 3.0);
    point end(4.0, 5.0, 6.0);

    vector3d vector(start, end);
    double expectedLength = std::sqrt(3 * 3 + 3 * 3 + 3 * 3);

    BOOST_TEST(vector.length() == expectedLength, boost::test_tools::tolerance(1e-5));
}

BOOST_AUTO_TEST_CASE(testDotProduct) {
    point start1(1.0, 2.0, 3.0);
    point end1(4.0, 5.0, 6.0);

    point start2(2.0, 3.0, 4.0);
    point end2(5.0, 6.0, 7.0);

    vector3d vector1(start1, end1);
    vector3d vector2(start2, end2);
    const double calculatedDotProduct = vector1.dotProduct(vector2);

    std::array<double, 3> delta1 = (end1 - start1).getCoordinates();
    std::array<double, 3> delta2 = (end2 - start2).getCoordinates();
    double expectedDotProduct = 0;
    for (size_t i = 0; i < 3; i++)
        expectedDotProduct += (delta1[i] * delta2[i]);    


    BOOST_TEST(calculatedDotProduct == expectedDotProduct);
}

BOOST_AUTO_TEST_CASE(testCrossProduct) {
    point start1(1.0, 2.0, 3.0);
    point end1(4.0, 5.0, 6.0);

    point start2(2.0, 3.0, 4.0);
    point end2(5.0, 6.0, 7.0);

    vector3d vector1(start1, end1);
    vector3d vector2(start2, end2);

    vector3d crossProduct = vector1.crossProduct(vector2);

    // Cross product result is perpendicular to both vectors,
    // so the dot product of the cross product and either vector should be zero.
    double dotProductWithVector1 = crossProduct.dotProduct(vector1);
    double dotProductWithVector2 = crossProduct.dotProduct(vector2);

    BOOST_TEST(dotProductWithVector1 == 0.0, boost::test_tools::tolerance(1e-5));
    BOOST_TEST(dotProductWithVector2 == 0.0, boost::test_tools::tolerance(1e-5));
}

BOOST_AUTO_TEST_CASE(testGetAngleTo) {
    point start1(1.0, 0.0, 0.0);
    point end1(2.0, 0.0, 0.0);

    point start2(0.0, 1.0, 0.0);
    point end2(0.0, 2.0, 0.0);

    vector3d vector1(start1, end1);
    vector3d vector2(start2, end2);

    double angle = vector1.getAngleTo(vector2);

    // Vectors are perpendicular, so the angle should be pi/2
    BOOST_TEST(angle == boost::math::constants::half_pi<double>(), boost::test_tools::tolerance(1e-5));
}

BOOST_AUTO_TEST_CASE(testGetDirection) {
    point start(4.0, 5.0, 6.0);
    point end(1.0, 2.0, 3.0);

    line3d line(start, end);
    vector3d calculatedDirectionVector = line.getDirectionVector();
    vector3d expectedDirectionVector({ 0, 0, 0 }, end - start);

    BOOST_CHECK(expectedDirectionVector == calculatedDirectionVector);
}

BOOST_AUTO_TEST_SUITE_END()
