#pragma once
#include "../template.h"

template<typename T>
class StackMap {
public:
	void add(T t, string key) {
		m_data.push_back(t);
		m_map.emplace(key, index);
		index++;
	}

	T* getByOrder(int i) {
		return &m_data.at(i);
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

	vector<T> getAllAsVector() const {
		return m_data;
	}

	map<string, T> getAllAsMap() {}

	void doForEach(void (*func)(T* t)) {
		for (int i = 0; i < m_data.size(); i++) {
			func(&m_data.at(i));
		}
	}

private:
	vector<T> m_data;
	map<string, int> m_map;
	int index = 0;
};

