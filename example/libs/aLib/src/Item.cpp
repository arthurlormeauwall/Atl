#include "Item.h"

bool Item::operator==(Item &rhs)
{
	return name == rhs.name && value == rhs.value;
}

std::string (*ItemtoString)(Item it) =
	[](Item it) -> std::string {
	return std::string("Name : ")
		.append(it.name)
		.append(" and value : ")
		.append(std::to_string(it.value));
};
