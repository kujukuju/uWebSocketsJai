
#define EXPORT __declspec(dllexport)

#include "App.h"


extern "C" {

#include "wrapper/calls.cpp"

}