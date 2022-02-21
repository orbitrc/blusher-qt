#include <blusher/pointer-event.h>

namespace bl {

PointerEvent::PointerEvent(Button button, double x, double y)
{
    this->_button = button;
    this->_x = x;
    this->_y = y;
}

//=================
// Public Methods
//=================

PointerEvent::Button PointerEvent::button() const
{
    return this->_button;
}

double PointerEvent::x() const
{
    return this->_x;
}

double PointerEvent::y() const
{
    return this->_y;
}

} // namespace bl
