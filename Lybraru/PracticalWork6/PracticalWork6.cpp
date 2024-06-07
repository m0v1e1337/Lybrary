// PracticalWork6.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

#include <iostream>
#include "../StaticLib/Header.h"
#include <wtypes.h>
#include <string>

using namespace std;


int main()
{
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);

	HINSTANCE dynamicLib;
	dynamicLib = LoadLibrary(L"DynamicLib.dll");

	typedef bool (*CharSearchFunc)(const char*, const char*);
	CharSearchFunc searchFunc = reinterpret_cast<CharSearchFunc>(GetProcAddress(dynamicLib, "SearchCharacters"));

	cout << "Введите строку: ";
	string input;
	getline(cin, input);

	cout << "Введите, что в ней искать: ";
	string characters;
	getline(cin, characters);

	cout << "Содержит ли строка \"" << input << "\" символы \"" << characters << "\" ?" << endl;

	bool result = searchFunc(input.c_str(), characters.c_str()); // Использование динамической библиотеки

	fnStaticLib(result); // Использование статической библиотеки

	FreeLibrary(dynamicLib);
	
	return 0;
}

// Запуск программы: CTRL+F5 или меню "Отладка" > "Запуск без отладки"
// Отладка программы: F5 или меню "Отладка" > "Запустить отладку"

// Советы по началу работы 
//   1. В окне обозревателя решений можно добавлять файлы и управлять ими.
//   2. В окне Team Explorer можно подключиться к системе управления версиями.
//   3. В окне "Выходные данные" можно просматривать выходные данные сборки и другие сообщения.
//   4. В окне "Список ошибок" можно просматривать ошибки.
//   5. Последовательно выберите пункты меню "Проект" > "Добавить новый элемент", чтобы создать файлы кода, или "Проект" > "Добавить существующий элемент", чтобы добавить в проект существующие файлы кода.
//   6. Чтобы снова открыть этот проект позже, выберите пункты меню "Файл" > "Открыть" > "Проект" и выберите SLN-файл.
