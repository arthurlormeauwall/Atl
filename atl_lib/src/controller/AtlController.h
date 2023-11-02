#pragma once
#include "../pch.h"
#include "../presenter/output/OutputWriter.h"
#include "../model/TestContainer.h"
#include "../service/AtlService.h"
#include "../model/AllTests.h"


class AtlController 
{
protected: 
	sharedptr<AtlService> m_atlService;

public :
	AtlController(sharedptr<OutputWriter>);
	AtlController();
	void runAllTests(sharedptr<AllTest> allTests);
};

