#include "Aeroflot.h"
#include <string>
#include <iostream>
using namespace std;
#define size 7

Aeroflot::Aeroflot()  //конструктор
{
	cin >> *this; //для создания объектов массива
	cout << "\tРейс создан." << endl << endl;
	cout << "\nКонструктор\n";
}

Aeroflot::Aeroflot(int size1, string name, string plane)
{
	set_number(size1);
	set_name(name);
	set_plane(plane);
	cout << "\nКонструктор с параметром\n";
}

Aeroflot::Aeroflot(const Aeroflot& value) //конструктор копирвоания 
{
	int j = 0, k = 0, n1 = 0, n2 = 0, n3 = 0;
	string n4;
	string n5;

	for (j = 0; j < (size - 1); ++j)
	{
		for (k = j + 1; k < size; ++k)
		{
			n3 = aero[j].get_number();
			aero[j].set_number(aero[k].get_number());
			aero[k].set_number(n3);

			n4 = aero[j].get_name();
			aero[j].set_name(aero[k].get_name());
			aero[k].set_name(n4);

			n5 = aero[j].get_plane();
			aero[j].set_plane(aero[k].get_plane());
			aero[k].set_plane(n5);
		}
	}
	cout << "\nКоснтрукторк копирвоания\n";
}

Aeroflot::~Aeroflot() //деструктор 
{
	delete aero;
	cout << "\nДеструктор\n";
}

string Aeroflot::get_name()
{
	return name;
}
void Aeroflot::set_name(const string& name)
{
	this->name = name;
}

string Aeroflot::get_plane()
{
	return plane;
}
void Aeroflot::set_plane(const string& plane)
{
	this->plane = plane;
}

int Aeroflot::get_number()
{
	return number;
}
void Aeroflot::set_number(int number)
{
	this->number = number;
}

istream& operator >>(istream& in, Aeroflot& p)//Ввод рейсов
{
	int flag = 0;
	int flag2 = 0;
	string ch;
	cout << "Введите название пункта назначения рейса\n";
	string str;
	while ((flag != 1) || (flag2 == 0))
	{
		flag2 = 1;
		in >> str;
		for (auto c : str)
		{
			if (c == '1' || c == '2' || c == '3' || c == '4' || c == '5' || c == '6' || c == '7' || c == '8' || c == '9' || c == '0')
			{
				cout << "Ошибка, должны быть только буквы!" << endl;
				flag = 0;
				flag2 = 0;
			}
			else
			{
				flag = 1;
			}
		}
	}
	p.name = str;

	cout << "Введите тип самолета\n";
	in >> p.plane;

	cout << "Введите номер рейса\n";
	while (!(in >> p.number) || (cin.peek() != '\n')) // cin.peek() извлекает символ для просмотра 
	{
		cin.clear(); // cin.clear() восстанавливает поток, если что-то пошло не так. 
		while (cin.get() != '\n'); // cin.get() получает символ из потока данных и возвращает Int в виде кода символа.
		cout << "Ошибка, должны быть только цифры!" << endl; 
	}
	return in;
}

ostream& operator <<(ostream& out, const Aeroflot& p)
{
	out << p.number << " |  " << p.name << " | " << p.plane;
	return out;
}