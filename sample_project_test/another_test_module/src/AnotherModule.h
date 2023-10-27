#pragma once
#include "atl_includes.h"
#include "TestClassDeclarations.h"
#include <string>
#include <vector>

Module_Declaration(AnotherModule,
	add_test_class(AnotherTestClass)
	add_test_class(AClassUnderTest)
)

