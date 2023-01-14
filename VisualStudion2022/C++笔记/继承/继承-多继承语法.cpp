# include <iostream>
using namespace std;

class Base1 {

public:
	Base1() {

		m_A = 100;
	}
	int m_A;
};

class Base2 {

public:
	Base2() {

		m_A = 200;
	}
	int m_A;
};

class Son : public Base1, public Base2 {
public:
	int m_C;
	int m_D;

	Son() {

		m_C = 300;
		m_D = 400;
	}
};

void test01() {

	Son p;
	
	cout << p.Base1::m_A << endl;
	cout << p.Base2::m_A << endl;
}

int main() {

	test01();

	system("pause");

	return 0;
}