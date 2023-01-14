//静态成员函数
//1，所有的对象都共享一个函数
//2，静态成员函数只能访问静态成员变量
# include <iostream>
using namespace std;

class Person {

public:
	//静态的成员函数
	static void func() {

		m_A = 100;
		m_B = 200;//静态成员函数不可以访问非静态成员变量
		cout << "static void func的调用" << endl;
	}

	static int m_A;//静态成员变量
	int m_B; // 非静态成员变量
};

int Person::m_A = 0;


void test01() {

	//1,通过对象访问
	Person p;
	p.func();

	//通过类名访问
	Person::func();
}

void test02() {


}
int main() {

	test01();

	system("pause");

	return 0;
}