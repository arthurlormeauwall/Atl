#include "MyTestRunner.h"

int main(int argc, char* argv[]) {
	auto withAnsiConsoleColorEnabled = false;
	if (argv[1] && string(argv[1])=="c") {
			withAnsiConsoleColorEnabled = true;
	}
	auto testRunner = AtlController(withAnsiConsoleColorEnabled);;
	testRunner.runAllTests(std::make_shared<MyTests>());
	std::cin.get();
}
