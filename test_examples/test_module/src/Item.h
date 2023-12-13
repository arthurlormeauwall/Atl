#pragma once
#include "atl_includes.h"

struct Item {
	string name;
	int value;
	bool operator==(Item& rhs) {
		return name == rhs.name && value == rhs.value;
	}
	Item(string n, int v) :name(n), value(v) {}
};

string(*ItemtoString)(Item it) =
[](Item it)->string { return string("Name : ")
.append(it.name)
.append(" and value : ")
.append(std::to_string(it.value));
};
