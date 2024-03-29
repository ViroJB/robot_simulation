#ifndef I_SENSOR_H
#define I_SENSOR_H

#include <string>
#include <variant>

#include "../events/publisher.h"

class ISensor {
   private:
    std::string _id;

   public:
    using DataType = std::any;

    virtual void setPublisher(Publisher *publisher) = 0;
    virtual void attachTo(std::string id) = 0;
    virtual void measure() = 0;
    // virtual int getData() = 0;
    virtual DataType getData() = 0;
    virtual std::string getId() = 0;
    virtual ~ISensor() {}
};

#endif  // I_SENSOR_H