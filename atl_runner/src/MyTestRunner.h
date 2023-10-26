#pragma once
#include "atl_includes.h" 
#include "ModuleDeclaration.h"

class MyTestRunner : public AtlController {
public: MyTestRunner() : AtlController(std::make_shared<ConsoleOutputWriter>()) {} void addModules();
};