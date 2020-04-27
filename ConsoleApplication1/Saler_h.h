#pragma once
#include "system_h.h"
#include "Employee.h"
#include "department_h.h"
#include "date_h.h"
class Saler :virtual public Employee
{
private:
	float balance;		//销售额度
public:
	Saler();			
	Saler(const Saler &obj);	
	void Input();		//输入销售员信息
	void Output();		//输出销售员信息
	float GetBalance();	//获取员工销售额度
	void SetBalance(float tbalance);	//修改员工销售额度
	Saler &operator =(const Saler &obj);		
	friend ostream & operator << (ostream &out, Saler &s);	   
	friend istream & operator >> (istream &in, Saler &s);	    
};
