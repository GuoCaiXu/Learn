//vector存放自定义数据类型
# include <iostream>
using namespace std;
# include <string>
# include <vector>

//自定义数据类型
class Person {

public:
	Person(string name, int age) {

		this->mName = name;
		this->mAge = age;
	}

	string mName;
	int mAge;
};

void test01() {

	vector<Person>v;
	Person p1("aaa", 10);
	Person p2("bbb", 20);
	Person p3("ccc", 30);
	Person p4("ddd", 40);
	Person p5("eee", 50);

	//向容器中添加数据
	v.push_back(p1);
	v.push_back(p2);
	v.push_back(p3);
	v.push_back(p4);
	v.push_back(p5);

	//遍历容器中的数据
	for (vector<Person>::const_iterator it = v.begin(); it != v.end(); it++) {

		//cout << "姓名:" << (*it).mName << " 年龄:" << (*it).mAge << endl;
		cout << "姓名:" << it->mName << " 年龄:" << it->mAge << endl;
	}
}

//存放自定义数据类型 指针
void test02() {

	vector<Person*>v;
	Person p1("aaa", 10);
	Person p2("bbb", 20);
	Person p3("ccc", 30);
	Person p4("ddd", 40);
	Person p5("eee", 50);

	//向容器中添加数据
	v.push_back(&p1);
	v.push_back(&p2);
	v.push_back(&p3);
	v.push_back(&p4);
	v.push_back(&p5);

	for (vector<Person*>::iterator it = v.begin(); it != v.end(); it++) {
		cout << " 姓名:" << (*it)->mName << " 年龄:" << (*it)->mAge << endl;
	}
}

int main() {

	//test01();
	test02();

	system("pause");

	return 0;
}