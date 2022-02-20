#include <blusher/surface.h>

#include "surface-impl.h"

namespace bl {

Surface::Surface(Surface *parent)
{
    if (parent != nullptr) {
        this->_impl = new SurfaceImpl(parent->_impl);
    } else {
        this->_impl = new SurfaceImpl();
    }

    this->_parent = parent;

    this->set_color(Color::from_rgb(255, 255, 255));
}

//=================
// Public Methods
//=================

void Surface::paint()
{
    this->_impl->paint();
}

void Surface::set_color(const Color &color)
{
    this->_color = color;
    this->_impl->setColor(color);
}

void Surface::show()
{
    this->_impl->show();
}

} // namespace bl
