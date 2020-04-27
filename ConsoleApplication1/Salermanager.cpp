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

void SalerManager::Input()					//输入销售经理信息
{
	Saler::SetJob("销售经理");
	this->Saler::Init();
}
void SalerManager::Output()					//输出销售经理信息
{
	cout << setw(5) << Getid() << setw(8) << GetName() << setw(6) << Saler::GetSex() << setw(7) << GetAge() << setw(11) << GetDepartment() << setw(10) << Saler::GetJob() << "    ---" << setw(10) << GetTotal() << setw(12) << GetSalary() << endl;
}
float SalerManager::GetSalary()
{
	return Saler::GetSalary();
}
float SalerManager::GetTotal()				//获取该部门的销售总额度
{
	return totalBalance;
}
int SalerManager::Getid()				//获取工号 
{
	return Saler::Getid();
}
int SalerManager::GetAge()					//获取年龄
{
	return Saler::GetAge();
}
string SalerManager::GetName()				//获取姓名
{
	return Saler::GetName();
}
string SalerManager::GetDepartment() const				//获取员工的部门
{
	return Saler::GetDepartment();
}

void SalerManager::SetTotal(float ttotalBalance)		//修改该部门的销售总额度
{
	totalBalance = ttotalBalance;
}

void SalerManager::SetName(string tname)				//修改姓名
{
	Saler::SetName(tname);
}
void SalerManager::SetSex(string tsex)					//修改性别
{
	Saler::SetSex(tsex);
}
void SalerManager::SetAge(int tage)						//修改年龄
{
	Saler::SetAge(tage);
}
void SalerManager::SetJob(string tjob)					//修改岗位	
{
	Saler::SetJob(tjob);
}
void SalerManager::SetSalary(float tsalary)				//修改当月工资
{
	Saler::SetSalary(tsalary);
}
void SalerManager::SetDep(string tdepart)				//修改员工所属的部门 
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
