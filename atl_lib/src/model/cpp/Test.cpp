#include "../Test.h"
#include "../../template.h"

void Test::init() {
	addChildren();
	m_children.init();
}

void Test::addChildren() {};

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
	for (sharedptr<Test> t : m_children.getAllAsVector()) {
		if (!t->getData().result.pass) {
			return false;
		}
	}
	return true;
}

vector<string> Test::getChildrenMessage() {
	vector<string> messages;
	for (sharedptr<Test> t : m_children.getAllAsVector()) {
		messages.push_back(t->getData().result.message);
	}
	return messages;
}

void Test::computeChildrenResult() {
	m_testData.childrenResult.pass = areChildrenPassing();
	m_testData.childrenResult.message = getChildrenMessage();
}

void Test::add(sharedptr<Test> t) {
	m_children.add(t);
}

sharedptr<Test> Test::get(string name) {
	return m_children.getByOrder(m_children.getByName(name));
}

vector<sharedptr<Test>> Test::getAll() {
	return m_children.getAllAsVector();
}

TestData Test::getData() {
	return m_testData;
}

void Test::runAll() {
	run();
	m_children.run();
}
