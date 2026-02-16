#include <iostream>
#include <cstdlib>


using namespace std;


bool isCompatible(int version) {
	if (version == 10) {
		return true;
	}
	return false;
}

int main(int argc, char* argv[]) {

	if (argc < 2) {
		cout << "Ошибка: Требуется указать версию!" << endl;
		cout << "Пример использования: " << argv[0] << " <версия>" << endl;
		return 1;
	}


	int targetVersion = atoi(argv[1]);


	cout << isCompatible(targetVersion) << endl;

	return 0;
}
