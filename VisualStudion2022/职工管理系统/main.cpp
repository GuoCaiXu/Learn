# include <iostream>
using namespace std;
# include "workManger.h"
# include "worker.h"
# include "boss.h"
# include "manager.h"
# include "employee.h"
 
int main() {

	WorkManager wm;
	int choice; 
	while (true) {

	   //展示菜单
		wm.Show_Menu();
		cout << endl;
		cout << "请输入你的选择:";
		cin >> choice;
		cout << endl;

		switch (choice) {
		case 0:   //退出系统
			wm.ExitSystem();
			break;
		case 1:  //添加职工
			wm.Add_Emp();
			break;
		case 2:  //显示职工
			wm.Show_Emp();
			break;
		case 3:  //删除职工
			wm.Del_Emp();
		    break; 
		case 4:  //修改职工
			wm.Mod_Emp();
			break;
		case 5:  //查找职工
			wm.Find_Emp();
			break;
		case 6:  //按照编号排序
			wm.Sort_Emp();
			break;
		case 7:  //清空所有文档
			wm.Clean_File();
			break;
		}
	}

	system("pause");

	return 0;
}