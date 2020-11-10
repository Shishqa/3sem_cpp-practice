/*============================================================================*/
#ifndef SHISHGL_EVENT_SYSTEM_IPP
#define SHISHGL_EVENT_SYSTEM_IPP
/*============================================================================*/
namespace ShishGL {

    template <typename SomeEvent, typename... Args>
    EventSystem::Helper<SomeEvent, void>
    EventSystem::postEvent(Args&&... args) {

        auto event = new SomeEvent(std::forward<Args>(args)...);
        Events().push(event);
    }

    /*--------------------------------------------------------------------*/

    template <typename SomeEvent, typename... Args>
    EventSystem::Helper<SomeEvent, bool>
    EventSystem::sendEvent(Object::ID sender, Args&&... args) {

        auto event = new SomeEvent(std::forward<Args>(args)...);

        bool status = sendEvent(sender, event);

        delete event;
        return status;
    }

}
/*============================================================================*/
#endif //SHISHGL_EVENT_SYSTEM_IPP
/*============================================================================*/
