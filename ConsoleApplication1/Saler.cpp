#include "stdafx.h"
#include "Saler_h.h"
Saler::Saler()				
{
	job = "ÏúÊÛÔ±";
	balance = 0;
}
Saler::Saler(const Saler &obj)
{
	balance = obj.balance;			
	eCount = obj.eCount;			
	id = obj.id;			        
	name = obj.name;				
	sex = obj.sex;					
	age = obj.age;					
	SetDep(obj.GetDepartment());	
	job = obj.job;					
	salary = obj.salary;			
}

void Saler::Input()			
{
	this->Init();
}
void Saler::Output()		
{
	cout << setw(5) << id << setw(8) << name << setw(6) << sex << setw(7) << age << setw(11) << GetDepartment() << setw(10) << job << "    ---" << setw(10) << balance << setw(12) << salary << endl;
}

float Saler::GetBalance()	
{
	return balance;
}
void Saler::SetBalance(float tbalance)	
{
	balance = tbalance;
}

Saler &Saler::operator =(const Saler &obj)		
{
	Employee::operator = (obj);
	this->balance = obj.balance;
	return *this;
}
ostream & operator << (ostream &out, Saler &s)	    
{
	out << s.id << ' ' << s.name << ' ' << s.sex << ' ' << s.age << ' ' << s.department << ' ' << s.job << ' ' << s.balance << ' ' << s.salary << endl;
	return out;
}
istream & operator >> (istream &in, Saler &s)	    
{
	in >> s.id >> s.name >> s.sex >> s.age >> s.department
		>> s.job >> s.balance >> s.salary;
	return in;
}