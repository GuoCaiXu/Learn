//类模板分文件编写
# include <iostream>
using namespace std;

//第一种解决方式， 直接包含 源文件
//# include "Person.cpp"

//第二种解决方式， 将.h和.cpp中的内容写到一起， 将后缀名改为.hpp文件
# include "Person.hpp"

void test01() {

	Person<string, int>p("张三", 18);
	p.showPerson();
}

int main() {

	test01();

	system("pause");

	return 0;
}

//总结：主流的解决方式是第二种， 将类模板成员函数写到一起， 并将后缀名改为.hpp