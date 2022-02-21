#ifndef _BL_WINDOW_H
#define _BL_WINDOW_H

#include <stdint.h>

#include <blusher/surface.h>

namespace bl {

class Window : public Surface
{
    Window();

private:
    uint32_t width;
    uint32_t height;

    Surface *_decoration;
    Surface *_resize;
    Surface *_border;
    Surface *_body;
};

} // namespace bl

#endif /* _BL_WINDOW_H */
