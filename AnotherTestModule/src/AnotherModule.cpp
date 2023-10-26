#include <memory>
#include <string>
#include <vector>
#include "AnotherModule.h"
#include "MyTestClass.h"

START_ADDING_TEST_CLASS_TO_MODULE(AnotherModule)
	ADD_TEST_CLASS(AnotherTestClass)
END_ADDING_TEST_CLASS_TO_MODULE