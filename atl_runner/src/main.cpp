#include "MyTestRunner.h"



int main() {
	MyRunner testRunner = MyRunner();
	testRunner.runAllTests(std::make_shared<MyTests>());
}
