#ifndef EVENT_DISPATCHER_H
#define EVENT_DISPATCHER_H

#include <unordered_map>
#include <vector>
#include <functional>
#include <string>
#include <iostream>
#include <any>

class EventDispatcher
{
private:
    using EventHandler = std::function<void(const std::any &)>;
    std::unordered_map<std::string, std::vector<EventHandler>> eventHandlers;

public:
    void registerForEvent(const std::string &eventName, const EventHandler &handler);
    void dispatchEvent(const std::string &eventName);

    template <typename T>
    void dispatchEvent(const std::string &eventName, const T &data);
};

// irgendwie muss das hier sein, damit es funktioniert. wegen des templates oder so
template <typename T>
void EventDispatcher::dispatchEvent(const std::string &eventName, const T &data)
{

    auto it = eventHandlers.find(eventName);

    if (it != eventHandlers.end())
    {
        #if DEBUG
            std::cout << "Dispatching event: " << eventName << std::endl;
        #endif
        for (const auto &handler : it->second)
        {
            handler(data);
        }
    }
    else
    {
        std::cout << "Event not found: " << eventName << std::endl;
    }
}

#endif // EVENT_DISPATCHER_H