//
// Created by toptan on 28.07.2022.
// A simple PIMPL helper taken from:
// https://herbsutter.com/gotw/_101/
//

#ifndef VUI_PIMPL_H
#define VUI_PIMPL_H

#include <memory>

template<typename T>
class pimpl {
private:
    std::unique_ptr<T> m;

public:
    pimpl();
    template<typename... Args>
    pimpl(Args &&...);
    ~pimpl();
    T *operator->();
    T &operator*();
};

#endif//VUI_PIMPL_H
