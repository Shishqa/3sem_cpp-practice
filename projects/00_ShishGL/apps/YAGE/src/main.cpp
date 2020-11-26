/*============================================================================*/
#include "YAGE.hpp"
#include "CoreApplication.hpp"
#include "WindowManager.hpp"
#include "SubscriptionManager.hpp"
/*============================================================================*/
using namespace ShishGL;
/*============================================================================*/

int main(int argc, char* argv[]) {

    CoreApplication::init(&argc, argv);

    YAGE::create();

    WindowManager::dump("layout.dot");
    SubscriptionManager::dump("subs.dot");

    return CoreApplication::run();
}

/*============================================================================*/
