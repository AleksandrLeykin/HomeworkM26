#pragma once

#include <vector>

#ifndef _SUMARRAY_
#define _SUMARRAY_

class SumArray
{
private:
	// vector size ������ ������� 
	int m_size;

	// number of threads to calculate sum ���������� ������� ��� ������� ����� 
	int m_numThreads;

	//vector of values ������ ��������
	std::vector<int> m_values;

	//result is a sum of all values of vector ��������� ����� �������� �������
	int m_result;

	//calculate a sum of values of the interval [l_index, r_index]
	void cal_sum_part(int left_index, int right_index, int index);
public:
	//size of vector, nummber of threads � ����������� �������� ��������� ������
	SumArray(int size, int numThreads);
	~SumArray();

	//calculate sum of values using threads //��������� ����� �������� � �������������� �������
	int calculate_using_threads();

	//calculate sum of values in main thread ��������� ����� �������� � �������� ������
	int calculate_without_threads();           
	//print values of vector //������� �������� �������
	void printArray();
};

#endif // !_SUMARRAY_