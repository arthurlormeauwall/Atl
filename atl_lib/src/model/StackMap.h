#pragma once
#include "../template.h"

template<typename T>
class StackMap {
	vector<T> m_data;
public:
	void add(T t) { m_data.push_back(t); }
	T getByOrder(int i) { return m_data.at(i); }
	int getByName(string) {
		return 0;
	}
	void remove(int) {}
	vector<T> getAllAsVector() { return m_data; }
	map<string, T> getAllAsMap() {}
	void init() {
		for (T t : m_data) {
			t->init();
		}
	}
	void run() {
		for (T t : m_data) {
			t->run();
		}
	}
};
