#include <memory>
#include <string>
#include <vector>
#include "MyModule.h"
#include "MyTestClass.h"

START_ADDING_TEST_CLASS_TO_MODULE(MyModule)
ADD_TEST_CLASS(MyTestClass)
END_ADDING_TEST_CLASS_TO_MODULE