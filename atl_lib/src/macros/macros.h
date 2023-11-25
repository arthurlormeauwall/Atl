#pragma once
#include "../model/Result.h"

using Assertions = std::vector<Result>;

#define isEqualTo(T, actual, expected) IsEqualTo<T>(actual, expected).getResult(\
				[](T a, T e)->bool { return a == e; },\
				[](T it)->string { return std::to_string(it); })\

#define isEqualToString(actual, expected) IsEqualTo<string>(actual, expected).getResult(\
				[](string a, string e)->bool { return a == e; },\
				[](string it)->string { return it; })\

#define isEqualToCustomToString(T, actual, expected, toString) IsEqualTo<T>(actual, expected).getResult(\
				[](T a, T e)->bool { return a == e; },\
				toString)\

#define addAssertion push_back 
