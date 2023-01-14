//常用遍历算法 transform
# include <iostream>
using namespace std;
# include <vector>
# include <algorithm>

class Tranget {

public:
	int operator()(int v) {

		return v;
	}
};

class MyPrint {

public :
	void operator()(int val) {

		cout << val << " ";
	}
};

void test01() {

	vector<int>v;
	for (int i = 0; i < 10; i++) {

		v.push_back(i);
	}

	vector<int>vTrarget; //目标容器

	vTrarget.resize(v.size());
	transform(v.begin(), v.end(), vTrarget.begin(), Tranget());

	for_each(vTrarget.begin(), vTrarget.end(), MyPrint());
	cout << endl;
}

int main() {

	test01();

	system("pause");

	return 0;
}