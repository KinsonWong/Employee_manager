#include "stdafx.h"
#include "menu_h.h"
Technician technician;
Menu::Menu()
{}
void Menu::Show()		
{
	system("cls");
	cout << "\n";
	cout << "     员工工资管理系统 " << endl;
	cout<<"==========================="<<endl;
	cout << "1-员工管理     2-查询管理            " << endl;
	cout << "3-排序管理     4-统计管理            " << endl;
	cout << "5-部门管理     0-退出系统            " << endl;
	cout<<"==========================="<<endl;
}

void Menu::ManageShow()				
{
	system("cls");
	cout << "\n";
	cout << "              员工管理" << endl;
	cout<<"==========================================="<<endl;
	cout << "1.添加员工信息     2.修改员工信息          " << endl;
	cout << "3.删除员工信息     4.计算技术员的工资  " << endl;
	cout << "5.计算销售员工资   0.返回主菜单            " << endl;
	cout<<"==========================================="<<endl;
	
}
void Menu::SearchShow()				
{
	system("cls");
	cout << "\n";
	cout << "                     查询" << endl;
	cout<<"=============================================="<<endl;
	cout << "1.输出全部部门员工       2.输出各个部门员工       " << endl;
	cout << "3.输出各个岗位员工       4.按工号查询             " << endl;
	cout << "5.按姓名查询             0.返回主菜单             " << endl;
	cout<<"=============================================="<<endl;
}
void Menu::SortShow()					
{
	system("cls");
	cout << "\n";
	cout << "                   排序 "<< endl;
	cout<<"=============================================="<<endl;
	cout << "1.全体员工工资排序       2.各个岗位工资排序         " << endl;
	cout << "0.返回上一级菜单                         " << endl;
	cout<<"=============================================="<<endl;
}

void Menu::CountShow()	
{
	system("cls");
	cout << "\n";
	cout << "                    统计" << endl;
	cout<<"==============================================="<<endl;
	cout << "1.各个部门的统计分析    2.全体员工的统计分析   " << endl;
	cout << "0.返回主菜单                   " << endl;
	cout<<"==============================================="<<endl;
}
void Menu::DepShow()	
{
	system("cls");
	cout << "\n";
	cout << "               部门管理" << endl;
	cout<<"=========================================="<<endl;
	cout << "1.添加部门     2.删除部门     3.修改部门      " << endl;
	cout << "4.浏览部门     0.返回主菜单         " << endl;
	cout<<"=========================================="<<endl;
}
void Menu::InquireShowByDepartment()	
{
	system("cls");
	cout << "\n";
	cout << "统计--各个部门的员工信息\n";
	cout<<" "<<endl;
	int i;
	for (i = 1; i <= technician.GetDCount(); i++)
	{
		cout << i << "-" << technician.GetDep(i - 1) << endl;
	}
	cout<<"\n";
	cout << "0.返回上一级菜单                     " << endl;
	
}
void Menu::InquireShowByJob()			
{
	system("cls");
	cout << "\n";
	cout <<"========================查询各个岗位的员工信息=============================" <<endl;
	cout << "                                                                        " <<endl;
	cout << "    1.经理    2.销售经理    3.销售员    4.技术员    0.返回上一级菜单    " <<endl;
	cout << "                                                                        " <<endl;
	cout <<"============================================================================"<<endl;
	
}
void Menu::SortShowByJob()	
{
	system("cls");
	cout << "\n";
	cout <<"========================排序-各个岗位工资降序==============================" << endl;
	cout << "                                                                        " << endl;
	cout << "    1.经理    2.销售经理    3.销售员    4.技术员    0.返回上一级菜单    " << endl;
	cout << "                                                                        " <<endl;
	cout<<"============================================================================"<<endl;
}
void Menu::CountShowByTotal()		
{
	system("cls");
	cout << "\n";
	cout << "                统计--全体员工" << endl;
	cout<<"===================================================="<<endl;
	cout << "1.最高与最低工资统计    2.统计超出平均工资的员工 " << endl;
	cout << "0.返回上一级菜单                   " << endl;
	cout<<"===================================================="<<endl;

}
void Menu::CountShowByDepartment()	
{
	system("cls");
	cout << "\n";
	cout << "统计--各个部门\n";
	cout << "                                                                    \n";
	int i;
	for (i = 1; i <= technician.GetDCount(); i++)
	{
		cout << i << "-" << technician.GetDep(i - 1) << endl;
	}
	cout << "                                                                    " << endl;
	cout << "0-返回上一级菜单                    " << endl;
}
void Menu::OneDepartment(int choice)					
{
	system("cls");
	cout << "\n";
	cout << "                    "<<technician.GetDep(choice)<<endl;
	cout<<"================================================="<<endl;
	cout << "1.浏览该部门的员工      2.统计该部门的员工信息   " << endl;
	cout << "0.返回上一级菜单                     " << endl;
	cout<<"================================================="<<endl;

}