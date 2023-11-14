#include "MyTestRunner.h"

int main() {
	MyRunner testRunner = MyRunner();
	testRunner.runSomeTests(std::make_shared<MyTests>(), vector<string>{"Another Module", "Another test klass"});
	std::cin.get();
}
