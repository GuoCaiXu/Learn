//常用集合算法 set_difference
# include <iostream>
# include <vector>
# include <algorithm>
using namespace std;

void myPrint(int val) {

	cout << val << " ";
}

void test01() {

	vector<int>v1;
	vector<int>v2;

	for (int i = 0; i < 10; i++) {

		v1.push_back(i);
		v2.push_back(i + 5);
	}

	vector<int>v;

	v.resize(max(v1.size(), v2.size()));

	auto itEnd = set_difference(v1.begin(), v1.end(), v2.begin(), v2.end(), v.begin());

	for_each(v.begin(), itEnd, myPrint);
	cout << endl;
}

int main() {

	test01();

	system("pause");

	return 0;
}