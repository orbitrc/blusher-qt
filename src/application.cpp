#include <blusher/application.h>

#include "application-impl.h"

namespace bl {

Application::Application(int argc, char *argv[])
{
    this->_impl = new ApplicationImpl(argc, argv);
}

Application::~Application()
{
    delete this->_impl;
}

//==================
// Public Methods
//==================

int Application::exec()
{
    return this->_impl->exec();
}

} // namespace bl
