#include "ConsoleOutputWriter.h"

void ConsoleOutputWriter::write(sharedptr<string> out)
{
	std::cout << *out << std::endl;
}
