#include "../../template.h"
#include "TestInit.h"


void TestInit::initChildrenTest(vector<sharedptr<TestInit>> children) {
	for (sharedptr<TestInit> t : children) {
		m_testData.children.add(t->init());
	}
}

sharedptr<TestData> TestInit::init() {
	addChildren();
	initChildrenTest(m_children.getAllAsVector());
	return std::make_shared<TestData>(m_testData);
}

void TestInit::addChildren() {
}

void TestInit::add(sharedptr<TestInit> t) {
	m_children.add(t);
}

