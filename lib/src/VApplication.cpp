//
// Created by toptan on 27.7.2022.
//
#include "VApplication.h"

#include "pimpl_impl.h"
#include "logging.h"

#include <chrono>
#include <iostream>
#include <thread>

extern "C" {
#include <clib/exec_protos.h>
}

struct VApplication::impl {
    static std::unique_ptr<VApplication> VAPP_INSTANCE;

    std::atomic_bool m_eventLoopDone{false};
    int m_exitCode{0};

    static VApplication &instance();

    explicit impl(bool eventLoopDone = false);
    void init(int, char **);
    int exec();
    void exit(int);
};

std::unique_ptr<VApplication> VApplication::impl::VAPP_INSTANCE;

VApplication &VApplication::impl::instance() {
    if (!impl::VAPP_INSTANCE) {
        impl::VAPP_INSTANCE = std::unique_ptr<VApplication>(new VApplication);
    }
    return *impl::VAPP_INSTANCE;
}

VApplication::impl::impl(bool eventLoopDone) : m_eventLoopDone(false) {}

void VApplication::impl::init(int argc, char **argv) {
}

int VApplication::impl::exec() {

    while (!m_eventLoopDone) {
        //        Wait(1L);
        std::this_thread::sleep_for(std::chrono::milliseconds(50));
    }
    LOG("Exiting application\n");
    return m_exitCode;
}

void VApplication::impl::exit(int status) {
    LOG("Quiting event loop with status: " << status << std::endl);
    m_exitCode = status;
    m_eventLoopDone = true;
}

VApplication &VApplication::instance() {
    return impl::instance();
}

VApplication::VApplication() = default;

VApplication::~VApplication() = default;

void VApplication::init(int argc, char **argv) {
    m->init(argc, argv);
}

int VApplication::exec() {
    return m->exec();
}

void VApplication::exit(int status) {
    m->exit(status);
}
