/*============================================================================*/
#include <stdexcept>

#include "LogSystem.hpp"
#include "ObjectManager.hpp"
#include "Renderable.hpp"
#include "LayoutManager.hpp"
#include "RenderSystem.hpp"
#include "Platform.hpp"
/*============================================================================*/
using namespace ShishGL;
/*============================================================================*/

bool RenderSystem::is_initialized = false;

IPlatform* RenderSystem::active_platform = nullptr;

/*----------------------------------------------------------------------------*/

IPlatform& RenderSystem::Renderer() {
    if (!active_platform) {
        LogSystem::printError("Using Renderer() before initialization!");
        throw std::runtime_error("Error: using class Renderer()"
                                 "which is not initialized");
    }
    return *active_platform;
}

/*----------------------------------------------------------------------------*/

IPlatform& ShishGL::RENDERER() {
    return RenderSystem::Renderer();
}

/*----------------------------------------------------------------------------*/

bool RenderSystem::isInitialized() {
    return is_initialized;
}

/*----------------------------------------------------------------------------*/

bool RenderSystem::init(int *argc_ptr, char **argv) {

    if (is_initialized) {
        return false;
    }

    LogSystem::printLog("Initializing platform");

#ifdef USE_SFML
    active_platform = new SfmlPlatform();
    LogSystem::printLog("SFML platform is now active");
#endif

    active_platform->initDisplay(argc_ptr, argv);
    LogSystem::printLog("Platform initialized");

    is_initialized = true;

    return true;
}

/*----------------------------------------------------------------------------*/

bool RenderSystem::update() {

    if (!is_initialized) {
        LogSystem::printError("Running RenderSystem before initialization");
        throw std::runtime_error("Error: Running RenderSystem before initialization");
    }

    Renderer().clear(Color{0, 0, 0, 255});
    render(LayoutManager::ROOT);
    Renderer().display();

    return true;
}

/*----------------------------------------------------------------------------*/

void RenderSystem::render(Renderable::ID obj) {

    if (!LayoutManager::Layout().count(obj)) {
        return;
    }

    for (auto& child : LayoutManager::Layout()[obj].children) {
        GET<Renderable>(child).onRender();
        render(child);
    }
}

/*----------------------------------------------------------------------------*/

bool RenderSystem::terminate() {

    LogSystem::printLog("Terminating platform...");

    Renderer().closeDisplay();

    delete active_platform;
    active_platform = nullptr;

    LogSystem::printLog("Platform terminated");

    is_initialized = false;

    return true;
}

/*============================================================================*/
