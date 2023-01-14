# include <iostream>
using namespace std;
# include <string>
# include <vector>
# include <ctime>
# include <map>
# define CEHUA 1
# define MEISHU 2
# define YANFA 3

class Staff {

public:
	Staff(string name, int wage) {
		
		this->m_Name = name;
		this->m_Wage = wage;
	}
	string m_Name;  //姓名
	int m_Wage;  //工资
};

//创建10名员工
void createSta(vector<Staff>&v) {

	for (int i = 0; i < 10; i++) {
		string namesend = "ABCDEFGHIJ";
		string name;

		name += namesend[i];
		int wage = rand() % 10000 + 10000;

		Staff s(name, wage);

		v.push_back(s);
	}
}

//随机分组
void Digr(vector<Staff>& v, multimap<int, Staff>&m) {

	for (vector<Staff>::iterator it = v.begin(); it != v.end(); it++) {

		int key = rand() % 3 + 1;
		
		m.insert(make_pair(key, *it));
	}
}

//显示
void showStaff(multimap<int, Staff>& m) {

	multimap<int, Staff>::iterator pos = m.find(CEHUA);
	int count = m.count(CEHUA);
	cout << "策划部门：    "  << count  << "人" << endl;
	int index = 0;
	for (; pos != m.end() && index < count; pos++, index++) {

		cout << "姓名：" << pos->second.m_Name << " 工资：" << pos->second.m_Wage << endl;
	}

	cout << "-----------------------------------------" << endl;

    pos = m.find(MEISHU);
	count = m.count(MEISHU);
	cout << "美术部门：   " << count  << "人" << endl;
	index = 0;
	for (; pos != m.end() && index < count; pos++, index++) {

		cout << "姓名：" << pos->second.m_Name << " 工资：" << pos->second.m_Wage << endl;
	}

	cout << "-----------------------------------------" << endl;

	pos = m.find(YANFA);
	count = m.count(YANFA);
	cout << "研发部门：   " << count  << "人" << endl;
	index = 0;
	for (; pos != m.end() && index < count; pos++, index++) {

		cout << "姓名：" << pos->second.m_Name << " 工资：" << pos->second.m_Wage << endl;
	}
}

int main() {

	//创建10名员工
	vector<Staff>v;
	createSta(v);

	srand((unsigned int)time(NULL));

	//遍历vector容器 随机分组
	multimap<int, Staff>m;
	Digr(v, m);

	//显示部门信息
	showStaff(m);

	system("pause");

	return 0;
}