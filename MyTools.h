#pragma once

namespace EasyTools {
	// Под-коробка для математики
	namespace Math {
		int getSum(int start, int end);
		double getFinalPrice(double price, double discount);
		int sumArray(int* arr, int size);
	}

	// Под-коробка для вывода данных
	namespace Print {
		void printNumber(int limit, bool evenOnly = true);
		void printAddress(int* ptr);
	}
}