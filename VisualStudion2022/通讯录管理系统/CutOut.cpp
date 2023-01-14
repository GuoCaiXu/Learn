# include "CutOut.h"

void CutOut(Person& Data) {

	string name, Choose;

	do {
		cout << "" << endl;
		cout << "请输入你要删除的联系人的名字：" << endl;
		cin >> name;

		if (Judgement(Data, name) == -1) {

			cout << "" << endl;
			cout << "未查到此联系人!" << endl;
		}
		else {

			int i = Judgement(Data, name);
			for (i; i < Data.Quantity + 1; i++) {

				Data.Data[i] = Data.Data[i + 1];

			}
			cout << "" << endl;
			cout << "删除成功！" << endl;
			Data.Quantity--;
		}
	
		cout << "" << endl;
		cout << "你还要继续删除吗？" << endl;
		cout << "输入Y/N" << endl;
		cin >> Choose;
	} while (Choose == "Y" || Choose == "y" || Choose == "是");

	if (Choose == "N" || Choose == "n" || Choose == "否") {

		cout << "" << endl;
		cout << "返回主菜单！" << endl;
	}
}