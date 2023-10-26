#include "MyTestRunner.h"

void MyTestRunner::addModules() {
	for (std::shared_ptr<UnitTestController> ut : MyModule::getModule()) {
		addRunner(ut);
	}
}

