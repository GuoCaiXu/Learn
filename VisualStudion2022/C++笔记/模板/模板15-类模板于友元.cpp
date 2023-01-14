//类模板与友元
# include <iostream>
using namespace std;
# include <string>

//全局函数类内实现 - 直接在类内声明友元即可
//全局函数类外实现 - 需要提前让编译器知道全局函数的存在

template <class T1, class T2>
class Person;

//类外实现
template<class T1, class T2>
void printPerson2(Person<T1, T2> p) {
	cout << "类外实现 -- 姓名：" << p.m_Name << "  类外实现 -- 年龄:" << p.m_Age << endl;
}


//通过全局函数 打印Person信息

template<class T1, class T2>
class Person {

	//全局函数 类内实现
	friend void printPerson(Person<T1,T2> p) {
		cout << "姓名：" << p.m_Name << "  年龄:" << p.m_Age << endl;
	}

	//全局函数 类外实现
	//加空模板参数列表
	//如果全局函数 是类外实现， 需要让编译器提前知道这个函数的存在
	friend void printPerson2<>(Person<T1,T2> p);

public:
	Person(T1 name, T2 age) {
		m_Name = name;
		m_Age = age;
	}

private:
	T1 m_Name;
	T2 m_Age;
};

void test01() {

	Person<string, int>p("张三", 18);
	//printPerson(p);
	printPerson2(p);
}

int main() {

	test01();

	system("pause");

	return 0;
}