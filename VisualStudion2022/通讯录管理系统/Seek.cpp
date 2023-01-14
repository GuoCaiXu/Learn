//查找函数源文件
# include "Seek.h"

void Seek(Person &Data) {

	string name, Choose;

	do {
		cout << "" << endl;
		cout << "请输入你要查找联系人的名字:";
		cin >> name;

		if (Judgement(Data, name) == -1) {
			cout << "" << endl;
			cout << "未查到返回主菜单！" << endl;
			return;
		}
		else {
			cout << "" << endl;
			cout << "联系人" << Data.Data[Judgement(Data, name)].name << "信息如下：" << endl;
			cout << "电话号码:" << Data.Data[Judgement(Data, name)].number << "    地址:" << Data.Data[Judgement(Data, name)].Address << endl;
		}
		cout << "" << endl;
		cout << "你还要继续查找吗？" << endl;
		cout << "输入Y/N" << endl;
		cin >> Choose;
	} while (Choose == "Y" || Choose == "y" || Choose == "是");

	if (Choose == "N" || Choose == "n" || Choose =="否") {

		cout << "" << endl;
		cout << "返回主菜单！" << endl;
	}
}