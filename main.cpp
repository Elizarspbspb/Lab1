#include "Aeroflot.h"
#include "Function.h"
#include <string>
#include <iostream>
#include <fstream>
#include <sstream>
using namespace std;

#define size 7
#define ERROR_400 400

int main()
{
	int size1 = 0;
	int a = 0;
	int flag1 = 0, flag2 = 0, flag3 = 0;
	int i = 0;
	setlocale(LC_ALL, "");
	int b = 0, red = 0, red2 = 0;
	int select = 0;

	stringstream ss;
	string str;
	string temp;

	cout << "Задание 1" << endl;
	cout << "Любой символ - выход из программы" << endl;
	cin >> select;
	if (select == 1)
	{
		cout << "Создание 7 объектов" << endl;

		ARRAY* a1 = new ARRAY();
		a1->sort();
		for (;;)  // цикл бесконечности
		{
			cout << "\n1. Показать\n2. Найти\n3. Редактировать записи\n4. Выход\n";
			cin >> a;
			if (a == 1)
			{
				a1->show();
			}
			else if (a == 2)
			{
				try
				{
					a1->search();
				}
				catch (int error)
				{
					switch (error)
					{
					case ERROR_400:
						cout << endl << "\n Рейсы не найдены." << endl;
						break;
					default:
						cout << endl << "\n Неизвестная ошибка." << endl;
					}
				}
			}
			else if (a == 3)
			{
				try
				{
					cout << " Введите номер редактируемой записи: " << endl;
					cin >> red;  //редактируемый элемент
					if (red >= 1 && red <= 7)
					{
						cout << " Введите номер рейса: " << endl;
						cin >> red2;  //вводим номер рейса
						if (a1->redact(red - 1, red2) == 0)
						{
							a1->sort();
							cout << " Успех " << endl;
						}
					}
					else
						cout << " Ошибка...Данного номера не существует " << endl;
				}
				catch (const exception& exc)
				{
					cout << " Такой номер рейса уже существует " << endl;
					cout << exc.what();
				}
			}
			else
				return 0;
		}
		delete[] a1;
	}
	else
		cout << "Выход из программы" << endl;
	system("pause");
	return 0;
}