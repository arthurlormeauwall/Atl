#pragma once
#include "atl_includes.h" 
#include "anotherTestClass.h"

class MyTestRunner : public AtlController {
public: MyTestRunner() : AtlController(std::make_shared<ConsoleOutputWriter>()) {} void addModules();
};