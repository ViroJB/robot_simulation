#include "robot.h"

Robot::Robot(std::vector<std::unique_ptr<Sensor>>&& sensors, EventDispatcher* eventDispatcher, int x, int y, int mapSizeX, int mapSizeY) : sensors(std::move(sensors)), eventDispatcher(eventDispatcher), x(x), y(y), mapSizeX(mapSizeX), mapSizeY(mapSizeY), direction(1) {
    x, y = 0;
}

std::pair<int, int> Robot::getCoordinates() {
    return std::make_pair(x, y);
}

void Robot::setPosition(int x, int y) {
    this->x = x;
    this->y = y;
}

void Robot::turnRight()
{
    if(direction == West) {
        direction = North;
    } else {
        direction += 1;
    }
}

void Robot::turnLeft()
{
    if(direction == North) {
        direction = West;
    } else {
        direction -= 1;
    }
}

void Robot::turnTo(int direction)
{
    if(direction >= 0 && direction <= 3) {
        this->direction = direction;
    }
}

void Robot::turnRandom()
{
    turnTo(rand() % 4);
}

void Robot::move()
{
    // temp
    // change every 20 moves to a random direction
    if(rand() % 20 == 0) {
        std::cout << "Robot is turning randomly" << std::endl;
        turnRandom();
    }

    if(direction == North && y < mapSizeX - 1) {
        y++;
    } else if(direction == East && x < mapSizeY - 1) {
        x++;
    } else if(direction == South && y > 0) {
        y--;
    } else if(direction == West && x > 0) {
        x--;
    } else {
        turnRandom();
        std::cout << "Robot cannot move in that direction. Turning..." << std::endl;
        move();
    }
}

void Robot::updateState() {
    move();
    std::pair<int, int> coordinates = getCoordinates();
    eventDispatcher->dispatchEvent("RobotChangedPosition", coordinates);

    for (auto &sensor : sensors) {
        sensor->measure();
    }
}

void Robot::printState() {
    std::cout << "Robot is at: (" << x << ", " << y << ")" << std::endl;
    std::cout << "Robot is facing: " << direction << std::endl;

    std::cout << "Robot has " << sensors.size() << " sensors." << std::endl;
    for (auto &sensor : sensors) {
        std::cout << sensor->getId() << " Data: " << sensor->getData() << std::endl;
    }
}
