#include "Item.h"

bool Item::operator==(Item &rhs)
{
	return name == rhs.name && value == rhs.value;
}

