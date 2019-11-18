#pragma once
#include "Aeroflot.h"
#define NARR 7
#define ERROR_400 400

class ARRAY {
private:
	Aeroflot* aero;
	int j, k;
public:
	int i;
	ARRAY();
	ARRAY(int d);
	~ARRAY();
	void sort();
	int  proverka1(int k);
	int  redact(int red, int red2);
	void show();
	void search();
};