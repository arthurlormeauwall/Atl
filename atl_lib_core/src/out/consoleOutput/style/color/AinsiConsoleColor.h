#pragma once


#define F_BLACK "30"
#define F_RED "31"
#define F_GREEN "32"
#define F_YELLOW "33"
#define F_BLUE "34"
#define F_MAGENTA "35"
#define F_CYAN "36"
#define F_WHITE "37"

#define B_BLACK "40"
#define B_RED "41"
#define B_GREEN "42"
#define B_YELLOW "43"
#define B_BLUE "44"
#define B_MAGENTA "45"
#define B_CYAN "46"
#define B_WHITE "47"

#define RESET_COLOR "\x1b[0m"

#define COLOR_BEGIN(v) string("\x1b[").append(v)
#define END_COLOR .append("m")

#define COLOR(v) COLOR_BEGIN(v)END_COLOR
