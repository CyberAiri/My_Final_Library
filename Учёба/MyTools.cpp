#include "MyTools.h"
#include <iostream>
#include <Windows.h>
#include <string.h>
#include <tlhelp32.h>
#include <tchar.h>

namespace EasyTools {
	namespace Memory {
		// Теперь принимает TCHAR - ему всё равно на настройки Юникода
		// Функция возвращает PID процесса с именем procName
		DWORD GetPid(const TCHAR* procName) {
			DWORD pid = 0;
			HANDLE snapshot = CreateToolhelp32Snapshot(TH32CS_SNAPPROCESS, 0);

			if (snapshot != INVALID_HANDLE_VALUE) {
				PROCESSENTRY32 pe;
				pe.dwSize = sizeof(pe);

				if (Process32First(snapshot, &pe)) {
					do {
						// _tcsicmp — это универсальная версия сравнения строк
						if (_tcsicmp(pe.szExeFile, procName) == 0) {
							pid = pe.th32ProcessID;
							break;
						}
					} while (Process32Next(snapshot, &pe));
				}
			}
			CloseHandle(snapshot);
			return pid;
		}

		// Здесь тоже используем const TCHAR*
		// Функция пишет в память процесса с именем procName значение value по адресу address
		bool WriteInt(const TCHAR* procName, uintptr_t address, int value) {
			DWORD pid = GetPid(procName);
			if (pid == 0) return false;

			HANDLE hProc = OpenProcess(PROCESS_ALL_ACCESS, FALSE, pid);
			if (hProc) {
				bool result = WriteProcessMemory(hProc, (LPVOID)address, &value, sizeof(int), NULL);
				CloseHandle(hProc);
				return result;
			}
			return false;
		}
	}

	namespace Math {
		// Функция возвращает сумму чисел от start до end
		int getSum(int start, int end) {
			int total = 0;
			for (int i = start; i <= end; i++) {
				total += i;
			}
			return total;
		}

		// Функция возвращает цену со скидкой
		double getFinalPrice(double price, double discount) {
			if (discount > 100) discount = 100;
			return price * (1 - discount / 100);
		}

		// Функция возвращает сумму элементов массива
		int sumArray(int* arr, int size) {
			int sum = 0;
			for (int i = 0; i < size; i++) {
				// Мы используем указатель 'arr' как массив!
				sum += arr[i];
			}
			return sum;
		}
		// функция возвращает сумму элементов массива и выводит в консоль
		void makeSnowball(int* arr, int size) {
			for (int i = 1; i < size; i++) {
				arr[i] = arr[i] + arr[i - 1];
				std::cout << arr[i] << " ";
			}
		}
	}

	namespace Print {

		// Функция печатает числа от 0 до limit
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
		// Функция печатает текст в консоль
		void printAddress(int* ptr) {
			if (ptr != nullptr) {
				// Печатаем сам адрес (где лежит) и значение (что лежит)
				std::cout << "Адрес в памяти: " << ptr << " | Значение: " << *ptr << std::endl;
			}
		}
	}
}