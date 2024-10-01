#include "MyTests.h"
#include <iostream>
int main(int argc, char* argv[]) {
	auto atlController = AtlController(argv);;
	atlController.runAllTests(std::make_shared<MyTests>());
	std::cin.get();
	// std::cout<<"Hello from atl app"<<std::endl;
	
}
