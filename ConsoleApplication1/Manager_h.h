#pragma once
#include "system_h.h"
#include "Employee.h"
#include "department_h.h"
#include "date_h.h"
class Manager :virtual public Employee
{

public:
	Manager();			
	Manager(const Manager &obj);	

	void Input();		
	void Output();		

	Manager &operator =(const Manager &obj);		
	friend ostream & operator << (ostream &out, Manager &m);	    
	friend   istream & operator >> (istream &in, Manager &m);
};
