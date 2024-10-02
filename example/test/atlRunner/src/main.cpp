#include "AllTests.h"
int main(int argc, char* argv[]) {
	auto atlController = AtlController(argv);;
	atlController.runAllTests(std::make_shared<AllTests>());
	std::cin.get();
}
