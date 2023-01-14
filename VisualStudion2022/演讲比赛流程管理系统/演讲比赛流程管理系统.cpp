# include <iostream>
# include "speechManager.h"
using namespace std;

int main() {

	SpeechManager s;
	int choise; //用户的选择

	//菜单功能
	while (true) {
		s.show_Menu();

		cout << "请输入你的选择" << endl;
		cin >> choise; //接受用户的选择

		switch (choise) {
		case 0:
			s.exitsYstem();
			break;
		case 1:
			s.startSpeech();
			break;
		case 2:
			s.showRecord();
			break;
		case 3:
			s.clearRecord();
			break;
		default:
			system("cls");
			break;
		}
	}


	system("pause");

	return 0;
}