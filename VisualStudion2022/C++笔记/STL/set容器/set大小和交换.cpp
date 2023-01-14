//set大小和交换
# include <iostream>
using namespace std;
# include<set>

/*
- size();      //返回容器中元素的数目
- empty();     //判断容器是否为空
- swap();      //交换两个集合容器
*/

void printSet(set<int>s) {

	for (set<int>::iterator it = s.begin(); it != s.end(); it++) {

		cout << *it << " ";
	}
	cout << endl;
}

//大小
void test01() {

	set<int>s1;

	//输入数据
	s1.insert(10);
	s1.insert(20);
	s1.insert(40);
	s1.insert(30); 
	s1.insert(30);

	//打印容器
	printSet(s1);  //10 20 30 40

	//判断是否为空
	if (s1.empty()) {
		cout << "s1为空" << endl;
	}
	else {
		cout << "s1不为空" << endl;
		cout << "s1的大小为：" << s1.size() << endl;  //4
	}
}

//交换
void test02() {

	set<int>s1;

	//输入数据
	s1.insert(10);
	s1.insert(20);
	s1.insert(40);
	s1.insert(30);
	s1.insert(30);

	set<int>s2;

	//输入数据
	s2.insert(100);
	s2.insert(200);
	s2.insert(400);
	s2.insert(300);
	s2.insert(300);

	cout << "交换前" << endl;
	printSet(s1);
	printSet(s2);
	cout << "---------------------" << endl;
	s1.swap(s2);
	cout << "交换后" << endl;
	printSet(s1);
	printSet(s2);
}

int main() {

	//test01();
	test02();

	system("pause");

	return 0;
}