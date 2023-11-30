#include "colorHelpers.h"

string color(string color, string content) {
	return COLOR(color).append(content).append(RESET_COLOR);
}

string colorForeGroundAndBackGround(string colorF, string colorB, string content) {
	return COLOR_F_B(colorF, colorB).append(content).append(RESET_COLOR);
}