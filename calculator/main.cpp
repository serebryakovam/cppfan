#include <iostream>
#include "calculator.h"


int main()
{
	Calculator calc;

	std::cout << calc.GCD(10, 10) << "\n";
	std::cout << calc.LCM(-10, -35) << "\n";
	std::cout << calc.Pow(2, 5) << "\n";
	std::cout << calc.Division(7, 5) << "\n";
	std::cout << calc.CheckSignEqual(5, 5) << "\n";
	return 0;
}
