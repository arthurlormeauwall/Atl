#pragma once
#include "../template.h"
#include "../presenter/output/OutputWriter.h"
#include "../model/AllTest.h"
#include "../service/AtlService.h"


class AtlController 
{
protected: 
	sharedptr<AtlService> m_atlService;

public :
	AtlController(sharedptr<OutputWriter>);
	AtlController();
	void runAllTests(sharedptr<AllTest> allTests);
};

