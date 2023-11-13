#pragma once
#include "../../template.h"


class Comparable {
public:
	virtual string toString() = 0;
	virtual bool operator==(const Comparable* rhs) = 0;
};
