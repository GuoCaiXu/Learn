//常用算术生成算法 fill
# include <iostream>
# include <vector>
# include <numeric>
# include <algorithm>
using namespace std;

void myPrint(int val) {

	cout << val << " ";
}

void test01() {

	vector<int>v;

	v.resize(10);

	fill(v.begin(), v.end(), 100);

	for_each(v.begin(), v.end(), myPrint);
	cout << endl;
}

int main() {

	test01();

	system("pause");

	return 0;
}