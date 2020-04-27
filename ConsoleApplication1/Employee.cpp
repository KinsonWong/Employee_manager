#include "stdafx.h"
#include "Employee.h"
int Employee::eCount = 0;		
int Employee::MaxNum = 0;
Employee::Employee()					
{
	age = 0;							//没有这个员工
	salary = 0;							
	job = "   ";
	name = "   ";
	id = 0;
	sex = "   ";
	SetDep("    ");
}
void Employee::Init()					//初始化
{
	string depart;
	cout << "输入姓名:";
	cin >> name;
	cout << "输入性别:";
	cin >> sex;
	while (sex != "男" && sex != "女")
	{
		cout << "输入错误!请重新输入(男或者女):";
		cin >> sex;
	}
	cout << "输入出生日期(格式为 2001-1-1):";
	char strAge[13];
	int year, month, day;
	int i;
	cin >> strAge;
	while (strAge[4] != '-' || (strAge[7] != '-'&& strAge[6]!='-'))
	{
		cout << "输入错误,请重新输入:";
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
		cout << "输入的日期不切实际!请重新输入:";
		goto AGAIN;
	}
	birthday.Set_date(year, month, day);
	age=2018-year;
	cout << "输入部门:";
	cin >> depart;
	while (Check(depart) == "0")
	{
		cout << "还没有" << depart << "这个部门,请重新输入:";
		cin >> depart;
	}
	SetDep(depart);
	id = MaxNum + 1;					
	eCount++;								
	MaxNum++;
}
void Employee::Output()						//输出员工信息
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
int Employee::GetECount()					//获取员工数目
{
	return eCount;
}
int Employee::Getid()					//获取工号  
{
	return id;
}
int Employee::GetAge()						//获取员工年龄
{
	return age;
}
float Employee::GetSalary()					//获取员工当月工资
{
	return salary;
}
string Employee::GetName()					//获取员工姓名
{
	return name;
}
string Employee::GetSex()					//获取员工性别
{
	return sex;
}
string Employee::GetJob()					//获取员工岗位
{
	return job;
}
string Employee::GetDepartment()  const		//获取员工的部门
{
	return department;
}
void Employee::SetMaxNum(int m)				//初始化最大工号
{
	MaxNum = m;
}
void Employee::SetECount(int size)			//修改员工数目
{
	eCount = size;
}
void Employee::SetName(string tname)		//修改姓名
{
	name = tname;
}
void Employee::SetSex(string tsex)			//修改性别
{
	sex = tsex;
}
void Employee::SetAge(int tage)				//修改年龄
{
	age = tage;
}
void Employee::SetJob(string tjob)			//修改岗位	
{
	job = tjob;
}
void Employee::SetSalary(float tsalary)		//修改当月工资
{
	salary = tsalary;
}
void Employee::SetDep(string tdepart)		//修改员工所属的部门 
{
	department = tdepart;
}
void Employee::InitDep(string *s, int *b, int length)	//初始化部门信息
{
	dep.Set_Dep(s, b, length);
}
string Employee::Check(string d)						//查找是否有这个部门  
{
	return dep.Check(d);
}
void Employee::AddDep(string NewDep)					//添加部门
{
	dep.Add(NewDep);
}
void Employee::DeleteDep(string OldDep)					//删除部门
{
	dep.Delete(OldDep);
}
void Employee::ModifyDep(string OldDep, string NewDep)	//修改部门的名字
{
	dep.Modify(OldDep, NewDep);
}
void Employee::BrowseDep()						//浏览部门
{
	dep.Scan();
}
int Employee::GetDNumber(string d)				//获取部门数目
{
	return dep.GetDNumber(d);
}
int Employee::GetDCount()const					//获取部门数目
{
	return dep.GetDCount();
}
string Employee::GetDep(int choice)				//获取部门
{
	return dep.GetDep(choice);
}