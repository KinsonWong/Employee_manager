#pragma once
#include "system_h.h"
#include "Employee.h"
#include "department_h.h"
#include "Technician_h.h"
#include "date_h.h"
#include "Saler_h.h"
#include "Manager_h.h"
#include "SalerManager_h.h"
#include "menu_h.h"
class Background
{
private:
	Saler saler;				//����Ա
	Manager manager;			//����
	SalerManager salerm;		//���۾���
	Menu menu;					//�˵�
public:
	Background();								
	~Background();								
	void Load();									
	void Save();								
	void Run();									
	void Add();									
	void Delete(int num);						
	template <class T>
	int Modify(T &type);						//�޸�Ա����Ϣ		
	void CountSalary(int flag);					//���㼼��Ա���¹���   
	void AllOutput();					//�����������Ա����Ϣ	
	void OutputByDepartment(int choice);		//���������Ա��
	void OutputByJob(int choice);				//����λ���Ա��
	int Search(string na, int num);							
	void SearchModify(int choice, string name, int num);	//����Ա����Ϣ�����
	void TotalSalaryDown();									//ȫ��Ա�������ʽ������
	void JobSalaryDown(int choice);							
	void CountUpAndDown();									//ͳ���������͹���
	void CountAverage();									//ͳ��ƽ������
	void CountByDepartment(int choice);						//������ͳ��
	void SortByNum();										//����������
	void SortBySalary();									//����������
	void DepartmentManager(int choice);						//���Ź���
	int GetDepartEmployeeNumber(int choice);
};