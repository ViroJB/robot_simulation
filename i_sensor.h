#ifndef I_SENSOR_HPP
#define I_SENSOR_HPP

#include <string>

class Sensor {
private:
    std::string id;
public:
    virtual void measure() = 0;
    virtual int getData() = 0;
    virtual std::string getId() = 0;
    virtual ~Sensor() {}
};

#endif // I_SENSOR_HPP