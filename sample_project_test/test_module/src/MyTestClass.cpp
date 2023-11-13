#include "MyTestClass.h"
#include "MyClass.h"
#include "atl_includes.h"

struct o : public Comparable{
	int a = 3;
	string toString() {
		return std::to_string(a);
	}
	bool operator==(const Comparable* rhs) override {
		return a == ((o*)rhs)->a;
	}
	o(int p) : a(p) {}
};


void MyTestClass::addChildren() {
	add(createUnitTestBuilder("should add two number",
		[]()->std::vector<Result>
		{
			Assertions assertions;
			o a(4);
			o b(5);
			Comparable* actual = &a;
			Comparable* expected = &b;
			assertions.push_back(assertThat<Comparable*>(actual).isEqualTo(expected)->getResult());
			return assertions;
		}
	));
}
