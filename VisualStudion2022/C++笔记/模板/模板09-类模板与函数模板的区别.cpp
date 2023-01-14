//类模板与函数模板的区别
# include <iostream>
using namespace std;

//类模板与函数模板区别主要有两点：
//1.类模板没有自动类型推导的使用方法
//2.类模板在模板参数列表可以有默认参数

template<class NameType, class AgeType = int>
class Person {
public :
	Person(NameType name, AgeType age) {
		this->m_Name = name;
		this->m_Age = age;
	}

	void showPerson() {
		cout << "name = " << this->m_Name << "  age = " << this->m_Age << endl;
	}

	NameType m_Name;
	AgeType m_Age;
};

//1.类模板没有自动类型推导的使用方法
void test01() {

	//Person p1("张三", 18); //错误， 无法使用自动类型推导
	Person<string, int> p1("张三", 18);  //正确， 只能用显示指定类型
	p1.showPerson();
}

//2.类模板在模板参数列表可以有默认参数
void test02() {
	Person<string> p2("李四", 18);
	p2.showPerson();
}

int main() {

	test01();
	test02();

	system("pause");

	return 0;
}

//总结：
//     类模板使用只能用显示指定类型方式
//     类模板中的模板参数列表可以有默认参数