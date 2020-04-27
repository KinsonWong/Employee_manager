#pragma once
#include "system_h.h"
#include "Employee.h"
#include "department_h.h"
#include "date_h.h"
class Saler :virtual public Employee
{
private:
	float balance;		//���۶��
public:
	Saler();			
	Saler(const Saler &obj);	
	void Input();		//��������Ա��Ϣ
	void Output();		//�������Ա��Ϣ
	float GetBalance();	//��ȡԱ�����۶��
	void SetBalance(float tbalance);	//�޸�Ա�����۶��
	Saler &operator =(const Saler &obj);		
	friend ostream & operator << (ostream &out, Saler &s);	   
	friend istream & operator >> (istream &in, Saler &s);	    
};
