#include "MyTestRunner.h"

int main() {
	auto testRunner = AtlController();
	testRunner.runAllTests(std::make_shared<MyTests>());
	//testRunner.runSomeTests(std::make_shared<MyTests>(), vector<string>{"Module"});
	std::cin.get();
}
