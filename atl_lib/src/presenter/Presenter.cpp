#include "Presenter.h"

string getTestResultsAsString(sharedptr<AllTestResult> allTestResult) {
	string out;
	for (std::map<std::string, ModuleResult>::iterator mit = allTestResult->modules.begin(); mit != allTestResult->modules.end(); mit++) {
		out.append("* Module : ").append(mit->second.name).append("\n");
		for (testMap<TestClassResult>::iterator tcit = mit->second.testClasses.begin();
			tcit != mit->second.testClasses.end();
			tcit++) {
			string tcIndent = "==>";
			out.append(tcIndent).append("Test class : ").append(tcit->second.name).append("\n");
			for (testMap<sharedptr<UnitTestResult>>::iterator utit = tcit->second.unitTestResults.begin();
				utit != tcit->second.unitTestResults.end();
				utit++) {
				string utIndent = "--------------------";
				out.append(utIndent).append(utit->second->path.unitTestName);
				if (utit->second->result->pass) {
					out.append("       SUCCESS \n");
				}
				else {
					out.append("       ASSERT FAILURES \n").append(utit->second->result->message);
				}
			}
			out.append("\n");
		}
		out.append("\n\n");
	}
	return out;
}

string Presenter::getStringFromTestResult(sharedptr<AllTestResult> allTestResult)
{
	string out;
	out.append(welcomeView);
	out.append(getTestResultsAsString(allTestResult));
	out.append(goodbyeView);
	return out;
}
