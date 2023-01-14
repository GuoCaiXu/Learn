# include "Interface.h"

void Interface(Person &Data) {

	int Choose;

	while(true) {

		cout << "************" << endl;
		cout << "1.添加联系人" << endl;
		cout << "2.查看联系人" << endl;
		cout << "3.查找联系人" << endl;
		cout << "4.删除联系人" << endl;
		cout << "5.修改联系人" << endl;
		cout << "6.清空联系人" << endl;
		cout << "0.退出该程序" << endl;
		cout << "************" << endl;

		cout << "" << endl;
		cout << "选择你想使用的功能：";
		cin >> Choose;

		//功能界面
		Function(Choose, Data);

		if (Choose == 0) {

			cout << "" << endl;
			cout << "退出程序!" << endl;

			return;
		}
	}
}
