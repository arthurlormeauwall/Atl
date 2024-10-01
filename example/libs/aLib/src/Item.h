#pragma once
#include <string>
struct Item {
	std::string name;
	int value;
	bool operator==(Item& rhs);
	Item(std::string n, int v) :name(n), value(v) {}
};

std::string(*ItemtoString)(Item it) =
[](Item it)->std::string { return std::string("Name : ")
.append(it.name)
.append(" and value : ")
.append(std::to_string(it.value));
};
