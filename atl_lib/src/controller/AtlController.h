#pragma once
#include "../template.h"
#include "../presenter/output/OutputWriter.h"
#include "../testBuilder/TestBuilder.h"
#include "../service/AtlService.h"


class AtlController 
{
protected: 
	sharedptr<AtlService> m_atlService;

public :
	AtlController(sharedptr<OutputWriter>);
	AtlController();
	void runAllTest(sharedptr<AllTestBuilder> allTests);
};

