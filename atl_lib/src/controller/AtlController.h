#pragma once
#include "../pch.h"
#include "../presenter/output/OutputWriter.h"
#include "UnitTestController.h"


class AtlController 
{

protected: 
	std::vector<sharedptr<UnitTestController>> m_unitTests;
	sharedptr<AtlService> m_atlService;

public :
	AtlController(sharedptr<OutputWriter>);
	AtlController();
	virtual void addModules() = 0;
	void addRunner(sharedptr<UnitTestController>);
	void prepare();
	void runAllTests();
};

