#include "Aeroflot.h"
#include "Function.h"

#include <cstdlib>
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
	char ch;
	int a = 0;
	int flag1 = 0, flag2 = 0, flag3 = 0;
	int i = 0;
	setlocale(LC_ALL, "");
	int b = 0, red = 0, red2 = 0;
	int select = 0;
	//=================================
	stringstream ss;
	string str;
	string temp;

	printf("\n  Выбор Задания:\n");
	printf("1 - Задание 1 \n");

	printf("\n Любой символ - выход из программы\n");
	scanf_s("%d", &select);
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
					cin >> red;  //редактируемый елемент
					if (red >= 1 && red <= 7)
					{
						cout << " Введите номер рейса: " << endl;
						cin >> red2;  //вводим номер рейса
						if (a1->redact(red - 1, red2) == 0)
						{
							a1->sort();
							printf("УСПех\n");
						}
					}
					else
						printf(" Ошибка....Данного номера не существует\n");
				}
				catch (const exception& exc)
				{
					printf(" Одинаковые номера рейсов \n");
					cout << exc.what();
				}
			}
			else
				return 0;
		}
		delete[] a1;
	}
	system("pause");
	return 0;
}