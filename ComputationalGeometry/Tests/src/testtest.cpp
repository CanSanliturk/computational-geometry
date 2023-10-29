#include "testtest.hpp"

#include "utilities.h"

#include <boost/test/unit_test.hpp>

void example_test() {
    utilities::logger("Running example test...");
    BOOST_CHECK(2 + 2 == 5); // Replace with your actual test logic
}
