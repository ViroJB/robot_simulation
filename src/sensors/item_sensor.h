#ifndef ITEM_SENSOR_H
#define ITEM_SENSOR_H

#include <vector>

#include "../event_dispatcher/event_dispatcher.h"
#include "i_sensor.h"

// TODO changed return type in ISensor::getData to DataType(std::variant), change the rest of the code so it works again..
// NOTE for now just get the item list
class ItemSensor : public ISensor {
   public:
    ItemSensor() {}
    void setEventDispatcher(EventDispatcher *eventDispatcher);
    void attachTo(std::string id);
    void measure();
    DataType getData();

   private:
    std::string _attachedTo;
    EventDispatcher *_eventDispatcher;
    std::vector<std::pair<int, int>> _itemPositions;
};

#endif  // ITEM_SENSOR_H