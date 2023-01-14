# include <iostream>
using namespace std;
 
//公共继承
class Base1 {

public:
	int m_A;
protected:
	int m_B;
private:
	int m_C;
};

class Son1 : public Base1 {

public:
	void func() {

		m_A = 100;
		m_B = 100;
		//m_C = 100; //wrong 父类中私有成员子类访问不到， 不管是哪种继承方式子类都继承不到
	}
};

void test01() {

	Son1 s1;
	s1.m_A = 1000;
	//s1.m_B = 1000; // 错误 到了Son1中 m_B是保护权限 类外访问不到
}

//保护继承
class Base2 {

public:
	int m_A;
protected:
	int m_B;
private:
	int m_C;
};

class Son2 : protected Base2 {

public:
	void func() {

		m_A = 100; //父类中公共成员， 到子类中变为保护权限
		m_B = 100; //父类中保护成员， 到子类中变为保护权限
		//m_C = 100; //wrong 父类中私有成员子类访问不到， 不管是哪种继承方式子类都继承不到
	}
};

void test02() {

	Son2 s1;
	//s1.m_A = 1000; //wrong 在Song2中 m_A变为保护权限， 因此类外访问不到
	//s1.m_B = 1000;  //wrong 在Song2中 m_A变为保护权限， 因此类外访问不到
}

//私有继承
class Base3 {

public:
	int m_A;
protected:
	int m_B;
private:
	int m_C;
};

class Son3 : private Base3 {

	void func() {

		m_A = 100;  //父类中公共成员， 到子类中变为私有权限
		m_B = 100;  //父类中保护成员， 到子类中变为私有权限
	}
};
void test() {

	//m_A = 1000; //wrong 在Song3中 m_A变为私有权限， 因此类外访问不到
	//m_B = 1000; //wrong 在Song3中 m_A变为私有权限， 因此类外访问不到
}

class Grand3 : public Son3 {

	//m_A = 100; //因为父类Son3是私有权限， 所以子类Grand3访问不到
	//m_B = 1000;
};

int main() {

	system("pause");

	return 0;
}