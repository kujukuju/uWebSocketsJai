
#ifdef __unix__
#define EXPORT __attribute__((visibility("default")))
#elif defined(_WIN32) || defined(WIN32)
#define EXPORT __declspec(dllexport)
#endif

#include "App.h"

extern "C" {

#include "wrapper/calls.cpp"

}