#include "MyTestRunner.h"

int main(int argc, char* argv[]) {
	auto atlController = AtlController(argv);;
	atlController.runAllTests(std::make_shared<MyTests>());
	std::cin.get();
}
