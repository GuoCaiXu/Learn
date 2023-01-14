//vector插入和删除
# include <iostream>
using namespace std;
# include <vector>

//功能描述：对vector容器进行插入， 删除操作

/*
函数原型：
       push_back(lel);                                     尾部插入元素ele
	   pop_back();                                         删除最后一个元素
	   insert(const_iterator pos, ele);                    迭代器指向位置pos插入元素ele
	   insert(const_iterator pos, int count, ele);         迭代器指向位置pos插入count个元素ele
	   erase(const_iterator pos);                          删除迭代器指向的元素
	   erase(cinst_iterator start, const_iterator end);    删除迭代器从start到end之间元素
	   clear();                                            删除容器中所有元素
*/

void printVector(vector<int>& v) {

	for (vector<int>::iterator it = v.begin(); it != v.end(); it++) {
		cout << *it << " ";
	}
	cout << endl;
}

void test01() {

	vector<int> v;
	//尾插
	v.push_back(10);
	v.push_back(20);
	v.push_back(30);
	v.push_back(40);
	v.push_back(50);

	//遍历
	printVector(v);

	//尾删
	v.pop_back();
	printVector(v);

	//插入  第一个参数也是迭代器
	v.insert(v.begin(), 100);
	printVector(v);

	v.insert(v.begin(), 2, 100);
	printVector(v);

	//删除  参数也是迭代器
	v.erase(v.begin());
	printVector(v);

	//清空
	//v.erase(v.begin(), v.end());
	v.clear();
	printVector(v);


}

int main() {

	test01();

	system("pause");

	return 0;
}