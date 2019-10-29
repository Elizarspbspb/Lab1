#include "Aeroflot.h"
#include <cstdlib>
#include <string>
#include <iostream>
using namespace std;
#define size 7

Aeroflot::Aeroflot()     //конструктор
{
	cin >> *this; //  для создания объектов массива
	cout << "\tРейс создан." << endl << endl;
	cout << "\nКонструктор\n";
}

Aeroflot::Aeroflot(int size1)
{
	cout << "\nКонструктор с параметром\n";
}

Aeroflot::Aeroflot(const Aeroflot& value)       //конструктор копирвоания 
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

Aeroflot::~Aeroflot()         //деструктор 
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

Aeroflot & Aeroflot::operator=(Aeroflot & drob)
{
	name = drob.name;
	plane = drob.plane;
	number = drob.number;
	return *this;
}

int Aeroflot::get_number()
{
	return number;
}
void Aeroflot::set_number(int number)
{
	this->number = number;
}

int Aeroflot::get_setchik()
{
	return setchik;
}
void Aeroflot::set_setchik(int setchik)
{
	this->setchik = setchik;
}

bool operator!=(istream & in, char)
{
	return false;
}

istream& operator >>(istream& in, Aeroflot& p)   //Ввод рейсов
{
	cout << "Введите название пункта назначения рейса\n";
	cin.ignore();
	getline(in, p.name);

	cout << "Введите тип самолета\n";
	in >> p.plane;

	cout << "Введите номер рейса\n";
	in >> p.number;

	return in;
}


ostream& operator <<(ostream& out, const Aeroflot& p)
{
	out << p.number << " |  " << p.name << " | " << p.plane;
	return out;
}