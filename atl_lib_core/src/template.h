#pragma once 

#include <iostream>
#include <vector>
#include <string>
#include <memory>
#include <map>

template<typename T>
using sharedptr = std::shared_ptr<T>;

using string = std::string;

template<typename T>
using vector = std::vector<T>;

template<typename K, typename T>
using map = std::map<K, T>;



