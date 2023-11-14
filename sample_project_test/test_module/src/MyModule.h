#pragma once
#include "atl_includes.h"
#include "MyTestClass.h"
#include <string>
#include <memory>
#include <vector>

DECLARE_MODULE(MyModule,
	ADD_TEST_CLASS(MyTestClass);
);

