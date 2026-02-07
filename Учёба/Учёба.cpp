/*
 * C++ ВСЕ ОСНОВЫ В ОДНОМ ФАЙЛЕ - 500+ строк
 * Полный набор для игры в отладчике
 * ВСЕ ТЕМЫ ОТ А ДО Я
 */
#define _CRT_SECURE_NO_WARNINGS
#include <iostream>  // ввод-вывод
#include <cstring>   // строки C
#include <cstdlib>   // rand, malloc
#include <ctime>     // time

using namespace std; // чтобы не писать std::

// ==================== 1. ПЕРЕМЕННЫЕ И ТИПЫ ====================

void demoVariables() {
	cout << "\n=== 1. ПЕРЕМЕННЫЕ И ТИПЫ ДАННЫХ ===" << endl;

	// Базовые типы
	int integer = 42;           // целое число
	float floating = 3.14f;     // дробное число (32 бита)
	double dbl = 2.71828;       // двойная точность (64 бита)
	char character = 'A';       // символ
	bool boolean = true;        // логический тип

	// Модификаторы
	short small = 32767;        // короткое целое
	long big = 2147483647L;     // длинное целое  
	long long huge = 9223372036854775807LL; // очень длинное
	unsigned int positive = 4294967295U; // только положительные

	// Константы
	const int CONST_VAL = 100;  // нельзя изменить
#define MACRO_VAL 200       // макрос (старый стиль)

	// Вывод значений
	cout << "int: " << integer << ", адрес: " << &integer << endl;
	cout << "float: " << floating << ", размер: " << sizeof(float) << " байт" << endl;
	cout << "double: " << dbl << ", размер: " << sizeof(double) << " байт" << endl;
	cout << "char: " << character << ", код: " << (int)character << endl;
	cout << "bool: " << boolean << endl;
	cout << "const: " << CONST_VAL << endl;

	// ПРИМЕЧАНИЕ ДЛЯ ОТЛАДЧИКА:
	// Посмотрите адреса переменных в Memory Window
	// Сравните размеры разных типов
}

// ==================== 2. УКАЗАТЕЛИ (САМОЕ ВАЖНОЕ!) ====================

void demoPointers() {
	cout << "\n\n=== 2. УКАЗАТЕЛИ ===" << endl;

	int x = 10;           // обычная переменная
	int* ptr = &x;        // указатель хранит АДРЕС x

	cout << "x = " << x << ", адрес x = " << &x << endl;
	cout << "ptr = " << ptr << " (хранит адрес x)" << endl;
	cout << "*ptr = " << *ptr << " (разыменование)" << endl;

	// Меняем значение через указатель
	*ptr = 999;
	cout << "После *ptr = 999: x = " << x << endl;

	// Двойной указатель
	int** pptr = &ptr;
	cout << "pptr = " << pptr << " (адрес указателя ptr)" << endl;
	cout << "*pptr = " << *pptr << " (значение ptr = адрес x)" << endl;
	cout << "**pptr = " << **pptr << " (значение x)" << endl;

	// Указатель на void (универсальный)
	void* vptr = &x;
	cout << "void* vptr = " << vptr << endl;
	cout << "*(int*)vptr = " << *(int*)vptr << " (приведение типа)" << endl;

	// Нулевой указатель
	int* nullPtr = nullptr;
	cout << "nullptr: " << nullPtr << endl;

	// ПРИМЕЧАНИЕ ДЛЯ ОТЛАДЧИКА:
	// 1. В Watch добавьте: x, &x, ptr, *ptr, pptr, **pptr
	// 2. В Memory Window введите адрес &x и увидите байты числа 10
	// 3. Посмотрите как *ptr меняет значение в памяти
}

// ==================== 3. МАССИВЫ ====================

void demoArrays() {
	cout << "\n\n=== 3. МАССИВЫ ===" << endl;

	// Статический массив (в стеке)
	int staticArray[5] = { 1, 2, 3, 4, 5 };

	cout << "Статический массив: ";
	for (int i = 0; i < 5; i++) {
		cout << staticArray[i] << " ";
	}
	cout << endl;

	cout << "Адрес массива: " << staticArray << endl;
	cout << "Адрес первого элемента: " << &staticArray[0] << endl;
	cout << "Адрес второго элемента: " << &staticArray[1] << endl;

	// Динамический массив (в куче)
	int* dynamicArray = new int[5];
	for (int i = 0; i < 5; i++) {
		dynamicArray[i] = i * 10;
	}

	cout << "Динамический массив: ";
	for (int i = 0; i < 5; i++) {
		cout << dynamicArray[i] << " ";
	}
	cout << endl;
	cout << "Адрес в куче: " << dynamicArray << endl;

	// Массив и указатели
	cout << "\nМассив как указатель:" << endl;
	int arr[3] = { 100, 200, 300 };
	int* parr = arr;  // parr указывает на первый элемент

	cout << "arr[0] = " << arr[0] << " = " << *parr << endl;
	cout << "arr[1] = " << arr[1] << " = " << *(parr + 1) << endl;
	cout << "arr[2] = " << arr[2] << " = " << *(parr + 2) << endl;

	// Двумерный массив
	int matrix[2][3] = {
		{1, 2, 3},
		{4, 5, 6}
	};

	cout << "\nДвумерный массив:" << endl;
	for (int i = 0; i < 2; i++) {
		for (int j = 0; j < 3; j++) {
			cout << matrix[i][j] << " ";
		}
		cout << endl;
	}

	// Очистка динамической памяти
	delete[] dynamicArray;

	// ПРИМЕЧАНИЕ ДЛЯ ОТЛАДЧИКА:
	// 1. Сравните адреса элементов массива - они идут подряд
	// 2. Разница адресов = sizeof(int) байт
	// 3. Посмотрите как расположена матрица в памяти (строчно)
}

// ==================== 4. СТРОКИ ====================

void demoStrings() {
	cout << "\n\n=== 4. СТРОКИ ===" << endl;

	// С-строки (массив char)
	char cString[] = "Hello";
	cout << "C-string: " << cString << endl;
	cout << "Длина: " << strlen(cString) << endl;
	cout << "Размер массива: " << sizeof(cString) << " байт" << endl;

	// Работа с символами
	cout << "Первый символ: " << cString[0] << " код: " << (int)cString[0] << endl;
	cout << "Последний символ: " << cString[4] << endl;
	cout << "Нулевой символ (терминатор): " << (int)cString[5] << endl;

	// C++ строки
	string cppString = "World";
	cout << "C++ string: " << cppString << endl;
	cout << "Длина: " << cppString.length() << endl;
	cout << "Емкость: " << cppString.capacity() << endl;

	// Конкатенация
	string combined = cppString + " " + cppString;
	cout << "Объединенная: " << combined << endl;

	// Доступ к символам
	cppString[0] = 'w';
	cout << "После изменения: " << cppString << endl;

	// ПРИМЕЧАНИЕ ДЛЯ ОТЛАДЧИКА:
	// 1. Посмотрите как C-строка хранится в памяти: H e l l o \0
	// 2. Сравните адреса символов
	// 3. Посмотрите внутреннюю структуру std::string
}

// ==================== 5. СТРУКТУРЫ ====================

struct Person {
	char name[50];
	int age;
	double salary;
}; // <- точка с запятой ОБЯЗАТЕЛЬНА!

struct Point {
	int x, y;

	// Метод структуры (C++)
	void print() {
		cout << "Point(" << x << ", " << y << ")" << endl;
	}
};

void demoStructures() {
	cout << "\n\n=== 5. СТРУКТУРЫ ===" << endl;

	// Создание структуры
	Person person1;
	strcpy(person1.name, "Ivan");
	person1.age = 25;
	person1.salary = 50000.5;

	cout << "Person: " << person1.name
		<< ", age: " << person1.age
		<< ", salary: " << person1.salary << endl;

	// Инициализация
	Person person2 = { "Anna", 30, 60000.0 };

	// Указатель на структуру
	Person* ptrPerson = &person1;
	cout << "Через указатель: " << ptrPerson->name << endl;
	cout << "Альтернативно: " << (*ptrPerson).name << endl;

	// Структура с методами
	Point p = { 10, 20 };
	p.print();

	// Размер структуры
	cout << "sizeof(Person) = " << sizeof(Person) << " байт" << endl;
	cout << "Выравнивание: адрес age = " << (long long)&person1.age - (long long)&person1 << endl;

	// ПРИМЕЧАНИЕ ДЛЯ ОТЛАДЧИКА:
	// 1. Посмотрите расположение полей в памяти
	// 2. Обратите внимание на выравнивание (padding)
	// 3. Посмотрите как работает оператор ->
}

// ==================== 6. ФУНКЦИИ ====================

// Обычная функция
int add(int a, int b) {
	return a + b;
}

// Функция с указателями
void swap(int* a, int* b) {
	int temp = *a;
	*a = *b;
	*b = temp;
}

// Функция с ссылками (C++)
void swapRef(int& a, int& b) {
	int temp = a;
	a = b;
	b = temp;
}

// Перегрузка функций
void print(int x) {
	cout << "Целое: " << x << endl;
}

void print(double x) {
	cout << "Дробное: " << x << endl;
}

void print(const char* text) {
	cout << "Строка: " << text << endl;
}

// Рекурсивная функция
int factorial(int n) {
	if (n <= 1) return 1;
	return n * factorial(n - 1);
}

void demoFunctions() {
	cout << "\n\n=== 6. ФУНКЦИИ ===" << endl;

	// Вызов функции
	int sum = add(10, 20);
	cout << "add(10, 20) = " << sum << endl;

	// Функция с указателями
	int x = 5, y = 10;
	cout << "До swap: x=" << x << ", y=" << y << endl;
	swap(&x, &y);
	cout << "После swap: x=" << x << ", y=" << y << endl;

	// Функция с ссылками
	swapRef(x, y);
	cout << "После swapRef: x=" << x << ", y=" << y << endl;

	// Перегрузка
	print(42);
	print(3.14);
	print("Hello");

	// Рекурсия
	cout << "Факториал 5 = " << factorial(5) << endl;

	// Указатель на функцию
	int (*funcPtr)(int, int) = add;
	cout << "Через указатель: " << funcPtr(30, 40) << endl;

	// ПРИМЕЧАНИЕ ДЛЯ ОТЛАДЧИКА:
	// 1. Пошагово выполните swap() с F11
	// 2. Посмотрите Call Stack при рекурсии
	// 3. Сравните передачу по значению/указателю/ссылке
}

// ==================== 7. УСЛОВНЫЕ ОПЕРАТОРЫ ====================

void demoConditions() {
	cout << "\n\n=== 7. УСЛОВНЫЕ ОПЕРАТОРЫ ===" << endl;

	int a = 10, b = 20;

	// if-else
	if (a > b) {
		cout << "a > b" << endl;
	}
	else if (a < b) {
		cout << "a < b" << endl;
	}
	else {
		cout << "a == b" << endl;
	}

	// Тернарный оператор
	int max = (a > b) ? a : b;
	cout << "Максимум: " << max << endl;

	// switch-case
	int day = 3;
	switch (day) {
	case 1: cout << "Понедельник" << endl; break;
	case 2: cout << "Вторник" << endl; break;
	case 3: cout << "Среда" << endl; break;
	case 4: cout << "Четверг" << endl; break;
	case 5: cout << "Пятница" << endl; break;
	default: cout << "Выходной" << endl;
	}

	// Логические операторы
	bool condition1 = true;
	bool condition2 = false;

	if (condition1 && !condition2) {
		cout << "condition1 И НЕ condition2" << endl;
	}

	if (condition1 || condition2) {
		cout << "condition1 ИЛИ condition2" << endl;
	}
}

// ==================== 8. ЦИКЛЫ ====================

void demoLoops() {
	cout << "\n\n=== 8. ЦИКЛЫ ===" << endl;

	cout << "for loop: ";
	for (int i = 0; i < 5; i++) {
		cout << i << " ";
	}
	cout << endl;

	cout << "while loop: ";
	int j = 0;
	while (j < 5) {
		cout << j << " ";
		j++;
	}
	cout << endl;

	cout << "do-while loop: ";
	int k = 0;
	do {
		cout << k << " ";
		k++;
	} while (k < 5);
	cout << endl;

	// Вложенные циклы
	cout << "\nТаблица умножения (5x5):" << endl;
	for (int row = 1; row <= 5; row++) {
		for (int col = 1; col <= 5; col++) {
			cout << row * col << "\t";
		}
		cout << endl;
	}

	// break и continue
	cout << "\nbreak на 3: ";
	for (int i = 0; i < 10; i++) {
		if (i == 3) break;
		cout << i << " ";
	}
	cout << endl;

	cout << "continue на четных: ";
	for (int i = 0; i < 10; i++) {
		if (i % 2 == 0) continue;
		cout << i << " ";
	}
	cout << endl;

	// Бесконечный цикл (закомментирован)
	/*
	while(true) {
		// что-то делаем
		// нужен break для выхода
	}
	*/
}

// ==================== 9. ДИНАМИЧЕСКАЯ ПАМЯТЬ ====================

void demoDynamicMemory() {
	cout << "\n\n=== 9. ДИНАМИЧЕСКАЯ ПАМЯТЬ ===" << endl;

	// malloc/free (C-style)
	int* cMemory = (int*)malloc(10 * sizeof(int));
	if (cMemory != nullptr) {
		cout << "malloc выделил " << 10 * sizeof(int) << " байт по адресу: " << cMemory << endl;
		free(cMemory);
		cout << "Память освобождена free()" << endl;
	}

	// new/delete (C++ style)
	int* cppMemory = new int[10];
	cout << "new выделил память по адресу: " << cppMemory << endl;
	delete[] cppMemory;
	cout << "Память освобождена delete[]" << endl;

	// Одиночный объект
	int* single = new int(42);
	cout << "Одиночный new: " << *single << endl;
	delete single;

	// УТЕЧКА ПАМЯТИ (для демонстрации)
	int* leak = new int[100];
	cout << "Создана утечка: 100 int не будут освобождены" << endl;
	// НЕТ delete[] leak - УТЕЧКА!

	// ВИСЯЧИЙ УКАЗАТЕЛЬ (dangling pointer)
	int* dangling;
	{
		int local = 777;
		dangling = &local;
		cout << "В блоке: *dangling = " << *dangling << endl;
	}
	// dangling теперь висячий указатель!
	cout << "Вне блока: dangling указывает на несуществующую память" << endl;

	// ПРИМЕЧАНИЕ ДЛЯ ОТЛАДЧИКА:
	// 1. Сравните адреса от malloc и new
	// 2. Проверьте утечки в Diagnostic Tools
	// 3. Посмотрите что происходит при delete
}

// ==================== 10. КЛАССЫ И ОБЪЕКТЫ ====================

class Car {
private:
	char model[50];
	int year;
	double price;

public:
	// Конструктор по умолчанию
	Car() {
		strcpy(model, "Unknown");
		year = 0;
		price = 0.0;
		cout << "Car создан (конструктор по умолчанию)" << endl;
	}

	// Параметризованный конструктор
	Car(const char* m, int y, double p) {
		strcpy(model, m);
		year = y;
		price = p;
		cout << "Car создан: " << model << endl;
	}

	// Деструктор
	~Car() {
		cout << "Car уничтожен: " << model << endl;
	}

	// Методы
	void display() {
		cout << "Модель: " << model
			<< ", Год: " << year
			<< ", Цена: $" << price << endl;
	}

	void setPrice(double newPrice) {
		price = newPrice;
	}

	double getPrice() const {
		return price;
	}
};

void demoClasses() {
	cout << "\n\n=== 10. КЛАССЫ И ОБЪЕКТЫ ===" << endl;

	// Создание объектов
	Car car1;  // конструктор по умолчанию
	Car car2("Toyota", 2020, 25000.0);

	// Вызов методов
	car1.display();
	car2.display();

	// Изменение состояния
	cout << "\nМеняем цену Toyota..." << endl;
	car2.setPrice(23000.0);
	cout << "Новая цена: $" << car2.getPrice() << endl;

	// Указатель на объект
	Car* carPtr = &car2;
	cout << "\nЧерез указатель: ";
	carPtr->display();

	// Объект в куче
	Car* heapCar = new Car("BMW", 2023, 50000.0);
	heapCar->display();
	delete heapCar;  // важно!

	// ПРИМЕЧАНИЕ ДЛЯ ОТЛАДЧИКА:
	// 1. Пошагово пройдите конструкторы и деструкторы
	// 2. Посмотрите как хранятся данные объекта в памяти
	// 3. Сравните stack (car1) и heap (heapCar) объекты
}

// ==================== ГЛАВНАЯ ФУНКЦИЯ ====================

int main() {
	cout << "=== C++ ВСЕ ОСНОВЫ В ОДНОМ ПРОЕКТЕ ===" << endl;
	cout << "Используйте F11 для пошагового выполнения\n" << endl;

	// === ТОЧКИ ОСТАНОВА ДЛЯ ИССЛЕДОВАНИЯ ===
	// Поставьте точку останова ЗДЕСЬ (строка 470)
	// Затем нажимайте F11 и исследуйте каждый раздел

	// 1. Переменные и типы
	demoVariables();

	// 2. Указатели (самое важное!)
	demoPointers();

	// 3. Массивы
	demoArrays();

	// 4. Строки
	demoStrings();

	// 5. Структуры
	demoStructures();

	// 6. Функции
	demoFunctions();

	// 7. Условные операторы
	demoConditions();

	// 8. Циклы
	demoLoops();

	// 9. Динамическая память
	demoDynamicMemory();

	// 10. Классы и объекты
	demoClasses();

	// === ДОПОЛНИТЕЛЬНЫЕ ПРИМЕРЫ ===
	cout << "\n\n=== ДОПОЛНИТЕЛЬНЫЕ ПРИМЕРЫ ===" << endl;

	// Указатели и массивы вместе
	int numbers[] = { 10, 20, 30, 40, 50 };
	int* numPtr = numbers;

	cout << "\nnumbers[0] = " << numbers[0]
		<< " = *numPtr = " << *numPtr << endl;
	cout << "numbers[1] = " << numbers[1]
		<< " = *(numPtr + 1) = " << *(numPtr + 1) << endl;

	// Арифметика указателей
	cout << "\nАрифметика указателей:" << endl;
	cout << "numPtr = " << numPtr << endl;
	cout << "numPtr + 1 = " << numPtr + 1 << endl;
	cout << "Разница адресов: "
		<< (char*)(numPtr + 1) - (char*)numPtr << " байт" << endl;

	// Указатели на разные типы
	char charValue = 'Z';
	int intValue = 100;
	double doubleValue = 3.14;

	void* voidPtr;
	voidPtr = &charValue;
	cout << "\nchar через void*: " << *(char*)voidPtr << endl;

	voidPtr = &intValue;
	cout << "int через void*: " << *(int*)voidPtr << endl;

	voidPtr = &doubleValue;
	cout << "double через void*: " << *(double*)voidPtr << endl;

	// === ИГРА В ОТЛАДЧИКЕ ===
	cout << "\n\n=== ЧТО ИССЛЕДОВАТЬ В ОТЛАДЧИКЕ ===" << endl;
	cout << "1. WATCH WINDOW - добавляйте:" << endl;
	cout << "   - &variable (адрес)" << endl;
	cout << "   - *pointer (значение по указателю)" << endl;
	cout << "   - sizeof(type) (размер типа)" << endl;
	cout << "   - (char*)&var (адрес как char* для байтов)" << endl;

	cout << "\n2. MEMORY WINDOW - вводите адреса и смотрите:" << endl;
	cout << "   - Байты переменных" << endl;
	cout << "   - Как идут массивы в памяти" << endl;
	cout << "   - Структуры (поля подряд)" << endl;
	cout << "   - Строки (символы и нулевой байт)" << endl;

	cout << "\n3. CALL STACK - смотрите:" << endl;
	cout << "   - Цепочку вызовов функций" << endl;
	cout << "   - Локальные переменные в каждом фрейме" << endl;
	cout << "   - Параметры функций" << endl;

	cout << "\n4. BREAKPOINTS - ставьте на:" << endl;
	cout << "   - Изменение переменных" << endl;
	cout << "   - Выделение/освобождение памяти" << endl;
	cout << "   - Вход/выход из функций" << endl;

	// Создаём переменные для игры в отладчике
	int playVar = 777;
	int* playPtr = &playVar;
	int** playPPtr = &playPtr;

	cout << "\n\nПеременные для игры:" << endl;
	cout << "playVar = " << playVar << " &playVar = " << &playVar << endl;
	cout << "playPtr = " << playPtr << " *playPtr = " << *playPtr << endl;
	cout << "playPPtr = " << playPPtr << " **playPPtr = " << **playPPtr << endl;

	// Изменяем значения через разные уровни указателей
	**playPPtr = 888;
	cout << "После **playPPtr = 888: playVar = " << playVar << endl;

	*playPtr = 999;
	cout << "После *playPtr = 999: playVar = " << playVar << endl;

	// Массив для исследования
	int researchArray[5] = { 1, 2, 3, 4, 5 };
	cout << "\nМассив для исследования:" << endl;
	for (int i = 0; i < 5; i++) {
		cout << "researchArray[" << i << "] = " << researchArray[i]
			<< " адрес = " << &researchArray[i] << endl;
	}

	cout << "\n=== ЗАДАНИЯ ДЛЯ ОТЛАДЧИКА ===" << endl;
	cout << "1. Измените playVar через Memory Window" << endl;
	cout << "2. Найдите в памяти строку \"Hello\"" << endl;
	cout << "3. Посмотрите байты числа 3.14 (double)" << endl;
	cout << "4. Сравните адреса локальных и глобальных переменных" << endl;
	cout << "5. Найдите утечку памяти в Diagnostic Tools" << endl;

	cout << "\nНажмите Enter для завершения...";
	cin.get();  // Пауза

	return 0;
}