//类模板案例
# include <iostream>
using namespace std;
# include "MyArray.hpp"
# include <string>

/*
案例描述：
        可以对内置数据类型以及自定义数据类型的数据进行储存
		将数组中的数据存储到堆区
		构造函数中可以传入数组容量
		提供对应的拷贝函数以及operator=防止浅拷贝问题
		提供尾插法和尾删法对数组中的数据进行增加和删除
		可以通过下标的方式访问数组中的元素
		可以获取数组中当前元素个数和数组容量
*/

//打印函数
void printIntArray(MyArray<int>& arr) {
	for (int i = 0; i < arr.getSize(); i++) {
		cout << arr[i] << endl;
	}
}

void test01() {

	MyArray<int>arr1(5);
	for (int i = 0; i < arr1.getCapacity(); i++) {
		
		arr1.Push_Back(i);
	}

	cout << "arr1的打印输出为:" << endl;

	printIntArray(arr1);

	cout << "arr1的容量为:" << arr1.getCapacity() << endl;
	cout << "arr1的大小为:" << arr1.getSize() << endl;

	cout << "------------------------" << endl;
	MyArray<int>arr2(arr1);

	cout << "arr2的打印输出为:" << endl;

	printIntArray(arr2);


	//尾删
	arr2.Del_Back();
	cout << "arr2尾删后:" << endl;
	cout << "arr2的容量为:" << arr2.getCapacity() << endl;
	cout << "arr2的大小为:" << arr2.getSize() << endl;
}

void test02();

int main() {

	//test01();
	test02();

	system("pause");

	return 0;
}

//测试自定义数据类型
class Person {

public :

	Person(){}
	//有参构造
	Person(string name, int age) {
		this->m_Name = name;
		this->m_Age = age;
	}

	string m_Name;
	int m_Age;
};

void printPersonArray(MyArray<Person> &arr) {

	for (int i = 0; i < arr.getSize(); i++) {
		cout << "姓名:" << arr[i].m_Name << "  年龄:" << arr[i].m_Age << endl;
	}
}

void test02() {

	MyArray<Person>arr3(10);

	Person p1("张三", 18);
	Person p2("李四", 19);
	Person p3("孙悟空", 999);
	Person p4("小李", 20);
	Person p5("小丽", 22);

	//将数据插入到数组中
	arr3.Push_Back(p1);
	arr3.Push_Back(p2);
	arr3.Push_Back(p3);
	arr3.Push_Back(p4);
	arr3.Push_Back(p5);

	//打印数组
	printPersonArray(arr3);

	//输出容量
	cout << "输入容量大小为:" << arr3.getCapacity() << endl;

	//输出的大小
	cout << "输入大小为:" << arr3.getSize() << endl;

}