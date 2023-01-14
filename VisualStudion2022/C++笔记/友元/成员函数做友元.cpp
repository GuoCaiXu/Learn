# include <iostream>
using namespace std;
# include <string> 

class Buliding;//类的前置声明

class goodGay {

public:
	goodGay();

	void visit();

	Buliding *buliding;

};

class Buliding {


	friend void goodGay::visit(); //成员函数做又元

public:
	Buliding();

	string m_SittingRoom;

private:
	string m_RedRoom;
};

Buliding::Buliding() {

	m_SittingRoom = "客厅";
	m_RedRoom = "卧室";
}

goodGay::goodGay() {

	buliding = new Buliding;
}

void goodGay::visit() {

	cout << "好基友类正在访问：" << buliding->m_SittingRoom << endl;

	cout << "好基友类正在访问：" << buliding->m_RedRoom << endl;

}

void test01() {

	goodGay gg;

	gg.visit();
}


int main() {

	test01();

	system("pause");

	return 0;
}