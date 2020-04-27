#include "stdafx.h"
#include "menu_h.h"
Technician technician;
Menu::Menu()
{}
void Menu::Show()		
{
	system("cls");
	cout << "\n";
	cout << "     Ա�����ʹ���ϵͳ " << endl;
	cout<<"==========================="<<endl;
	cout << "1-Ա������     2-��ѯ����            " << endl;
	cout << "3-�������     4-ͳ�ƹ���            " << endl;
	cout << "5-���Ź���     0-�˳�ϵͳ            " << endl;
	cout<<"==========================="<<endl;
}

void Menu::ManageShow()				
{
	system("cls");
	cout << "\n";
	cout << "              Ա������" << endl;
	cout<<"==========================================="<<endl;
	cout << "1.���Ա����Ϣ     2.�޸�Ա����Ϣ          " << endl;
	cout << "3.ɾ��Ա����Ϣ     4.���㼼��Ա�Ĺ���  " << endl;
	cout << "5.��������Ա����   0.�������˵�            " << endl;
	cout<<"==========================================="<<endl;
	
}
void Menu::SearchShow()				
{
	system("cls");
	cout << "\n";
	cout << "                     ��ѯ" << endl;
	cout<<"=============================================="<<endl;
	cout << "1.���ȫ������Ա��       2.�����������Ա��       " << endl;
	cout << "3.���������λԱ��       4.�����Ų�ѯ             " << endl;
	cout << "5.��������ѯ             0.�������˵�             " << endl;
	cout<<"=============================================="<<endl;
}
void Menu::SortShow()					
{
	system("cls");
	cout << "\n";
	cout << "                   ���� "<< endl;
	cout<<"=============================================="<<endl;
	cout << "1.ȫ��Ա����������       2.������λ��������         " << endl;
	cout << "0.������һ���˵�                         " << endl;
	cout<<"=============================================="<<endl;
}

void Menu::CountShow()	
{
	system("cls");
	cout << "\n";
	cout << "                    ͳ��" << endl;
	cout<<"==============================================="<<endl;
	cout << "1.�������ŵ�ͳ�Ʒ���    2.ȫ��Ա����ͳ�Ʒ���   " << endl;
	cout << "0.�������˵�                   " << endl;
	cout<<"==============================================="<<endl;
}
void Menu::DepShow()	
{
	system("cls");
	cout << "\n";
	cout << "               ���Ź���" << endl;
	cout<<"=========================================="<<endl;
	cout << "1.��Ӳ���     2.ɾ������     3.�޸Ĳ���      " << endl;
	cout << "4.�������     0.�������˵�         " << endl;
	cout<<"=========================================="<<endl;
}
void Menu::InquireShowByDepartment()	
{
	system("cls");
	cout << "\n";
	cout << "ͳ��--�������ŵ�Ա����Ϣ\n";
	cout<<" "<<endl;
	int i;
	for (i = 1; i <= technician.GetDCount(); i++)
	{
		cout << i << "-" << technician.GetDep(i - 1) << endl;
	}
	cout<<"\n";
	cout << "0.������һ���˵�                     " << endl;
	
}
void Menu::InquireShowByJob()			
{
	system("cls");
	cout << "\n";
	cout <<"========================��ѯ������λ��Ա����Ϣ=============================" <<endl;
	cout << "                                                                        " <<endl;
	cout << "    1.����    2.���۾���    3.����Ա    4.����Ա    0.������һ���˵�    " <<endl;
	cout << "                                                                        " <<endl;
	cout <<"============================================================================"<<endl;
	
}
void Menu::SortShowByJob()	
{
	system("cls");
	cout << "\n";
	cout <<"========================����-������λ���ʽ���==============================" << endl;
	cout << "                                                                        " << endl;
	cout << "    1.����    2.���۾���    3.����Ա    4.����Ա    0.������һ���˵�    " << endl;
	cout << "                                                                        " <<endl;
	cout<<"============================================================================"<<endl;
}
void Menu::CountShowByTotal()		
{
	system("cls");
	cout << "\n";
	cout << "                ͳ��--ȫ��Ա��" << endl;
	cout<<"===================================================="<<endl;
	cout << "1.�������͹���ͳ��    2.ͳ�Ƴ���ƽ�����ʵ�Ա�� " << endl;
	cout << "0.������һ���˵�                   " << endl;
	cout<<"===================================================="<<endl;

}
void Menu::CountShowByDepartment()	
{
	system("cls");
	cout << "\n";
	cout << "ͳ��--��������\n";
	cout << "                                                                    \n";
	int i;
	for (i = 1; i <= technician.GetDCount(); i++)
	{
		cout << i << "-" << technician.GetDep(i - 1) << endl;
	}
	cout << "                                                                    " << endl;
	cout << "0-������һ���˵�                    " << endl;
}
void Menu::OneDepartment(int choice)					
{
	system("cls");
	cout << "\n";
	cout << "                    "<<technician.GetDep(choice)<<endl;
	cout<<"================================================="<<endl;
	cout << "1.����ò��ŵ�Ա��      2.ͳ�Ƹò��ŵ�Ա����Ϣ   " << endl;
	cout << "0.������һ���˵�                     " << endl;
	cout<<"================================================="<<endl;

}