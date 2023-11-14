#include "MyTestRunner.h"

#define RUN_ALL_TEST(builder, controller) controller c = controller();\
	c.runAllTest(std::make_shared<builder>())\



int main() {
	RUN_ALL_TEST(MyTests, MyRunner);
	std::cin.get();
}
