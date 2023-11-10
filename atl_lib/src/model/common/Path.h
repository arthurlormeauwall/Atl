#pragma once
#include "../../template.h"

struct Path
{
	string moduleName;
	string testClassName;
	string unitTestName;
	Path() :
		moduleName("Undefined"),
		testClassName("Undefined"),
		unitTestName("Undefined") {}
	Path(string m, string t, string u) :
		moduleName(m),
		testClassName(t),
		unitTestName(u) {}
	Path(string m) :
		moduleName(m),
		testClassName("Undefined"),
		unitTestName("Undefined") {}
	Path(string m, string t) :
		moduleName(m),
		testClassName(t),
		unitTestName("Undefined") {}
};

