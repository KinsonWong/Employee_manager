#pragma once
#include "system_h.h"
#include "Employee.h"
#include "department_h.h"
#include "date_h.h"
#include "Saler_h.h"
#include "Manager_h.h"
class SalerManager :public Saler, public Manager	
{
	float totalBalance;	
public:
	SalerManager();		
	SalerManager(const SalerManager &obj);	

	void Input();		//输入销售经理信息
	void Output();		//输出销售经理信息
	int Getid();
	int GetAge();
	float GetTotal();						//获取该部门的销售总额度
	float GetSalary();
	string GetName();
	string GetDepartment() const;			//获取员工的部门
	void SetName(string tname);				//修改姓名
	void SetSex(string tsex);				//修改性别
	void SetAge(int tage);					//修改年龄
	void SetJob(string tjob);				//修改岗位	
	void SetSalary(float tsalary);			//修改当月工资
	void SetDep(string tdepart);			//修改员工所属的部门 
	void SetTotal(float ttotalBalance);		//修改该部门的销售总额度


	SalerManager &operator =(const SalerManager &obj);					
	friend ostream & operator << (ostream &out, SalerManager &sm);	    
	friend istream & operator >> (istream &in, SalerManager &sm);	    
};
