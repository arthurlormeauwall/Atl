#pragma once 

#include <iostream>
#include <vector>
#include <string>
#include <memory>
#include <map>

template<typename T>
using testMap = std::map<std::string, T>;

template<typename T>
using sharedptr = std::shared_ptr<T>;

using string = std::string;

template<typename T>
using vector = std::vector<T>;
