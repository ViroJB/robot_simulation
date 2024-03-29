#ifndef PUBLISHER_H
#define PUBLISHER_H

#include <any>
#include <functional>
#include <iostream>
#include <string>
#include <unordered_map>

#include "../debug.h"

class Publisher {
   public:
    using Callback = std::function<void(const std::any&)>;

    void subscribe(const std::string& eventType, Callback callback);
    void unsubscribe(const std::string& eventType);
    void publish(const std::string& eventType);
    void publish(const std::string& eventType, const std::any& data);

   private:
    std::unordered_map<std::string, std::vector<Callback>> subscribers;
};

#endif  // PUBLISHER_H