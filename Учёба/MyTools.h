#pragma once

namespace EasyTools {
	// Под-коробка для математики
	namespace Math {
		int getSum(int start, int end);
		double getFinalPrice(double price, double discount);
	}

	// Под-коробка для вывода данных
	namespace Print {
		void printNumber(int limit, bool evenOnly = true);
	}
}