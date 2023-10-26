#include "MyTestRunner.h"
#include "MyModule.h"
#include "AnotherModule.h"

ADDING_MODULES_TO_RUNNER(MyRunner)
	ADD_MODULE(MyModule)
	ADD_MODULE(AnotherModule)
END

