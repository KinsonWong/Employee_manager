#include "stdafx.h"
#include "Manager_h.h"
Manager::Manager()			
{
	salary = 8000;
	job = "¾­Àí";
}
Manager::Manager(const Manager &obj)	
{
	eCount = obj.eCount;				
	id = obj.id;				
	name = obj.name;					
	sex = obj.sex;						
	age = obj.age;						
	SetDep(obj.GetDepartment());		
	job = obj.job;						
	salary = obj.salary;				
}

void Manager::Input()
{
	this->Init();			
}
void Manager::Output()
{
	cout << setw(5) << id << setw(8) << name << setw(6) << sex << setw(7) << age << setw(11) << department << setw(10) << job << "    ---" << "      ----" << setw(12) << salary << endl;
}

Manager &Manager::operator = (const Manager &obj)		
{
	Employee::operator = (obj);
	return *this;
}
ostream & operator << (ostream &out, Manager &m)	    
{
	out << m.id << ' ' << m.name << ' ' << m.sex << ' ' << m.age << ' ' << m.department << ' ' << m.job << ' ' << m.salary << endl;
	return out;
}
istream & operator >> (istream &in, Manager &m)	    
{
	in >> m.id >> m.name >> m.sex >> m.age >> m.department
		>> m.job >> m.salary;
	return in;
}