#include "../template.h"
#include "TestTreeBuilder.h"

void TestTreeBuilder::initChildrenTest(vector<sharedptr<TestTreeBuilder>> children) {
	for (sharedptr<TestTreeBuilder> t : children) {
		m_testData.children.add(*t->init(), t->m_testData.path);
	}
}

sharedptr<TestData> TestTreeBuilder::init() {
	addChildren();
	initChildrenTest(m_children.getAllAsVector());
	return std::make_shared<TestData>(m_testData);
}

void TestTreeBuilder::addChildren() {
}

void TestTreeBuilder::add(sharedptr<TestTreeBuilder> t) {
	m_children.add(t,t->m_testData.path);
}

