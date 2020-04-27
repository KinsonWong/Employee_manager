#pragma once
#include "system_h.h"
#include "date_h.h"
#include "department_h.h"
class Employee
{
protected:
	static int eCount;				//员工数目
	static int MaxNum;				//最大工号
	int id;                         //工号
	int age;						//年龄
	float salary;					//工资
	string name;					//姓名
	string sex;						//性别
	string department;				//员工所属部门
	Department dep;					//部门 
	string job;						//岗位	
	Date birthday;				    //生日
public:
	Employee();						
	void Init();					
	virtual void Output();			//输出员工信息	
	Employee &operator =(const Employee &obj);	
	static int GetECount();				//获取员工数目
	int Getid();					    //获取工号     
	int GetAge();						//获取员工年龄
	float GetSalary();					//获取员工当月工资
	string GetName();					//获取员工姓名
	string GetSex();					//获取员工性别
	string GetJob();					//获取员工岗位
	string GetDepartment() const;		//获取员工的部门
	void SetMaxNum(int m);				//初始化最大工号
	void SetECount(int size);			//修改员工数目
	void SetName(string tname);			//修改姓名
	void SetSex(string tsex);			//修改性别
	void SetAge(int tage);				//修改年龄
	void SetJob(string tjob);			//修改岗位	
	void SetSalary(float tsalary);		//修改当月工资
	void SetDep(string tdepart);		//修改员工所属的部门 
	void InitDep(string *s, int *b, int length);		//初始化部门
	string Check(string d);								//查找是否有这个部门  
	void AddDep(string NewDep);							//添加部门
	void DeleteDep(string OldDep);						//删除部门
	void ModifyDep(string OldDep, string NewDep);		//修改部门的名字
	void BrowseDep();									//浏览部门
	int GetDNumber(string d);							//获取部门编号
	int GetDCount() const;								//获取部门数目
	string GetDep(int choice);							//获取部门
};
