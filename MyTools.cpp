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
	}
}