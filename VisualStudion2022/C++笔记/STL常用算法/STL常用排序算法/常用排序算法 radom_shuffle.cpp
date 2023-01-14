//常用排序算法 radom_shuffle
# include <iostream>
# include <vector>
# include <algorithm>
# include <ctime>
using namespace std;

void MyPrint(int val) {
	
	cout << val << " ";
}

void test01() {

	srand((unsigned int)time(NULL));

	vector<int>v;
	for (int i = 0; i < 10; i++) {
		v.push_back(i);
	}

	//利用洗牌 算法 打乱顺序
	random_shuffle(v.begin(), v.end());

	for_each(v.begin(), v.end(), MyPrint);
	cout << endl;
}

int main() {

	test01();

	system("pause");

	return 0;
}