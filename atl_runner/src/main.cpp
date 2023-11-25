#include "MyTestRunner.h"

int main() {
	MyRunner testRunner = MyRunner();
	testRunner.runAllTest(std::make_shared<MyTests>());
	std::cin.get();
}
