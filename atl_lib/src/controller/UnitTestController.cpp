#include "UnitTestController.h"

void UnitTestController::setAtlService(sharedptr<AtlService> atlService) 
{
	m_atlService = atlService;	
}

void UnitTestController::add(sharedptr<UnitTest> test) 
{		
	m_atlService->addUnitTest(test); 	
}
