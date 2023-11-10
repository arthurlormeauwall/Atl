#pragma once
#include "../template.h"
#include "TestData.h"

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

