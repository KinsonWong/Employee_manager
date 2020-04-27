#pragma once
#include "system_h.h"
#include "date_h.h"
#include "department_h.h"
class Employee
{
protected:
	static int eCount;				//Ա����Ŀ
	static int MaxNum;				//��󹤺�
	int id;                         //����
	int age;						//����
	float salary;					//����
	string name;					//����
	string sex;						//�Ա�
	string department;				//Ա����������
	Department dep;					//���� 
	string job;						//��λ	
	Date birthday;				    //����
public:
	Employee();						
	void Init();					
	virtual void Output();			//���Ա����Ϣ	
	Employee &operator =(const Employee &obj);	
	static int GetECount();				//��ȡԱ����Ŀ
	int Getid();					    //��ȡ����     
	int GetAge();						//��ȡԱ������
	float GetSalary();					//��ȡԱ�����¹���
	string GetName();					//��ȡԱ������
	string GetSex();					//��ȡԱ���Ա�
	string GetJob();					//��ȡԱ����λ
	string GetDepartment() const;		//��ȡԱ���Ĳ���
	void SetMaxNum(int m);				//��ʼ����󹤺�
	void SetECount(int size);			//�޸�Ա����Ŀ
	void SetName(string tname);			//�޸�����
	void SetSex(string tsex);			//�޸��Ա�
	void SetAge(int tage);				//�޸�����
	void SetJob(string tjob);			//�޸ĸ�λ	
	void SetSalary(float tsalary);		//�޸ĵ��¹���
	void SetDep(string tdepart);		//�޸�Ա�������Ĳ��� 
	void InitDep(string *s, int *b, int length);		//��ʼ������
	string Check(string d);								//�����Ƿ����������  
	void AddDep(string NewDep);							//��Ӳ���
	void DeleteDep(string OldDep);						//ɾ������
	void ModifyDep(string OldDep, string NewDep);		//�޸Ĳ��ŵ�����
	void BrowseDep();									//�������
	int GetDNumber(string d);							//��ȡ���ű��
	int GetDCount() const;								//��ȡ������Ŀ
	string GetDep(int choice);							//��ȡ����
};
