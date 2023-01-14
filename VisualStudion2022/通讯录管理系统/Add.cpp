# include "Add.h"

int i = 0;

void Add(Person& Data) {

	if (AddJudgement(Data) == -1) {

		i = 0;
	}

	string Choose;

	do {
		Data.Quantity++;
		cout << "" << endl;
		cout << "请添加联系人的资料：" << endl;
		cout << "名字:";
		cin >> Data.Data[i].name;
		cout << "电话号码：";
		cin >> Data.Data[i].number;
		cout << "地址：";
		cin >> Data.Data[i].Address;
		i++;
		cout << "" << endl;
		cout << "你还要继续添加吗?" << endl;
		cout << "输入Y/N" << endl;
		cin >> Choose;


	} while (Choose == "Y" || Choose == "y" || Choose == "是");

	if (Choose == "N" || Choose == "n" || Choose == "否") {

		cout << "" << endl;
		cout << "返回主菜单!" << endl;
	}
}