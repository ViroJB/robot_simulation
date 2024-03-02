#ifndef EVENT_DISPATCHER_HPP
#define EVENT_DISPATCHER_HPP

#include <unordered_map>
#include <vector>
#include <functional>
#include <string>
#include <iostream>
#include <any>


using EventHandler = std::function<void()>;
class EventDispatcher {
    private:
        std::unordered_map<std::string, std::vector<EventHandler>> eventHandlers;
        
    public:
        void registerForEvent(const std::string& eventName, EventHandler handler);
        void dispatchEvent(const std::string& eventName);
};

#endif // EVENT_DISPATCHER_HPP