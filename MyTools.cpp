#include "MyTools.h"
#include <iostream>

namespace EasyTools {

	namespace Math {
		int getSum(int start, int end) {
			int total = 0;
			for (int i = start; i <= end; i++) {
				total += i;
			}
			return total;
		}

		double getFinalPrice(double price, double discount) {
			if (discount > 100) discount = 100;
			return price * (1 - discount / 100);
		}
		int sumArray(int* arr, int size) {
			int sum = 0;
			for (int i = 0; i < size; i++) {
				// Мы используем указатель 'arr' как массив!
				sum += arr[i];
			}
			return sum;
		}
	}

	namespace Print {
		void printNumber(int limit, bool evenOnly) {
			for (int i = 0; i <= limit; i++) {
				if (evenOnly) {
					if (i % 2 == 0) std::cout << i << " ";
				}
				else {
					if (i % 2 != 0) std::cout << i << " ";
				}
			}
			std::cout << std::endl;
		}
		void printAddress(int* ptr) {
			if (ptr != nullptr) {
				// Печатаем сам адрес (где лежит) и значение (что лежит)
				std::cout << "Адрес в памяти: " << ptr << " | Значение: " << *ptr << std::endl;
			}
		}
	}
}