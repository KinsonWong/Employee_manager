#include "stdafx.h"
#include "department_h.h"
int Department::dCount = 6;	
string Dep[6] = { "����", "������Դ��", "�г�Ӫ����", "�з���", "��Ϣ��", "����" };
Department::Department()					
{
	str = new string[Department::dCount];
	for (int i = 0; i < dCount; i++)		
		str[i] = Dep[i];

	dnumber = new int[Department::dCount];
	for (int i = 0; i < dCount; i++)		
		dnumber[i] = i + 1;
}
Department::~Department()					
{
	if (str)
		delete[]str;
	str = NULL;

	if (dnumber)
		delete[]dnumber;
	dnumber = NULL;
}

void Department::Set_Dep(string *s, int *b, int length)	//�����ļ����ʼ��������Ϣ
{
	str = new string[length];
	dnumber = new int[length];
	for (int i = 0; i < length; i++)
	{
		str[i] = s[i];
		dnumber[i] = b[i];
	}
}

string Department::Check(string d)			//�����Ƿ���������� 
{
	for (int i = 0; i < dCount; i++)
	{
		if (d == str[i])
			return d;
	}
	return "0";
}

void Department::Add(string NewDep)			
{
	if (Check(NewDep) != "0")				
		return;

	string *temp = new string[Department::dCount];
	int *itemp = new int[Department::dCount];
	for (int i = 0; i < dCount; i++)		
		temp[i] = str[i];
	for (int i = 0; i < dCount; i++)		
		itemp[i] = dnumber[i];
	if (str)
		delete[]str;
	if (dnumber)
		delete[]dnumber;

	int i;
	str = new string[Department::dCount + 1];
	dnumber = new int[Department::dCount + 1];
	for (i = 0; i < dCount; i++)		
		str[i] = temp[i];
	for (i = 0; i < dCount; i++)		
		dnumber[i] = itemp[i];

	dnumber[dCount] = dnumber[i - 1] + 1;
	str[dCount] = NewDep;					
	dCount++;
	cout << "��Ӳ��ųɹ���\n";
	delete[]temp;
}

void Department::Delete(string OldDep)		
{
	if (dCount != 0 && Check(OldDep) != "0")
	{
		for (int i = 0; i < dCount; i++)
		{
			if (str[i] == OldDep)						
			{
				cout << "ɾ��" << OldDep << "���ųɹ�!\n";
				for (int j = i; j < dCount - 1; j++)
				{
					str[j] = str[j + 1];				
					dnumber[j] = dnumber[j + 1];
				}
				break;
			}
		}
		dCount--;
	}
	else
		cout << "��û�иò���!\n";
}

void Department::Modify(string OldDep, string NewDep)	
{
	if (dCount != 0 && Check(OldDep) != "0")
	{
		for (int i = 0; i < dCount; i++)
		{
			if (str[i] == OldDep)						
			{
				str[i] = NewDep;
				cout << "�޸Ĳ��ųɹ�!\n";
				break;
			}
		}
	}
	else
		cout << "��û�иò���!\n";
}

void Department::Scan()						
{
	cout << endl;
	for (int i = 0; i < dCount; i++)
	{
		cout << "       ѡ��:(" << i + 1 << ")    ���:" << dnumber[i] <<"   "<< str[i] <<endl;
	}
}

int  Department::GetDNumber(string d)		//��ȡ���ű�� 
{
	for (int i = 0; i < dCount; i++)
	{
		if (str[i] == d)
			return i;
	}
	return -1;
}

int Department::GetDCount()					//��ȡ������Ŀ
{
	return dCount;
}

string Department::GetDep(int choice)		//��ȡ���貿��
{
	if (choice < 0 || choice >= dCount)
		return "0";
	return str[choice];
}