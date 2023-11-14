#include "MyTestRunner.h"

int main() {
	MyRunner testRunner = MyRunner();
	testRunner.runSomeTests(std::make_shared<MyTests>(), vector<string>{"Another Module", "A third test class", "Another test that should fail"});
	std::cin.get();
}
