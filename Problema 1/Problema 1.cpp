// Problema 1.cpp : This file contains the 'main' function. Program execution begins and ends there.
//


#include <iostream>
#include "Fractie.h"
#include "Problema 1.h"

int main()
{
	try {
		std::cout << "Hello World!\n";
		Fractie<int> f = Fractie<int>::Fractie(2, 4);
		Fractie<int> g = Fractie<int>::Fractie(6, 3);
		Fractie<int> h = Fractie<int>::Fractie();
		f.print();
		g.print();
		h = f + g;
		h.print();
		f = g - h;
		f.print();
		h = (int)5;
	}
	catch (std::invalid_argument exception) {
		std::cout << "Numitorul nu poate fi 0";
	}
}

//2/3+2/1 = 2/3+6/3=8/3