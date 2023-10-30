#pragma once
#include "atl_includes.h"
#include "MyTestClass.h"
#include <string>
#include <memory>
#include <vector>

std::vector<std::shared_ptr<UnitTestController>> getTestClasses_MyModule() {
    std::vector<std::shared_ptr<UnitTestController>> ut; 
    ut.push_back(std::make_shared<MyTestClass_>()); 
    return ut;
}