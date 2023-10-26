#include "AtlController.h"


AtlController::AtlController(sharedptr<OutputWriter> testOutput) {
	m_atlService = std::make_shared<AtlService> (testOutput);
}

AtlController::AtlController() 
{
	m_atlService = std::make_shared<AtlService>(); 
}

void AtlController::addRunner(sharedptr<UnitTestController> runner)
{
	m_unitTests.push_back(runner);
}

void AtlController::prepare() 
{
	addModules();
	for (sharedptr<UnitTestController> runner : m_unitTests) 
	{
		runner->setAtlService(m_atlService);
		runner->addTests();
	}
}
void AtlController::runAllTests()
{
	prepare();
	m_atlService->runAllTests();
}
