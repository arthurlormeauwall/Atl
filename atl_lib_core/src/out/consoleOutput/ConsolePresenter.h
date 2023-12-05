#pragma once
#include "../../template.h"
#include "../../model/Model.h"
#include "../views/Views.h"
#include "../views/CommonViews.h"
#include "ConsoleResultStringWriter.h"
#include "color/ConsolecolorHelpers.h"


class ConsoleResultPresenter {
public:
	void addResultToStringWriter(const ResultView&, ResultStringWriter&);
};

class ConsoleAssertPresenter {
public:
	void addResultToStringWriter(const ResultView&, ResultStringWriter&);
};
class ConsoleUnitTestPresenter {
	ConsoleResultPresenter m_consoleResultPresenter;
	ConsoleAssertPresenter m_consoleAssertPresenter;
public:
	void addResultToStringWriter(const UnitTestView&, ResultStringWriter&);
};

class ConsoleTestClassPresenter {
	ConsoleResultPresenter m_consoleResultPresenter;
	ConsoleUnitTestPresenter m_consoleUnitTestPresenter;
public:
	void addResultToStringWriter(const TestClassView&, ResultStringWriter&);
};

class ConsoleModulePresenter {
	ConsoleResultPresenter m_consoleResultPresenter;
	ConsoleTestClassPresenter m_consoleTestClassPresenter;
public:
	void addResultToStringWriter(const ModuleView&, ResultStringWriter&);
};


class ConsoleAllTestPresenter {
	ConsoleResultPresenter m_consoleResultPresenter;
	ConsoleModulePresenter m_consoleModulePresenter;
public:
	string getStringFromTestResult(const TestData&);
	void addResultToStringWriter(const AllTestView&, ResultStringWriter&);
};

