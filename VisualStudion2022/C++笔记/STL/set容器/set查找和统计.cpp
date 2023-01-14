//set查找和统计
# include <iostream>
using namespace std;
# include <set>

/*
- find(key);         //查找key是否存在，若存在，返回该键的元素的迭代器，若不存在，返回set.end();
- count(key);        //统计key元素个数
*/

void test01() {

	//查找
	set<int>s1;

	//插入数据
	s1.insert(10);
	s1.insert(30);
	s1.insert(20);
	s1.insert(40);

	set<int>::iterator pos = s1.find(30);

	if (pos != s1.end()) {

		cout << "找到元素" << endl;
		cout << "s1 = " << *pos << endl;
	}
	else {
		cout << "未找到" << endl;
	}
}

//统计
void test02() {

	set<int>s1;

	//插入数据
	s1.insert(10);
	s1.insert(30);
	s1.insert(20);
	s1.insert(40);

	//统计30的个数
	int num = s1.count(30);

	//对于set而言，统计结果要么是0，要么是1
	cout << "30有" << num << "个" << endl;
}

int main() {

	//test01();
	test02();

	system("pause");

	return 0;
}