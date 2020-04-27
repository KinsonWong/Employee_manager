#pragma once
#include "system_h.h"
#include "date_h.h"
#include "department_h.h"
#include "Employee.h"
#include "Manager_h.h"
#include "Saler_h.h"
#include "SalerManager_h.h"
#include "Technician_h.h"

class Menu
{
public:
	Menu();				                 
	void Show();		                 //���˵�
	void ManageShow();	                 //Ա������˵�
	void SearchShow();	                 //��ѯ�˵�
	void SortShow();	                 //�������
	void CountShow();	                 //ͳ�Ʋ˵�
	void DepShow();		                 //���Ź���˵�
	void InquireShowByDepartment();		 //�������Ա����Ϣ
	void InquireShowByJob();			 //��λ���Ա����Ϣ
	void SortShowByJob();				 //����ĳ��λ��Ա�����ʴӸߵ���
	void CountShowByTotal();			 //ͳ��ȫ��Ա��Ա����Ϣ
	void CountShowByDepartment();		 //����ͳ��Ա����Ϣ
	void OneDepartment(int choice);		 //������Ϣ
};
