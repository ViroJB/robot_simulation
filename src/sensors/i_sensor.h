#ifndef I_SENSOR_H
#define I_SENSOR_H

#include <string>
#include <variant>

class ISensor {
   private:
    std::string _id;

   public:
    using DataType = std::variant<int, std::pair<int, int>>;

    virtual void setEventDispatcher(EventDispatcher *eventDispatcher) = 0;
    virtual void attachTo(std::string id) = 0;
    virtual void measure() = 0;
    // virtual int getData() = 0;
    virtual DataType getData() = 0;
    virtual std::string getId() = 0;
    virtual ~ISensor() {}
};

#endif  // I_SENSOR_H