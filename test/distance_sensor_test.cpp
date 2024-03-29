#include <gtest/gtest.h>
#include "../src/sensors/distance_sensor.h"

TEST(DistanceSensor, Measure_ReturnsCorrectDistance) {
    DistanceSensor sensor;
    sensor.setTargetPosition(2, 1);
    sensor.setRobotPosition(0, 0);
    sensor.measure();
    auto data = std::get<int>(sensor.getData());

    EXPECT_EQ(data, 3);
}
