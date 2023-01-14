//map查找和统计
# include <iostream>
using namespace std;
# include <map>

/*
- find(key);          //查找key是否存在若存在，返回该键的元素的迭代器，若不存在，返回set.end();
- count(key)；        //统计key的元素个数
*/

void test01() {

	//查找
	map<int, int>m;

	//插入数据
	m.insert(make_pair(1, 10));
	m.insert(make_pair(2, 20));
	m.insert(make_pair(3, 30));
	m.insert(make_pair(4, 40));
	m.insert(make_pair(3, 50));

	map<int, int>::iterator pos = m.find(3);

	if (pos != m.end()) {
		cout << "查找该元素 key = " << pos->first << " value = " << pos->second << endl;
	}
	else {

		cout << "元素未找到" << endl;
	}

	//统计
	int num = m.count(3);
	cout << "num = " << num << endl;  //map不允许插入重复的key，count统计而言结构要么是0要么是1
	//multimap的统计可能大于1
}

int main() {

	test01();

	system("pause");

	return 0;
}