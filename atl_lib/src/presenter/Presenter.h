#pragma once
#include "../pch.h"
#include "../model/TestResultContainer.h" 
#include "views/Views.h"

class Presenter {
public :
	string getStringFromTestResult(sharedptr<AllTestResult>);
};
