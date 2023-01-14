//构造函数调用规则
#include <iostream>
using namespace std;

//1，创造一个类， c++编译器会给每个类添加至少3个函数
	//默认构造 （空实现）
	//析构函数 （空实现）
	//拷贝函数 （值拷贝）
class Person {

public:
	Person() {
		cout << "Person 默认函数的调用" << endl;
	}

	Person(int a) {
		cout << "Person 有参函数的调用" << endl;
		m_age = a;
	}

	//Person(const Person & p) {

	//	m_age = p.m_age;
	//	cout << "Person 拷贝函数的调用" << endl;
	//}
	~Person() {
		cout << "Person 析构函数的调用" << endl;
	}

	int m_age;
};

void test01() {

	Person p;

	p.m_age = 18;

	Person p2(p);
	cout << "p2的年龄为：" << p2.m_age << endl; //如果没有21~25行代码年龄还会是18，因为当没有拷贝函数时编译器会生成一个拷贝函数值传递
}

int main() {

	test01();

	system("pause");

	return 0;
}