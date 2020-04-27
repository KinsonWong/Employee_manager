#pragma once
#include "system_h.h"
#include "Employee.h"
#include "department_h.h"
#include "date_h.h"
class Technician:virtual public Employee	
{
private:
	float hours;			//工作时间
public:
	Technician();							
	Technician(const Technician &obj);			 

	void Input();			//输入技术员信息
	void Output();			//输出技术员信息
	float GetHours();		//获取工时
	void SetHours(float hour);//修改工时

	Technician &operator =(const Technician &obj);		
	friend ostream & operator << (ostream &out, Technician &tec);	
	friend istream & operator >> (istream &in, Technician &tec);		
};
