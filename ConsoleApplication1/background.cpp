#include "stdafx.h"
#include "background_h.h"
static int g_iSize = 0;						
extern Technician technician;
map<int, Technician> g_Tec;					//����Աg_Tec				
map<int, Saler> g_S;						//����Աg_S					
map<int, Manager> g_M;						//����g_M
map<int, SalerManager> g_SM;				//���۾���g_SM

map<int, Technician>::iterator g_pTec;		//����Ա������g_pTec		 
map<int, Saler>::iterator g_pS;				//����Ա������g_pS
map<int, Manager>::iterator g_pM;			//���������g_pM
map<int, SalerManager>::iterator g_pSM;		//���۾��������g_pSM

map<int, string> g_dep;						//��������
vector<int> g_iIter;						//�洢����				
vector<int>::iterator g_piIter;				//�洢���ŵĵ�����
vector<float> g_fIter;						//����ȫ��Ա������
vector<float>::iterator g_pfIter;			//����ȫ��Ա�����ʵĵ�����
vector<float> g_fTec;						//���漼��Ա�Ĺ���
vector<float> g_fS;							//��������Ա�Ĺ���
vector<float> g_fM;							//���澭��Ĺ���
vector<float> g_fSM;						//�������۾���Ĺ���
int g_sel;									//ѡ��
bool CmpNum(const int &nFirst, const int &nSecond)
{
	if (nFirst < nSecond) //��С��������		
		return true;
	return false;
}
bool CmpSalary(const float &nFirst, const float &nSecond)
{
	if (nFirst > nSecond) //�ɴ�С����	
		return true;
	return false;
}

Background::Background()					
{
	Load();
	g_iSize = g_Tec.size() + g_S.size() + g_M.size() + g_SM.size();
	if (g_iSize)
	{
		technician.SetECount(g_iSize);
		SortByNum();
		g_piIter = g_iIter.end() - 1;
		technician.SetMaxNum(*g_piIter);
	}
}
Background::~Background()					
{
	Save();
	g_iSize = g_Tec.size() + g_S.size() + g_M.size() + g_SM.size();	
}

/*���ļ���ȡ����Ӧ��������*/
void Background::Load()			
{
	int length = 0;
	ifstream fread_tec("Technician.txt");
	ifstream fread_s("Saler.txt");
	ifstream fread_m("Manager.txt");
	ifstream fread_sm("SalerManager.txt");
	ifstream fread_dep("Department.txt");
	if (!fread_tec)						
		cout << "Technician.txt" << "�ļ���ʧ��" << endl;
	else
	{
		fread_tec >> length;
		for (int i = 0; i < length; i++)
		{
			fread_tec >> technician;
			g_Tec.insert(make_pair(technician.Getid(), technician));
		}
	}
	if (!fread_s)						
		cout << "Saler.txt" << "�ļ���ʧ��" << endl;
	else
	{
		fread_s >> length;
		for (int i = 0; i < length; i++)
		{
			fread_s >> saler;
			g_S.insert(make_pair(saler.Getid(), saler));
		}
	}
	if (!fread_m)						
		cout << "Manager.txt" << "�ļ���ʧ��" << endl;
	else
	{
		fread_m >> length;
		for (int i = 0; i < length; i++)
		{
			fread_m >> manager;
			g_M.insert(make_pair(manager.Getid(), manager));
		}
	}

	if (!fread_sm)						
		cout << "SalerManager.txt" << "�ļ���ʧ��" << endl;
	else
	{
		fread_sm >> length;
		for (int i = 0; i < length; i++)
		{
			fread_sm >> salerm;
			g_SM.insert(make_pair(salerm.Getid(), salerm));
		}
	}

	if (!fread_dep)						
		cout << "Department.txt" << "�ļ���ʧ��" << endl;
	else
	{
		fread_dep >> length;
		int *b = new int[length];
		string *temp = new string[length];
		for (int i = 0; i < length; i++)
			fread_dep >> b[i] >> temp[i];
		technician.InitDep(temp, b, length);
		delete[]b;
		delete[]temp;
	}
	fread_tec.close();										
	fread_s.close();
	fread_m.close();
	fread_sm.close();
	fread_dep.close();
}

/*�����ݱ��浽�ļ���*/
void Background::Save()	
{
	ofstream fwrite_tec("Technician.txt");
	ofstream fwrite_s("Saler.txt");
	ofstream fwrite_m("Manager.txt");
	ofstream fwrite_sm("SalerManager.txt");
	ofstream fwrite_dep("Department.txt");
	if (!fwrite_tec)						
		cout << "Technician.txt" << "�ļ���ʧ��" << endl;
	else
	{
		if (g_Tec.size())
		{
			fwrite_tec << g_Tec.size() << endl;
			for (g_pTec = g_Tec.begin(); g_pTec != g_Tec.end(); g_pTec++)
				fwrite_tec << g_pTec->second;					
		}
		else
			fwrite_tec << 0;
	}

	if (!fwrite_s)						
		cout << "Saler.txt" << "�ļ���ʧ��" << endl;
	else
	{
		if (g_S.size())
		{
			fwrite_s << g_S.size() << endl;
			for (g_pS = g_S.begin(); g_pS != g_S.end(); g_pS++)
				fwrite_s << g_pS->second;					
		}
		else
			fwrite_s << 0;
	}

	if (!fwrite_m)						
		cout << "Manager.txt" << "�ļ���ʧ��" << endl;
	else
	{
		if (g_M.size())
		{
			fwrite_m << g_M.size() << endl;
			for (g_pM = g_M.begin(); g_pM != g_M.end(); g_pM++)
				fwrite_m << g_pM->second;					
		}
		else
			fwrite_m << 0;
	}

	if (!fwrite_sm)						
		cout << "SalerManager.txt" << "�ļ���ʧ��" << endl;
	else
	{
		if (g_SM.size())
		{
			fwrite_sm << g_SM.size() << endl;
			for (g_pSM = g_SM.begin(); g_pSM != g_SM.end(); g_pSM++)
				fwrite_sm << g_pSM->second;					
		}
		else
			fwrite_sm << 0;
	}

	if (!fwrite_dep)
		cout << "Department.txt" << "�ļ���ʧ��" << endl;
	else
	{
		fwrite_dep << technician.GetDCount() << endl;
		for (int i = 0; i < technician.GetDCount(); i++)
			fwrite_dep << technician.GetDNumber(technician.GetDep(i)) << ' ' << technician.GetDep(i) << endl;  
	}
	fwrite_tec.close();										
	fwrite_s.close();
	fwrite_m.close();
	fwrite_sm.close();
	fwrite_dep.close();
}

/*��������*/
void Background::Run()		
{
	string na;				//����
	int num = -1;				//����
	int sel, sel_1 = 1, sel_2 = 1, sel_3 = 1, sel_4, sel_5, sel_6 = 1;
	int choice;
	char ch_1 = 'Y', ch_2 = 'Y';

	if (!g_iSize)				//û��Ա������
	{
		cout << "��û��Ա�����ݣ������������1��Ա��!" << endl;
		cout << "���еĲ�����:";
		for (int i = 0; i < technician.GetDCount(); i++)
			cout << "    " << technician.GetDep(i);
		cout << "\n\n";
		Add();
	}

	do
	{
		menu.Show();					
		cout << "������ѡ��:";
		cin >> sel;
		switch (sel)
		{
		case 1:							//Ա������
		FIRST :
			menu.ManageShow();
			  cout << "������ѡ��:";
			  cin >> g_sel;
			  switch (g_sel)
			  {
			  case 1:						//���Ա����Ϣ
				  Add();
				  break;
			  case 2:						//�޸�Ա����Ϣ
				  cout << "��������Ҫ�޸ĵ�Ա���Ĺ���!" << endl;
				  cin >> num;
				  choice = Search("0", num);
				  if (choice == 0)
				  {
					  cout << "û�иù��ŵ�Ա��!\n";
					  break;
				  }
				  SearchModify(choice, "0", num);
				  break;
			  case 3:						//ɾ��Ա����Ϣ
				  cout << "��������Ҫɾ����Ա���Ĺ���!" << endl;
				  cin >> num;
				  Delete(num);
				  break;
			  case 4:						//���㼼��Ա���¹���
				  CountSalary(1);
				  break;
			  case 5:						//��������Ա�����۾����¹���
				  CountSalary(0);
				  break;
			  case 0:
				  break;
			  default:
				  break;
			  }
			  system("pause");
			  if (g_sel != 0)
				  goto FIRST;
			  break;

		case 2://��ѯ����
		SECOND :
			menu.SearchShow();
			   cout << "������ѡ��:";
			   cin >> g_sel;
			   switch (g_sel)
			   {
			   case 1:
				   AllOutput();						//�����������Ա����Ϣ
				   break;
			   case 2:
				   while (sel_1)
				   {
					   menu.InquireShowByDepartment();		//���������Ա����Ϣ
					   cout << "������ѡ��:";
					   cin >> sel_1;
					   OutputByDepartment(sel_1);			//���������Ա��
					   system("pause");
				   }
				   break;
			   case 3:
				   while (sel_2)
				   {
					   menu.InquireShowByJob();			//����λ���Ա����Ϣ
					   cout << "������ѡ��:";
					   cin >> sel_2;
					   OutputByJob(sel_2);					//����λ���Ա��
					   system("pause");
				   }
				   break;
			   case 4:
				   ch_1 = 'y';
				   while (ch_1 == 'y' || ch_1 == 'Y')
				   {
					   cout << "������Ҫ���ҵ�Ա�����ţ�" ;//�����Ų���Ա����Ϣ
					   cin >> num;
					   if (!Search("", num))
						   cout << "û�иù��ŵ�Ա��\n";
					   cout << "�Ƿ������ѯ(Y/N)?\n";
					   cin >> ch_1;
				   }
				   break;
			   case 5:									//����������Ա����Ϣ
				   ch_2 = 'y';
				   while (ch_2 == 'y' || ch_2 == 'Y')
				   {
					   cout << "������Ҫ���ҵ�Ա������!" << endl;
					   cin >> na;
					   if (!Search(na, 0))
						   cout << "û�и�������Ա��\n";
					   cout << "�Ƿ������ѯ(Y/N)?\n";
					   cin >> ch_2;
				   }
				   break;
			   case 0:
				   break;
			   default:
				   break;
			   }
			   if (g_sel != 0)
				   goto SECOND;
			   break;

		case 3://�������
		THIRD :
			menu.SortShow();
			  cout << "������ѡ��:";
			  cin >> g_sel;
			  switch (g_sel)
			  {
			  case 1:
				  TotalSalaryDown();					//ȫ��Ա������������Ա����Ϣ
				  break;
			  case 2:
				  sel_3 = 1;
				  while (sel_3)
				  {
					  menu.SortShowByJob();				//����ĳ��λ��Ա�����ʴӸߵ���
					  cout << "������ѡ��:";
					  cin >> sel_3;
					  JobSalaryDown(sel_3);				//������λ���ʽ������
				  }
				  break;
			  default:
				  break;
			  }
			  if (g_sel != 0)
				  goto THIRD;
			  break;

		case 4://ͳ�ƹ���
		FOURTH1 :
			SortBySalary();
				menu.CountShow();
				cout << "������ѡ��:";
				cin >> g_sel;
				switch (g_sel)
				{
				case 1:
					sel_5 = 1;
					while (sel_5)
					{
						menu.CountShowByDepartment();		//����ͳ��Ա����Ϣ
						cout << "������ѡ��:";
						cin >> sel_5;
						if (!sel_5)
							break;
						CountByDepartment(sel_5);
						system("pause");
					}
					break;
				case 2:
				FOURTH2 :
					menu.CountShowByTotal();			//ȫ��Ա��ͳ��Ա����Ϣ
						cout << "������ѡ��:";
						cin >> sel_4;
						if (sel_4 == 1)
							CountUpAndDown();
						else if (sel_4 == 2)
							CountAverage();
						system("pause");
						if (sel_4)
							goto FOURTH2;
				case 0:
					break;
				default:
					break;
				}
				if (g_sel)
					goto FOURTH1;
				break;

		case 5:
			sel_6 = 1;
			while (sel_6)
			{
				menu.DepShow();
				cout << "������ѡ��:";
				cin >> sel_6;
				DepartmentManager(sel_6);
			}
			break;
		default:
			break;
		}
	} while (sel);
}
/*���Ա����Ϣ*/
void Background::Add()
{
	int flag = 1;
	char ch;
	cout << "1.����Ա  2.����Ա  3.����  4.���۾���  0.����" << endl;
	cout << "������ѡ��:";
	cin >> g_sel;
	switch (g_sel)
	{
	case 1:
		technician.Input();
		g_Tec.insert(make_pair(technician.Getid(), technician)); 		
		break;
	case 2:
		saler.Input();
		g_S.insert(make_pair(saler.Getid(), saler)); 			
		break;
	case 3:
		manager.Input();
		g_M.insert(make_pair(manager.Getid(), manager)); 			
		break;
	case 4:
		salerm.Input();
		for (g_pSM = g_SM.begin(); g_pSM != g_SM.end(); g_pSM++)				
		{
			if (salerm.GetDepartment() == g_pSM->second.GetDepartment())		
			{
				cout << "���ʧ�ܣ��ò����Ѿ��������۾�����!" << endl;
				flag = 0;
				break;
			}
		}
		if (g_pSM == g_SM.end())											
			g_SM.insert(make_pair(salerm.Getid(), salerm)); 					
		break;
	case 0:
		break;
	default:
		cout << "�������!\n";
		break;
	}
	if (g_sel&&flag)
		cout << "��ӳɹ�!" << endl;
	cout << "�Ƿ�������(Y/N)?\n";
	cin >> ch;
	if (ch == 'y' || ch == 'Y')
		Add();
	else
		return;
}

/*������ɾ��Ա����Ϣ*/
void Background::Delete(int num)
{
	int sel;
	sel = Search("0", num);
	if (sel == 1)
	{
		g_Tec.erase(num);
		cout << "ɾ���ɹ�!" << endl;
	}
	else if (sel == 2)
	{
		g_S.erase(num);
		cout << "ɾ���ɹ�!" << endl;
	}
	else if (sel == 3)
	{
		g_M.erase(num);
		cout << "ɾ���ɹ�!" << endl;
	}
	else if (sel == 4)
	{
		g_SM.erase(num);
		cout << "ɾ���ɹ�!" << endl;
	}
	else
		cout << "û�иù��ŵ�Ա��!" << endl;
}

/*�����Ų��Һ��޸�Ա����Ϣ*/
template <class T>
int Background::Modify(T &type)
{
	string name = "", sex = "", depart = "", job = "";
	int age;
	float salary;
	cout << "���� " << "1.����" << " 2.�Ա�" << " 3.����" << " 4.����" << " 5.��λ" << " 6.��ʱ" << ' ' << " 7.���۶��/8.�����۶��"" 9.����" << endl;
	cout << "������Ҫ�޸ĵ�ѡ��(���Ų����޸�):";
	cin >> g_sel;
	switch (g_sel)
	{
	case 1:
		cout << "�������޸ĺ������:";
		cin >> name;
		type.SetName(name);
		break;
	case 2:
		cout << "�������޸ĺ���Ա�:";
		cin >> sex;
		type.SetSex(sex);
		break;
	case 3:
		cout << "�������޸ĺ������:";
		cin >> age;
		type.SetAge(age);
		break;
	case 4:
		cout << "�������޸ĺ�Ĳ���:";
		cin >> depart;
		type.SetDep(depart);
		break;
	case 5:
		cout << "�������޸ĺ�ĸ�λ:";
		cin >> job;
		type.SetJob(job);
		break;
	case 6:
		break;
	case 7:
		break;
	case 8:
		break;
	case 9:
		cout << "�������޸ĺ�Ĺ���:";
		cin >> salary;
		type.SetSalary(salary);
	case 0:
		return 0;
	default:
		cout << " �������!\n";
		break;
	}
	if (g_sel == 6)
		return 1;
	else if (g_sel == 7)
		return 2;
	else if (g_sel == 8)
		return 3;
	cout << "�޸ĺ����ϢΪ:\n";
	cout << " �� �� " << " �� ��  " << "�� �� " << " �� ��" << "    �� ��" << "     �� λ" << "    �� ʱ" << "  ���۶��" << "     ��  ��" << endl;
	cout << "------------------------------------------------------------------------------\n";
	cout << type;
	return 0;
}

/*�������㼼��Ա���¹���*/
void Background::CountSalary(int flag)		
{
	float hours;					
	float balance;					
	float total = 0;				//���������۶��
	if (flag == 1)
	{
		for (g_pTec = g_Tec.begin(); g_pTec != g_Tec.end(); g_pTec++)	//��������Ա
		{
			if (g_pTec->second.GetSalary() == 0)
			{
				g_pTec->second.Output();
				cout << "�������Ա���Ĺ�ʱ:";
				cin >> hours;
				g_pTec->second.SetHours(hours);					
				g_pTec->second.SetSalary((float)hours * 100);	//���㼼��Ա����
				cout << "����ɹ�!\n�Ƿ��������!���밴1,���밴0��" << endl;
				cin >> g_sel;
				if (g_sel)
					continue;		
				else
					break;
			}
		}
		if (g_pTec == g_Tec.end())
			cout << "���м���Ա�Ĺ��ʼ���ɹ�\n";
	}
	else if (flag == 0)
	{
		for (g_pS = g_S.begin(); g_pS != g_S.end(); g_pS++)	//��������Ա
		{
			if (g_pS->second.GetSalary() == 0)
			{
				g_pS->second.Output();
				cout << "�������Ա�������۶��:";
				cin >> balance;
				g_pS->second.SetBalance(balance);							
				g_pS->second.SetSalary((float)(balance * 0.04));		//��������Ա����
				cout << "����ɹ�!�Ƿ��������!���밴1,���밴0��" << endl;
				cin >> g_sel;
				if (g_sel)
					continue;
				else
					break;
			}

		}
		if (g_pS == g_S.end())
			cout << "��������Ա�Ĺ��ʼ���ɹ�!" << endl;
	}
	if (flag == 0)			
	{
		if (g_pS == g_S.end())
		{
			for (g_pSM = g_SM.begin(); g_pSM != g_SM.end(); g_pSM++)		//	�������۾���
			{
				for (g_pS = g_S.begin(); g_pS != g_S.end(); g_pS++)     	//��������Ա
				{
					if (g_pSM->second.GetDepartment() == g_pS->second.GetDepartment())  
						total += g_pS->second.GetSalary();
					g_pSM->second.SetSalary((float)(total*0.005)+5000);					//�������۾�����		
					g_pSM->second.SetTotal(total);
				}
			}
		}
	}
}

/*���ȫ��Ա����Ϣ*/
void Background::AllOutput()
{
	int i = 0;
	SortByNum();
	if (g_Tec.size() == 0 && g_S.size() == 0 && g_M.size() == 0 && g_SM.size() == 0)
	{
		cout << "��û��Ա����Ϣ!" << endl;
		return;
	}                           
	cout << " �� �� " << " �� ��  " << "�� �� " << " �� ��" << "    �� ��" << "     �� λ" << "    �� ʱ" << "  ���۶��" << "     ��  ��" << endl;
	cout << "------------------------------------------------------------------------------\n";
	for (; i < g_iIter.size(); i++)
	{
		for (g_pTec = g_Tec.begin(); g_pTec != g_Tec.end(); g_pTec++)
		{
			if (g_pTec->second.Getid() == g_iIter[i])
			{
				g_pTec++->second.Output();
				break;
			}
		}

		for (g_pS = g_S.begin(); g_pS != g_S.end(); g_pS++)
		{
			if (g_pS->second.Getid() == g_iIter[i])
			{
				g_pS++->second.Output();
				break;
			}
		}
		for (g_pM = g_M.begin(); g_pM != g_M.end(); g_pM++)
		{
			if (g_pM->second.Getid() == g_iIter[i])
			{
				g_pM++->second.Output();
				break;
			}
		}
		for (g_pSM = g_SM.begin(); g_pSM != g_SM.end(); g_pSM++)
		{
			if (g_pSM->second.Getid() == g_iIter[i])
			{
				g_pSM++->second.Output();
				break;
			}
		}
	}
	cout<<"\n";
	system("pause");
}
/*���������Ա��*/
void Background::OutputByDepartment(int choice)
{
	choice--;
	if (choice<0 || choice>technician.GetDCount())
		return;
	system("cls");
	cout << " �� �� " << " �� ��  " << "�� �� " << " �� ��" << "    �� ��" << "     �� λ" << "    �� ʱ" << "  ���۶��" << "     ��  ��" << endl;
	cout << "------------------------------------------------------------------------------\n";
	for (g_pTec = g_Tec.begin(); g_pTec != g_Tec.end(); g_pTec++)
	{
		if (g_pTec->second.GetDepartment() == technician.GetDep(choice))
		{
			g_pTec->second.Output();
		}
	}
	for (g_pS = g_S.begin(); g_pS != g_S.end(); g_pS++)
	{
		if (g_pS->second.GetDepartment() == technician.GetDep(choice))
		{
			g_pS->second.Output();
		}
	}
	for (g_pM = g_M.begin(); g_pM != g_M.end(); g_pM++)
	{
		if (g_pM->second.GetDepartment() == technician.GetDep(choice))
			g_pM->second.Output();
	}
	for (g_pSM = g_SM.begin(); g_pSM != g_SM.end(); g_pSM++)
	{
		if (g_pSM->second.GetDepartment() == technician.GetDep(choice))
			g_pSM->second.Output();
	}
}

/*����λ���Ա��*/
void Background::OutputByJob(int choice)
{
	if (choice == 0)
		return;
	cout << " �� �� " << " �� ��  " << "�� �� " << " �� ��" << "    �� ��" << "     �� λ" << "    �� ʱ" << "  ���۶��" << "     ��  ��" << endl;
	cout << "------------------------------------------------------------------------------\n";
	switch (choice)
	{
	case 1:
		for (g_pM = g_M.begin(); g_pM != g_M.end(); g_pM++)	
			g_pM->second.Output();
		break;
	case 2:
		for (g_pSM = g_SM.begin(); g_pSM != g_SM.end(); g_pSM++)
			g_pSM->second.Output();
		break;
	case 3:
		for (g_pS = g_S.begin(); g_pS != g_S.end(); g_pS++)
			g_pS->second.Output();
		break;
	case 4:
		for (g_pTec = g_Tec.begin(); g_pTec != g_Tec.end(); g_pTec++)
			g_pTec->second.Output();
		break;
	default:
		break;
	}
	cout << " �� �� " << " �� ��  " << "�� �� " << " �� ��" << "    �� ��" << "     �� λ" << "    �� ʱ" << "  ���۶��" << "     ��  ��" << endl;
}

/*������/���Ų���Ա����Ϣ*/
int Background::Search(string na, int num)			
{
	cout << " �� �� " << " �� ��  " << "�� �� " << " �� ��" << "    �� ��" << "     �� λ" << "    �� ʱ" << "  ���۶��" << "     ��  ��" << endl;
	cout << "------------------------------------------------------------------------------\n";
	if (num != 0)
	{
		g_pTec = g_Tec.find(num);				
		if (g_pTec != g_Tec.end())				
		{
			g_pTec->second.Output();
			cout << "------------------------------------------------------------------------------\n";
			return 1;
		}
		g_pS = g_S.find(num);					
		if (g_pS != g_S.end())				
		{
			g_pS->second.Output();
			cout << "------------------------------------------------------------------------------\n";
			return 2;
		}
		g_pM = g_M.find(num);					
		if (g_pM != g_M.end())				
		{
			g_pM->second.Output();
			cout << "------------------------------------------------------------------------------\n";
			return 3;
		}
		g_pSM = g_SM.find(num);	 				
		if (g_pSM != g_SM.end())				
		{
			g_pSM->second.Output();
			cout << "------------------------------------------------------------------------------\n";
			return 4;
		}
		return 0;
	}
	else
	{
		for (g_pTec = g_Tec.begin(); g_pTec != g_Tec.end(); g_pTec++)
		{
			if (na == g_pTec->second.GetName())
			{
				g_pTec->second.Output();
				cout << "------------------------------------------------------------------------------\n";
				return 1;
			}
		}

		for (g_pS = g_S.begin(); g_pS != g_S.end(); g_pS++)
		{
			if (na == g_pS->second.GetName())
			{
				g_pS->second.Output();
				cout << "------------------------------------------------------------------------------\n";
				return 2;
			}
		}

		for (g_pM = g_M.begin(); g_pM != g_M.end(); g_pM++)
		{
			if (na == g_pM->second.GetName())
			{
				g_pM->second.Output();
				cout << "------------------------------------------------------------------------------\n";
				return 3;
			}
		}

		for (g_pSM = g_SM.begin(); g_pSM != g_SM.end(); g_pSM++)
		{
			if (na == g_pSM->second.GetName())
			{
				g_pSM->second.Output();
				cout << "------------------------------------------------------------------------------\n";
				return 4;
			}
		}
		return 0;
	}
}
/*����Ա����Ϣ�����*/
void Background::SearchModify(int choice, string name, int num)
{
	float hours = 0;
	float balance = 0;
	float total = 0;
	int i;
	if (num != 0)
	{
		if (!choice)
			cout << "û�и�������Ա��" << endl;
		else if (choice == 1)
		{

			g_pTec = g_Tec.find(num);
			i = Modify(g_pTec->second);
			if (i == 1)
			{
				cout << "��������Ҫ�޸ĺ��ʱ��:";
				cin >> hours;
				g_pTec->second.SetHours(hours);
			}
			if (i != 0 && i != 1)
				cout << "����Աû�и�����Ϣ!" << endl;
		}
		else if (choice == 2)
		{
			g_pS = g_S.find(num);
			i = Modify(g_pS->second);
			if (i == 2)
			{
				cout << "��������Ҫ�޸ĺ�Ķ��:";
				cin >> hours;
				g_pS->second.SetBalance(balance);
			}
			if (i != 0 && i != 2)
				cout << "����Աû�и�����Ϣ!" << endl;
		}

		else if (choice == 3)
		{
			g_pM = g_M.find(num);
			Modify(g_pM->second);
		}
		else if (choice == 4)
		{
			g_pSM = g_SM.find(num);
			i = Modify(g_pSM->second);
			if (i == 3)
			{
				cout << "��������Ҫ�޸ĺ�������۶��:";
				cin >> total;
				g_pSM->second.SetTotal(total);
			}
			if (i != 0 && i != 3)
				cout << "���۾���û�и�����Ϣ!" << endl;
		}
	}
}
/*������λ���ʽ������*/
void Background::JobSalaryDown(int choice)
{
	if (!choice)
		return;
	map<int, Technician> T;
	map<int, Saler> S;
	map<int, Manager> M;
	map<int, SalerManager> SM;

	map<int, Technician>::iterator pT;
	map<int, Saler>::iterator pS;
	map<int, Manager>::iterator pM;
	map<int, SalerManager>::iterator pSM;

	T.insert(g_Tec.begin(), g_Tec.end());
	S.insert(g_S.begin(), g_S.end());
	M.insert(g_M.begin(), g_M.end());
	SM.insert(g_SM.begin(), g_SM.end());
	if (g_Tec.size() == 0 && g_S.size() == 0 && g_M.size() == 0 && g_SM.size() == 0)
	{
		cout << "��û��Ա����Ϣ!" << endl;
		return;
	}
	cout << " �� �� " << " �� ��  " << "�� �� " << " �� ��" << "    �� ��" << "     �� λ" << "    �� ʱ" << "  ���۶��" << "     ��  ��" << endl;
	cout << "------------------------------------------------------------------------------\n";
	switch (choice)
	{
	case 1:
		for (pM = M.begin(); pM != M.end(); pM++)
			g_fM.push_back(pM->second.GetSalary());
		sort(g_fM.begin(), g_fM.end(), CmpSalary);			
		for (int i = 0; i < g_M.size(); i++)
		{
			for (pM = M.begin(); pM != M.end(); pM++)
			{
				if (pM->second.GetSalary() == g_fM[i])
				{
					pM->second.Output();
					M.erase(pM);
					break;
				}
			}
		}
		break;
	case 2:
		for (pSM = SM.begin(); pSM != SM.end(); pSM++)
			g_fSM.push_back(pSM->second.GetSalary());
		sort(g_fSM.begin(), g_fSM.end(), CmpSalary);			
		for (int i = 0; i < g_SM.size(); i++)
		{
			for (pSM = SM.begin(); pSM != SM.end(); pSM++)
			{
				if (pSM->second.GetSalary() == g_fSM[i])
				{
					pSM->second.Output();
					SM.erase(pSM);
					break;
				}
			}
		}
		break;
	case 3:
		for (pS = S.begin(); pS != S.end(); pS++)
			g_fS.push_back(pS->second.GetSalary());
		sort(g_fS.begin(), g_fS.end(), CmpSalary);			
		for (int i = 0; i < g_S.size(); i++)
		{
			for (pS = S.begin(); pS != S.end(); pS++)
			{
				if (pS->second.GetSalary() == g_fS[i])
				{
					pS->second.Output();
					S.erase(pS);
					break;
				}
			}
		}
		break;
	case 4:
		for (pT = T.begin(); pT != T.end(); pT++)
			g_fTec.push_back(pT->second.GetSalary());
		sort(g_fTec.begin(), g_fTec.end(), CmpSalary);			
		for (int i = 0; i < g_fTec.size(); i++)
		{
			for (pT = T.begin(); pT != T.end(); pT++)
			{
				if (pT->second.GetSalary() == g_fTec[i])
				{
					pT->second.Output();
					T.erase(pT);
					break;
				}
			}
		}
		break;
	default:
		break;
	}
	cout << "------------------------------------------------------------------------------\n";
	g_fTec.erase(g_fTec.begin(), g_fTec.end());
	g_fS.erase(g_fS.begin(), g_fS.end());
	g_fM.erase(g_fM.begin(), g_fM.end());
	g_fSM.erase(g_fSM.begin(), g_fSM.end());
	system("pause");
}

/*ȫ��Ա�������ʽ������*/
void Background::TotalSalaryDown()
{
	map<int, Technician> TecTemp;
	map<int, Saler> STemp;
	map<int, Manager> MTemp;
	map<int, SalerManager> SMTemp;

	map<int, Technician>::iterator pTecTemp;
	map<int, Saler>::iterator pSTemp;
	map<int, Manager>::iterator pMTemp;
	map<int, SalerManager>::iterator pSMTemp;

	SortBySalary();
	cout << " �� �� " << " �� ��  " << "�� �� " << " �� ��" << "    �� ��" << "     �� λ" << "    �� ʱ" << "  ���۶��" << "     ��  ��" << endl;
	cout << "------------------------------------------------------------------------------\n";
	TecTemp.insert(g_Tec.begin(), g_Tec.end());
	STemp.insert(g_S.begin(), g_S.end());
	MTemp.insert(g_M.begin(), g_M.end());
	SMTemp.insert(g_SM.begin(), g_SM.end());

	if (TecTemp.size() == 0 && STemp.size() == 0 && MTemp.size() == 0 && SMTemp.size() == 0)
	{
		cout << "��û��Ա����Ϣ!" << endl;
		return;
	}

	for (int i = 0; i < technician.GetECount();)
	{
		for (pTecTemp = TecTemp.begin(); pTecTemp != TecTemp.end(); pTecTemp++)
		{
			if (pTecTemp->second.GetSalary() == g_fIter[i])
			{
				pTecTemp->second.Output();
				TecTemp.erase(pTecTemp);
				goto LOOP;
			}

		}
		for (pSTemp = STemp.begin(); pSTemp != STemp.end(); pSTemp++)
		{
			if (pSTemp->second.GetSalary() == g_fIter[i])
			{
				pSTemp->second.Output();
				STemp.erase(pSTemp);
				goto LOOP;
			}
		}
		for (pMTemp = MTemp.begin(); pMTemp != MTemp.end(); pMTemp++)
		{
			if (pMTemp->second.GetSalary() == g_fIter[i])
			{
				pMTemp->second.Output();
				MTemp.erase(pMTemp);
				goto LOOP;
			}
		}
		for (pSMTemp = SMTemp.begin(); pSMTemp != SMTemp.end(); pSMTemp++)
		{
			if (pSMTemp->second.GetSalary() == g_fIter[i])
			{
				pSMTemp->second.Output();
				SMTemp.erase(pSMTemp);
				goto LOOP;
			}
		}
	LOOP:
		i++;
	}
	cout << "------------------------------------------------------------------------------\n";
	TecTemp.erase(TecTemp.begin(), TecTemp.end());
	STemp.erase(STemp.begin(), STemp.end());
	MTemp.erase(MTemp.begin(), MTemp.end());
	SMTemp.erase(SMTemp.begin(), SMTemp.end());
	system("pause");
}

/*ͳ��ȫ��Ա�����������͹���*/
void Background::CountUpAndDown()
{
	SortBySalary();
	vector<float>::iterator max = max_element(g_fIter.begin(), g_fIter.end());
	vector<float>::iterator min = min_element(g_fIter.begin(), g_fIter.end());
	cout << "��߹���Ϊ:" << *max << "    " << "��͹���Ϊ:" << *min << endl;
	cout << "ȫ��Ա������߹��ʺ���͹��ʵ�Ա����Ϣ����:\n";
	cout << " �� �� " << " �� ��  " << "�� �� " << " �� ��" << "    �� ��" << "     �� λ" << "    �� ʱ" << "  ���۶��" << "     ��  ��" << endl;
	cout << "------------------------------------------------------------------------------\n";
	for (g_pTec = g_Tec.begin(); g_pTec != g_Tec.end(); g_pTec++)
	{
		if (g_pTec->second.GetSalary() == *max)
			g_pTec->second.Output();
	}
	for (g_pS = g_S.begin(); g_pS != g_S.end(); g_pS++)
	{
		if (g_pS->second.GetSalary() == *max)
			g_pS->second.Output();
	}
	for (g_pM = g_M.begin(); g_pM != g_M.end(); g_pM++)
	{
		if (g_pM->second.GetSalary() == *max)
			g_pM->second.Output();
	}
	for (g_pSM = g_SM.begin(); g_pSM != g_SM.end(); g_pSM++)
	{

		if (g_pSM->second.GetSalary() == *max)
			g_pSM->second.Output();
	}
	for (g_pTec = g_Tec.begin(); g_pTec != g_Tec.end(); g_pTec++)
	{
		if (g_pTec->second.GetSalary() == *min)
			g_pTec->second.Output();
	}
	for (g_pS = g_S.begin(); g_pS != g_S.end(); g_pS++)
	{
		if (g_pS->second.GetSalary() == *min)
			g_pS->second.Output();
	}
	for (g_pM = g_M.begin(); g_pM != g_M.end(); g_pM++)
	{
		if (g_pM->second.GetSalary() == *min)
			g_pM->second.Output();
	}
	for (g_pSM = g_SM.begin(); g_pSM != g_SM.end(); g_pSM++)
	{

		if (g_pSM->second.GetSalary() == *min)
			g_pSM->second.Output();
	}
	cout << "------------------------------------------------------------------------------\n";
}

/*ͳ��ȫ��Ա����ƽ������ ����ʾ����ƽ�����ʵ�Ա����Ϣ*/
void Background::CountAverage()
{
	SortBySalary();
	float sum = 0;
	for (int i = 0; i < g_fIter.size(); i++)
		sum += g_fIter[i];
	float average = sum / g_fIter.size(); 
	cout << "ȫ��Ա����ƽ������Ϊ:" << average << endl;
	cout << "����ȫ��Ա��ƽ�����ʵ�Ա��������:\n";
	cout << " �� �� " << " �� ��  " << "�� �� " << " �� ��" << "    �� ��" << "     �� λ" << "    �� ʱ" << "  ���۶��" << "     ��  ��" << endl;
	cout << "------------------------------------------------------------------------------\n";
	for (g_pTec = g_Tec.begin(); g_pTec != g_Tec.end(); g_pTec++)
	{
		if (g_pTec->second.GetSalary()>average)
			g_pTec->second.Output();
	}
	for (g_pS = g_S.begin(); g_pS != g_S.end(); g_pS++)
	{
		if (g_pS->second.GetSalary() > average)
			g_pS->second.Output();
	}
	for (g_pM = g_M.begin(); g_pM != g_M.end(); g_pM++)
	{
		if (g_pM->second.GetSalary() > average)
			g_pM->second.Output();
	}
	for (g_pSM = g_SM.begin(); g_pSM != g_SM.end(); g_pSM++)
	{
		if (g_pSM->second.GetSalary() > average)
			g_pSM->second.Output();
	}
	cout << "------------------------------------------------------------------------------\n";
}
void Background::CountByDepartment(int choice)
{
	int count = 0;
	--choice;
	float max = 0;
	float min = 0;
	int flag = 0;
	float sum = 0;
	float average = 0;
	for (g_pTec = g_Tec.begin(); g_pTec != g_Tec.end(); g_pTec++)
	{
		if (g_pTec->second.GetDepartment() == technician.GetDep(choice))		
		{
			if (!flag)
			{
				min = g_pTec->second.GetSalary();
				flag = 1;
			}
			if (g_pTec->second.GetSalary() >= max)					//��߹���
				max = g_pTec->second.GetSalary();
			if (g_pTec->second.GetSalary() <= min)					//��͹���
				min = g_pTec->second.GetSalary();
			sum += g_pTec->second.GetSalary();
		}
	}
	for (g_pS = g_S.begin(); g_pS != g_S.end(); g_pS++)
	{
		if (g_pS->second.GetDepartment() == technician.GetDep(choice))
		{
			if (!flag)
			{
				min = g_pS->second.GetSalary();
				flag = 1;
			}
			if (g_pS->second.GetSalary() >= max)
				max = g_pS->second.GetSalary();
			if (g_pS->second.GetSalary() <= min)
				min = g_pS->second.GetSalary();
			sum += g_pS->second.GetSalary();
		}
	}
	for (g_pM = g_M.begin(); g_pM != g_M.end(); g_pM++)
	{
		if (g_pM->second.GetDepartment() == technician.GetDep(choice))
		{
			if (!flag)
			{
				min = g_pM->second.GetSalary();
				flag = 1;
			}
			if (g_pM->second.GetSalary() >= max)
				max = g_pM->second.GetSalary();
			if (g_pM->second.GetSalary() <= min)
				min = g_pM->second.GetSalary();
			sum += g_pM->second.GetSalary();
		}
	}
	for (g_pSM = g_SM.begin(); g_pSM != g_SM.end(); g_pSM++)
	{
		if (g_pSM->second.GetDepartment() == technician.GetDep(choice))
		{
			if (!flag)
			{
				min = g_pSM->second.GetSalary();
				flag = 1;
			}
			if (g_pSM->second.GetSalary() >= max)
				max = g_pSM->second.GetSalary();
			if (g_pSM->second.GetSalary() <= min)
				min = g_pSM->second.GetSalary();
			sum += g_pSM->second.GetSalary();
		}
	}
	cout << technician.GetDep(choice) << ":��߹���Ϊ:" << max << "   ��͹���Ϊ:" << min << endl;
	average = sum / technician.GetECount(); 
	cout << technician.GetDep(choice) << "��ƽ������Ϊ:" << average << endl;
	cout << "��" << technician.GetDep(choice) << "�г���ƽ�����ʵ�Ա������:\n";
	cout << "------------------------------------------------------------------------------\n";;
	for (g_pTec = g_Tec.begin(); g_pTec != g_Tec.end(); g_pTec++)
	{
		if (g_pTec->second.GetSalary() > average &&g_pTec->second.GetDepartment() == technician.GetDep(choice))
		{
			g_pTec->second.Output();
			count++;
		}
	}
	for (g_pS = g_S.begin(); g_pS != g_S.end(); g_pS++)
	{
		if (g_pS->second.GetSalary() > average&&g_pS->second.GetDepartment() == technician.GetDep(choice))
		{
			g_pS->second.Output();
			count++;
		}
	}
	for (g_pM = g_M.begin(); g_pM != g_M.end(); g_pM++)
	{
		if (g_pM->second.GetSalary() > average&&g_pM->second.GetDepartment() == technician.GetDep(choice))
		{
			g_pM->second.Output();
			count++;
		}
	}
	for (g_pSM = g_SM.begin(); g_pSM != g_SM.end(); g_pSM++)
	{
		if (g_pSM->second.GetSalary() > average&&g_pSM->second.GetDepartment() == technician.GetDep(choice))
		{
			g_pSM->second.Output();
			count++;
		}
	}
	cout << "------------------------------------------------------------------------------\n";
	cout << "����ƽ�����ʵ�Ա����" << count << "�ˡ�\n";
}
/*ȫ�尴Ա����������*/
void Background::SortByNum()
{
	g_pTec = g_Tec.begin(), g_pM = g_M.begin(), g_pS = g_S.begin(), g_pSM = g_SM.begin();
	while (g_pTec != g_Tec.end())
	{
		g_iIter.push_back(g_pTec->second.Getid());
		g_pTec++;
	}
	while (g_pM != g_M.end())
	{
		g_iIter.push_back(g_pM->second.Getid());
		g_pM++;
	}
	while (g_pS != g_S.end())
	{
		g_iIter.push_back(g_pS->second.Getid());
		g_pS++;
	}
	while (g_pSM != g_SM.end())
	{
		g_iIter.push_back(g_pSM->second.Getid());
		g_pSM++;
	}
	sort(g_iIter.begin(), g_iIter.end(), CmpNum);			//��������
	g_iIter.erase(std::unique(g_iIter.begin(), g_iIter.end()), g_iIter.end());	
}
void Background::SortBySalary()
{
	static map<int, Technician>::iterator Tec = g_Tec.begin();
	static map<int, Manager>::iterator M = g_M.begin();
	static map<int, Saler>::iterator S = g_S.begin();
	static map<int, SalerManager>::iterator SM = g_SM.begin();
	if (g_fIter.size() == 0)
	{
		Tec = g_Tec.begin(); M = g_M.begin(); S = g_S.begin(); SM = g_SM.begin();
	}
	while (Tec != g_Tec.end())
	{
		g_fIter.push_back(Tec->second.GetSalary());
		Tec++;
	}
	while (M != g_M.end())
	{
		g_fIter.push_back(M->second.GetSalary());
		M++;
	}
	while (S != g_S.end())
	{
		g_fIter.push_back(S->second.GetSalary());
		S++;
	}
	while (SM != g_SM.end())
	{
		g_fIter.push_back(SM->second.GetSalary());
		SM++;
	}
	sort(g_fIter.begin(), g_fIter.end(), CmpSalary);			//������
}
void Background::DepartmentManager(int choice)
{
	string OldDep, NewDep;
	int sel = 0;
	switch (choice)
	{
	case 1:
		cout << "��������Ҫ��ӵĲ�������:";
		cin >> NewDep;
		technician.AddDep(NewDep);
		system("pause");
		break;
	case 2:
		cout << "��������Ҫɾ���Ĳ�������:";
		cin >> OldDep;
		g_fIter.clear();
		for (g_pTec = g_Tec.begin(); g_pTec != g_Tec.end();)
		{
			if (g_pTec->second.GetDepartment() == OldDep)
			{
				g_pTec = g_Tec.erase(g_pTec);
				technician.SetECount(technician.GetECount() - 1);
			}
			else
				++g_pTec;
		}
		for (g_pS = g_S.begin(); g_pS != g_S.end();)
		{
			if (g_pS->second.GetDepartment() == OldDep)
			{
				g_pS = g_S.erase(g_pS);
				technician.SetECount(technician.GetECount() - 1);
			}
			else
				++g_pS;
		}
		for (g_pM = g_M.begin(); g_pM != g_M.end();)
		{
			if (g_pM->second.GetDepartment() == OldDep)
			{
				g_pM = g_M.erase(g_pM);
				technician.SetECount(technician.GetECount() - 1);
			}
			else
				++g_pM;
		}
		for (g_pSM = g_SM.begin(); g_pSM != g_SM.end();)
		{
			if (g_pSM->second.GetDepartment() == OldDep)
			{
				g_pSM = g_SM.erase(g_pSM);
				technician.SetECount(technician.GetECount() - 1);
			}
			else
				++g_pSM;
		}
		technician.DeleteDep(OldDep);
		system("pause");
		break;
	case 3:
		cout << "��������Ҫ�޸ĵĲ�������:";
		cin >> OldDep;
		if (technician.Check(OldDep) == "0")
		{
			cout << "��û�иò��š�\n";
			system("pause");
			return;
		}
		cout << "���������޸ĺ�Ĳ�������:";
		cin >> NewDep;
		technician.ModifyDep(OldDep, NewDep);
		for (g_pTec = g_Tec.begin(); g_pTec != g_Tec.end();)
		{
			if (g_pTec->second.GetDepartment() == OldDep)
				g_pTec->second.SetDep(NewDep);
			else
				++g_pTec;
		}
		for (g_pS = g_S.begin(); g_pS != g_S.end();)
		{
			if (g_pS->second.GetDepartment() == OldDep)
				g_pS->second.SetDep(NewDep);
			else
				++g_pS;
		}
		for (g_pM = g_M.begin(); g_pM != g_M.end();)
		{
			if (g_pM->second.GetDepartment() == OldDep)
				g_pM->second.SetDep(NewDep);
			else
				++g_pM;
		}
		for (g_pSM = g_SM.begin(); g_pSM != g_SM.end();)
		{
			if (g_pSM->second.GetDepartment() == OldDep)
				g_pSM->second.SetDep(NewDep);
			else
				++g_pSM;
		}
		system("pause");
		break;
	case 4:
		while (choice)
		{
			system("cls");
			cout << "���в�����Ϣ����:";
			technician.BrowseDep();
			cout << "0.���ز˵�" << endl;
			cout << "������ѡ��(��ѯ�ò��ŵ���Ϣ):";
			cin >> choice;
			if (!choice)
				break;
			choice--;
			menu.OneDepartment(choice);
			choice++;
			cin >> sel;
			if (sel == 1)
				OutputByDepartment(choice);
			else if (sel == 2)
				CountByDepartment(choice);
			system("pause");
		}
		break;
	case 0:
		return;
	default:
		cout << "�������!";
		break;
	}
}
int GetDepartEmployeeNumber(int choice)
{
	int count = 0;
	for (int i = 0; i < technician.GetDCount(); i++)
	{
		if (i == choice)
		{
			for (g_pTec = g_Tec.begin(); g_pTec != g_Tec.end(); g_pTec++)
			{
				if (g_pTec->second.GetDepartment() == technician.GetDep(choice))
				{
					count++;
				}
			}
			for (g_pS = g_S.begin(); g_pS != g_S.end(); g_pS++)
			{
				if (g_pS->second.GetDepartment() == technician.GetDep(choice))
				{
					count++;
				}
			}
			for (g_pM = g_M.begin(); g_pM != g_M.end(); g_pM++)
			{
				if (g_pM->second.GetDepartment() == technician.GetDep(choice))
				{
					count++;
				}
			}
			for (g_pSM = g_SM.begin(); g_pSM != g_SM.end(); g_pSM++)
			{
				if (g_pSM->second.GetDepartment() == technician.GetDep(choice))
				{
					count++;
				}
			}
		}
	}
	return count;
}