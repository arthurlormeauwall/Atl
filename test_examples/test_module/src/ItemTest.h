#pragma once
#include "atl_includes.h"

struct Item {
	string name;
	int value;
	bool operator==(Item& rhs) {
		return name == rhs.name && value == rhs.value;
	}
	string(*toString)(Item it) =
		[](Item it)->string { return string("Name : ")
		.append(it.name)
		.append(" and value : ")
		.append(std::to_string(it.value));
	};

	Item(string n, int v) :name(n), value(v) {}
};


class ItemTest: public TestClassBuilder {
public:
	ItemTest(string name) : TestClassBuilder(name) {}
	virtual void addUnitTests() override;
};