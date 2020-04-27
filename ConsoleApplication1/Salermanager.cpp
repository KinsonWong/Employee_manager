#include "stdafx.h"
#include "SalerManager_h.h"
SalerManager::SalerManager()			
{
	totalBalance = 0;
}
SalerManager::SalerManager(const SalerManager &obj)
{
	eCount = obj.eCount;				
	id = obj.id;				        
	name = obj.name;					
	sex = obj.sex;						
	age = obj.age;						
	SetDep(obj.GetDepartment());		
	job = obj.job;						
	salary = obj.salary;				
	totalBalance = obj.totalBalance;	
}

void SalerManager::Input()					//�������۾�����Ϣ
{
	Saler::SetJob("���۾���");
	this->Saler::Init();
}
void SalerManager::Output()					//������۾�����Ϣ
{
	cout << setw(5) << Getid() << setw(8) << GetName() << setw(6) << Saler::GetSex() << setw(7) << GetAge() << setw(11) << GetDepartment() << setw(10) << Saler::GetJob() << "    ---" << setw(10) << GetTotal() << setw(12) << GetSalary() << endl;
}
float SalerManager::GetSalary()
{
	return Saler::GetSalary();
}
float SalerManager::GetTotal()				//��ȡ�ò��ŵ������ܶ��
{
	return totalBalance;
}
int SalerManager::Getid()				//��ȡ���� 
{
	return Saler::Getid();
}
int SalerManager::GetAge()					//��ȡ����
{
	return Saler::GetAge();
}
string SalerManager::GetName()				//��ȡ����
{
	return Saler::GetName();
}
string SalerManager::GetDepartment() const				//��ȡԱ���Ĳ���
{
	return Saler::GetDepartment();
}

void SalerManager::SetTotal(float ttotalBalance)		//�޸ĸò��ŵ������ܶ��
{
	totalBalance = ttotalBalance;
}

void SalerManager::SetName(string tname)				//�޸�����
{
	Saler::SetName(tname);
}
void SalerManager::SetSex(string tsex)					//�޸��Ա�
{
	Saler::SetSex(tsex);
}
void SalerManager::SetAge(int tage)						//�޸�����
{
	Saler::SetAge(tage);
}
void SalerManager::SetJob(string tjob)					//�޸ĸ�λ	
{
	Saler::SetJob(tjob);
}
void SalerManager::SetSalary(float tsalary)				//�޸ĵ��¹���
{
	Saler::SetSalary(tsalary);
}
void SalerManager::SetDep(string tdepart)				//�޸�Ա�������Ĳ��� 
{
	Saler::SetDep(tdepart);
}

SalerManager &SalerManager::operator = (const SalerManager &obj)		
{
	Manager::operator = (obj);
	totalBalance = obj.totalBalance;
	return *this;
}
ostream & operator << (ostream &out, SalerManager &sm)	   
{
	out << sm.Getid() << ' ' << sm.GetName() << ' ' << sm.GetSex() << ' ' << sm.GetAge() << ' ' << sm.department << ' ' << sm.GetJob() << ' ' << sm.GetTotal() << ' ' << sm.GetSalary() << endl;
	return out;
}
istream & operator >> (istream &in, SalerManager &sm)	    
{
	in >> sm.id >> sm.name >> sm.sex >> sm.age >> sm.department
		>> sm.job >> sm.totalBalance >> sm.salary;
	return in;
}
