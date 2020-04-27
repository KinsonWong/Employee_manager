#pragma once
#include "system_h.h"
class Date
{
protected:
	int age;
	int year;
	int month;
	int day;
public:  
	void Set_date(int y, int m, int d);
	int GetYear();
	int GetMonth();
	int GetDay();
	int GetAge();
};
