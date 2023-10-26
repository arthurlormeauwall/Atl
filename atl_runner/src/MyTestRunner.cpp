#include "MyTestRunner.h"

void MyTestRunner::addModules() {
	addRunner(std::make_shared<MyTestClass>());

}

