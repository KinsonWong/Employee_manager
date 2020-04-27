#include "stdafx.h"
#include "date_h.h"
void Date::Set_date(int y,int m,int d)
{
	year = y;
	month = m;
	day = d;
}
int Date::GetYear()
{
	return year;
}
int Date::GetMonth()
{
	return month;
}
int Date::GetDay()
{
	return day;
}
int Date::GetAge()
{
	age = 2018 - year;
	return age;
}