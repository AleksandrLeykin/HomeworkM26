#pragma once

#include <vector>

#ifndef _SUMARRAY_
#define _SUMARRAY_

class SumArray
{
private:
	// vector size размер вектора 
	int m_size;

	// number of threads to calculate sum количество потоков для расчета суммы 
	int m_numThreads;

	//vector of values вектор значений
	std::vector<int> m_values;

	//result is a sum of all values of vector результат суммы значений вектора
	int m_result;

	//calculate a sum of values of the interval [l_index, r_index]
	void cal_sum_part(int left_index, int right_index, int index);
public:
	//size of vector, nummber of threads в конструторе рандомно заполняем вектор
	SumArray(int size, int numThreads);
	~SumArray();

	//calculate sum of values using threads //вычислить сумму значений с использованием потоков
	int calculate_using_threads();

	//calculate sum of values in main thread вычислить сумму значений в основном потоке
	int calculate_without_threads();           
	//print values of vector //вывести значения вектора
	void printArray();
};

#endif // !_SUMARRAY_