# include <iostream>
using namespace std;

//函数模板
//语法：
//template<typename T>
//函数声明或定义

//交换两个整型函数
void swapInt(int& a, int& b) {
	int temp = a;
	a = b;
	b = temp;
}

//交换两个浮点型函数
void swapDou(double& a, double& b) {
	double temp = a;
	a = b;
	b = temp;
}

//因为这样很麻烦所以我们需要模板
template<typename T> //我们声明一个模板， 告诉编译器后面代码中紧跟着的T不要报错 T是一个通用的数据类型
void mySwap(T& a, T& b) {
	T temp = a;
	a = b;
	b = temp;
}

void test() {

	int a = 10;
	int b = 20;
	//swapInt(a, b);
	//利用函数模板交换
	//两种方式使用函数模板
	//1.自动类型推导
	//mySwap(a, b);
	//2.显示指定类型
	mySwap<int>(a, b);
	cout << "a = " << a << endl;
	cout << "b = " << b << endl;

	/*double c = 1.1;
	double d = 2.2;
	swapDou(c, d);
	cout << "c = " << c << endl;
	cout << "d = " << d << endl;*/
}

int main() {

	test();

	system("pause");
	
	return 0;
}

//总结：
//     1.函数模板利用关键字template
//     2.使用函数模板有两种方式： 自动类型推导， 显示指定类型
//     3.模板的目的是为了提高复用性， 将类型参数化