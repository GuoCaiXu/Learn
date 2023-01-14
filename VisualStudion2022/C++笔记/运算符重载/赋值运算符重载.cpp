//赋值运算符重载
# include <iostream>
using namespace std;

class Person {
	friend void test01();

public:
	Person(int age) {
		m_Age = new int(age);
	}

	Person & operator=(Person& p) {

		//编译器是提供浅拷贝
		//m_Age = p.m_Age;

		//应该先判断是否有属性在堆区， 如果有先释放干净， 然后再深拷贝
		if (m_Age != NULL) {

			delete m_Age;
			m_Age = NULL;
		}
		//深拷贝
		m_Age = new int(*p.m_Age);

		return *this;
	}

	~Person() { //当用析构函数释放内存时代码回崩溃  这时我们需要深拷贝来解决浅拷贝带来的问题

		if (m_Age != NULL) {

			delete m_Age;
			m_Age = NULL;
		}
	}


private:
	int *m_Age;
};


void test01() {

	Person p1(18);

	Person p2(20);

	Person p3(10);

	//p2 = p1;

	p3 = p2 = p1; //当等于三个数时赋值运算符需要返回一个p2的值



	cout << "p1 = " << *p1.m_Age << endl;
	cout << "p2 = " << *p2.m_Age << endl;
	cout << "p3 = " << *p3.m_Age << endl;

}

int main() {

	test01();

	system("pause");

	return 0;
}