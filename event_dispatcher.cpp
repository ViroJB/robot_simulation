#include "event_dispatcher.h"

void EventDispatcher::registerForEvent(const std::string& eventName, EventHandler handler) {
    eventHandlers[eventName].push_back(handler);
}

void EventDispatcher::dispatchEvent(const std::string& eventName) {
    std::cout << "Dispatching event: " << eventName << std::endl;

    auto it = eventHandlers.find(eventName);

    if (it != eventHandlers.end()) {
        std::cout << "Event found: " << eventName << std::endl;
        for (const auto& handler : it->second) {
            handler();
        }
    } else {
        std::cout << "Event not found: " << eventName << std::endl;
    }
}
