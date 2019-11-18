#pragma once
#include <iostream>
#include <string>
using namespace std;

class Aeroflot {
public:
	Aeroflot* aero;

	Aeroflot();         //конструктор
	//Aeroflot(const string & name, int number, const string & plane);

	Aeroflot(int size1, string name, string plane);         //конструктор
	Aeroflot(const Aeroflot& value);       //конструктор копирвоания
	~Aeroflot();        //деструктор

	string get_name();  //доступ к private полям
	void set_name(const string& name);

	int get_number();
	void set_number(int number);

	string get_plane();
	void set_plane(const string& plane);

	int get_setchik();
	void set_setchik(int setchik);

	Aeroflot& operator= (Aeroflot &drob);
private:
	string name;      //название пункта назначения
	int number;      //номер рейса 
	string plane;         //тип самолета

	int setchik = 0;      //номер рейса 

	friend istream& operator >>(istream& in, Aeroflot& p);
	friend ostream& operator <<(ostream& out, const Aeroflot& p);
};