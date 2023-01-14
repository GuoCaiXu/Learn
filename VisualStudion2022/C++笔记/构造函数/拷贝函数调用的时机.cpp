# include <iostream>
using namespace std;

class Person {

public:
	Person() {
		cout << "Person 默认构造函数的调用" << endl;
	}

	Person(int age) {
		m_age = age;
		cout << "Person 有参函数的调用" << endl;
	}
	Person(const Person &p) {
		m_age = p.m_age;
			cout << "Person 拷贝函数的调用" << endl;
	}

	~Person() {
		cout << "Person 析构函数的调用" << endl;
	}
	int m_age;
};

//1，使用一个已经创建完毕的对象来初始化一个新对象
void test01() {

	Person p1(20);
	Person p2(p1);

	cout << "p2的年龄为：" << p2.m_age << endl;
}

//2，值传递的方式给函数传值
void doWork(Person p) {

	
}
void test02() {

	Person p;
	doWork(p);
}

//3，值方式返回局部对象

Person doWork2() {

	Person p1;
	cout << (int*)&p1 << endl;
	return p1;
}

void test03() {

	Person p2;

	Person p = doWork2();
	//Person p = p2;
	cout << (int*)&p << endl;

}

int main() {

	//test01();
	//test02();
	test03();

	system("pause");

	return 0;
}