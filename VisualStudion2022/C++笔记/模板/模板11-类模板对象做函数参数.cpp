//类模板对象做函数参数
# include <iostream>
using namespace std;
# include <string>

//1.指定传入类型
//2.参数模板化
//3.整个类模板化
template<class T1, class T2>
class Person {
	
public:
	Person(T1 name, T2 age) {
		this->m_Name = name;
		this->m_Age = age;
	}

	void showPerson() {
		cout << "姓名:" << this->m_Name << "  年龄:" << this->m_Age << endl;
	}

	T1 m_Name;
	T2 m_Age;
};

//1.指定传入类型

void priantPerson1(Person<string, int>& p) {

	p.showPerson();
}

void test01() {
	Person<string, int>p("张三", 18);
	priantPerson1(p);
}

//2.参数模板化
template<class T1, class T2>
void priantPerson2(Person<T1, T2>&p) {
	p.showPerson();
	cout << "T1 的类型为:" << typeid(T1).name() << endl;
	cout << "T2 的类型为:" << typeid(T2).name() << endl;
}

void test02() {
	Person<string, int>p("李四", 19);
	priantPerson2(p);
}

//3.整个类模板化
template<class T>
void priantPerson3(T &p) {
	p.showPerson();
	cout << "T 的类型为:" << typeid(T).name() << endl;
}

void test03() {
	Person<string, int>p("小丽", 20);
	priantPerson3(p);
}

int main() {

	test01();
	test02();
	test03();

	system("pause");

	return 0;
}

//总结：
//     通过类模板的对象， 可以有三种方式向函数中进行传参
//     使用比较广泛是第一种：指定传入的类型
//     第一种是比较常用的