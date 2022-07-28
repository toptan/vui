//
// Created by toptan on 28.07.2022.
//

#ifndef VUI_LOGGING_H
#define VUI_LOGGING_H

#ifdef DEBUG
#define LOG(X)  std::cout << X;
#else
#define LOG(X)  ;
#endif
#endif//VUI_LOGGING_H
