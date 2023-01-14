//常用查找算法 adjacent_find
# include <iostream>
# include <vector>
# include <algorithm>
using namespace std;

void test01() {

	vector<int>v;
	v.push_back(0);
	v.push_back(2);
	v.push_back(0);
	v.push_back(3);
	v.push_back(1);
	v.push_back(4);
	v.push_back(3);
	v.push_back(3);

	auto pos = adjacent_find(v.begin() , v.end());
	if (pos == v.end()) {

		cout << "未找到" << endl;
	}
	else {
		cout << "找到" << *pos << endl;
	}
}

int main() {

	test01();

	system("pause");

	return 0;
}