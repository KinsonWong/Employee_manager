#pragma once
#include "system_h.h"
#include "Employee.h"
#include "department_h.h"
#include "date_h.h"
#include "Saler_h.h"
#include "Manager_h.h"
class SalerManager :public Saler, public Manager	
{
	float totalBalance;	
public:
	SalerManager();		
	SalerManager(const SalerManager &obj);	

	void Input();		//�������۾�����Ϣ
	void Output();		//������۾�����Ϣ
	int Getid();
	int GetAge();
	float GetTotal();						//��ȡ�ò��ŵ������ܶ��
	float GetSalary();
	string GetName();
	string GetDepartment() const;			//��ȡԱ���Ĳ���
	void SetName(string tname);				//�޸�����
	void SetSex(string tsex);				//�޸��Ա�
	void SetAge(int tage);					//�޸�����
	void SetJob(string tjob);				//�޸ĸ�λ	
	void SetSalary(float tsalary);			//�޸ĵ��¹���
	void SetDep(string tdepart);			//�޸�Ա�������Ĳ��� 
	void SetTotal(float ttotalBalance);		//�޸ĸò��ŵ������ܶ��


	SalerManager &operator =(const SalerManager &obj);					
	friend ostream & operator << (ostream &out, SalerManager &sm);	    
	friend istream & operator >> (istream &in, SalerManager &sm);	    
};
