#include <iostream>
#define CALL_WITH_MAX(a, b) print((a) > (b) ? (a) : (b))


template <typename T>
void print(const T& a)
{
	std::cout << a << std::endl;
}


template <typename T>
inline void callWithMax(const T& a, const T& b)
{
	print(a > b ? a : b);
}

int main()
{
	int a1{ 5 };
	int b1{ 0 };
	int a2{ 5 };
	int b2{ 0 };
	int a3{ 5 };
	int b3{ 0 };
	int a4{ 5 };
	int b4{ 0 };
	callWithMax(++a1, b1);
	callWithMax(++a2, b2+10);
	CALL_WITH_MAX(++a3, b3);  // a is incremented twice
	CALL_WITH_MAX(++a4, b4 + 10); // a is incremented once

	return 1;
}