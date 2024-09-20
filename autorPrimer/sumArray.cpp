#include "sumArray.h"
#include <cstdlib>
#include <ctime>
#include <thread>


SumArray::SumArray(int size, int numThreads): m_size(size), m_numThreads(numThreads) {
	const int min_value = 0;
	const int max_values = 10;
	srand(time(0));
	for (int i = 0; i < size; i++) {
		m_values.push_back((min_value + rand()) % (max_values - min_value + 1));
	}
}

SumArray::~SumArray()
{
}

int SumArray::calculate_using_threads()
{
	std::vector<std::thread> threads;
	int left_index = 0;
	int right_index = 0;
	int element_count = m_size / m_numThreads;
	m_result = 0;

	for (int i = 0; i < m_numThreads; ++i) {
		if (i == m_numThreads - 1) {
			//if we have left elements, we consider them если у нас есть левые элементы, мы их учитываем
			right_index = m_values.size();
		}
		else
			right_index += element_count;

		//create a thread создаем поток
		std::thread t(&SumArray::cal_sum_part, this, left_index, right_index - 1, i);

		//we cannot copy a thread object so we move it мы не можем скопировать объект потока, поэтому мы перемещаем его
		threads.push_back(std::move(t));
		left_index += element_count;
	}

	for (auto& t : threads)
	{
		if (t.joinable())
			t.join();
	}

	return m_result;
}

void SumArray::cal_sum_part(int left_index, int right_index, int index)
{
	int s = 0;
	while (left_index <= right_index) {
		s += m_values[left_index++];
	}
	m_result += s;
	//std::cout << "Thread id = " << std::this_thread::get_id() << "  index = " << index << " sum = " << s << std::endl;
}