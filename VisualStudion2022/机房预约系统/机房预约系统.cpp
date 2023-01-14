# include <iostream>
# include "identity.h"
# include "student.h"
# include "teacher.h"
# include "manager.h"
# include "orderFile.h"
using namespace std;

//管理员菜单
void managerMenu(Identity*& manager);

//学生菜单
void studentMenu(Identity*& student);

//教师菜单
void TeacherMenu(Identity*& teacher);

//登录模块
void LoginIn(string fileName, int type) {

	Identity* person = NULL;

	ifstream ifs(fileName, ios::in);

	//文件不存在
	if (!ifs.is_open()) {

		cout << "文件不存在" << endl;
		ifs.close();
		return;
	}

	int id = 0;
	string name;
	string pwd;

	//学生登录
	if (type == 1) {

		cout << "请输入你的学生学号" << endl;
		cin >> id;
	}
	//教师登录
	else if (type == 2) {

		cout << "请输入你的职工号" << endl;
		cin >> id;
	}

	cout << "请输入用户名" << endl;
	cin >> name;

	cout << "请输入密码" << endl;
	cin >> pwd;

	int fId;
	string fName;
	string fPwd;

	if (type == 1) {

		//学生登录验证
		while (ifs >> fId && ifs >> fName && ifs >> fPwd) {

			if (id == fId && name == fName && pwd == fPwd) {
				system("cls");
				cout << "\t\t ----------------------------------\n";
				cout << "\t\t|                                  |\n";
				cout << "\t\t|           学生验证成功！         |\n";
				cout << "\t\t|                                  |\n";
				cout << "\t\t ----------------------------------\n";
				system("pause");
				system("cls");
				person = new Student(id, name, pwd);
				studentMenu(person);
				return;
			}
		}
	}
	else if (type == 2) {

		//教师登录验证
		while (ifs >> fId && ifs >> fName && ifs >> fPwd) {


			if (id == fId && name == fName && pwd == fPwd) {

				system("cls");
				cout << "\t\t ----------------------------------\n";
				cout << "\t\t|                                  |\n";
				cout << "\t\t|           教师验证成功！         |\n";
				cout << "\t\t|                                  |\n";
				cout << "\t\t ----------------------------------\n";
				system("pause");
				system("cls");
				person = new Teacher(id, name, pwd);
				TeacherMenu(person);
				return;
			}
		}
	}
	else if (type == 3) {

		//管理员登录验证
		while (ifs >> fName && ifs >> fPwd) {

			if (name == fName && pwd == fPwd) {

				system("cls");
				cout << "\t\t ----------------------------------\n";
				cout << "\t\t|                                  |\n";
				cout << "\t\t|           登录验证成功！         |\n";
				cout << "\t\t|                                  |\n";
				cout << "\t\t ----------------------------------\n";
				system("pause");
				system("cls");
				person = new Manager(name, pwd);
				managerMenu(person);
				return;
			}
		}
	}

	cout << "验证登录失败!" << endl;

	system("pause");
	system("cls");
	return;
}

//管理员菜单
void managerMenu(Identity*& manager) {

	while (true) {

		//管理员菜单
		manager->operMenu();

		Manager* man = (Manager*)manager;
		int select = 0;

		cin >> select;
		system("cls");

		//添加账号
		if (select == 1) {

			man->addPerson();
		}
		//查看账号
		else if (select == 2) {

			man->showPerson();
		}
		//查看机房
		else if (select == 3) {

			cout << "查看机房" << endl;
			man->showComputer();
		}
		//清空预约
		else if (select == 4) {

			man->CleanFile();
		}
		else {
			delete manager;
			cout << "\t\t ----------------------------------\n";
			cout << "\t\t|                                  |\n";
			cout << "\t\t|            注销成功！            |\n";
			cout << "\t\t|                                  |\n";
			cout << "\t\t ----------------------------------\n";
			system("pause");
			system("cls");
			return;
		}
	}
}

//学生菜单
void studentMenu(Identity*& student) {

	while (true) {

		///学生菜单
		student->operMenu();

		Student* stu = (Student*)student;
		int select;

		cin >> select;
		system("cls");

		if (select == 1) { //申请预约

			stu->applyOrder();
		}
		else if (select == 2) { //查看目录预约

			stu->showMyOrder();
		}
		else if (select == 3) { //查看所有预约

			stu->showAllOrder();
		}
		else if (select == 4) { //取消预约

			stu->cancelOrder();
		}
		else {
			delete student;
			system("cls");
			cout << "\t\t ----------------------------------\n";
			cout << "\t\t|                                  |\n";
			cout << "\t\t|            注销成功！            |\n";
			cout << "\t\t|                                  |\n";
			cout << "\t\t ----------------------------------\n";
			system("pause");
			system("cls");
			return;
		}
	}
}

//教师菜单
void TeacherMenu(Identity*& teacher) {

	while (true) {

		//教师菜单
		teacher->operMenu();

		Teacher* tea = (Teacher*)teacher;
		int select;

		cout << "输入:";
		cin >> select;

		if (select == 1) { //查看所有预约

			tea->showAllOrder();
		}
		else if (select == 2) { //审核预约

			tea->validOrder();
		}
		else {

			delete teacher;
			system("cls");
			cout << "\t\t ----------------------------------\n";
			cout << "\t\t|                                  |\n";
			cout << "\t\t|            注销成功！            |\n";
			cout << "\t\t|                                  |\n";
			cout << "\t\t ----------------------------------\n";
			system("pause");
			system("cls");
			return;
		}
	}
}

int main() {


	int select;

	while (true) {

		cout << "================================= 欢迎来到传智播客机房预约系统====================================" << endl;
		cout << endl << "请输入你的身份:" << endl;
		cout << "\t\t-----------------------------------------------\n";
		cout << "\t\t|                                              |\n";
		cout << "\t\t|                1. 学生代表                   |\n";
		cout << "\t\t|                                              |\n";
		cout << "\t\t|                2. 老    师                   |\n";
		cout << "\t\t|                                              |\n";
		cout << "\t\t|                3. 管 理 员                   |\n";
		cout << "\t\t|                                              |\n";
		cout << "\t\t|                0. 退    出                   |\n";
		cout << "\t\t|                                              |\n";
		cout << "\t\t|                                              |\n";
		cout << "\t\t-----------------------------------------------\n";
		cout << "请输入你的选择:";
		
		cin >> select;  //接受用户选择

		switch (select) {

		case 1:  //学生身份
			LoginIn(STUDENT_FILE, 1);
			break;
		case 2:  //老师身份
			LoginIn(TEACHER_FILE, 2);
			break;
		case 3:  //管理员身份
			LoginIn(ADMIN_FILE, 3);
			break;
		case 0:  //退出程序
			cout << "欢迎下次使用！" << endl;
			system("Pause");
			system("cls");
			return 0;
			break;
		default:
			cout << "输入有误请重新输入！" << endl;
			system("pause");
			system("cls");
			break;
		}
	}

	system("pause");

	return 0;
}