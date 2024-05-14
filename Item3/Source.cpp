#include <vector>
#include <algorithm>
#include <iostream>

class Rational
{
private:
	int numerator;
	int denominator;

public:
	Rational(int num, int denom = 1) {
		numerator = num;
		denominator = denom;
	}

	// first const here is IMPORTANT
	// if not  (a * b) = c;  invoke operator= on the result of a*b!
	//  if (a * b = c) ... oops, meant to do a comparison!
	const Rational operator*(const Rational& other) const { 
		int newNumerator = numerator * other.numerator;
		int newDenominator = denominator * other.denominator;
		return Rational(newNumerator, newDenominator);
	}

	Rational& operator=(const Rational& other) {
		if (this != &other) { 
			this->numerator = other.numerator;
			this->denominator = other.denominator;
		}
		return *this;
	}
};


int main()
{
	std::vector<int> vec(30, 100);
	const std::vector<int>::iterator iter = vec.begin();
	*iter = 10; //  OK, changes what iter points to
	// ++iter;  error! iter is const

	std::vector<int>::const_iterator cIter = vec.begin(); // cIter acts like a const T
	// *cIter = 10; // error! *cIter is const
	++cIter; // fine, changes cIter
	return 1;
}


