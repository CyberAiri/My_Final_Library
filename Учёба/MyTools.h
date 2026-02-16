#pragma once
#include <windows.h>
#include <tchar.h>

namespace EasyTools {

	// Под-коробка для математики
	namespace Math {
		// Функция возвращает сумму чисел
		int getSum(int start, int end);
		// Функция возвращает цену со скидкой
		double getFinalPrice(double price, double discount);
		// Функция возвращает сумму элементов массива
		int sumArray(int* arr, int size);
	}

	// Под-коробка для вывода данных
	namespace Print {
		// Функция печатает числа
		void printNumber(int limit, bool evenOnly = true);

		// Функция печатает адрес указателя и его значение
		void printAddress(int* ptr);
	}

	// Под-коробка для работы с памятью
	namespace Memory {

		// Узнать ID процесса
		DWORD GetPid(const TCHAR* procName);

		// Записать число в процесс
		bool WriteInt(const TCHAR* procName, uintptr_t address, int value);

		// функция возвращает сумму элементов массива и выводит в консоль
		void makeSnowball(int* arr, int size);
	}
}