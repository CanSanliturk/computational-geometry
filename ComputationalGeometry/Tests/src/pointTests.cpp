#include "ComputationalGeometryCore/Entities/point.hpp"

#include <boost/test/unit_test.hpp>

using computationalgeometry::core::entities::point;

BOOST_AUTO_TEST_SUITE(PointTests)

BOOST_AUTO_TEST_CASE(TestPointEquals)
{
   point p1(1, 2, 3);
   point p2(1, 2, 3);
   BOOST_CHECK(p1 == p2);
           
   point p0;
   BOOST_CHECK(false == (p0 == p1));
}

BOOST_AUTO_TEST_CASE(TestPointGet)
{
   point p(1, 2, 3);

   BOOST_CHECK(1 == p.getX());
   BOOST_CHECK(2 == p.getY());
   BOOST_CHECK(3 == p.getZ());

   std::array<double, 3> expectedCoords = { 1, 2, 3 };
   std::array<double, 3>&& actualCoords = p.getCoordinates();
   for (size_t i = 0; i < 3; i++)
       BOOST_CHECK(expectedCoords[i] == actualCoords[i]);
}

BOOST_AUTO_TEST_CASE(TestPointSet)
{
   point p;
   p.setX(1);
   p.setY(2);
   p.setZ(3);

   BOOST_CHECK(1 == p.getX());
   BOOST_CHECK(2 == p.getY());
   BOOST_CHECK(3 == p.getZ());

   std::array<double, 3> expectedCoords = { 1, 2, 3 };
   std::array<double, 3>&& actualCoords = p.getCoordinates();
   for (size_t i = 0; i < 3; i++)
       BOOST_CHECK(expectedCoords[i] == actualCoords[i]);
}

BOOST_AUTO_TEST_CASE(TestPointHash)
{
   point pt1(1, 2, 3);
   point pt2(1.5, 6.3, 8.3);

   BOOST_CHECK(pt1.hash() != pt2.hash());

   point pt3(pt2);
   BOOST_CHECK(pt2.hash() == pt3.hash());
}

BOOST_AUTO_TEST_SUITE_END()
