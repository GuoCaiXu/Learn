//常用排序算法 merg
# include <iostream>
# include <vector>
# include <algorithm>
using namespace std;

void MyPrint(int val) {

	cout << val << " ";
}

void test01() {

	vector<int>v1;
	vector<int>v2;

	for (int i = 0; i < 10; i++) {

		v1.push_back(i);
		v2.push_back(i);
	}

	//目标容器
	vector<int>vTrarge;
	vTrarge.resize(v1.size() + v2.size());

	merge(v1.begin(), v1.end(), v2.begin(), v2.end(), vTrarge.begin());
	
	for_each(vTrarge.begin(), vTrarge.end(), MyPrint);
	cout << endl;
}

int main() {

	test01();

	system("pause");

	return 0;
}