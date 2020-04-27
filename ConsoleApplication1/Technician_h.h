#pragma once
#include "system_h.h"
#include "Employee.h"
#include "department_h.h"
#include "date_h.h"
class Technician:virtual public Employee	
{
private:
	float hours;			//����ʱ��
public:
	Technician();							
	Technician(const Technician &obj);			 

	void Input();			//���뼼��Ա��Ϣ
	void Output();			//�������Ա��Ϣ
	float GetHours();		//��ȡ��ʱ
	void SetHours(float hour);//�޸Ĺ�ʱ

	Technician &operator =(const Technician &obj);		
	friend ostream & operator << (ostream &out, Technician &tec);	
	friend istream & operator >> (istream &in, Technician &tec);		
};
