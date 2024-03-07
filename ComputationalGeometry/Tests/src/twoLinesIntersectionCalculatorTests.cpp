#include "ComputationalGeometryCore/Algorithms/twoLinesIntersectionCalculator.hpp"

#include <boost/test/unit_test.hpp>

using namespace computationalgeometry::core::entities;
using namespace computationalgeometry::core::algorithms;

BOOST_AUTO_TEST_SUITE(TwoLinesIntersectionCalculatorTests)

BOOST_AUTO_TEST_CASE(TestIntersectingLines)
{
    // define first line
    point line1_start(0, 0, 0);
    point line1_end(5, 5, 5);
    line3d line1(line1_start, line1_end);

    // define second line
    point line2_start(0, 0, 2.5);
    point line2_end(5, 5, 2.5);
    line3d line2(line2_start, line2_end);

    // define expected intersection
    point expectedIntersection(2.5, 2.5, 2.5);

    // calculate intersection
    twoLinesIntersectionCalculator calculator(line1, line2);

    BOOST_CHECK(expectedIntersection == calculator.getIntersection());
}

BOOST_AUTO_TEST_CASE(TestNonIntersectingLines)
{
    // define first line
    point line1_start(0, 0, 0);
    point line1_end(5, 5, 5);
    line3d line1(line1_start, line1_end);

    // define second line
    point line2_start(12, 43, 56);
    point line2_end(543, 32, 75);
    line3d line2(line2_start, line2_end);

    // calculate intersection
    twoLinesIntersectionCalculator calculator(line1, line2);

    std::optional<point> result = calculator.getIntersection();

    BOOST_CHECK(false == result.has_value());
}

BOOST_AUTO_TEST_SUITE_END()
