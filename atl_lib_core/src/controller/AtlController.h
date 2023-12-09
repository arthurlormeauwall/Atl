#pragma once
#include "../template.h"
#include "../out/output/OutputWriter.h"
#include "../testBuilder/TestBuilder.h"
#include "../service/AtlService.h"


class AtlController {
public:
	AtlController(char* argv[]);
	void runAllTests(sharedptr<AllTestBuilder> allTests);
	void runSomeTests(sharedptr<AllTestBuilder> allTests, vector<string> name);

protected:
	sharedptr<AtlService> m_atlService;
};

