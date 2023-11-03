#include "../template.h"
#include "Presenter.h"

//string AssertPresenter::getString(sharedptr<Result> assert) {
//	string out;
//	//out.append("Inside assert presenter \n");
//	return out;
//}
//string UnitTestPresenter::getString(Test unitTest) {
//	string out;
//	//out.append("Inside unit test presenter \n");
//	//out.append("module name : ").append(unitTest->getData().path.moduleName).append("\n");
//	//out.append("test class name : ").append(unitTest->getData().path.testClassName).append("\n");
//	//out.append("unit test name : ").append(unitTest->getData().path.unitTestName).append("\n");
//	return out;
//}
//string TestClassPresenter::getString(Test testClass) {
//	string out;
//	//out.append("Inside test class presenter \n");
//	//out.append("module name : ").append(testClass->getData().path.moduleName).append("\n");
//	//out.append("test class name : ").append(testClass->getData().path.testClassName).append("\n");
//
//	//vector<sharedptr<UnitTest>> unitTests = testClass->getAll();
//	//for (sharedptr<UnitTest> ut :  unitTests) {
//	//	out.append(m_unitTestPresenter.getString(ut));
//	//}
//	return out;
//}
//
//string ModulePresenter::getString(Test module) {
//	string out;
//	//out.append("Inside module presenter \n");
//	//out.append("module name : ").append(module->getData().path.moduleName).append("\n");
//
//	//vector<sharedptr<TestClass>> testClasses = module->getAll();
//	//for (sharedptr<TestClass> tc :  testClasses) {
//	//	out.append(m_testClassPresenter.getString(tc));
//	//}
//	return out;
//}

string Presenter::getStringFromTestResult(sharedptr<Test> allTest)
{
	string out;
	out.append(commonViews::welcome);

	//vector<Test> modules = allTest->getAll();
	//for (Test m : modules) {
	//	out.append(m_modulePresenter.getString(m));
	//}

	out.append(commonViews::goodBye);
	return out;
}
