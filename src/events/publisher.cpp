#include "publisher.h"

void Publisher::subscribe(const std::string& eventType, Callback callback) {
    subscribers[eventType].push_back(std::move(callback));
}

// TODO make it remove one subscriber, not the whole event
void Publisher::unsubscribe(const std::string& eventType) {
    // subscribers.erase(eventType);
}

void Publisher::publish(const std::string& eventType) {
    DEBUG_MSG("Publishing event without Data: " << eventType);
    if (subscribers.find(eventType) != subscribers.end()) {
        for (auto& callback : subscribers[eventType]) {
            callback(std::any());  // call with empty data
        }
    }
}

void Publisher::publish(const std::string& eventType, const std::any& data) {
    DEBUG_MSG("Publishing event with Data: " << eventType);
    if (subscribers.find(eventType) != subscribers.end()) {
        for (auto& callback : subscribers[eventType]) {
            callback(data);
        }
    }
}