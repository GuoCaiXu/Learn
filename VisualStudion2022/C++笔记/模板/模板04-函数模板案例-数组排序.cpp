# include <iostream>
using namespace std;

//案例描述：利用函数模板封装一个排序的函数， 可以对不同数据类型数组进行排序
//          排序规则从大到小， 排序算法为选择排序
//          分别利用char数组和int数组进行测试
            
template<class T>
void Sequence(T arr[], int len) {

	for (int i = 0; i < len; i++) {
		int mainOrMax = i;

		for (int j = i + 1; j < len; j++) {

			if (arr[mainOrMax] < arr[j]) {
				mainOrMax = j;
			}
		}

		if (mainOrMax != i) {
			T temp = arr[mainOrMax];
			arr[mainOrMax] = arr[i];
			arr[i] = temp;
		}
	}
}

void test01() {
	int arr1[] = { 2,4,7,3,1,9 };
	char arr2[] = "amdswb";

	Sequence(arr1, 6);
	Sequence(arr2, 6);

	for (int i = 0; i < 6; i++) {
		cout << arr1[i] << " ";
	}
	cout << endl;
	for (int i = 0; i < 6; i++) {
		cout << arr2[i] << " ";
	}
	cout << endl;
	cout << endl;
}

int main() {
	
	test01();

	system("pause");

	return 0;
}