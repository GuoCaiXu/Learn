//继承基本语法
# include <iostream>
using namespace std;

class Basepage {

public:
	void header() {

		cout << "首页, 公开课， 登录， 注册...（公共头部）" << endl;
	}
	void footer() {

		cout << "帮助中心， 交流合作， 站内地图...（公共底部）" << endl;
	}
	void left() {

		cout << "Java, python, C++...（公共分类列表）" << endl;
	}
};

//继承的好处： 减少重复代码
//语法： class 子类： 继承方式 父类
//子类 也称为 派生类
//父类 也称为 基类

class Java : public Basepage {   //继承基本语法

public:
	void content() {

		cout << "Java下载页面" << endl;
	}
};

class Python : public Basepage {

public:
	void content() {

		cout << "Python下载页面" << endl;
	}
};

class Cpp : public Basepage {

public:
	void content() {

		cout << "C++下载页面" << endl;
	}
};

void test01() {

	Java ja;
	ja.header();
	ja.footer(); 
    ja.left();
	ja.content();

	cout << "--------------------" << endl;

	Python py;
	py.header();
	py.footer();
	py.left();
	py.content();

	cout << "--------------------" << endl;

	Cpp cp;
	cp.header();
	cp.footer();
	cp.left();
	cp.content();
}

int main() {

	test01();

	system("pause");

	return 0;
}