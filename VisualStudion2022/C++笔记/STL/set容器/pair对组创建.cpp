//pair对组创建
# include <iostream>
using namespace std;
# include <string>

/*
两种方法：
- pair<type, type> p (value1, value2);
- pair<type, type> p = make_pair(value1, value2);
*/

void test01() {

	//第一种方式
	pair<string, int>p("张三", 18);

	cout << "姓名：" << p.first << "  年龄:" << p.second << endl;

	//第二种方式
	pair<string, int>p2 = make_pair("张三", 18);
	cout << "姓名：" << p.first << "  年龄:" << p.second << endl;
}

int main() {

	test01();

	system("pause");

	return 0;
}