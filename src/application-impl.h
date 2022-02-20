#ifndef APPLICATIONIMPL_H
#define APPLICATIONIMPL_H

#include <QGuiApplication>

namespace bl {

class ApplicationImpl
{
public:
    ApplicationImpl(int argc, char *argv[]);
    ~ApplicationImpl();

    int exec();

private:
    int _argc;

    QGuiApplication *_q_gui_application;
};

} // namespace bl

#endif // APPLICATIONIMPL_H
