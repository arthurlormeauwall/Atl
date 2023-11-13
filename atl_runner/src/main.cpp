#include "MyTestRunner.h"

struct s {
	int a = 0;
};

void doSomething(vector<s>* o) {
	for (s i : *o) {
		i.a = 3;
	}
}
void print(vector<s> o) {
	for (s i : o) {
		std::cout << i.a << std::endl;
	}
}
int main() {
	MyRunner testRunner = MyRunner();
	testRunner.runAllTest(std::make_shared<MyTests>());
	std::cin.get();
	//vector<s> test {s(), s(), s()};
	//print(test);
	//std::cout << "call to f " << std::endl;
	//for (auto i = 0; i < test.size(); i++) {
	//	test.at(i).a=4;
	//}
	//for (s e : test) {
	//	e.a=33;
	//}
	//print(test);
}
