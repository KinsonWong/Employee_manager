#include "stdafx.h"
#include "background_h.h"
static int g_iSize = 0;						
extern Technician technician;
map<int, Technician> g_Tec;					//技术员g_Tec				
map<int, Saler> g_S;						//销售员g_S					
map<int, Manager> g_M;						//经理g_M
map<int, SalerManager> g_SM;				//销售经理g_SM

map<int, Technician>::iterator g_pTec;		//技术员迭代器g_pTec		 
map<int, Saler>::iterator g_pS;				//销售员迭代器g_pS
map<int, Manager>::iterator g_pM;			//经理迭代器g_pM
map<int, SalerManager>::iterator g_pSM;		//销售经理迭代器g_pSM

map<int, string> g_dep;						//部门容器
vector<int> g_iIter;						//存储工号				
vector<int>::iterator g_piIter;				//存储工号的迭代器
vector<float> g_fIter;						//储存全部员工工资
vector<float>::iterator g_pfIter;			//储存全部员工工资的迭代器
vector<float> g_fTec;						//储存技术员的工资
vector<float> g_fS;							//储存销售员的工资
vector<float> g_fM;							//储存经理的工资
vector<float> g_fSM;						//储存销售经理的工资
int g_sel;									//选项
bool CmpNum(const int &nFirst, const int &nSecond)
{
	if (nFirst < nSecond) //由小到大排序		
		return true;
	return false;
}
bool CmpSalary(const float &nFirst, const float &nSecond)
{
	if (nFirst > nSecond) //由大到小排序	
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

/*将文件读取到对应的容器中*/
void Background::Load()			
{
	int length = 0;
	ifstream fread_tec("Technician.txt");
	ifstream fread_s("Saler.txt");
	ifstream fread_m("Manager.txt");
	ifstream fread_sm("SalerManager.txt");
	ifstream fread_dep("Department.txt");
	if (!fread_tec)						
		cout << "Technician.txt" << "文件打开失败" << endl;
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
		cout << "Saler.txt" << "文件打开失败" << endl;
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
		cout << "Manager.txt" << "文件打开失败" << endl;
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
		cout << "SalerManager.txt" << "文件打开失败" << endl;
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
		cout << "Department.txt" << "文件打开失败" << endl;
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

/*将数据保存到文件中*/
void Background::Save()	
{
	ofstream fwrite_tec("Technician.txt");
	ofstream fwrite_s("Saler.txt");
	ofstream fwrite_m("Manager.txt");
	ofstream fwrite_sm("SalerManager.txt");
	ofstream fwrite_dep("Department.txt");
	if (!fwrite_tec)						
		cout << "Technician.txt" << "文件打开失败" << endl;
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
		cout << "Saler.txt" << "文件打开失败" << endl;
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
		cout << "Manager.txt" << "文件打开失败" << endl;
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
		cout << "SalerManager.txt" << "文件打开失败" << endl;
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
		cout << "Department.txt" << "文件打开失败" << endl;
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

/*启动函数*/
void Background::Run()		
{
	string na;				//姓名
	int num = -1;				//工号
	int sel, sel_1 = 1, sel_2 = 1, sel_3 = 1, sel_4, sel_5, sel_6 = 1;
	int choice;
	char ch_1 = 'Y', ch_2 = 'Y';

	if (!g_iSize)				//没有员工数据
	{
		cout << "还没有员工数据！清先添加至少1名员工!" << endl;
		cout << "现有的部门有:";
		for (int i = 0; i < technician.GetDCount(); i++)
			cout << "    " << technician.GetDep(i);
		cout << "\n\n";
		Add();
	}

	do
	{
		menu.Show();					
		cout << "请输入选项:";
		cin >> sel;
		switch (sel)
		{
		case 1:							//员工管理
		FIRST :
			menu.ManageShow();
			  cout << "请输入选项:";
			  cin >> g_sel;
			  switch (g_sel)
			  {
			  case 1:						//添加员工信息
				  Add();
				  break;
			  case 2:						//修改员工信息
				  cout << "请输入你要修改的员工的工号!" << endl;
				  cin >> num;
				  choice = Search("0", num);
				  if (choice == 0)
				  {
					  cout << "没有该工号的员工!\n";
					  break;
				  }
				  SearchModify(choice, "0", num);
				  break;
			  case 3:						//删除员工信息
				  cout << "请输入你要删除的员工的工号!" << endl;
				  cin >> num;
				  Delete(num);
				  break;
			  case 4:						//计算技术员当月工资
				  CountSalary(1);
				  break;
			  case 5:						//计算销售员、销售经理当月工资
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

		case 2://查询管理
		SECOND :
			menu.SearchShow();
			   cout << "请输入选项:";
			   cin >> g_sel;
			   switch (g_sel)
			   {
			   case 1:
				   AllOutput();						//工号升序输出员工信息
				   break;
			   case 2:
				   while (sel_1)
				   {
					   menu.InquireShowByDepartment();		//按部门输出员工信息
					   cout << "请输入选项:";
					   cin >> sel_1;
					   OutputByDepartment(sel_1);			//按部门输出员工
					   system("pause");
				   }
				   break;
			   case 3:
				   while (sel_2)
				   {
					   menu.InquireShowByJob();			//按岗位输出员工信息
					   cout << "请输入选项:";
					   cin >> sel_2;
					   OutputByJob(sel_2);					//按岗位输出员工
					   system("pause");
				   }
				   break;
			   case 4:
				   ch_1 = 'y';
				   while (ch_1 == 'y' || ch_1 == 'Y')
				   {
					   cout << "请输入要查找的员工工号：" ;//按工号查找员工信息
					   cin >> num;
					   if (!Search("", num))
						   cout << "没有该工号的员工\n";
					   cout << "是否继续查询(Y/N)?\n";
					   cin >> ch_1;
				   }
				   break;
			   case 5:									//按姓名查找员工信息
				   ch_2 = 'y';
				   while (ch_2 == 'y' || ch_2 == 'Y')
				   {
					   cout << "请输入要查找的员工姓名!" << endl;
					   cin >> na;
					   if (!Search(na, 0))
						   cout << "没有该姓名的员工\n";
					   cout << "是否继续查询(Y/N)?\n";
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

		case 3://排序管理
		THIRD :
			menu.SortShow();
			  cout << "请输入选项:";
			  cin >> g_sel;
			  switch (g_sel)
			  {
			  case 1:
				  TotalSalaryDown();					//全体员工按工资排序员工信息
				  break;
			  case 2:
				  sel_3 = 1;
				  while (sel_3)
				  {
					  menu.SortShowByJob();				//排序某岗位的员工工资从高到低
					  cout << "请输入选项:";
					  cin >> sel_3;
					  JobSalaryDown(sel_3);				//各个岗位工资降序输出
				  }
				  break;
			  default:
				  break;
			  }
			  if (g_sel != 0)
				  goto THIRD;
			  break;

		case 4://统计管理
		FOURTH1 :
			SortBySalary();
				menu.CountShow();
				cout << "请输入选项:";
				cin >> g_sel;
				switch (g_sel)
				{
				case 1:
					sel_5 = 1;
					while (sel_5)
					{
						menu.CountShowByDepartment();		//部门统计员工信息
						cout << "请输入选项:";
						cin >> sel_5;
						if (!sel_5)
							break;
						CountByDepartment(sel_5);
						system("pause");
					}
					break;
				case 2:
				FOURTH2 :
					menu.CountShowByTotal();			//全体员工统计员工信息
						cout << "请输入选项:";
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
				cout << "请输入选项:";
				cin >> sel_6;
				DepartmentManager(sel_6);
			}
			break;
		default:
			break;
		}
	} while (sel);
}
/*添加员工信息*/
void Background::Add()
{
	int flag = 1;
	char ch;
	cout << "1.技术员  2.销售员  3.经理  4.销售经理  0.返回" << endl;
	cout << "请输入选项:";
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
				cout << "添加失败！该部门已经存在销售经理了!" << endl;
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
		cout << "输入错误!\n";
		break;
	}
	if (g_sel&&flag)
		cout << "添加成功!" << endl;
	cout << "是否继续添加(Y/N)?\n";
	cin >> ch;
	if (ch == 'y' || ch == 'Y')
		Add();
	else
		return;
}

/*按工号删除员工信息*/
void Background::Delete(int num)
{
	int sel;
	sel = Search("0", num);
	if (sel == 1)
	{
		g_Tec.erase(num);
		cout << "删除成功!" << endl;
	}
	else if (sel == 2)
	{
		g_S.erase(num);
		cout << "删除成功!" << endl;
	}
	else if (sel == 3)
	{
		g_M.erase(num);
		cout << "删除成功!" << endl;
	}
	else if (sel == 4)
	{
		g_SM.erase(num);
		cout << "删除成功!" << endl;
	}
	else
		cout << "没有该工号的员工!" << endl;
}

/*按工号查找后修改员工信息*/
template <class T>
int Background::Modify(T &type)
{
	string name = "", sex = "", depart = "", job = "";
	int age;
	float salary;
	cout << "工号 " << "1.姓名" << " 2.性别" << " 3.年龄" << " 4.部门" << " 5.岗位" << " 6.工时" << ' ' << " 7.销售额度/8.总销售额度"" 9.工资" << endl;
	cout << "请输入要修改的选项(工号不可修改):";
	cin >> g_sel;
	switch (g_sel)
	{
	case 1:
		cout << "请输入修改后的姓名:";
		cin >> name;
		type.SetName(name);
		break;
	case 2:
		cout << "请输入修改后的性别:";
		cin >> sex;
		type.SetSex(sex);
		break;
	case 3:
		cout << "请输入修改后的年龄:";
		cin >> age;
		type.SetAge(age);
		break;
	case 4:
		cout << "请输入修改后的部门:";
		cin >> depart;
		type.SetDep(depart);
		break;
	case 5:
		cout << "请输入修改后的岗位:";
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
		cout << "请输入修改后的工资:";
		cin >> salary;
		type.SetSalary(salary);
	case 0:
		return 0;
	default:
		cout << " 输入错误!\n";
		break;
	}
	if (g_sel == 6)
		return 1;
	else if (g_sel == 7)
		return 2;
	else if (g_sel == 8)
		return 3;
	cout << "修改后的信息为:\n";
	cout << " 工 号 " << " 姓 名  " << "性 别 " << " 年 龄" << "    部 门" << "     岗 位" << "    工 时" << "  销售额度" << "     工  资" << endl;
	cout << "------------------------------------------------------------------------------\n";
	cout << type;
	return 0;
}

/*批量计算技术员当月工资*/
void Background::CountSalary(int flag)		
{
	float hours;					
	float balance;					
	float total = 0;				//部门总销售额度
	if (flag == 1)
	{
		for (g_pTec = g_Tec.begin(); g_pTec != g_Tec.end(); g_pTec++)	//遍历技术员
		{
			if (g_pTec->second.GetSalary() == 0)
			{
				g_pTec->second.Output();
				cout << "情输入该员工的工时:";
				cin >> hours;
				g_pTec->second.SetHours(hours);					
				g_pTec->second.SetSalary((float)hours * 100);	//计算技术员工资
				cout << "计算成功!\n是否继续计算!是请按1,否请按0。" << endl;
				cin >> g_sel;
				if (g_sel)
					continue;		
				else
					break;
			}
		}
		if (g_pTec == g_Tec.end())
			cout << "所有技术员的工资计算成功\n";
	}
	else if (flag == 0)
	{
		for (g_pS = g_S.begin(); g_pS != g_S.end(); g_pS++)	//遍历销售员
		{
			if (g_pS->second.GetSalary() == 0)
			{
				g_pS->second.Output();
				cout << "情输入该员工的销售额度:";
				cin >> balance;
				g_pS->second.SetBalance(balance);							
				g_pS->second.SetSalary((float)(balance * 0.04));		//计算销售员工资
				cout << "计算成功!是否继续计算!是请按1,否请按0。" << endl;
				cin >> g_sel;
				if (g_sel)
					continue;
				else
					break;
			}

		}
		if (g_pS == g_S.end())
			cout << "所有销售员的工资计算成功!" << endl;
	}
	if (flag == 0)			
	{
		if (g_pS == g_S.end())
		{
			for (g_pSM = g_SM.begin(); g_pSM != g_SM.end(); g_pSM++)		//	遍历销售经理
			{
				for (g_pS = g_S.begin(); g_pS != g_S.end(); g_pS++)     	//遍历销售员
				{
					if (g_pSM->second.GetDepartment() == g_pS->second.GetDepartment())  
						total += g_pS->second.GetSalary();
					g_pSM->second.SetSalary((float)(total*0.005)+5000);					//计算销售经理工资		
					g_pSM->second.SetTotal(total);
				}
			}
		}
	}
}

/*输出全部员工信息*/
void Background::AllOutput()
{
	int i = 0;
	SortByNum();
	if (g_Tec.size() == 0 && g_S.size() == 0 && g_M.size() == 0 && g_SM.size() == 0)
	{
		cout << "还没有员工信息!" << endl;
		return;
	}                           
	cout << " 工 号 " << " 姓 名  " << "性 别 " << " 年 龄" << "    部 门" << "     岗 位" << "    工 时" << "  销售额度" << "     工  资" << endl;
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
/*按部门输出员工*/
void Background::OutputByDepartment(int choice)
{
	choice--;
	if (choice<0 || choice>technician.GetDCount())
		return;
	system("cls");
	cout << " 工 号 " << " 姓 名  " << "性 别 " << " 年 龄" << "    部 门" << "     岗 位" << "    工 时" << "  销售额度" << "     工  资" << endl;
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

/*按岗位输出员工*/
void Background::OutputByJob(int choice)
{
	if (choice == 0)
		return;
	cout << " 工 号 " << " 姓 名  " << "性 别 " << " 年 龄" << "    部 门" << "     岗 位" << "    工 时" << "  销售额度" << "     工  资" << endl;
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
	cout << " 工 号 " << " 姓 名  " << "性 别 " << " 年 龄" << "    部 门" << "     岗 位" << "    工 时" << "  销售额度" << "     工  资" << endl;
}

/*按姓名/工号查找员工信息*/
int Background::Search(string na, int num)			
{
	cout << " 工 号 " << " 姓 名  " << "性 别 " << " 年 龄" << "    部 门" << "     岗 位" << "    工 时" << "  销售额度" << "     工  资" << endl;
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
/*查找员工信息并输出*/
void Background::SearchModify(int choice, string name, int num)
{
	float hours = 0;
	float balance = 0;
	float total = 0;
	int i;
	if (num != 0)
	{
		if (!choice)
			cout << "没有该姓名的员工" << endl;
		else if (choice == 1)
		{

			g_pTec = g_Tec.find(num);
			i = Modify(g_pTec->second);
			if (i == 1)
			{
				cout << "请输入你要修改后的时间:";
				cin >> hours;
				g_pTec->second.SetHours(hours);
			}
			if (i != 0 && i != 1)
				cout << "技术员没有该项信息!" << endl;
		}
		else if (choice == 2)
		{
			g_pS = g_S.find(num);
			i = Modify(g_pS->second);
			if (i == 2)
			{
				cout << "请输入你要修改后的额度:";
				cin >> hours;
				g_pS->second.SetBalance(balance);
			}
			if (i != 0 && i != 2)
				cout << "销售员没有该项信息!" << endl;
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
				cout << "请输入你要修改后的总销售额度:";
				cin >> total;
				g_pSM->second.SetTotal(total);
			}
			if (i != 0 && i != 3)
				cout << "销售经理没有该项信息!" << endl;
		}
	}
}
/*各个岗位工资降序输出*/
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
		cout << "还没有员工信息!" << endl;
		return;
	}
	cout << " 工 号 " << " 姓 名  " << "性 别 " << " 年 龄" << "    部 门" << "     岗 位" << "    工 时" << "  销售额度" << "     工  资" << endl;
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

/*全体员工按工资降序输出*/
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
	cout << " 工 号 " << " 姓 名  " << "性 别 " << " 年 龄" << "    部 门" << "     岗 位" << "    工 时" << "  销售额度" << "     工  资" << endl;
	cout << "------------------------------------------------------------------------------\n";
	TecTemp.insert(g_Tec.begin(), g_Tec.end());
	STemp.insert(g_S.begin(), g_S.end());
	MTemp.insert(g_M.begin(), g_M.end());
	SMTemp.insert(g_SM.begin(), g_SM.end());

	if (TecTemp.size() == 0 && STemp.size() == 0 && MTemp.size() == 0 && SMTemp.size() == 0)
	{
		cout << "还没有员工信息!" << endl;
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

/*统计全体员工的最高与最低工资*/
void Background::CountUpAndDown()
{
	SortBySalary();
	vector<float>::iterator max = max_element(g_fIter.begin(), g_fIter.end());
	vector<float>::iterator min = min_element(g_fIter.begin(), g_fIter.end());
	cout << "最高工资为:" << *max << "    " << "最低工资为:" << *min << endl;
	cout << "全体员工中最高工资和最低工资的员工信息如下:\n";
	cout << " 工 号 " << " 姓 名  " << "性 别 " << " 年 龄" << "    部 门" << "     岗 位" << "    工 时" << "  销售额度" << "     工  资" << endl;
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

/*统计全体员工的平均工资 并显示超过平均工资的员工信息*/
void Background::CountAverage()
{
	SortBySalary();
	float sum = 0;
	for (int i = 0; i < g_fIter.size(); i++)
		sum += g_fIter[i];
	float average = sum / g_fIter.size(); 
	cout << "全体员工的平均工资为:" << average << endl;
	cout << "超出全体员工平均工资的员工有如下:\n";
	cout << " 工 号 " << " 姓 名  " << "性 别 " << " 年 龄" << "    部 门" << "     岗 位" << "    工 时" << "  销售额度" << "     工  资" << endl;
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
			if (g_pTec->second.GetSalary() >= max)					//最高工资
				max = g_pTec->second.GetSalary();
			if (g_pTec->second.GetSalary() <= min)					//最低工资
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
	cout << technician.GetDep(choice) << ":最高工资为:" << max << "   最低工资为:" << min << endl;
	average = sum / technician.GetECount(); 
	cout << technician.GetDep(choice) << "的平均工资为:" << average << endl;
	cout << "在" << technician.GetDep(choice) << "中超出平均工资的员工如下:\n";
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
	cout << "超出平均工资的员工有" << count << "人。\n";
}
/*全体按员工工号排序*/
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
	sort(g_iIter.begin(), g_iIter.end(), CmpNum);			//排序升序
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
	sort(g_fIter.begin(), g_fIter.end(), CmpSalary);			//排序降序
}
void Background::DepartmentManager(int choice)
{
	string OldDep, NewDep;
	int sel = 0;
	switch (choice)
	{
	case 1:
		cout << "请输入你要添加的部门名称:";
		cin >> NewDep;
		technician.AddDep(NewDep);
		system("pause");
		break;
	case 2:
		cout << "请输入你要删除的部门名称:";
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
		cout << "请输入你要修改的部门名称:";
		cin >> OldDep;
		if (technician.Check(OldDep) == "0")
		{
			cout << "还没有该部门。\n";
			system("pause");
			return;
		}
		cout << "请输入你修改后的部门名称:";
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
			cout << "所有部门信息如下:";
			technician.BrowseDep();
			cout << "0.返回菜单" << endl;
			cout << "请输入选项(查询该部门的信息):";
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
		cout << "输入错误!";
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