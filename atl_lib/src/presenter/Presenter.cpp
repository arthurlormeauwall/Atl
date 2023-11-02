#include "Presenter.h"

string AssertPresenter::getString(sharedptr<Result> assert) {
	string out;
	//out.append("Inside assert presenter \n");
	return out;
}
string UnitTestPresenter::getString(sharedptr<UnitTest> unitTest) {
	string out;
	//out.append("Inside unit test presenter \n");
	//out.append("module name : ").append(unitTest->getData().path.moduleName).append("\n");
	//out.append("test class name : ").append(unitTest->getData().path.testClassName).append("\n");
	//out.append("unit test name : ").append(unitTest->getData().path.unitTestName).append("\n");
	return out;
}
string TestClassPresenter::getString(sharedptr<TestClass> testClass) {
	string out;
	//out.append("Inside test class presenter \n");
	//out.append("module name : ").append(testClass->getData().path.moduleName).append("\n");
	//out.append("test class name : ").append(testClass->getData().path.testClassName).append("\n");

	//vector<sharedptr<UnitTest>> unitTests = testClass->getAll();
	//for (sharedptr<UnitTest> ut :  unitTests) {
	//	out.append(m_unitTestPresenter.getString(ut));
	//}
	return out;
}

string ModulePresenter::getString(sharedptr<Module> module) {
	string out;
	//out.append("Inside module presenter \n");
	//out.append("module name : ").append(module->getData().path.moduleName).append("\n");

	//vector<sharedptr<TestClass>> testClasses = module->getAll();
	//for (sharedptr<TestClass> tc :  testClasses) {
	//	out.append(m_testClassPresenter.getString(tc));
	//}
	return out;
}

string AllTestPresenter::getString(sharedptr<Test> allTest) {
	string out;
	//out.append("Inside all test presenter \n");

	//vector<sharedptr<Module>> modules = allTest->getAll();
	//for (sharedptr<Module> m : modules) {
	//	out.append(m_modulePresenter.getString(m));
	//}
	return out;
}


string Presenter::getStringFromTestResult(sharedptr<Test> allTestResult)
{
	string out;
	out.append(welcomeView);
	//out.append(m_allTestPresenter.getString(allTestResult));
	out.append(goodbyeView);
	return out;
}
