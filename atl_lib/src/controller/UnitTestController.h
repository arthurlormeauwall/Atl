#pragma once
#include "../pch.h"

#include "../service/AtlService.h"
#include "../model/TestContainer.h"

class UnitTestController
{
protected:
	sharedptr<AtlService> m_atlService;
	std::vector<sharedptr<Result>> m_assertResults;

public:
	void setAtlService(sharedptr<AtlService> atlService);
	virtual void addTests() = 0;
	void add(sharedptr<UnitTest> test);
};

