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
	Saler saler;				//销售员
	Manager manager;			//经理
	SalerManager salerm;		//销售经理
	Menu menu;					//菜单
public:
	Background();								
	~Background();								
	void Load();									
	void Save();								
	void Run();									
	void Add();									
	void Delete(int num);						
	template <class T>
	int Modify(T &type);						//修改员工信息		
	void CountSalary(int flag);					//计算技术员当月工资   
	void AllOutput();					//工号升序输出员工信息	
	void OutputByDepartment(int choice);		//按部门输出员工
	void OutputByJob(int choice);				//按岗位输出员工
	int Search(string na, int num);							
	void SearchModify(int choice, string name, int num);	//查找员工信息并输出
	void TotalSalaryDown();									//全体员工按工资降序输出
	void JobSalaryDown(int choice);							
	void CountUpAndDown();									//统计最高与最低工资
	void CountAverage();									//统计平均工资
	void CountByDepartment(int choice);						//按部门统计
	void SortByNum();										//按工号排序
	void SortBySalary();									//按工资排序
	void DepartmentManager(int choice);						//部门管理
	int GetDepartEmployeeNumber(int choice);
};