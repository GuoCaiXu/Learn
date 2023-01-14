# include "teacher.h"

//构造函数
Teacher::Teacher() {


}

//有参构造函数
Teacher::Teacher(int empid, string name, string pwd) {

	this->m_EmpId = empid;
	this->m_Name = name;
	this->m_Pwd = pwd;
}

//菜单界面
void Teacher::operMenu() {

	system("cls");
	cout << "欢迎教师：" << this->m_Name << "登录！" << endl;
	cout << "\t\t ----------------------------------\n";
	cout << "\t\t|                                  |\n";
	cout << "\t\t|          1.查看所有预约          |\n";
	cout << "\t\t|                                  |\n";
	cout << "\t\t|          2.审核预约              |\n";
	cout << "\t\t|                                  |\n";
	cout << "\t\t|          0.注销登录              |\n";
	cout << "\t\t|                                  |\n";
	cout << "\t\t ----------------------------------\n";
	cout << "请选择您的操作： " << endl;
}

//查看所有预约
void Teacher::showAllOrder() {

	OrderFile of;
	if (of.m_Size == 0) {

		system("cls");
		cout << "\t\t ----------------------------------\n";
		cout << "\t\t|                                  |\n";
		cout << "\t\t|            无预约记录            |\n";
		cout << "\t\t|                                  |\n";
		cout << "\t\t ----------------------------------\n";
		system("pause");
		system("cls");
		return;
	}

	system("cls");
	cout << "\t\t --------------------------------------------------------------------\n";
	cout << "\t\t|                                                                    |\n";
	for (int i = 0; i < of.m_Size; i++) {

		cout << "\t\t| " << i + 1 << " ";

		cout << "  预约日期：周" << of.m_orderDate[i]["时间"];
		cout << "  时段：" << (of.m_orderDate[i]["时间段"] == "1" ? "上午" : "下午");
		cout << "  姓名：" << of.m_orderDate[i]["学生姓名"];
		cout << "  机房：" << of.m_orderDate[i]["机房编号"];
		string status = "  状态：";       //0取消预约  1审核中  2已预约  -1预约失败
		if (of.m_orderDate[i]["审核状态"] == "1") {

			status += "审核中  ";
		}
		else if (of.m_orderDate[i]["审核状态"] == "2") {

			status += "预约成功";
		}
		else if (of.m_orderDate[i]["审核状态"] == "-1") {

			status += "预约失败";
		}
		else {

			status += "预约取消";
		}
		cout << status;
		cout << " |\n";
		cout << "\t\t|                                                                    |\n";
	}
	cout << "\t\t --------------------------------------------------------------------\n";
	system("pause");
	system("cls");
}

//审核预约
void Teacher::validOrder() {

	OrderFile of;
	if (of.m_Size == 0) {

		system("cls");
		cout << "\t\t ----------------------------------\n";
		cout << "\t\t|                                  |\n";
		cout << "\t\t|            无预约记录            |\n";
		cout << "\t\t|                                  |\n";
		cout << "\t\t ----------------------------------\n";
		system("pause");
		system("cls");
		return;
	}

	system("cls");
	cout << "待审核记录如下:" << endl;

	vector<int>v;
	int index = 0;

	cout << "\t\t -----------------------------------------------------------------\n";
	cout << "\t\t|                                                                 |\n";
	for (int i = 0; i < of.m_Size; i++) {

		if (of.m_orderDate[i]["审核状态"] == "1") {

			v.push_back(i);
			cout << "\t\t|  " << ++index << " ";
			cout << "预约的日期： 周" << of.m_orderDate[i]["时间"];
			cout << "  时间段：" << (of.m_orderDate[i]["时间段"] == "1" ? "上午" : "下午");
			cout << "  机房编号：" << of.m_orderDate[i]["机房编号"];
			string status = "  状态：";
			if (of.m_orderDate[i]["审核状态"] == "1") {

				status += "审核中 ";
			}

			cout << status << "   |\n";
			cout << "\t\t|                                                                 |\n";
		}
	}

	cout << "\t\t -----------------------------------------------------------------\n";
	cout << "请输入审核的预约记录，0代表返回" << endl;
	int select;
	int ret;
	while (true) {

		cout << "输入:";
		cin >> select;
		if (select > 0 && select <= of.m_Size) {


			if (select == 0) {

				break;
			}
			else {
				system("cls");
				cout << "\t\t ----------------------------------\n";
				cout << "\t\t|                                  |\n";
				cout << "\t\t|             1.通  过             |\n";
				cout << "\t\t|                                  |\n";
				cout << "\t\t|             2.不 通  过          |\n";
				cout << "\t\t|                                  |\n";
				cout << "\t\t ----------------------------------\n";
				cout << "请输入审核结果:";
				cin >> ret;

				if (ret == 1) {

					of.m_orderDate[v[select - 1]]["审核状态"] = "2";
				}
				else {

					of.m_orderDate[v[select - 1]]["审核状态"] = "-1";
				}

				of.updateOrder();
				system("cls");
				cout << "\t\t ----------------------------------\n";
				cout << "\t\t|                                  |\n";
				cout << "\t\t|            审核完毕！            |\n";
				cout << "\t\t|                                  |\n";
				cout << "\t\t ----------------------------------\n";
				system("pause");
				system("cls");
				break;
			}
		}
			cout << "输入有误！请重新输入" << endl;
	}
}