//list反转和排序
# include <iostream>
using namespace std;
# include <list>

/*
reverse();   //反转链表
sort();      //链表排序
*/

void printList(const list<int>& L) {

	for (list<int>::const_iterator it = L.begin(); it != L.end(); it++) {

		cout << *it << " ";
	}
	cout << endl;
}

void test01() {

	//反转
	list<int>L;
	L.push_back(20);
	L.push_back(10);
	L.push_back(90);
	L.push_back(40);
	L.push_back(60);
	L.push_back(30);

	cout << "反转前" << endl;
	printList(L);

	//反转
	L.reverse();
	cout << "反转后" << endl;
	printList(L);

	cout << "--------------" << endl;

	//所有不支持随机访问迭代器的容器，不可以用标准算法
	//不支持随机访问迭代器的容器，内部会提供对应一些算法
	//sort(L.begin(), L.end());

	//排序
	cout << "排序前 " << endl;
	printList(L);
	L.sort();
	cout << "排序后" << endl;
	printList(L);

}

int main() {

	test01();

	system("pause");

	return 0;
}