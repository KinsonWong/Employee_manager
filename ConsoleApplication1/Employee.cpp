#include "stdafx.h"
#include "Employee.h"
int Employee::eCount = 0;		
int Employee::MaxNum = 0;
Employee::Employee()					
{
	age = 0;							//û�����Ա��
	salary = 0;							
	job = "   ";
	name = "   ";
	id = 0;
	sex = "   ";
	SetDep("    ");
}
void Employee::Init()					//��ʼ��
{
	string depart;
	cout << "��������:";
	cin >> name;
	cout << "�����Ա�:";
	cin >> sex;
	while (sex != "��" && sex != "Ů")
	{
		cout << "�������!����������(�л���Ů):";
		cin >> sex;
	}
	cout << "�����������(��ʽΪ 2001-1-1):";
	char strAge[13];
	int year, month, day;
	int i;
	cin >> strAge;
	while (strAge[4] != '-' || (strAge[7] != '-'&& strAge[6]!='-'))
	{
		cout << "�������,����������:";
		AGAIN:
		cin >> strAge;
	}
	char y[5] = {0};
	for (i = 0; i < strlen(strAge); i++)
	{
		if (strAge[i] == '-')
			break;
		y[i] = (int) strAge[i];
	}
	int k = 0;
	char m[3] = {0};
	for (i++; i < strlen(strAge); i++)
	{
		if (strAge[i] == '-')
			break;
		m[k++] = (int) strAge[i];
	}
	int j = 0;
	char d[3] = {0};
	for (i++; i < strlen(strAge); i++)
	{
		if (strAge[i] == '\0')
			break;
		d[j++] = (int) strAge[i];
	}
	sscanf(y, "%d", &year);   
	sscanf(m,"%d", &month);
	sscanf(d, "%d", &day);
	if (year >2018 || year < 1900 || month>12 || day>31)
	{
		cout << "��������ڲ���ʵ��!����������:";
		goto AGAIN;
	}
	birthday.Set_date(year, month, day);
	age=2018-year;
	cout << "���벿��:";
	cin >> depart;
	while (Check(depart) == "0")
	{
		cout << "��û��" << depart << "�������,����������:";
		cin >> depart;
	}
	SetDep(depart);
	id = MaxNum + 1;					
	eCount++;								
	MaxNum++;
}
void Employee::Output()						//���Ա����Ϣ
{

}
Employee &Employee::operator = (const Employee &obj)
{
	this->id = obj.id;				        
	this->name = obj.name;					
	this->sex = obj.sex;					
	this->age = obj.age;					
	SetDep(department);						
	this->job = obj.job;					
	this->salary = obj.salary;				
	return *this;
}
int Employee::GetECount()					//��ȡԱ����Ŀ
{
	return eCount;
}
int Employee::Getid()					//��ȡ����  
{
	return id;
}
int Employee::GetAge()						//��ȡԱ������
{
	return age;
}
float Employee::GetSalary()					//��ȡԱ�����¹���
{
	return salary;
}
string Employee::GetName()					//��ȡԱ������
{
	return name;
}
string Employee::GetSex()					//��ȡԱ���Ա�
{
	return sex;
}
string Employee::GetJob()					//��ȡԱ����λ
{
	return job;
}
string Employee::GetDepartment()  const		//��ȡԱ���Ĳ���
{
	return department;
}
void Employee::SetMaxNum(int m)				//��ʼ����󹤺�
{
	MaxNum = m;
}
void Employee::SetECount(int size)			//�޸�Ա����Ŀ
{
	eCount = size;
}
void Employee::SetName(string tname)		//�޸�����
{
	name = tname;
}
void Employee::SetSex(string tsex)			//�޸��Ա�
{
	sex = tsex;
}
void Employee::SetAge(int tage)				//�޸�����
{
	age = tage;
}
void Employee::SetJob(string tjob)			//�޸ĸ�λ	
{
	job = tjob;
}
void Employee::SetSalary(float tsalary)		//�޸ĵ��¹���
{
	salary = tsalary;
}
void Employee::SetDep(string tdepart)		//�޸�Ա�������Ĳ��� 
{
	department = tdepart;
}
void Employee::InitDep(string *s, int *b, int length)	//��ʼ��������Ϣ
{
	dep.Set_Dep(s, b, length);
}
string Employee::Check(string d)						//�����Ƿ����������  
{
	return dep.Check(d);
}
void Employee::AddDep(string NewDep)					//��Ӳ���
{
	dep.Add(NewDep);
}
void Employee::DeleteDep(string OldDep)					//ɾ������
{
	dep.Delete(OldDep);
}
void Employee::ModifyDep(string OldDep, string NewDep)	//�޸Ĳ��ŵ�����
{
	dep.Modify(OldDep, NewDep);
}
void Employee::BrowseDep()						//�������
{
	dep.Scan();
}
int Employee::GetDNumber(string d)				//��ȡ������Ŀ
{
	return dep.GetDNumber(d);
}
int Employee::GetDCount()const					//��ȡ������Ŀ
{
	return dep.GetDCount();
}
string Employee::GetDep(int choice)				//��ȡ����
{
	return dep.GetDep(choice);
}