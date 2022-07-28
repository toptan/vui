//
// Created by toptan on 27.7.2022.
//

#ifndef VUI_VAPPLICATION_H
#define VUI_VAPPLICATION_H

#include <memory>
#include <atomic>

#include "pimpl.h"

/// The application class. A singleton.
class VApplication {
public:
    /// Returns a singleton instance of the current application.
    /// \return Instance of the application.
    static VApplication& instance();

    /// The destructor
    ~VApplication();

    // No copies nor moves!
    VApplication(const VApplication&) = delete;
    VApplication(VApplication&&) = delete;
    VApplication &operator=(const VApplication&) = delete;
    VApplication &operator=(VApplication&&) = delete;

    /// Initializes application with command line params.
    /// \param argc Number of params.
    /// \param argv Array of params.
    void init(int argc, char** argv);

    /// Starts the application main loop.
    /// \return Application exit code. 0 means app exited cleanly.
    int exec();

    /// Orders application to quit main loop and finish with given exit code.
    /// \param status The status code to pass to the operating system.
    void exit(int status);

private:
    struct impl;
    pimpl<impl> m;
    /// The constructor
    VApplication();


};


#endif//VUI_VAPPLICATION_H
