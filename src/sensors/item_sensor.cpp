#include "item_sensor.h"

void ItemSensor::setPublisher(Publisher *publisher) { 
    _publisher = publisher; 

    _publisher->subscribe("ItemListUpdated", std::bind(&ItemSensor::receiveItemListUpdated, this, std::placeholders::_1));
}

std::vector<std::pair<int, int>> ItemSensor::getItemPositions() { return _itemPositions; }

void ItemSensor::receiveItemListUpdated(const std::any &data) {
    const std::map<std::string, std::unique_ptr<IItem>> *itemList = std::any_cast<const std::map<std::string, std::unique_ptr<IItem>>*>(data);
    _itemPositions.clear();
    for(auto &item : *itemList) {
        _itemPositions.push_back(item.second->getPosition());
    }
}

void ItemSensor::attachTo(std::string id) { _attachedTo = id; }

void ItemSensor::measure() {
    // _publisher->publish(_attachedTo + "NewTargets");
}

// TODO implement
ISensor::DataType ItemSensor::getData() {
    DataType data = _itemPositions; // = _itemPositions;
    return data;
}

std::string ItemSensor::getId() { return _id; }