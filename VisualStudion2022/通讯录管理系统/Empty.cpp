# include "Empty.h"

void Empty(Person& Data) {

	int i, j;

	for (i = 0; i < Data.Quantity + 1; i++) {

		for (j = 0; j < Data.Quantity; j++) {

			Data.Data[j] = Data.Data[j + 1];
		}
	}

	Data.Quantity = 0;
	cout << "" << endl;
	cout << "联系人清空成功！" << endl;
	cout << "" << endl;
	cout << "返回主菜单！" << endl;
}