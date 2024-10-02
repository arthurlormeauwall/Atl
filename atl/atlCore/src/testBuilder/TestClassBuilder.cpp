#include "TestClassBuilder.h"

TestClassBuilder::TestClassBuilder(string name) : TestTreeBuilder(name) {}

void TestClassBuilder::addChildren() {
	addUnitTests();
}
void TestClassBuilder::createUnitTest(string name, vector<Result>(*f)()) {
	m_testData.hasChildren = true;
	add(std::make_shared<UnitTestBuilder>(name, f));
}
