#include "event_dispatcher.h"

void EventDispatcher::registerForEvent(const std::string& eventName, const EventHandler& handler) {
    eventHandlers[eventName].emplace_back(handler);
}

void EventDispatcher::dispatchEvent(const std::string& eventName) {

    auto it = eventHandlers.find(eventName);

    if (it != eventHandlers.end()) {
        std::cout << "Dispatching event without data: " << eventName << std::endl;
        for (const auto& handler : it->second) {
            handler(std::any{}); // Empty std::any, as no data is provided
        }
    } else {
        std::cout << "Event not found: " << eventName << std::endl;
    }
}