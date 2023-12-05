#pragma once
#include "../../template.h"
#include "../consoleOutput/color/ConsoleColorHelpers.h"
namespace commonViews {
	const vector<string> atl_ascii =vector<string>({
		 color(F_YELLOW,"        _      _____   _         _       ___   ____    ____       _      ____   __   __"),
		 color(F_YELLOW,"       / \\    |_   _| | |       | |     |_ _| | __ )  |  _ \\     / \\    |  _ \\  \\ \\ / / "),
		 color(F_YELLOW,"      / _ \\     | |   | |       | |      | |  |  _ \\  | |_) |   / _ \\   | |_) |  \\ V / "),
		 color(F_YELLOW,"     / ___ \\    | |   | |___    | |___   | |  | |_) | |  _ <   / ___ \\  |  _ <    | |  "),
		 color(F_YELLOW,"    /_/   \\_\\   |_|   |_____|   |_____| |___| |____/  |_| \\_\\ /_/   \\_\\ |_| \\_\\   |_|  ")
		});
	const string welcome = color(F_YELLOW,"****** WELCOME TO ******");
	const string presentation = color(F_YELLOW,"A C++ minimal unit test library");
	const string goodBye = color(F_YELLOW,
		"\n\n****** GOOD BYE ******\n");
}

