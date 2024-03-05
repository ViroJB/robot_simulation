#ifndef EVENT_DISPATCHER_H
#define EVENT_DISPATCHER_H

#include <any>
#include <functional>
#include <iostream>
#include <string>
#include <unordered_map>
#include <vector>

#include "../debug.h"

class EventDispatcher {
   private:
    using EventHandler = std::function<void(const std::any &)>;
    std::unordered_map<std::string, std::vector<EventHandler>> _eventHandlers;

   public:
    void registerForEvent(const std::string &eventName, const EventHandler &handler);
    void dispatchEvent(const std::string &eventName);

    template <typename T>
    void dispatchEvent(const std::string &eventName, const T &data);
};

// irgendwie muss das hier sein, damit es funktioniert. wegen des templates oder so
template <typename T>
void EventDispatcher::dispatchEvent(const std::string &eventName, const T &data) {
    auto it = _eventHandlers.find(eventName);

    if (it != _eventHandlers.end()) {
        DEBUG_MSG("Dispatching event: " << eventName);
        
        for (const auto &handler : it->second) {
            handler(data);
        }
    } else {
        std::cout << "Event not found: " << eventName << std::endl;
    }
}

#endif  // EVENT_DISPATCHER_H