/*============================================================================*/

#include "ShishGL/window_container.hpp"

/*----------------------------------------------------------------------------*/

using namespace ShishGL;

/*============================================================================*/

WindowContainer::WindowContainer(const Vector2<size_t>& size,
                                 const Vector2<int>& pos,
                                 const std::string_view& win_title)
                                 : Window(size, pos, win_title) {}

/*============================================================================*/
