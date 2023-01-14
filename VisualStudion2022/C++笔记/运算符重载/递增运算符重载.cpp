//重载递增运算符
# include <iostream>
using namespace std;

//自定义整形
class MyInteger {

	//友元类
	friend ostream& operator<<(ostream& cout, MyInteger& myint);

public:

	MyInteger() {

		m_Num = 0;
	}


	//重载前置++运算符  返回引用为了一直对一个数据进行操作
	MyInteger& operator++() {

		//先进行++运算
		m_Num++;

		//再将自身做返回
		return *this;
	}

	//重载后置++运算符
	MyInteger& operator++(int) {  //int 是占位参数， 可以用于区分前置和后置递增

		//先 记录当时结果
		MyInteger temp = *this;
		//后 递增
		m_Num++;
		//最后将记录结果返回
		return temp;
	}

private:
	int m_Num;
};

//重载<<运算符
ostream& operator<<(ostream& cout, MyInteger& myint) {

	cout << myint.m_Num;

	return cout;
}

void test01() {

	MyInteger myint;

	cout << ++myint << endl;
	cout << myint << endl;
}

void test02() {

	MyInteger myint;

	cout << myint++ << endl;
	cout << myint << endl;
}

int main() {

	//test01();
	test02();

	system("pause");

	return 0;
}