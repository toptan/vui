#include "VApplication.h"

#include <iostream>
#include <thread>
#include <chrono>

int main() {
    std::cout << "Hello, World!" << std::endl;

    std::thread t([]() {
        std::this_thread::sleep_for(std::chrono::seconds(2));
        VApplication::instance().exit(-1);
    });

    int status = VApplication::instance().exec();

    t.join();
    return status;
}
