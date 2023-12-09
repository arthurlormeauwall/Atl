#include "AtlController.h"


AtlController::AtlController(bool ansiColorEnabled) {
	m_atlService = std::make_shared<AtlService>(std::make_shared<ConsoleOutputWriter>(ansiColorEnabled));
}

void AtlController::runAllTests(sharedptr<AllTestBuilder> allTests) {
	m_atlService->runAllTests(*allTests->init());
}


void AtlController::runSomeTests(sharedptr<AllTestBuilder> allTests, vector<string> path) {
	m_atlService->runSomeTests(*allTests->init(), path);
}
