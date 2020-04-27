#include "stdafx.h"
#include "department_h.h"
int Department::dCount = 6;	
string Dep[6] = { "财务部", "人力资源部", "市场营销部", "研发部", "信息部", "服务部" };
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

void Department::Set_Dep(string *s, int *b, int length)	//加载文件后初始化部门信息
{
	str = new string[length];
	dnumber = new int[length];
	for (int i = 0; i < length; i++)
	{
		str[i] = s[i];
		dnumber[i] = b[i];
	}
}

string Department::Check(string d)			//查找是否有这个部门 
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
	cout << "添加部门成功。\n";
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
				cout << "删除" << OldDep << "部门成功!\n";
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
		cout << "还没有该部门!\n";
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
				cout << "修改部门成功!\n";
				break;
			}
		}
	}
	else
		cout << "还没有该部门!\n";
}

void Department::Scan()						
{
	cout << endl;
	for (int i = 0; i < dCount; i++)
	{
		cout << "       选项:(" << i + 1 << ")    编号:" << dnumber[i] <<"   "<< str[i] <<endl;
	}
}

int  Department::GetDNumber(string d)		//获取部门编号 
{
	for (int i = 0; i < dCount; i++)
	{
		if (str[i] == d)
			return i;
	}
	return -1;
}

int Department::GetDCount()					//获取部门数目
{
	return dCount;
}

string Department::GetDep(int choice)		//获取所需部门
{
	if (choice < 0 || choice >= dCount)
		return "0";
	return str[choice];
}