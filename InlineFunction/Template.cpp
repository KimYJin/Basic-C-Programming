#include<iostream>

template <typename T>

inline T SQUARE(T x)
{
	return x*x;
}

int main(void)
{
	std::cout<< SQUARE(12) << std::endl;
	std::cout<< SQUARE(3.15) << std::endl;
	return 0;
}