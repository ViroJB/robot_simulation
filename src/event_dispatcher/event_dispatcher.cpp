#include "event_dispatcher.h"

// TODO replace this thing.. rebuild it
EventDispatcher::EventDispatcher() : _eventHandlers() {
    std::cout << "EventDispatcher created" << std::endl;
    // _eventHandlers = std::unordered_map<std::string, std::vector<EventHandler>>();
}

void EventDispatcher::registerForEvent(const std::string &eventName, const EventHandler &handler) {
    std::cout << "Registering for event: " << eventName << std::endl;
    _eventHandlers[eventName].emplace_back(handler);
}

void EventDispatcher::dispatchEvent(const std::string &eventName) {
    auto it = _eventHandlers.find(eventName);

    if (it != _eventHandlers.end()) {
        DEBUG_MSG("Dispatching event without data: " << eventName);
        for (const auto &handler : it->second) { // zu first geaendert grad
            handler(std::any{});  // empty because no data
        }
    } else {
        std::cout << "Event not found: " << eventName << std::endl;
    }
}