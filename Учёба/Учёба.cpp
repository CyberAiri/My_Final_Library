#include "MyTools.h"
#include <iostream>

using namespace std;

int main() {

	int myNumbers[] = { 10, 20, 30, 40, 50 };
	// Передаем сам массив (это и есть адрес) и его размер
	int total = EasyTools::Math::sumArray(myNumbers, 5);

	cout << "Сумма массива: " << total << endl;
}