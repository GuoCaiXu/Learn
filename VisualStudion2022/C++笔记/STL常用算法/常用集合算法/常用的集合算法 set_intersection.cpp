//常用集合算法 set_intersection
# include <iostream>
# include <vector>
# include <algorithm>
using namespace std;

void myPrint(int val) {

	cout << val << " ";
}

void test01() {

	vector<int>v1;
	for (int i = 0; i < 10; i++) {
		v1.push_back(i);
	}

	vector<int>v2;
	for (int i = 5; i < 15; i++) {
		v2.push_back(i);
	}

	vector<int>v;

	//目标容器需要提前开辟空间
	//最特殊情况 大容器包含小容器 开辟空间 取最小容器即可
	v.resize(min(v1.size(),v2.size()));

	//获取交集
	auto itEnd = set_intersection(v1.begin(), v1.end(), v2.begin(), v2.end(), v.begin());

	for_each(v.begin(),itEnd, myPrint);
	cout << endl;
}

int main() {

	test01();

	system("pause");

	return 0;
}