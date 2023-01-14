# pragma once
# include <iostream>
using namespace std;

template<class T1, class T2>
class Person {

public:
	Person(T1 name, T2 age) {

		this->m_Name = name;
		this->m_Age = age;
	}

	void showPerson() {

		cout << "ÐÕÃû:" << this->m_Name << "  ÄêÁä:" << this->m_Age << endl;
	}

	T1 m_Name;
	T2 m_Age;
};