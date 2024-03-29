#include <gtest/gtest.h>
#include "../src/robots/robot.h"

TEST(Robot, Turn_Left) {
    Robot robot("Robot1", nullptr);
    robot.setDirection(North);
    robot.turn(Left);
    EXPECT_EQ(robot.getDirection(), West);
}

TEST(Robot, Turn_Right) {
    Robot robot("Robot1", nullptr);
    robot.setDirection(North);
    robot.turn(Right);
    EXPECT_EQ(robot.getDirection(), East);
}

TEST(Robot, Turn_InvalidDirection_Ignored) {
    Robot robot("Robot1", nullptr);
    robot.setDirection(North);
    robot.turn(7);
    EXPECT_EQ(robot.getDirection(), North);
}