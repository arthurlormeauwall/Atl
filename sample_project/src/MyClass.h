#pragma once

template<typename T>
class MyClass
{
public:
	float add(T,T);
};
template<typename T>
float MyClass<T>::add(T a, T b) {
	return a + b;
}
