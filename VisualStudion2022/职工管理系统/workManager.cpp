# include "workManger.h"

//构造函数
WorkManager::WorkManager() {

	//1.文件不存在
	
	ifstream ifs;
	ifs.open(FILENAME, ios::in);  //读文件

	if (!ifs.is_open()) {
		//初始化属性
		//初始化记录的人数
		this->m_EmpNum = 0;
		//初始化数组指针
		this->m_EmpArray = NULL;
		//初始化文件是否为空
		this->m_FileIsEmpyty = true;
		ifs.close();
		return;
	}
	//文件已存在， 并且没有记录
	char ch;
	ifs >> ch;
	if (ifs.eof()) {
		this->m_EmpNum = 0;
		this->m_EmpArray = NULL;
		this->m_FileIsEmpyty = true;
		ifs.close();
		return;
	}

	//3.文件存在， 并且记录数据
	int num = this->get_EmpNum();
	this->m_EmpNum = num;

	this->m_EmpArray = new Worker * [this->m_EmpNum];
	//将文件的数据， 存到数组中
	this->inti_Emp();
}

//展示菜单
void WorkManager::Show_Menu() {
	cout << "**************************************************" << endl;
	cout << "**************欢迎使用职工管理系统！**************" << endl;
	cout << "**************** 0.退出管理系统 ******************" << endl;
	cout << "**************** 1.增加职工信息 ******************" << endl;
	cout << "**************** 2.显示职工信息 ******************" << endl;
	cout << "**************** 3.删除离职职工 ******************" << endl;
	cout << "**************** 4.修改职工信息 ******************" << endl;
	cout << "**************** 5.查找职工信息 ******************" << endl;
	cout << "**************** 6.按照编号排序 ******************" << endl;
	cout << "**************** 7.清空所有文档 ******************" << endl;
	cout << "**************************************************" << endl;
}

//退出系统
void WorkManager::ExitSystem() {
	cout << endl;
	cout << "欢迎下次使用！" << endl;
	system("Pause");
	exit(0);
}

//添加职工人数
void WorkManager::Add_Emp() {

	cout << "请输入添加的职工的数量:" << endl;

	int addNum = 0;//保存用户的输入数量
	cin >> addNum;

	if (addNum > 0) {
		//添加
		//计算添加的新的空间大小
		int newSize = this->m_EmpNum + addNum; //新空间人数 = 原来记录人数 + 
		//开辟新空间
		Worker ** newSpace = new Worker* [newSize];

		//将原来空间下数据， 拷贝到新空间下
		if (this->m_EmpNum != NULL) {
			for (int i = 0; i < this->m_EmpNum; i++) {

				newSpace[i] = this->m_EmpArray[i];
			}
		}

		//批量添加新的数据
		for (int i = 0; i < addNum; i++) {
			int id;//职工编号
			string name;//职工姓名
			int dSelect;//部门选择

			//判断编号是否重复
			int ID[100];
			bool flag = true;
			int num = 0;

			while (true) {
				cout << "请输入第" << i + 1 << "个新职工编号：" << endl;
				cin >> id;
				int ret = this->IsExist(id);

				//判断输入的编号是否重复
				for (int j = 0; j < 100; j++) {
					if (ID[j] == id) {
						flag = false;
					}
				}

				if (ret == -1 && flag == true) {
					break;
				}
				else {
					cout << "输入职工编号重复请重新输入!" << endl;
					cout << endl;
					flag = true;
				}
			}

			//收集输入的编号来判断
			ID[num] = id;
			num++;

			cout << "请输入第" << i + 1 << "个新职工姓名：" << endl;
			cin >> name;

			cout << "请选择该职工的岗位:" << endl;
			cout << "1.普通职工" << endl;
			cout << "2.经理" << endl;
			cout << "3.老板" << endl;
			cin >> dSelect;

			Worker* worker = NULL;
			switch (dSelect) {
			case 1:
				worker = new Employee(id, name, 1);
				break;
			case 2:
				worker = new Manager(id, name, 2);
				break;
			case 3:
				worker = new Boss(id, name, 3);
				break;
			}
			//将创建职工， 保存到数组中
			newSpace[this->m_EmpNum + i] = worker;

		}

		//释放空间
		delete[] this->m_EmpArray;

		//更改新空间的指向
		this->m_EmpArray = newSpace;

		//更新新的职工人数
		this->m_EmpNum = newSize;

		//更新职工不为空的标志
		this->m_FileIsEmpyty = false;

		//提示添加成功
		cout << "成功添加" << addNum << "名职工!" << endl;
		//保存到文件中
		this->save();
	}
	else {
		cout << "输入数据有误!" << endl;
	}

	//按任意键后 清屏回到上级目录
	system("pause");
	system("cls");
}

//保存数据到文件
void WorkManager::save() {

	ofstream ofs;
	ofs.open(FILENAME, ios::out);  //用输出的方式打开文件 --写文件

	for (int i = 0; i < this->m_EmpNum; i++) {
		ofs << this->m_EmpArray[i]->m_Id << " "
			<< this->m_EmpArray[i]->m_Name << " "
			<< this->m_EmpArray[i]->m_DeptId << endl;
	}

	ofs.close();
}

//获取记录职工人数
int WorkManager::get_EmpNum() {
	ifstream ifs;
	ifs.open(FILENAME, ios::in);

	int id;
	string name;
	int dId;

	int num = 0;

	while (ifs >> id && ifs >> name && ifs >> dId) {
		//统计人数
		num++;
	}
	ifs.close();

	return num;
}

//初始化员工
void WorkManager::inti_Emp() {
	ifstream ifs;
	ifs.open(FILENAME, ios::in);

	int id;
	string name;
	int dId;

	int index = 0;
	while (ifs >> id && ifs >> name && ifs >> dId) {
		Worker * worker = NULL;
		//根据不同的部门Id创建不同对象
		if (dId == 1) { // 普通员工
			worker = new Employee(id, name, dId);
		}else if (dId == 2) { //经理
			worker = new Manager(id, name, dId);
		}
		else{ //总裁
			worker = new Boss(id, name, dId);
		}
		//存放在数组中
		this->m_EmpArray[index] = worker;
		index++;
	}

	ifs.close();
}

//显示职工
void WorkManager::Show_Emp() {
	if (this->m_FileIsEmpyty) {
		cout << "文件不存在！" << endl;
	}else {

		for (int i = 0; i < this->m_EmpNum; i++) {
			//利用多态调用接口
			this->m_EmpArray[i]->showInfo();
			cout << endl;
		}
	}
	if (this->m_EmpNum == 0) {
		cout << "文件为空!" << endl;
	}

	system("Pause");
	system("cls");
}

//删除职工
void WorkManager::Del_Emp() {
	if (this->m_FileIsEmpyty) {
		cout << "文件不存在或记录为空！" << endl;
	}else {
		//按照职工编号删除职工
		cout << "请输入想要删除职工的编号:" << endl;
		int id = 0;
		cin >> id;
		
		int index = this->IsExist(id);

		if (index != -1) {//职工存在并且要删除掉index位置上的职工
			for (int i = index; i < this->m_EmpNum - i; i++) {
				//数据前移
				this->m_EmpArray[i] = this->m_EmpArray[i + 1];
			}
			this->m_EmpNum--;//更新数组中记录人员个数
			//数据同步更新到文件中
			this->save();
			 
			cout << "删除成功！" << endl;
		}
		else {
			cout << "删除失败， 为找到该职工!" << endl;
		}
	}

	//按任意键清屏
	system("pause");
	system("cls");
}

//修改职工
void WorkManager::Mod_Emp() {
	if (this->m_FileIsEmpyty) {
		cout << "文件不存在或记录为空！" << endl;
	}
	else {
		cout << "请输入修改职工的编号:" << endl;
		int id;
		cin >> id;

		int ret = this->IsExist(id);
		if (ret != -1) {
			//查找到编号职工
			delete this->m_EmpArray[ret];

			int newId = 0;
			string newName = "";
			int dselect = 0;

			cout << "查到" << id << "号职工， 请输入新职工号:" << endl;
			cout << "输入:";
			cin >> newId;

			cout << "请输入新的姓名:" << endl;
			cout << "输入:";
			cin >> newName;

			cout << "请输入岗位:" << endl;
			cout << "1.普通职工" << endl;
			cout << "2.经理" << endl;
			cout << "3.老板" << endl;
			cout << "输入:";
			cin >> dselect;

			Worker* worker = NULL;
			switch (dselect) {
			case 1:
				worker = new Employee(newId, newName, dselect);
				break;
			case 2:
				worker = new Manager(newId, newName, dselect);
				break;
			case 3:
				worker = new Boss(newId, newName, dselect);
				break;
			default:
				break;
			}

			//更新数据 到数组中
			this->m_EmpArray[ret] = worker;

			cout << "修改成功！" << this->m_EmpArray[ret]->m_DeptId << endl;

			//保存到文件中
			this->save();
		}
		else {
			cout << "修改失败！ 查无此人" << endl;
		}
	}
	system("pause");
	system("cls");
}

//按照职工编号判断职工是否存在， 若存在返回职工在数组中位置， 不存在返回-1
int WorkManager::IsExist(int id){
	int index = -1;

	for (int i = 0; i < this->m_EmpNum; i++) {
		if (this->m_EmpArray[i]->m_Id == id) {
			//找到职工
			index = i;

			break;
		}
	}

	return index;
}

//查找职工
void WorkManager::Find_Emp() {
	if (this->m_FileIsEmpyty) {
		cout << "文件不存在或记录为空！" << endl;
	}
	else {
		cout << "请选择查找的方式:" << endl;
		cout << "1.按照职工编号查找" << endl;
		cout << "2.按姓名查找" << endl;

		string select = "";
		cin >> select;

		if (select == "1") { //按照职工号查找
			int id;
			cout << "请输入查找的职工编号:" << endl;
			cout << "输入:";
			cin >> id;

			int ret = this->IsExist(id);
			if (ret != -1) {
				cout << "查找成功， 职工编号为：" << endl;
				this->m_EmpArray[ret]->showInfo();
			}
			else {
				cout << "查找失败， 查无此人！" << endl;
			}
		}
		else if (select == "2") { //按照姓名查找
			string name;
			cout << "请输入查找职工的姓名:" << endl;
			cout << "输入:";
			cin >> name;

			bool flag = false;//查找到的标志
			for (int i = 0; i < m_EmpNum; i++) {
				if (m_EmpArray[i]->m_Name == name) {
					cout << endl;
					cout << "查找成功， 职工编号为:"
						<< m_EmpArray[i]->m_Id
						<< "的职工信息如下:" << endl;

					flag = true;
					this->m_EmpArray[i]->showInfo();
				}
			}
			if (flag == false) {
				//查无此人
				cout << "查找失败， 查无此人!" << endl;
			}
		}
		else {
			cout << "输入选项有误！" << endl;
		}
	}
	
	system("pause");
	system("cls");
}

//排序职工
void WorkManager::Sort_Emp() {

	if (this->m_FileIsEmpyty) {

		cout << "文件不存在或记录为空!" << endl;
		system("pause");
		system("cls");
	}
	else {
		cout << "请选择排序方式:" << endl;
		cout << "1.按职工号升序" << endl;
		cout << "2.按职工号降序" << endl;

		string select = "";
		cin >> select;

		for (int i = 0; i < m_EmpNum; i++) {

			int minOrMax = i;//声明最小值 或 最大值下标
			for (int j = i + 1; j < m_EmpNum; j++) {

				if (select == "1") { //升序

					if (m_EmpArray[minOrMax]->m_Id > m_EmpArray[j]->m_Id) {

						minOrMax = j;
					}
				}
				if (select == "2") {//降序

					if (m_EmpArray[minOrMax]->m_Id < m_EmpArray[j]->m_Id) {
						minOrMax = j;
					}
				}
			}

			if (i != minOrMax) {
				Worker* temp = m_EmpArray[i];
				m_EmpArray[i] = m_EmpArray[minOrMax];
				m_EmpArray[minOrMax] = temp;
			}
		}

		//打印
		if (select == "1" || select == "2") {
			cout << "排序成功， 排序后的结果为:" << endl;
			this->save();
			this->Show_Emp();
		}
		else {
			cout << "输入有误!" << endl;
			system("pause");
			system("cls");
		}
	}
}

//清空文件
void WorkManager::Clean_File() {

	cout << "确认清空？" << endl;
	cout << "1.确认" << endl;
	cout << "2.返回" << endl;

	string select = "0";
	cin >> select;

	if (select == "1") {
		//打开模式 ios::trunc 如果存在删除文件并重新创建
		ofstream ofs(FILENAME, ios::trunc);
		ofs.close();

		if (this->m_EmpArray != NULL) {
			for (int i = 0; i < m_EmpNum; i++) {
				if (this->m_EmpArray[i] != NULL) {
					delete this->m_EmpArray[i];
				}
			}
			this->m_EmpNum = 0;
			delete[] this->m_EmpArray;
			this->m_EmpArray = NULL;
			this->m_FileIsEmpyty = true;
		}
		cout << "清理成功！" << endl;
	}
	if (select != "1" && select != "2") {
		cout << "输入有误！" << endl;
	}
	system("pause");
	system("cls");
}

//析构函数
WorkManager::~WorkManager() {
	if (this->m_EmpArray != NULL) {

		delete[] this->m_EmpArray;
		this->m_EmpArray = NULL;
	}
}