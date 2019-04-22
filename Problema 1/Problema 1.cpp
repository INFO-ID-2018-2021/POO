// Problema 1.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include "Rational.h"

int main()
{
	try {
		Rational<int> f = Rational<int>(2, 3);
		Rational<int> g = Rational<int>(2);
		Rational<int> h = f / g;
		std::cout << h;
	}
	catch (std::invalid_argument exception) {
		std::cout << "Numitorul nu poate fi 0";
	}
}

//2/3+2/1 = 2/3+6/3=8/3