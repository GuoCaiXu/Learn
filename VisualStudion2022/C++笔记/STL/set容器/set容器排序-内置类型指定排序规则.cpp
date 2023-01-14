//set容器排序
# include <iostream>
using namespace std;
# include <set>

class myCompare {

public:
	bool operator()(int v1, int v2)const {

		return v1 > v2;
	}
};

void test01() {

	//默认从小到大
	set<int>s1;

	//插入数据
	s1.insert(20);
	s1.insert(50);
	s1.insert(10);
	s1.insert(30);
	s1.insert(40);

	for (set<int>::iterator it = s1.begin(); it != s1.end(); it++) {

		cout << *it << " ";
	}
	cout << endl;

	//指定排序规则为从大到小
	set<int, myCompare>s2;

	//插入数据
	s2.insert(20);
	s2.insert(50);
	s2.insert(10);
	s2.insert(30);
	s2.insert(40);

	for (set<int, myCompare>::iterator it = s2.begin(); it != s2.end(); it++) {

		cout << *it << " ";
	}
	cout << endl;
}

int main() {

	test01();

	system("pause");

	return 0;
}