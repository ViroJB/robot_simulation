#ifndef I_SENSOR_H
#define I_SENSOR_H

#include <string>

class ISensor {
   private:
    std::string _id;

   public:
    virtual void attachTo(std::string id) = 0;
    virtual void measure() = 0;
    virtual int getData() = 0;
    virtual std::string getId() = 0;
    virtual ~ISensor() {}
};

#endif  // I_SENSOR_H