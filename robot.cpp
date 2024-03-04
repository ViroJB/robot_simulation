#include "robot.h"

Robot::Robot(std::vector<std::unique_ptr<Sensor>> &&sensors, EventDispatcher *eventDispatcher, std::string id, int x, int y, int mapSizeX, int mapSizeY) : sensors(std::move(sensors)), eventDispatcher(eventDispatcher), id(id), x(x), y(y), mapSizeX(mapSizeX), mapSizeY(mapSizeY), direction(1)
{
    initSensors(id);
}

void Robot::initSensors(std::string id)
{
    for (auto &sensor : sensors)
    {
        sensor->attachTo(id);
    }
}

std::pair<int, int> Robot::getCoordinates()
{
    return std::make_pair(x, y);
}

void Robot::setPosition(int x, int y)
{
    this->x = x;
    this->y = y;
}

void Robot::turnRight()
{
    if (direction == West)
    {
        direction = North;
    }
    else
    {
        ++direction;
    }
}

void Robot::turnLeft()
{
    if (direction == North)
    {
        direction = West;
    }
    else
    {
        --direction;
    }
}

void Robot::turnTo(int direction)
{
    if (direction >= 0 && direction <= 3)
    {
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
    if (rand() % 20 == 0)
    {
        #if DEBUG
            std::cout << id << ": turning randomly" << std::endl;
        #endif
        turnRandom();
    }

    if (direction == North && y < mapSizeX - 1)
    {
        ++y;
    }
    else if (direction == East && x < mapSizeY - 1)
    {
        ++x;
    }
    else if (direction == South && y > 0)
    {
        --y;
    }
    else if (direction == West && x > 0)
    {
        --x;
    }
    else
    {
        #if DEBUG
            std::cout << id << ": cannot move in that direction. Turning." << std::endl;
        #endif
        turnRandom();
        move();
    }
}

void Robot::updateState()
{
    move();
    std::pair<int, int> coordinates = getCoordinates();
    eventDispatcher->dispatchEvent(id + "ChangedPosition", coordinates);

    for (auto &sensor : sensors)
    {
        sensor->measure();
    }
}

void Robot::printState()
{
    std::cout << id << ": position: (" << x << ", " << y << ")" << std::endl;
    std::cout << id << ": direction: " << direction << std::endl;

    std::cout << id << ": Sensors (" << sensors.size() << "): " << std::endl;
    for (auto &sensor : sensors)
    {
        std::cout << "   " << sensor->getId() << " Data: " << sensor->getData() << std::endl;
    }
    std::cout << std::endl;
}
