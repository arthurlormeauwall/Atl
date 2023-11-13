#pragma once
#include "../template.h"

template<typename T>
class StackMap {
	vector<T> m_data;
	map<string, int> m_map;
public:
	void add(T t) {
		m_data.push_back(t);
	}
	T getByOrder(int i) {
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
	vector<T> getAllAsVector() const { return m_data; }
	map<string, T> getAllAsMap() {}
	void doForEach(void (*func)(T* t)) {
		for (int i = 0; i < m_data.size(); i++) {
			func(&m_data.at(i));
		}
	}
};

