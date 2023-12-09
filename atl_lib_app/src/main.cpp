#include "MyTestRunner.h"

int main(int argc, char* argv[]) {
	auto testRunner = AtlController(argv);;
	testRunner.runAllTests(std::make_shared<MyTests>());
	std::cin.get();
}
