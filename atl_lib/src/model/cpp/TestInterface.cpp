#include "../../template.h"
#include "../TestInterface.h"


void initChildrenTest(vector<sharedptr<TestInterface>> children) {
	for (sharedptr<TestInterface> t : children) {
		t->init();
	}
}
void runChildrenTest(vector<sharedptr<TestInterface>> children) {
	for (sharedptr<TestInterface> t : children) {
		t->run();
	}
}

void TestInterface::init() {
	addChildren();
	initChildrenTest(m_children.getAllAsVector());
}

void TestInterface::run() {
	if (m_testData.hasChildren) {
		runChildrenTest(m_children.getAllAsVector());
		computeChildrenResult();
	}
	updateResult();
}

void TestInterface::addChildren() {
}

void TestInterface::add(sharedptr<TestInterface> t) {
	m_children.add(t);
}

void TestInterface::updateResult() {
	if (!m_testData.childrenResult.pass) {
		m_testData.result.pass = false;
		m_testData.result.message = "Some tests failed";
	}
	else {
		m_testData.result.pass = true;
		m_testData.result.message = "Succeed";
	}
}

vector<sharedptr<TestInterface>> TestInterface::getAllChildren() {
	return m_children.getAllAsVector();
}


TestData TestInterface::getData() {
	return m_testData;
}
bool TestInterface::areChildrenPassing() {
	for (sharedptr<TestInterface> t : m_children.getAllAsVector()) {
		if (!t->getData().result.pass) {
			return false;
		}
	}
	return true;
}


vector<Result> TestInterface::getChildrenResults() {
	vector<Result> results;
	for (sharedptr<TestInterface> t : m_children.getAllAsVector()) {
		results.push_back(Result(t->getData().result));
	}
	return results;
}


void TestInterface::computeChildrenResult() {
	m_testData.childrenResult = ChildrenResult(areChildrenPassing(), getChildrenResults());
}


