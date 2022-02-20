#ifndef _BL_APPLICATION_H
#define _BL_APPLICATION_H

namespace bl {

class ApplicationImpl;

class Application
{
public:
    Application(int argc, char *argv[]);
    ~Application();

    int exec();

private:
    ApplicationImpl *_impl;
};

} // namespace bl

#endif /* _BL_APPLICATION_H */
