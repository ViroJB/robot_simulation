#ifndef I_SENSOR_H
#define I_SENSOR_H

#include <string>
#include <variant>

#include "../events/publisher.h"

class ISensor {
   private:
    std::string _id;

   public:
    using DataType = std::any; // remove this and just use std::any directly? where DataType is used?

    virtual void setPublisher(Publisher *publisher) = 0;
    virtual void attachTo(std::string id) = 0;
    virtual void measure() = 0;
    virtual DataType getData() = 0;
    virtual std::string getId() = 0;
    virtual ~ISensor() {}
};

#endif  // I_SENSOR_H