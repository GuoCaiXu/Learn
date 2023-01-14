//函数调用运算符重载
# include <iostream>
using namespace std;
# include <string>

class Person {

public:

	void operator()(string text) {  //称为仿函数非常灵活

		cout << text << endl;
	}
};

class MyAdd {

public:
	int operator()(int a, int b){

		return a + b;
	}
};

void test01() {

	Person test; 
	test("你好!");
}

void test02() {

	MyAdd myadd;
	int ret = myadd(100, 100);
	cout << "ret = " << ret << endl;

	//匿名函数对象
	cout << MyAdd()(100, 100) << endl;
}

int main() {

	//test01();
	test02();

	system("pause");

	return 0;
}