#ifndef _BL_SURFACE_H
#define _BL_SURFACE_H

#include <memory>

#include "color.h"
#include "signal.h"
#include "pointer-event.h"

namespace bl {

class SurfaceImpl;

class Surface
{
public:
    Surface(Surface *parent = nullptr);

    /// Height of the surface.
    double height() const;

    void paint();

    Surface* parent();

    void set_color(const Color& color);

    void set_geometry(double x, double y, double width, double height);

    void show();

    /// Width of the surface.
    double width() const;

    /// This is implementation specific method. DO NOT USE THIS in an application.
    void move_if_window();

public:
    Signal<> color_changed;
    Signal<> clicked;

protected:
    //===============
    // Events
    //===============
    virtual void pointer_press_event(std::shared_ptr<PointerEvent> event);

    //===============
    // Protected
    //===============

private:
    void on_clicked();
    void pointer_press_handler(int impl_button, double x, double y);

private:
    SurfaceImpl *_impl;

    Surface *_parent;
    Color _color;
};

} // namespace bl

#endif /* _BL_SURFACE_H */
