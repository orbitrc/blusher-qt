#include <blusher/application.h>
#include <blusher/surface.h>
#include <blusher/color.h>

int main(int argc, char *argv[])
{
    bl::Application app(argc, argv);

    bl::Surface surface;

    surface.set_color(bl::Color::from_rgba(100, 100, 100, 100));
    surface.show();

    return app.exec();
}
