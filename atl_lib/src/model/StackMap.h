#pragma once
#include "../template.h"
#include "TestData.h"

class TestInterface {
public:
	virtual	void run() = 0;
	virtual	void init() = 0;
	virtual TestData getData() = 0;
};

template<typename T>
class StackMap {
	vector<sharedptr<T>> m_data;
	map<string, int> m_map;
public:
	void add(sharedptr<T> t) {
		m_data.push_back(t);
	}
	sharedptr<T> getByOrder(int i) {
		return m_data.at(i);
	}
	int getByName(string name) {
		map<string, int>::iterator it = m_map.find(name);
		if (it != m_map.end()) {
			return it->second;
		}
		else {
			return -1;
		}
	}
	void remove(int) {}
	vector<sharedptr<T>> getAllAsVector() { return m_data; }
	map<string, sharedptr<T>> getAllAsMap() {}

};

class TestStackMap {
	StackMap<TestInterface> m_data;
public:
	void init() {
		for (sharedptr<TestInterface> t : m_data.getAllAsVector()) {
			t->init();
		}
	}
	void run() {
		for (sharedptr<TestInterface> t : m_data.getAllAsVector()) {
			t->run();
		}
	}
	StackMap<TestInterface>* getTest() {
		return &m_data;
	}
};
