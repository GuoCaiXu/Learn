//list排序案例
# include <iostream>
using namespace std;
# include <string>
# include <list>

class Person {

public:

	Person(string name, int age, int height) {
		this->m_Name = name;
		this->m_Age = age;
		this->m_Height = height;
	}

	string m_Name;
	int m_Age;
	int m_Height;
};

//创造五个人
void createPer(list<Person>&L) {

	Person p1("张三", 35, 165);
	Person p2("李四", 35, 177);
	Person p3("于安林", 16, 175);
	Person p4("小丽", 18, 155);
	Person p5("狂徒", 35, 176);

	L.push_back(p1);
	L.push_back(p2);
	L.push_back(p3);
	L.push_back(p4);
	L.push_back(p5);
}

//排序规则
bool comparePer(Person& p1, Person& p2) {

	//按照年龄 升序
	if (p1.m_Age == p2.m_Age) {

		return p1.m_Height > p2.m_Height;
	}

	return p1.m_Age < p2.m_Age;
}

//显示排序
void showPer(const list<Person>&L) {

	for (list<Person>::const_iterator it = L.begin(); it != L.end(); it++) {

		cout << " 姓名：" << (*it).m_Name << " \t年龄：" << (*it).m_Age << " \t身高：" << (*it).m_Height << endl;
	}
}

int main() {

	//创造五个人
	list<Person>L;
	createPer(L);
	cout << "排序前" << endl;
	showPer(L);

	cout << "------------------------------------------------------" << endl;
	//排序
	L.sort(comparePer);
	cout << "排序后" << endl;
	showPer(L);

	system("Pause");

	return 0;
}

