#include "stdafx.h"
#include "Technician_h.h"
Technician::Technician()						
{
	hours = 0;
	job = "技术员";
}
Technician::Technician(const Technician &obj)	
{
	hours = obj.hours;				
	eCount = obj.eCount;			
	id = obj.id;			        
	name = obj.name;			    
	sex = obj.sex;					
	age = obj.age;					
	SetDep(obj.GetDepartment());	
	job = obj.job;					
	salary = obj.salary;			
}

void Technician::Input()			//输入技术员信息
{
	this->Init();
}
void Technician::Output()			//输出技术员信息
{ 
	cout << setw(5) << id << setw(8) << name << setw(6) << sex << setw(7) << age << setw(11) << GetDepartment() << setw(10) << job << setw(6) << hours << "       ----" << setw(12) << salary << endl;
}

float Technician::GetHours()		//获取工时
{
	return hours;
}
void Technician::SetHours(float hour)	//修改工时
{
	this->hours = hour;
}

Technician &Technician::operator = (const Technician &obj)	
{
	Employee::operator = (obj);								
	this->hours = obj.hours;
	return *this;
}
ostream & operator << (ostream &out, Technician &tec)	   
{
	out << tec.id << ' ' << tec.name << ' ' << tec.sex << ' ' << tec.age << ' ' << tec.GetDepartment()
		<< ' ' << tec.job << ' ' << tec.hours << ' ' << tec.salary << endl;
	return out;
}
istream & operator >> (istream &in, Technician &tec)	    
{
	in >> tec.id >> tec.name >> tec.sex >> tec.age >> tec.department
		>> tec.job >> tec.hours >> tec.salary;
	return in;
}
