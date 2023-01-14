//map大小和交换
# include <iostream>
using namespace std;
# include <map>

/*
- size();        //返回容器中元素的数目
- empty();       //判断容器是否为空
- swap(st);      //交换两个集合的容器
*/

void printMap(map<int, int>& m) {

	for (map<int, int>::iterator it = m.begin(); it != m.end(); it++) {

		cout << "key = " << it->first << "  value = " << it->second << endl;
	}
	cout << endl;
}

void test01() {

	map<int, int>m;

	m.insert(pair<int, int>(1, 10));
	m.insert(pair<int, int>(2, 20));
	m.insert(pair<int, int>(3, 30));
	m.insert(pair<int, int>(4, 40));

	//判断
	if (m.empty()) {

		cout << "m为空" << endl;
	}
	else {

		cout << "m不为空" << endl;

		//大小
		cout << "m的大小为：" << m.size() << endl;
	}

	//交换
	map<int, int>m2;

	m2.insert(pair<int, int>(10, 100));
	m2.insert(pair<int, int>(20, 200));
	m2.insert(pair<int, int>(30, 300));
	m2.insert(pair<int, int>(40, 400));

	cout << "交换前:" << endl;
	printMap(m);
	printMap(m2);

	cout << "-------------------" << endl;
	cout << "交换后：" << endl;
	m2.swap(m);
	printMap(m);
	printMap(m2);
}

int main() {

	test01();

	system("pause");

	return 0;
}