#pragma once 

#include <iostream>
#include <vector>
#include <string>
#include <memory>
#include <map>

template<typename T>
using testMap = std::map<std::string, T>;

template<typename T>
using sharedptr = std::shared_ptr<T>;

using string = std::string;

template<typename T>
using vector = std::vector<T>;

template<typename K, typename T>
using map = std::map<K, T>;

template<typename T>
class TestInMemoryRepository {
	vector<T> data;
public:
	void add(T t) { data.push_back(t); }
	T getByOrder(int i) { return data.at(i); }
	int getByName(string) {}
	void remove(int) {}
	vector<T> getAllAsVector() { return data; }
	map<string, T> getAllAsMap() {}
	void init() {
		for (T t : data) {
			t->init();
		}
	}
	void run() {
		for (T t : data) {
			t->run();
		}
	}
};
