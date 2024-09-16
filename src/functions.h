#pragma once

#include <iostream>
#include "vector"
#include <cstdlib> // srand() end rand()
#include <ctime> // time()

void cinClear() {
	std::cin.clear();
	std::cin.ignore(32767, '\n');
}

int getInt() {
	while (true) {
		int num = 0;
		std::cin >> num;
		if (std::cin.fail()) {
			cinClear();
			std::cout << "Веден не верный символ! Invalid character entered!";
		}
		else
			return num;
	}
}

std::vector<int> myArray(int n) {
	std::vector<int> myArray(n);

	//generating different random numbers
	srand(time(nullptr));

	for (int i = 0; i < myArray.size(); i++)
	{
		// random numbers from 1 to 100
		myArray[i] = rand() % 101;		
	}

	return myArray;
}