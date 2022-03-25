
#include "App.h"

#define EXPORT __declspec(dllexport)

extern "C" {

#include "wrapper/calls.cpp"

}