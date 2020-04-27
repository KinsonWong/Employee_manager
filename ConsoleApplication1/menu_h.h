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
	void Show();		                 //主菜单
	void ManageShow();	                 //员工管理菜单
	void SearchShow();	                 //查询菜单
	void SortShow();	                 //排序管理
	void CountShow();	                 //统计菜单
	void DepShow();		                 //部门管理菜单
	void InquireShowByDepartment();		 //部门输出员工信息
	void InquireShowByJob();			 //岗位输出员工信息
	void SortShowByJob();				 //排序某岗位的员工工资从高到低
	void CountShowByTotal();			 //统计全体员工员工信息
	void CountShowByDepartment();		 //部门统计员工信息
	void OneDepartment(int choice);		 //部门信息
};
