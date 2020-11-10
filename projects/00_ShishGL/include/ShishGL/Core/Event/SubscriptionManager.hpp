/*============================================================================*/
#ifndef SHISHGL_SUBSCRIPTION_MANAGER_HPP
#define SHISHGL_SUBSCRIPTION_MANAGER_HPP
/*============================================================================*/
#include <unordered_map>
#include <unordered_set>

#include "Object.hpp"
/*============================================================================*/
namespace ShishGL {

    class SubscriptionManager {
    public:

        SubscriptionManager() = delete;

        static void subscribe(Object::ID sender, Object::ID receiver);

        static void unsubscribe(Object::ID sender, Object::ID receiver);

        static void unsubscribeAll(Object::ID sender);

        virtual ~SubscriptionManager() = default;

    private:

        using SubscriptionPool =
            std::unordered_map<Object::ID, std::unordered_set<Object::ID>>;

        friend class EventSystem;

        static SubscriptionPool& Subscriptions();

    };

}
/*============================================================================*/
#endif //SHISHGL_SUBSCRIPTION_MANAGER_HPP
/*============================================================================*/