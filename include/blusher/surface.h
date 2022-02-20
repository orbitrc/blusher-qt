#ifndef _BL_SURFACE_H
#define _BL_SURFACE_H

#include "color.h"
#include "signal.h"

namespace bl {

class SurfaceImpl;

class Surface
{
public:
    Surface(Surface *parent = nullptr);

    void paint();

    void set_color(const Color& color);

    void show();

public:
    Signal<> color_changed;

private:
    SurfaceImpl *_impl;

    Surface *_parent;
    Color _color;
};

} // namespace bl

#endif /* _BL_SURFACE_H */