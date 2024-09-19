#pragma once

#include <iostream>
#include "vector"
#include <cstdlib> // srand() end rand()
#include <ctime> // time()


struct Param {
	int m_begin, m_end, result;
	std::vector<int> m_vec;
	Param(std::vector<int> vec, int begin, int end): m_vec(vec), m_begin(begin), m_end(end), result(0) {}
	Param(): m_begin(0), m_end(0), result(0) {}
};

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

int sumOfElements(std::vector<int> vec, int begin, int end) {
	int result = 0;
	for (int i = begin; i < end; i++)
	{
		result += vec[i];
	}
	std::cout << result << std::endl;
	return result;
}

DWORD WINAPI sumOfElements1(LPVOID lpParam) {
	Param* param = (Param*)lpParam;
	for (int i = param->m_begin; i < param->m_end; i++)
	{
		param->result += param->m_vec[i];
	}
	return 0;
}

//auxiliary functions вспомогательные функции
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