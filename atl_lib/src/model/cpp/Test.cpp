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

 
vector<Result> Test::getChildrenResults() {
	vector<Result> results;
	for (sharedptr<TestInterface> t : m_children.getTest()->getAllAsVector()) {
		results.push_back(Result(t->getData().result));
	}
	return results;
}

 
void Test::computeChildrenResult() {
	m_testData.childrenResult = ChildrenResult(areChildrenPassing(), getChildrenResults());
}

 
void Test::add(sharedptr<TestInterface> t) {
	m_children.getTest()->add(t);
}

 
//sharedptr<TestInterface> Test::get(string name) {
//	return m_children.getTest()->getByOrder(m_children.getTest()->getByName(name));
//}

 
vector<sharedptr<TestInterface>> Test::getAllChildren() {
	return m_children.getTest()->getAllAsVector();
}

 
TestData Test::getData() {
	return m_testData;
}

 
//void Test::runAll() {
//	run();
//	m_children.run();
//}


