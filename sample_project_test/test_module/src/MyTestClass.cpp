#include "MyTestClass.h"
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

void MyTestClass::addUnitTests() {
	createUnitTest("A test that should succeed",
		[]()->std::vector<Result>
		{
			Assertions assertions;
			Item item1("item_1", 1);
			Item item2("item_2", 2);
			assertions.addAssertion(IsEqualTo<Item>(item1, item2).getResultWithCustomToString(item1.toString));
			return assertions;
		}
	);
}
