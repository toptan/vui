//
// Created by toptan on 28.07.2022.
// A simple PIMPL helper taken from:
// https://herbsutter.com/gotw/_101/
//

#include "pimpl.h"

#include <utility>

template<typename T>
pimpl<T>::pimpl() : m{ new T{} } { }

template<typename T>
template<typename ...Args>
pimpl<T>::pimpl( Args&& ...args )
    : m{ new T{ std::forward<Args>(args)... } } { }

template<typename T>
pimpl<T>::~pimpl() { }

template<typename T>
T* pimpl<T>::operator->() { return m.get(); }

template<typename T>
T& pimpl<T>::operator*() { return *m.get(); }