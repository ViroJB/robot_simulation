#ifndef ITEM_SENSOR_H
#define ITEM_SENSOR_H

#include <vector>
#include <map>
#include <memory>

#include "../events/publisher.h"
#include "../items/i_item.h"
#include "i_sensor.h"

// NOTE for now just get the item list
class ItemSensor : public ISensor {
   public:
    ItemSensor() {}
    void setPublisher(Publisher *publisher);
    void attachTo(std::string id);
    void measure();
    void receiveItemListUpdated(const std::any &data);
    DataType getData();
    std::string getId();
    std::vector<std::pair<int, int>> getItemPositions();

   private:
    std::string _id = "ItemSensor";
    std::string _attachedTo;
    Publisher *_publisher;
    std::vector<std::pair<int, int>> _itemPositions;
};

#endif  // ITEM_SENSOR_H