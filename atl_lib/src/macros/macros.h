#pragma once
#include "../model/Result.h"

using Assertions = std::vector<Result>;

#define ADD_TEST_CLASS(name) add(createTestClassBuilder<name>(#name))

#define DECLARE_MODULE(name, content) class name: public ModuleBuilder {\
public:\
	name(TestData td) : ModuleBuilder(td) {}\
	virtual void addChildren() override {\
	content\
	}\
}\

#define add_custom_assert(content) push_back(content)
#define add_build_in_assert(content)push_back(content->getResult())
#define ADD_UNIT_TEST(name) add(createUnitTestBuilder(name,\
		[]()->std::vector<Result>\

#define END_UT )); 

#define DEFINE_UNIT_TESTS(name) void name::addChildren() {\

#define END }

#define DECLARE_TEST_CLASS(name) class name: public TestClassBuilder {\
public:\
	name(TestData td) : TestClassBuilder(td) {}\
	virtual void addChildren() override;\
}\

