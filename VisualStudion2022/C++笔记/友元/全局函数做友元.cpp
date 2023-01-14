//全局函数做友元类
# include <iostream>
using namespace std;
# include <string>

class Buliding {

	friend void goodGay(Buliding& buliding);

public:
  	Buliding() {

		m_BedRoom = "卧室";
		m_SittingRoom = "客厅";
	}

public:
	string m_SittingRoom;  //客厅
private:
	string m_BedRoom; //卧室
};

	void goodGay(Buliding &buliding) {  //好基友

		cout << "好基友全局函数 正在访问：" << buliding.m_SittingRoom << endl;

		cout << "好基友全局函数 正在访问：" << buliding.m_BedRoom << endl;
	}

	void test01() {

		Buliding buliding;
		goodGay(buliding);
	}


int main() {

	test01();

	system("pause");

	return 0;

}