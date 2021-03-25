#define CATCH_CONFIG_MAIN  // This tells Catch to provide a main() - only do this in one cpp file

#include <stddef.h>
#include "test/catch.hpp"
#include "sensor-validate.h"

TEST_CASE("reports error when soc jumps abruptly") {
  double socReadings[] = {0.0, 0.01, 0.5, 0.51};
  int numOfSocReadings = sizeof(socReadings) / sizeof(socReadings[0]);
  double maxSocDelta = 0.05;
  REQUIRE(validateSensorParmtReadings_i(socReadings, numOfSocReadings,maxSocDelta) == 0);
}

TEST_CASE("reports error when current jumps abruptly") {
  double currentReadings[] = {0.0, 0.02, 0.03, 0.33};
  int numOfCurReadings = sizeof(currentReadings) / sizeof(currentReadings[0]);
  double maxCurrentDelta = 0.1;
  REQUIRE(validateSensorParmtReadings_i(currentReadings, numOfCurReadings,maxCurrentDelta) == 0);
}

TEST_CASE("reports no error in case of soc not jumps abruptly ") {
  double socReadings[] = {0.0, 0.01, 0.02, 0.03};
  int numOfSocReadings = sizeof(socReadings) / sizeof(socReadings[0]);
  double maxSocDelta = 0.05;
 REQUIRE(validateSensorParmtReadings_i(socReadings, numOfSocReadings,maxSocDelta) == 1);
}

TEST_CASE("reports no error in case of current not jumps abruptly ") {
  double currentReadings[] = {0.0, 0.05, 0.08, 0.09};
  int numOfCurReadings = sizeof(currentReadings) / sizeof(currentReadings[0]);
  double maxCurrentDelta = 0.1;
  REQUIRE(validateSensorParmtReadings_i(currentReadings, numOfCurReadings,maxCurrentDelta) == 1);
}

TEST_CASE("reports no error in case of soc maintained as 0") {
  double socReadings[] = {0.0, 0.0, 0.0, 0.0};
  int numOfSocReadings = sizeof(socReadings) / sizeof(socReadings[0]);
  double maxSocDelta = 0.05;
  REQUIRE(validateSensorParmtReadings_i(socReadings, numOfSocReadings,maxSocDelta) == 1);
}

TEST_CASE("reports no error in case of current maintained as 0 ") {
  double currentReadings[] = {0.0, 0.0, 0.0, 0.0};
  int numOfCurReadings = sizeof(currentReadings) / sizeof(currentReadings[0]);
  double maxCurrentDelta = 0.1;
  REQUIRE(validateSensorParmtReadings_i(currentReadings, numOfCurReadings,maxCurrentDelta) == 1);
}

/*TEST_CASE("No process in case on any NULL pointer issue ") {
  double currentReadings[] = {0.0, 0.0, 0.0, 0.0};
  int numOfCurReadings = sizeof(currentReadings) / sizeof(currentReadings[0]);
  REQUIRE(validateSensorParmtReadings_i(NULL, numOfCurReadings) == 1);
} */
