# include <iostream>
using namespace std;

class Base {

public:

	Base() {
		cout << "Base 的构造函数的调用" << endl;
	}
	~Base() {

		cout << "Base 的析构函数调用" << endl;
	}
};

class Son : public Base {


public:

	Son() {

		cout << "Son 的构造函数调用" << endl;
	}

	~Son() {

		cout << "Son 的析构函数调用" << endl;
	}
};

void test01() {

	Son p1;
}

int main() {

	test01();
	/********************************************
	_____________________________________________
	vs 输出为：
	Base 的构造函数的调用
    Son 的构造函数调用
    Son 的析构函数调用
    Base 的析构函数调用
	_____________________________________________
	**********************************************/

	//继承中的构造和析构顺序如下：
	//先构造父类，再构造子类， 析构的顺序与构造函数顺序相反

	system("pause");

	return 0;
}