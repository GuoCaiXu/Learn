# include "student.h"

//构造函数
Student::Student() {

}

//有参构造
Student::Student(int id, string name, string pwd) {

	this->m_Id = id;
	this->m_Name = name;
	this->m_Pwd = pwd;

	ifstream ifs(COMPUTER_FILE, ios::in);
	
	ComputerRoom c;
	while (ifs >> c.m_ComId && ifs >> c.m_MaxNum) {

		this->vCom.push_back(c);
	}

	ifs.close();
}

//菜单界面
void Student::operMenu() {

	cout << "欢迎学生代表：" << this->m_Name << "登录！" << endl;
	cout << "\t\t ----------------------------------\n";
	cout << "\t\t|                                  |\n";
	cout << "\t\t|          1.申请预约              |\n";
	cout << "\t\t|                                  |\n";
	cout << "\t\t|          2.查看我的预约          |\n";
	cout << "\t\t|                                  |\n";
	cout << "\t\t|          3.查看所有预约          |\n";
	cout << "\t\t|                                  |\n";
	cout << "\t\t|          4.取消预约              |\n";
	cout << "\t\t|                                  |\n";
	cout << "\t\t|          0.注销登录              |\n";
	cout << "\t\t|                                  |\n";
	cout << "\t\t ----------------------------------\n";
	cout << "请选择您的操作： ";
}

//申请预约
void Student::applyOrder() {

	    int date;
		int interval;
		int room;

	while (true) {
		cout << "机房开发时间为周一到周五!" << endl;
		cout << "\t\t ----------------------------------\n";
		cout << "\t\t|                                  |\n";
		cout << "\t\t|                                  |\n";
		cout << "\t\t|            1.周  一              |\n";
		cout << "\t\t|                                  |\n";
		cout << "\t\t|            2.周  二              |\n";
		cout << "\t\t|                                  |\n";
		cout << "\t\t|            3.周  三              |\n";
		cout << "\t\t|                                  |\n";
		cout << "\t\t|            4.周  四              |\n";
		cout << "\t\t|                                  |\n";
		cout << "\t\t|            5.周  五              |\n";
		cout << "\t\t|                                  |\n";
		cout << "\t\t ----------------------------------\n";
		cout << "请输入申请预约的时间: ";


			cin >> date;
			if (date >= 1 && date <= 5) {

				break;
				system("cls");
			}

			cout << "输入有误，请重新输入" << endl;
			system("pause");
			system("cls");
	}

	while (true) {

		system("cls");
		cout << "请输入申请预约时间段:" << endl;
		cout << "\t\t ----------------------------------\n";
		cout << "\t\t|                                  |\n";
		cout << "\t\t|                                  |\n";
		cout << "\t\t|            1.上  午              |\n";
		cout << "\t\t|                                  |\n";
		cout << "\t\t|            2.下  午              |\n";
		cout << "\t\t|                                  |\n";
		cout << "\t\t ----------------------------------\n";

		cout << "输入:";
		cin >> interval;
		if (interval >= 1 && interval <= 2) {

			break;
		}

		cout << "输入错误！请重新输入" << endl;
		system("pause");
	}

	system("cls");
	while (true) {
		cout << "请选择机房:" << endl;
		cout << "\t\t ----------------------------------\n";
		cout << "\t\t|                                  |\n";
		cout << "\t\t|      1号机房的容量：" << this->vCom[0].m_MaxNum << "           | \n";
		cout << "\t\t|                                  |\n";
		cout << "\t\t|      2号机房的容量：" << this->vCom[1].m_MaxNum << "           | \n";
		cout << "\t\t|                                  |\n";
		cout << "\t\t|      3号机房的容量：" << this->vCom[2].m_MaxNum << "           | \n";
		cout << "\t\t|                                  |\n";
		cout << "\t\t ----------------------------------\n";

		cout << "输入:";
		cin >> room;

		if (room >= 1 && room <= 3) {

			break;
			system("cls");
		}

		cout << "输入有误！请重新输入" << endl;
		system("pause");
		system("cls");

	}

	system("cls");
	cout << "\t\t ----------------------------------\n";
	cout << "\t\t|                                  |\n";
	cout << "\t\t|        预约成功！审核中          |\n";
	cout << "\t\t|                                  |\n";
	cout << "\t\t ----------------------------------\n";

	ofstream ofs(ORDER_FILE, ios::app);
	ofs << "时间:" << date << " ";
	ofs << "时间段:" << interval << " ";
	ofs << "学生编号:" << this->m_Id << " ";
	ofs << "学生姓名:" << this->m_Name << " ";
	ofs << "机房编号:" << room << " ";
	ofs << "审核状态:" << 1 << endl;

	ofs.close();

	system("pause");
	system("cls");
}

//查看我的预约
void Student::showMyOrder() {

	OrderFile of;
	if (of.m_Size == 0) {

		cout << "\t\t ----------------------------------\n";
		cout << "\t\t|                                  |\n";
		cout << "\t\t|            无预约记录!           |\n";
		cout << "\t\t|                                  |\n";
		cout << "\t\t ----------------------------------\n";
		system("pause");
		system("cls");
		return;
	}

	cout << "\t\t ----------------------------------------------------\n";
	cout << "\t\t|                                                    |\n";
	for (int i = 0; i < of.m_Size; i++) {

		if (atoi(of.m_orderDate[i]["学生编号"].c_str()) == this->m_Id) {

			cout << "\t\t| 预约日期：周" << of.m_orderDate[i]["时间"];
			cout << "  时段：" << (of.m_orderDate[i]["时间段"] == "1" ? "上午" : "下午");
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
			cout << "\t\t|                                                    |\n";
		}
	}
	cout << "\t\t ----------------------------------------------------\n";
	system("pause");
	system("cls");
}

//查看所有预约
void Student::showAllOrder() {

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

//取消预约
void Student::cancelOrder() {

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

	cout << "审核中或预约成功的记录可以取消，请输入取消的记录" << endl;
	vector<int>v; //存放最大容器中的下标编号
	int index = 1;

	cout << "\t\t -----------------------------------------------------------------\n";
	cout << "\t\t|                                                                 |\n";
	for (int i = 0; i < of.m_Size; i++) {

		//先判断是自身学号
		if (this->m_Id == atoi(of.m_orderDate[i]["学生编号"].c_str())) {  //atio()把读取的strig学生编号转化为int 类型

			//再筛选状态  审核中或预约成功
			if (of.m_orderDate[i]["审核状态"] == "1" || of.m_orderDate[i]["审核状态"] == "2") {

				v.push_back(i);
				cout << "\t\t|  " << index++ << " ";
				cout << "预约的日期： 周" << of.m_orderDate[i]["时间"];
				cout << "  时间段：" << (of.m_orderDate[i]["时间段"] == "1" ? "上午" : "下午");
				cout << "  机房编号：" << of.m_orderDate[i]["机房编号"];
				string status = "  状态：";
				if (of.m_orderDate[i]["审核状态"] == "1") {

					status += "审核中 ";
				}
				else if (of.m_orderDate[i]["审核状态"] == "2") {

					status += "预约成功";
				}

				cout << status << "   |\n";
				cout << "\t\t|                                                                 |\n";
			}
		}
	}
	cout << "\t\t -----------------------------------------------------------------\n";

	cout << "请输入取消的记录，0代表返回" << endl;
	int select = 0;

	while (true) {

		cout << "输入:";
		cin >> select;

		if (select >= 0 && select <= of.m_Size) {

			if (select == 0) {

				break;
			}
			else {

				of.m_orderDate[v[select - 1]]["审核状态"] = "0";

				of.updateOrder();

				cout << "\t\t ----------------------------------\n";
				cout << "\t\t|                                  |\n";
				cout << "\t\t|            已取消预约！          |\n";
				cout << "\t\t|                                  |\n";
				cout << "\t\t ----------------------------------\n";
				break;
			}
		}

		cout << "输入有误! 请重新输入" << endl;
	}

	system("pause");
	system("cls");
}