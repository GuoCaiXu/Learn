//常用拷贝和替换算法 replace_if
# include <iostream>
# include <vector>
# include <algorithm>
using namespace std;

class Great20 {

public:
	bool operator()(int val) {
		return val >= 20;
	}
};

void myPrint(int val) {

	cout << val << " ";
}
void test01() {

	vector<int>v;

	v.push_back(10);
	v.push_back(20);
	v.push_back(40);
	v.push_back(50);
	v.push_back(30);

	cout << "替换前" << endl;
	for_each(v.begin(), v.end(), myPrint);
	cout << endl;

	cout << "替换后" << endl;
	replace_if(v.begin(), v.end(), Great20(), 2000);

	for_each(v.begin(), v.end(), myPrint);
	cout << endl;

}

int main() {

	test01();

	system("pause");

	return 0;
}