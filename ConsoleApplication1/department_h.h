#pragma once
#include "system_h.h"
class Department
{
protected:
	static int dCount;		               //������Ŀ
	string *str;			               //�������в���
	int *dnumber;			               //���ű�� 
public:
	Department();					
	~Department();					
	void Set_Dep(string *s, int *b, int length);	//�����ļ����ʼ��������Ϣ
	string Check(string d);			                //�����Ƿ����������  
	void Add(string NewDep);		                
	void Delete(string OldDep);		                
	void Modify(string OldDep, string NewDep);	    
	void Scan();					                
	int GetDNumber(string d);		                //��ȡ���ű��
	static int GetDCount();			                
	string GetDep(int sel);		                    //��ȡ���貿��
};
