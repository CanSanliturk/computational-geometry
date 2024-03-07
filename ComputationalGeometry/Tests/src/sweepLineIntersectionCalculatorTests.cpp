#include "ComputationalGeometryCore/Algorithms/sweepLineIntersectionCalculator.hpp"

#include <boost/test/unit_test.hpp>

using namespace computationalgeometry::core::entities;
using namespace computationalgeometry::core::algorithms;

BOOST_AUTO_TEST_SUITE(SweepLineIntersectionCalculatorTests)

BOOST_AUTO_TEST_CASE(TestAddLine)
{
    sweepLineIntersectionCalculator calculator;

    line3d line1({ 1, 2, 0}, { 4, 5, 0 });
    BOOST_CHECK(1 == calculator.addLine(line1));

    line3d line2;
    BOOST_CHECK(2 == calculator.addLine(line2));

    BOOST_CHECK(2 == calculator.getLineCount());
}

BOOST_AUTO_TEST_CASE(TestAddLines)
{
    sweepLineIntersectionCalculator calculator;
    std::vector<line3d> lines { { { 1, 2, 0}, { 4, 5, 0 } }, { } };
    BOOST_CHECK(2 == calculator.addLines(lines));
    BOOST_CHECK(2 == calculator.getLineCount());
}

BOOST_AUTO_TEST_CASE(TestRemoveLine)
{
    sweepLineIntersectionCalculator calculator;
    std::vector<line3d> lines { { { 1, 2, 0}, { 4, 5, 0 } }, { } };
    unsigned long id = calculator.addLines(lines);
    BOOST_CHECK(true == calculator.removeLine(id));
    BOOST_CHECK(false == calculator.removeLine(id));
}

BOOST_AUTO_TEST_CASE(TestFindIntersectionEmptyLineCollection)
{
    sweepLineIntersectionCalculator calculator;
    std::vector<point> intersecionPoints = calculator.getIntersectionPoints();
    BOOST_CHECK(true == intersecionPoints.empty());
}

BOOST_AUTO_TEST_CASE(TestFindIntersectionWithNonIntersectingLines)
{
    sweepLineIntersectionCalculator calculator;
    calculator.addLines({ { { 1, 2, 0}, { 4, 5, 0 } }, { } });
    std::vector<point> intersecionPoints = calculator.getIntersectionPoints();
    BOOST_CHECK(true == intersecionPoints.empty());
}

BOOST_AUTO_TEST_CASE(TestFindIntersectionTwoIntersectingLines)
{
    sweepLineIntersectionCalculator calculator;
    calculator.addLines( {
            {{ 0, 1, 0}, { 1, 0, 0 }}, {{ 0, 0, 0 }, { 1, 1, 0 }} // they intersect at (0.5, 0.5, 0)
        }
    );

    std::vector<point> intersection = calculator.getIntersectionPoints();

    BOOST_CHECK_EQUAL(1, intersection.size());

    if (1 == intersection.size()) {
        point expected(0.5, 0.5);
        BOOST_CHECK(expected == intersection.front());
    }
}

BOOST_AUTO_TEST_SUITE_END()
