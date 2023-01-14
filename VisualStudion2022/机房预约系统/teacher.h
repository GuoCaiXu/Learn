#pragma once
# include <iostream>
# include <vector>
# include "identity.h"
# include "orderFile.h"
# include "manager.h"
using namespace std;

class Teacher : public Identity {

public:

	//构造函数
	Teacher();

	//有参构造函数
	Teacher(int empid, string name, string pwd);

	//菜单界面
	virtual void operMenu();

	//查看所有预约
	void showAllOrder();

	//审核预约
	void validOrder();

	//教师编号
	int m_EmpId;
};