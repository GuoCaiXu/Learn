//内建函数对象逻辑仿函数
# include <iostream>
using namespace std;
# include <vector>
# include <algorithm>
# include <functional>

/*
template<class T> bool logical_and<T>      //逻辑与
template<class T> bool logical_or<T>       //逻辑或
template<class T> bool logical_not<T>      //逻辑非
*/

//逻辑非 logical_not
void test01() {

	vector<int>v;
	v.push_back(true);
	v.push_back(false);
	v.push_back(true);
	v.push_back(true);


	for (vector<int>::iterator it = v.begin(); it != v.end(); it++)
	{
		cout << *it << " ";
	}
	cout << endl;

	//利用逻辑非 将容器v搬运到 容器v2中，并执行取反操作
	vector<bool>v2;
	v2.resize(v.size());

	transform(v.begin(), v.end(), v2.begin(), logical_not<bool>());

	for (vector<bool>::iterator it = v2.begin(); it != v2.end(); it++)
	{
		cout << *it << " ";
	}
	cout << endl;
}

int main() {

	test01();

	system("pause");

	return 0;
}