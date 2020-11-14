/*============================================================================*/
#ifndef SHISHGL_SUBSCRIPTION_MANAGER_HPP
#define SHISHGL_SUBSCRIPTION_MANAGER_HPP
/*============================================================================*/
#include <unordered_map>
#include <unordered_set>

#include "Listener.hpp"
/*============================================================================*/
namespace ShishGL {

    class SubscriptionManager {
    public:

        SubscriptionManager() = delete;

        static void subscribe(Listener* sender, Listener* receiver);

        static void unsubscribe(Listener* sender, Listener* receiver);

        static void unsubscribeAll(Listener* sender);

        static void unsubscribeFromAll(Listener* receiver);

        virtual ~SubscriptionManager() = default;

    private:

        using SubscriptionPool =
            std::unordered_map<Listener*, std::unordered_set<Listener*>>;

        friend class EventSystem;

        static SubscriptionPool& Subscriptions();

    };

}
/*============================================================================*/
#endif //SHISHGL_SUBSCRIPTION_MANAGER_HPP
/*============================================================================*/