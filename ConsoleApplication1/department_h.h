#pragma once
#include "system_h.h"
class Department
{
protected:
	static int dCount;		               //部门数目
	string *str;			               //储存所有部门
	int *dnumber;			               //部门编号 
public:
	Department();					
	~Department();					
	void Set_Dep(string *s, int *b, int length);	//加载文件后初始化部门信息
	string Check(string d);			                //查找是否有这个部门  
	void Add(string NewDep);		                
	void Delete(string OldDep);		                
	void Modify(string OldDep, string NewDep);	    
	void Scan();					                
	int GetDNumber(string d);		                //获取部门编号
	static int GetDCount();			                
	string GetDep(int sel);		                    //获取所需部门
};
