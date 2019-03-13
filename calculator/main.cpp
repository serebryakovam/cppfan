#include "calculator.h"
#include "assert_calculator.h"
#include <iostream>


int main()
{
	TestSum();
	TestDef();
	TestMultiplicattion();
	TestDivision();
	TestPow();
	TestGCD();
	TestLCM();
	TestCheckSignEqual();

	Calculator calc;
	std::cout << calc.GCD(10, 10) << "\n";
	std::cout << calc.LCM(-10, -35) << "\n";
	std::cout << calc.Pow(2, 5) << "\n";
	std::cout << calc.Division(7, 5) << "\n";
	std::cout << calc.CheckSignEqual(5, 5) << "\n";
	
	return 0;
}
