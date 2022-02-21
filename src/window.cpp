#include <blusher/window.h>

#define BLUSHER_SHADOW_WIDTH 40
#define BLUSHER_RESIZE_WIDTH 5
#define BLUSHER_BORDER_WIDTH 1

namespace bl {

Window::Window()
{
    this->_width = 200;
    this->_height = 200;

    this->_decoration = static_cast<Surface*>(this);
    this->_resize = new Surface(this->_decoration);

    // Init decoration.
    this->_decoration->set_geometry(
        0,
        0,
        this->_width + (BLUSHER_SHADOW_WIDTH * 2),
        this->_height + (BLUSHER_SHADOW_WIDTH * 2)
    );
    this->_decoration->set_color(Color::from_rgba(0, 0, 0, 100));

    // Init resize.
    this->_resize->set_geometry(
        BLUSHER_SHADOW_WIDTH - BLUSHER_RESIZE_WIDTH,
        BLUSHER_SHADOW_WIDTH - BLUSHER_RESIZE_WIDTH,
        this->_width + (BLUSHER_RESIZE_WIDTH * 2),
        this->_height + (BLUSHER_RESIZE_WIDTH * 2)
    );
    this->_resize->set_color(Color::from_rgba(255, 0, 0, 100));
}

uint32_t Window::width() const
{
    return this->_width;
}

uint32_t Window::height() const
{
    return this->_height;
}

void Window::show()
{
    this->_decoration->show();
    this->_decoration->paint();

    this->_resize->show();
    this->_resize->paint();
}

} // namespace bl
