#pragma once
#include "../../template.h"
#include "../../model/Model.h"
#include "../views/Views.h"
#include "../views/CommonViews.h"
#include "ConsoleResultStringWriter.h"

class ConsoleResultPresenter {
	bool m_ansiColorEnabled;
public:
	explicit ConsoleResultPresenter(bool ansiColorEnabled) :
		m_ansiColorEnabled(ansiColorEnabled)
	{}
	void addResultToStringWriter(const ResultView&, ResultStringWriter&);
};

class ConsoleAssertPresenter {
	bool m_ansiColorEnabled;
public:
	explicit ConsoleAssertPresenter(bool ansiColorEnabled) :
		m_ansiColorEnabled(ansiColorEnabled)
	{}
	void addResultToStringWriter(const ResultView&, ResultStringWriter&);
};

class ConsoleUnitTestPresenter {
	ConsoleResultPresenter m_consoleResultPresenter;
	ConsoleAssertPresenter m_consoleAssertPresenter;
	bool m_ansiColorEnabled;
public:
	explicit ConsoleUnitTestPresenter(bool ansiColorEnabled) :
		m_ansiColorEnabled(ansiColorEnabled),
		m_consoleResultPresenter(ConsoleResultPresenter(ansiColorEnabled)),
		m_consoleAssertPresenter(ConsoleAssertPresenter(ansiColorEnabled))
	{}
	void addResultToStringWriter(const UnitTestView&, ResultStringWriter&);
};

class ConsoleTestClassPresenter {
	ConsoleResultPresenter m_consoleResultPresenter;
	ConsoleUnitTestPresenter m_consoleUnitTestPresenter;
	bool m_ansiColorEnabled;
public:
	explicit ConsoleTestClassPresenter(bool ansiColorEnabled) :
		m_ansiColorEnabled(ansiColorEnabled),
		m_consoleResultPresenter(ConsoleResultPresenter(ansiColorEnabled)),
		m_consoleUnitTestPresenter(ConsoleUnitTestPresenter(ansiColorEnabled))
	{}
	void addResultToStringWriter(const TestClassView&, ResultStringWriter&);
};

class ConsoleModulePresenter {
	ConsoleResultPresenter m_consoleResultPresenter;
	ConsoleTestClassPresenter m_consoleTestClassPresenter;
	bool m_ansiColorEnabled;
public:
	explicit ConsoleModulePresenter(bool ansiColorEnabled) :
		m_ansiColorEnabled(ansiColorEnabled),
		m_consoleResultPresenter(ConsoleResultPresenter(ansiColorEnabled)),
		m_consoleTestClassPresenter(ConsoleTestClassPresenter(ansiColorEnabled))
	{}
	void addResultToStringWriter(const ModuleView&, ResultStringWriter&);
};


class ConsoleAllTestPresenter {
	ConsoleResultPresenter m_consoleResultPresenter;
	ConsoleModulePresenter m_consoleModulePresenter;
	bool m_ansiColorEnabled;
public:
	explicit ConsoleAllTestPresenter(bool ansiColorEnabled) :
		m_ansiColorEnabled(ansiColorEnabled),
		m_consoleResultPresenter(ConsoleResultPresenter(ansiColorEnabled)),
		m_consoleModulePresenter(ConsoleModulePresenter(ansiColorEnabled))
	{}
	string getStringFromTestResult(const TestData&);
	void addResultToStringWriter(const AllTestView&, ResultStringWriter&);
};

