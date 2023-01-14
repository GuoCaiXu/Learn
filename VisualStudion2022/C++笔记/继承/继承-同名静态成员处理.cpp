//同名静态成员处理
# include <iostream>
using namespace std;

class Base {

public:
	static int m_A;

	static void func() {

		cout << "Base- static void func()的调用" << endl;
	}
};
int Base::m_A = 100;

class Son : public Base{

public: 
	static int m_A;

	static void func() {

		cout << "Son - static void func()的调用" << endl;
	}
};
int Son::m_A = 200;

//同名静态函数成员属性
void test01() {

	//1.通过对象访问
	Son p;
	cout << "通过对象访问：" << endl;
	cout << "Son 下 m_A = " << p.m_A << endl;
	cout << "Base 下 m_A = " << p.Base::m_A << endl;

	//2.通过类名访问
	cout << "通过类吗访问：" << endl;
	cout << "Son 下 m_A = " << Son::m_A << endl;
	cout << "Base 下 m_A = " << Son::Base::m_A << endl;

	/*
	-----------------------------------------------------
	*****************************************************
	vs输出：

	 通过对象访问：
     Son 下 m_A = 200
     Base 下 m_A = 100
     通过类吗访问：
     Son 下 m_A = 200
     Base 下 m_A = 100
     请按任意键继续. . .
	 ****************************************************
	 ____________________________________________________*/

}

//同名静态成员函数
void test02() {

	Son s;

	//1.通过对象访问的
	cout << "通过对象访问:" << endl;
	s.func();
	s.Base::func();

	//2.通过类名访问
	cout << "通过类名访问:" << endl;
	Son::func();
	Base::func(); //73的 Base::func(); 行和 74的Son::Base::func(); 行的作用一样 等价
	Son::Base::func();
}
/*
————————————————————————————————----------
**************************************************************************
vs输出：

通过对象访问:
Son - static void func()的调用
Base- static void func()的调用
通过类名访问:
Son - static void func()的调用
Base- static void func()的调用
Base- static void func()的调用
请按任意键继续. . .
****************************************************************************
——————————————————————————————————————*/

int main() {

	//test01();
	test02();

	system("pause");

	return 0;
}