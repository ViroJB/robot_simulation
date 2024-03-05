#include "event_dispatcher.h"

void EventDispatcher::registerForEvent(const std::string &eventName, const EventHandler &handler) {
    _eventHandlers[eventName].emplace_back(handler);
}

void EventDispatcher::dispatchEvent(const std::string &eventName) {
    auto it = _eventHandlers.find(eventName);

    if (it != _eventHandlers.end()) {
#if DEBUG
        std::cout << "Dispatching event without data: " << eventName << std::endl;
#endif
        for (const auto &handler : it->second) {
            handler(std::any{});  // empty std::any, as no data is provided
        }
    } else {
        std::cout << "Event not found: " << eventName << std::endl;
    }
}