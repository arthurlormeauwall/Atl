#include "AtlController.h"

AtlController::AtlController(char* argv[]) {
	auto withAnsiConsoleColorEnabled = false;
	if (argv[1] && string(argv[1]) == "c") {
		withAnsiConsoleColorEnabled = true;
	}
	m_atlService = std::make_shared<AtlService>(std::make_shared<ConsoleOutputWriter>(withAnsiConsoleColorEnabled));
}

void AtlController::runAllTests(sharedptr<AllTestBuilder> allTests) {
	m_atlService->runAllTests(*allTests->init());
}


void AtlController::runSomeTests(sharedptr<AllTestBuilder> allTests, vector<string> path) {
	m_atlService->runSomeTests(*allTests->init(), path);
}
