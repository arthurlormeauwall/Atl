#pragma once
#include "atl_includes.h" 
#include "AnotherModule.h"
#include "MyModule.h"

Runner_Declaration_With_Console_Output(MyRunner,
	//Add_Module(MyModule)
	Add_Module(AnotherModule)
)