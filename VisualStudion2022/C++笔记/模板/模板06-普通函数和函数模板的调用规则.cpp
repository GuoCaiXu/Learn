//普通函数和函数模板的调用规则
# include <iostream>
using namespace std;

//1.如果函数模板和普通函数都可以调用， 优先调用普通函数
//2.可以通过空模板参数列表 强制调用 函数模板
//3.函数模板可以发生函数重载
//4.如果函数模板可以产生更好的匹配， 优先调用函数模板

void myPrint(int a, int b) {
	cout << "普通函数的调用" << endl;
}

template<class T>
void myPrint(T a, T b) {
	cout << "函数模板的调用" << endl;
}

template<class T>
void myPrint(T a, T b, T c) {
	cout << "函数模板重载的调用" << endl;
}

void test01() {

	int a = 10;
	int b = 20;

	//如果函数模板和普通函数都可以调用， 优先调用普通函数
	myPrint(a, b);

	//可以通过空模板参数列表 强制调用 函数模板
	myPrint<>(a, b);

	//函数模板可以发生函数重载
	myPrint(a, b, 100);

	//如果函数模板可以产生更好的匹配， 优先调用函数模板
	char c = 'c';
	char d = 'd';
	myPrint(c, d);
}

int main() {

	test01();

	system("Pause");

	return 0;
}