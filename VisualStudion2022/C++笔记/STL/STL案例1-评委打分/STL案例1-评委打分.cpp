# include <iostream>
using namespace std;
# include <vector>
# include <deque>
# include <string>
# include <ctime>
# include <algorithm>

//选手类
class Person {

public:
	Person(string name, int score) {

		this->m_Name = name;
		this->m_Score = score;
	}

	string m_Name;  //姓名
	int m_Score;  //平均分
};

//1.创建五名选手
void creatPerson(vector<Person>& v) {

	string nameSend = "ABCDE";
	for (int i = 0; i < 5; i++) {
		string name;
		name += nameSend[i];

		int score = 0;

		Person p(name, score);

		v.push_back(p);
	}
}

//2.给五名选手打分
void setScore(vector<Person>& v) {

	for (vector<Person>::iterator it = v.begin(); it != v.end(); it++) {

		deque<int>d;
		for (int j = 0; j < 10; j++) {

			d.push_back(rand() % 41 + 60);
		}

		//小到大排序
		sort(d.begin(), d.end());


		//去除最低分和最高分
		d.pop_back();
		d.pop_front();

		//取平均分
		int sum = 0;
		for (deque<int>::iterator div = d.begin(); div != d.end(); div++) {

			sum += *div;
		}
		int avg = sum / d.size();
		it->m_Score = avg;
	}
}

//3.显示最后得分
void showScore(vector<Person>& v) {

	for (vector<Person>::iterator it = v.begin(); it != v.end(); it++) {

		cout << "姓名： 选手" << (*it).m_Name << " 平均分:" << (*it).m_Score << endl;
	}
}

int main() {

	//随机数种子
	srand((unsigned int)time(NULL));

	//1.创建五名选手
	vector<Person>v;
	creatPerson(v);

	//2.给五名选手打分
	setScore(v);

	//3.显示最后得分
	showScore(v);

	system("pause");

	return 0;
}