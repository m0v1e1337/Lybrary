// StaticLib.cpp : Определяет функции для статической библиотеки.
//

#include "pch.h"
#include <iostream>
#include "framework.h"

using namespace std;

// TODO: Это пример библиотечной функции.
void fnStaticLib(const bool& result)
{
	if (result)
	{
		cout << "Да!" << std::endl;
	}
	else
	{
		cout << "Нет!" << std::endl;
	}
}
