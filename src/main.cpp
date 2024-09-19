#include <chrono>
#include <thread>
#include <windows.h>
#include "functions.h"


int main() {
		
	setlocale(LC_ALL, "ru");
	std::cout << "enter the number of elements in the array\nвведите колличество элементов в массиве" << std::endl;
	int n = getInt();	

	std::vector myArrays = myArray(n);
	/*for (int i = 0; i < myArrays.size(); i++)]
	{
		std::cout << myArrays[i] << " ";
	}
	std::cout << std::endl;*/

	//counting the time of the sum in one thread подсчет времени суммы в одном потоке
	auto begin = std::chrono::steady_clock::now();

	int result = 0;
	for (int i = 0; i < myArrays.size(); i++)
	{
		result += myArrays[i];
	}
	std::cout << "sum of array elements = " << result << std::endl;

	auto end = std::chrono::steady_clock::now();
	
	auto timeВifference_ms = std::chrono::duration_cast<std::chrono::milliseconds>(end - begin);

	std::cout << "The time: " << timeВifference_ms.count() << " ms\n";


	//split an array into parts разбить массив на части
	std::cout << "Рow many parts to split the array into? 1 - 10\nНа сколько частей разделить массив? 1 - 10" << std::endl;
	int m = getInt();

	//
	DWORD threadId1;
	//DWORD threadId2;

	switch (m)
	{
	case 1:
		//counting the time of the sum in one thread подсчет времени суммы в одном потоке
		begin = std::chrono::steady_clock::now();
				
		result = sumOfElements(myArrays, 0, myArrays.size());
		std::cout << "m = 1 = " << result << std::endl;
		end = std::chrono::steady_clock::now();
		
		timeВifference_ms = std::chrono::duration_cast<std::chrono::milliseconds>(end - begin);
		std::cout << "The time: " << timeВifference_ms.count() << " ms\n";
		break;
	case 2:
		//std::cout << sumOfElements(myArrays, 0, (myArrays.size() / 2)) << std::endl;
		//std::cout << sumOfElements(myArrays, (myArrays.size() / 2), myArrays.size()) << std::endl;
		result = 0;
		begin = std::chrono::steady_clock::now();	
		{
			//result = sumOfElements(myArrays, 0, (myArrays.size() / 2));
			Param param1(myArrays, 0, (myArrays.size() / 2));
			HANDLE hThread1;
			hThread1 = CreateThread(nullptr, 0, sumOfElements1, &param1, 0, &threadId1);
			if (hThread1 == nullptr) {
				//произошла ошибка при создании потока
				std::cout << "CreateThread failed" << std::endl;
				return 1;
			}
			else {
				//поток создан ждем, пока поток завершится
				WaitForSingleObject(hThread1, INFINITE);
				//после завершения потока выводим результат
				std::cout << "sum thread1 = " << param1.result << std::endl;
				CloseHandle(hThread1);
			}
			result += param1.result;

			Param param(myArrays, (myArrays.size() / 2), myArrays.size());
			HANDLE hThread;

			hThread = CreateThread(nullptr, 0, sumOfElements1, &param, 0, &threadId1);
			//проверяем дескриптор созданного потока
			if (hThread == nullptr) {
				//произошла ошибка при создании потока
				std::cout << "CreateThread failed" << std::endl;
				return 1;
			}
			else {
				//поток создан ждем, пока поток завершится
				WaitForSingleObject(hThread, INFINITE);
				//после завершения потока выводим результат
				std::cout << "sum thread1 = " << param.result << std::endl;
				CloseHandle(hThread);
			}
			result += param.result;

			std::cout << "sum array = " << result << std::endl;


			/*std::thread t1(sumOfElements, myArrays, 0, (myArrays.size() / 2));
			
			std::thread t2(sumOfElements, myArrays, (myArrays.size() / 2), myArrays.size());
			if (t1.joinable())
				t1.join();
			if (t2.joinable())
				t2.join();*/

			//result = sumOfElements(myArrays, 0, (myArrays.size() / 2)) + sumOfElements(myArrays, ((myArrays.size() / 2)), myArrays.size());
			//std::cout << "m = 2 = " << result << std::endl;
		}
		end = std::chrono::steady_clock::now();

		timeВifference_ms = std::chrono::duration_cast<std::chrono::milliseconds>(end - begin);
		std::cout << "The time: " << timeВifference_ms.count() << " ms\n";
		break;
	default:
		break;
	}

	//creating threads создание потоков

	return 0;
}

