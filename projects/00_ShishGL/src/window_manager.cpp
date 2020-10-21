/*============================================================================*/

#include <cstdio>
#include <stdexcept>

#include "window_manager.hpp"
#include "log.hpp"

/*----------------------------------------------------------------------------*/

using namespace ShishGL;

/*============================================================================*/

WindowManager::WindowMap& WindowManager::ActiveWindows() {
    static WindowMap ACTIVE_WINDOWS;
    return ACTIVE_WINDOWS;
}

/*----------------------------------------------------------------------------*/

void WindowManager::makeActive(Window* window) {

    if (!window) {
        printLog("Warning: tried to make NULL window active!");
        return;
    } else if (window->info.id != Window::ID_UNDEFINED) {
        printLog("Warning: tried to activate window twice!");
        return;
    }

    window->info.id = GraphicBase::createWindow(
            window->info.name,
            window->info.pos,
            window->info.size
            );

    activate(window);
}

/*----------------------------------------------------------------------------*/

void WindowManager::activate(Window* window) {

    ActiveWindows()[window->info.id] = window;

    printLog("Window %p is now active with id %d",
             reinterpret_cast<void*>(window), window->info.id);

//    for (const auto& p_subwindow : window->subwindows) {
//        p_subwindow->info.id = GI::create_window(window->info.id,
//                                                 p_subwindow->info.pos,
//                                                 p_subwindow->info.size);
//        activate(p_subwindow);
//    }
}

/*----------------------------------------------------------------------------*/

void WindowManager::makeInactive(Window* window) {

    if (!window) {
        printLog("Warning: tried to deactivate NULL window!");
        return;
    } else if (window->info.id == Window::ID_UNDEFINED) {
        //printLog("Warning: tried to deactivate not active window!");
        return;
    }

    ActiveWindows().erase(window->info.id);
    GraphicBase::destroyWindow(window->info.id);

    window->info.id = Window::ID_UNDEFINED;

    printLog("Window %p is now inactive", reinterpret_cast<void*>(window));
}


//void WindowManager::setHandlers(Window* window) {
//    glutSetWindow(window->info.id);
//    glutIdleFunc(manageOnIdle);
//    glutDisplayFunc(manageOnRender);
//    glutEntryFunc(manageOnEntry);
//    glutReshapeFunc(manageOnReshape);
//    glutMouseFunc(manageOnMouseClick);
//    glutKeyboardFunc(manageOnKeyPress);
//}

/*----------------------------------------------------------------------------*/

/*
Window* WindowManager::getCurrentActiveWindow() {
    const int active_win_id = glutGetWindow();
    try {
        return ActiveWindows().at(active_win_id);
    } catch (const std::out_of_range&) {
        return nullptr;
    }
}
*/

/*============================================================================*/
