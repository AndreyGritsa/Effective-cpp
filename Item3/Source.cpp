#include <vector>
#include <algorithm>
#include <iostream>
#include <string>

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


class TextBlock {
private:
	std::string text;
public:
	TextBlock(std::string text) : text(text)
	{};
	~TextBlock() = default;

	const char& operator[](std::size_t position) const // operator [] for const objects
	{
		return text[position];
	}

	char& operator[](std::size_t position) // operator [] for non-const objects
	{
		// this way we could add any additional functionality 
		// to the const version of the method
		// and call it here without code duplication
		return const_cast<char&>(								// cast away const on op[]’s return type;	
			static_cast<const TextBlock&>(*this)[position]);	// add const to *this’s type; call const version of op[]																
	}

};

void print(const TextBlock& ctb) // in this function, ctb is const
{
	std::cout << ctb[0] << std::endl; // calls const TextBlock::operator[]
}

class CTextBlock {
public:
	CTextBlock(char* pText) : pText(pText) {};
	char& operator[](std::size_t position) const // inappropriate (but bitwise) const declaration of operator[]
	{
		return pText[position];
	}
private:
	char* pText;
	mutable std::size_t textLength{0}; // these data members may
	mutable bool lengthIsValid{false}; // always be modified, even in const member functions
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

	TextBlock tb("Hello");
	std::cout << tb[0] << std::endl;; // calls non-const TextBlock::operator []
	const TextBlock ctb("World");
	std::cout << ctb[0] << std::endl; // calls const TextBlock::operator []
	print(tb); // we can use for both, const operator [] will be called
	print(ctb);

	const CTextBlock cctb("Hello"); // declare constant object
	char* pc = &cctb[0]; // call the const operator[] to get a pointer to cctb’s data
	// *pc = 'J'; // cctb now has the value “Jello”
	// std::cout << &cctb << std::endl;

	return 1;
}


