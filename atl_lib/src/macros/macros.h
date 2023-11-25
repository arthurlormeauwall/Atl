#pragma once
#include "../model/Result.h"

using Assertions = std::vector<Result>;
#define defaultCompare []()
#define addBuildInAssertion(content) push_back(content->getResult()) 
#define addCustomAssertion(content) push_back(content) 
