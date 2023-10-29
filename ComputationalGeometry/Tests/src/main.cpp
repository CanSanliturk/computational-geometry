#include "pointTests.hpp"

#include "logging.hpp"

#include <boost/test/unit_test.hpp>

int main() {

    utilities::logger("Tests start");

    tests::pointTests::runTests();

    return 0;
}