//修改联系人源文件
# include"Alter.h"

void Alter(Person& Data) {

	string name, Choose;
	int Choose_1;

	do {
		cout << "" << endl;
		cout << "请输入你要修改的联系人的名字：" << endl;
		cin >> name;

		if (Judgement(Data, name) == -1) {

			cout << "" << endl;
			cout << "未查到此联系人!" << endl;
		}
		else {

			int i = Judgement(Data, name);
			
			cout << "" << endl;
			cout << "请选择你想修改的部分：" << endl;
			cout << "****************" << endl;
			cout << "1.联系人全部资料" << endl;
			cout << "2.  联系人名字  " << endl;
			cout << "3.联系人电话号码" << endl;
			cout << "4.  联系人地址  " << endl;
			cout << "****************" << endl;

			cout << "请选择你的功能";
			cin >> Choose_1;

			switch (Choose_1) {
          case 1:
			  cout << "" << endl;
			  cout << "名字：";
			  cin >> Data.Data[i].name;
			  cout << "电话号码：";
			  cin >> Data.Data[i].number;
			  cout << "地址：";
			  cin >> Data.Data[i].Address;
			  cout << "" << endl;
			  cout << "修改成功！" << endl;
	          break;
		  case 2:
			  cout << "" << endl;
			  cout << "名字：";
			  cin >> Data.Data[i].name;
			  cout << "" << endl;
			  cout << "修改成功！" << endl;
			  break;
		  case 3:
			  cout << "" << endl;
			  cout << "电话号码：";
			  cin >> Data.Data[i].number;
			  break;
		  case 4:
			  cout << "" << endl;
			  cout << "地址：" << endl;
			  cin >> Data.Data[i].Address;
			  cout << "" << endl;
			  cout << "修改成功！" << endl;
			  break;
		  default:
			  break;
			}
		}

		cout << "" << endl;
		cout << "你还要继续修改吗？" << endl;
		cout << "输入Y/N" << endl;
		cin >> Choose;
	} while (Choose == "Y" || Choose == "y" || Choose == "是");

	if (Choose == "N" || Choose == "n" || Choose == "否") {

		cout << "" << endl;
		cout << "返回主菜单！" << endl;
	}
}
