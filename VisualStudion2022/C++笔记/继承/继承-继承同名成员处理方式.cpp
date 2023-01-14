//继承同名成员处理方式
# include <iostream>
using namespace std;

class Base {

public:
	int m_A;

	Base() {

		m_A = 100;
	}

	void func() {

		cout << "Base  - func()的调用" << endl;
	}

	void func(int a) {

		cout << "Base  - func(ina a)的调用" << endl;
	}

};

class Son : public Base {

public:
	int m_A;

	Son() {

		m_A = 200;
	}

	void func() {

		cout << "Son - func() 的调用" << endl;
	}
};

//同名成员属性处理
void test01() {

	Son p1;
	
	cout << "m_A = " << p1.m_A << endl;
	//如果通过子类对象 访问到父亲中同名成员， 需要加作用域
	cout << "m_A = " << p1.Base::m_A << endl;

	//p1.func(100);// wrong
	//如果子类中出现父类同名的成员函数， 子类同名成员会隐藏掉父类中所以同名成员函数
	//如果想访问到父类这被隐藏的同名成员函数， 需要加作用域

	p1.Base::func(100);
}

//同名成员函数处理
void test02() {

	Son p1;

	p1.func(); //直接调用 调用是子类中的同名成员

	//如何调用到父类中的同名成员？
	p1.Base::func();

}

int main() {

	
	test01();
	//test02();

	system("pause");

		return 0;
}