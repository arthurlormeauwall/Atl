#include "AtlController.h"


AtlController::AtlController() {
	m_atlService = std::make_shared<AtlService>(std::make_shared<ConsoleOutputWriter>());
}

void AtlController::runAllTests(sharedptr<AllTestBuilder> allTests) {
	m_atlService->runAllTests(*allTests->init());
}


void AtlController::runSomeTests(sharedptr<AllTestBuilder> allTests, vector<string> path) {
	m_atlService->runSomeTests(*allTests->init(), path);
}
