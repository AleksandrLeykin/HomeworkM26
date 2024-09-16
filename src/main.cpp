#include "functions.h"
#include <chrono>

int main() {
		
	setlocale(LC_ALL, "ru");
	std::cout << "enter the number of elements in the array\nââåäèòå êîëëè÷åñòâî ýëåìåíòîâ â ìàññèâå" << std::endl;
	int n = getInt();
	

	std::vector myArrays = myArray(n);
	/*for (int i = 0; i < myArrays.size(); i++)
	{
		std::cout << myArrays[i] << " ";
	}
	std::cout << std::endl;*/

	auto begin = std::chrono::steady_clock::now();

	int result = 0;
	for (int i = 0; i < myArrays.size(); i++)
	{
		result += myArrays[i];
	}
	std::cout << "sum of array elements = " << result << std::endl;

	auto end = std::chrono::steady_clock::now();
	
	auto timeÂifference_ms = std::chrono::duration_cast<std::chrono::milliseconds>(end - begin);

	std::cout << "The time: " << timeÂifference_ms.count() << " ms\n";

	return 0;
}

