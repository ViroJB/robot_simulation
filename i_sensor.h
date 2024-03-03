#ifndef I_SENSOR_H
#define I_SENSOR_H

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

#endif // I_SENSOR_H