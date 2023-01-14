# include <iostream>
using namespace std;

class Base {
public:

	//纯虚函数
	//只要有一个纯虚函数， 这个类称为抽象类
	//抽象类特点：
	//1.无法实例化对象
	//2.抽象类的子类  必须重写父类中的纯虚函数， 否则也属于抽象类
	virtual void func() = 0;
};

class Son : public Base {
public:
	void func() {     //重写父类中的纯虚函数

		cout << "重写父类中的纯虚函数" << endl;

	}
};

void test() {

	//Base s;// wrong 抽象类无法实例化对象
	//new Base;//wrong 抽象类无法实例化对象

	//Son s;//wrong 子类必须重新父类中的纯虚函数， 否则无法实例化对象

	Base* base = new Son;
	base->func();
}

int main() {

	test();

	system("pause");

	return 0;
}