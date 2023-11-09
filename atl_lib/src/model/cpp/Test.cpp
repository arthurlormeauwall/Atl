#include "../Test.h"
#include "../../template.h"

void Test::init() {
	addChildren();
	m_children.init();
}

 
void Test::run() {
	if (m_testData.hasChildren) {
		m_children.run();
		computeChildrenResult();
	}
	updateResult();
}

 
void Test::updateResult() {
	if (!m_testData.childrenResult.pass) {
		m_testData.result.pass = false;
		m_testData.result.message = "Some tests failed";
	}
	else {
		m_testData.result.pass = true;
		m_testData.result.message = "Succeed";
	}
}

 
bool Test::areChildrenPassing() {
	for (sharedptr<TestInterface> t : m_children.getTest()->getAllAsVector()) {
		if (!t->getData().result.pass) {
			return false;
		}
	}
	return true;
}

 
vector<string> Test::getChildrenMessage() {
	vector<string> messages;
	for (sharedptr<TestInterface> t : m_children.getTest()->getAllAsVector()) {
		messages.push_back(t->getData().result.message);
	}
	return messages;
}

 
void Test::computeChildrenResult() {
	m_testData.childrenResult.pass = areChildrenPassing();
	m_testData.childrenResult.message = getChildrenMessage();
}

 
void Test::add(sharedptr<TestInterface> t) {
	m_children.getTest()->add(t);
}

 
sharedptr<TestInterface> Test::get(string name) {
	return m_children.getTest()->getByOrder(m_children.getTest()->getByName(name));
}

 
vector<sharedptr<TestInterface>> Test::getAllChildren() {
	return m_children.getTest()->getAllAsVector();
}

 
TestData Test::getData() {
	return m_testData;
}

 
void Test::runAll() {
	run();
	m_children.run();
}


