#include "event_dispatcher.h"

void EventDispatcher::registerForEvent(const std::string &eventName, const EventHandler &handler) {
    _eventHandlers[eventName].emplace_back(handler);
}

void EventDispatcher::dispatchEvent(const std::string &eventName) {
    auto it = _eventHandlers.find(eventName);

    if (it != _eventHandlers.end()) {
        DEBUG_MSG("Dispatching event without data: " << eventName);
        for (const auto &handler : it->second) {
            handler(std::any{});  // empty because no data
        }
    } else {
        std::cout << "Event not found: " << eventName << std::endl;
    }
}