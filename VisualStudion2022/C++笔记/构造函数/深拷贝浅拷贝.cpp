//深拷贝和浅拷贝
# include <iostream>
using namespace std;

class Person {

public:
	int m_Age;
	int *m_Height;

	Person() {

		cout << "Person 默认构造函数的调用" << endl;
	}

	Person(int age, int height) {

		cout << "Person 有参构造函数的调用" << endl;
		m_Age = age;
		m_Height = new int(height);
	}

	Person(const Person& p) {

		cout << "Person 拷贝构造函数的调用" << endl;
		m_Age = p.m_Age;
		//m_Height = p.m_Height;//编译器默认实现的就是这行代码

		m_Height = new int(*p.m_Height);
	}

	~Person() {

		cout << "Person 析构函数的调用" << endl;

		if (m_Height != NULL) {

			delete m_Height;
			m_Height = NULL;
		}
	}
};

void test01() {

	Person p1(18, 160);

	cout << "p1的年龄为：" << p1.m_Age << "  p1的身高为：" << *p1.m_Height << endl;
	
	Person p2(p1);

	cout << "p2的年龄为：" << p2.m_Age << "  p2的身高为：" << *p2.m_Height << endl;
}

int main() {

	test01();

	system("pause");

	return 0;
}