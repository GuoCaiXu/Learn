//继承中的对象模型
# include <iostream>
using namespace std;

class Base {

public:
	int m_A;
protected:
	int m_B;
private:
	int m_C;
};

class Son : public Base {

public:
	int m_D;

};

void test01() {

	cout << "size of Son = " << sizeof(Son) << endl;
	//vs开发人命令提示符输入cl /d1 reportSingleClassLayoutSon "继承-继承中的对象模型.cpp"也可查看单个类的布局
}


int main() { 

	test01();
	
	system("Pause");

	return 0;
}