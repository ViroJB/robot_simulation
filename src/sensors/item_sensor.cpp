#include "item_sensor.h"

void ItemSensor::setEventDispatcher(EventDispatcher *eventDispatcher) { _eventDispatcher = eventDispatcher; }

void ItemSensor::attachTo(std::string id) { _attachedTo = id; }
