
#include "AtlController.h"


AtlController::AtlController(sharedptr<OutputWriter> testOutput) {
	m_atlService = std::make_shared<AtlService> (testOutput);
}

AtlController::AtlController() {
	m_atlService = std::make_shared<AtlService>(); 
}

void AtlController::runAllTest(sharedptr<AllTestInit> allTests){
	m_atlService->runAllTests(allTests->init());
}
