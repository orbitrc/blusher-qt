#include "application-impl.h"

namespace bl {

ApplicationImpl::ApplicationImpl(int argc, char *argv[])
{
    this->_argc = argc;

    this->_q_gui_application = new QGuiApplication(this->_argc, argv);
}

ApplicationImpl::~ApplicationImpl()
{
    delete this->_q_gui_application;
}

int ApplicationImpl::exec()
{
    return this->_q_gui_application->exec();
}

} // namespace bl
