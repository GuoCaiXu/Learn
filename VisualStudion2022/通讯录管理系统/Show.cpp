# include "Show.h"

void Show(Person& Data) {

	cout << "联系人信息如下：" << endl;

	for (int i = 0; i < Data.Quantity; i++) {
		cout << "" << endl;
		cout << "名字：" << Data.Data[i].name << "    电话号码：" << Data.Data[i].number << "    地址：" << Data.Data[i].Address << endl;
		cout << "" << endl;
	}

	if (Data.Quantity == 0) {
		cout << "" << endl;
		cout << "通讯录无联系人！" << endl;
		cout << "" << endl;
		cout << "返回主菜单！" << endl;
		cout << "" << endl;
	}
}