#pragma once
#include <string>

struct Item {
	std::string name;
	int value;
	bool operator==(Item& rhs);
	Item(std::string n, int v) :name(n), value(v) {}
};

