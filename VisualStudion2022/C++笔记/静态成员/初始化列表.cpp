//初始化列表
# include <iostream>
using namespace std;

class Person {

public:
	Person() :m_A(10), m_B(20), m_C(30){   //语法
	}

		int m_A, m_B, m_C;
};

void test01() {

	Person p;

	cout << p.m_A << "  " << p.m_B << "  " << p.m_C << endl;
}
int main() {

	test01();

	system("pause");

	return 0;
}