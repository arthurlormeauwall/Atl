#include "ConsoleColorHelpers.h"

string color(string color, string content, bool shouldUseAinsiColor) {
	if (shouldUseAinsiColor) {
		return COLOR(color).append(content).append(RESET_COLOR);
	}
	return content;
}