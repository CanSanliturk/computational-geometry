#include "pointTests.hpp"

#include "point.hpp"

#include "logging.hpp"

#include <boost/test/unit_test.hpp>

namespace tests {
    namespace pointTests {
    
        using core::point;

        bool runTests() {

            utilities::logger("========== POINT TEST CASES START ==========");

            bool result = true;

            result &= testEquals();

            utilities::logger("=========== POINT TEST CASES END ===========");

            if (true == result)
                utilities::logger("All passed");
            else
                utilities::logger("Some failed!");

            return result;
        }

        bool testEquals() {

            bool result = true;

            point p1(1, 2, 3);
            point p2(1, 2, 3);
            result &= (p1 == p2);
            BOOST_CHECK(result);
            
            point p0;
            result &= (false == (p0 == p1));
            BOOST_CHECK(result);

            return result;
        }

        bool testNotEquals() {
            return false;
        }

        bool testGetX() {
            return false;

        }

        bool testGetY() {
            return false;

        }

        bool testGetZ() {
            return false;

        }

        bool testGetCoordinates() {
            return false;

        }

        bool testSetX() {

            return false;
        }

        bool testSetY() {
            return false;

        }

        bool testSetZ() {
            return false;

        }

        bool testGetDistance() {
            return false;

        }
    }
}