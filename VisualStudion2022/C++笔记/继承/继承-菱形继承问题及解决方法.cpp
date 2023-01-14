//菱形继承
# include <iostream>
using namespace std;

//动物类
class animal{

public:
	int m_A;
};

//羊类
//利用虚继承 解决菱形继承问题
//在继承之前 加上关键字 virtual 变为虚继承
//Animal类称为 虚基类
class Sheep :virtual public animal{};

//驼类
class Tuo :virtual public animal{};

//羊驼类
class SheTuo : public Sheep, public Tuo{};

void test01() {

	SheTuo s1;

	s1.Sheep::m_A = 18;
	s1.Tuo::m_A = 28;

	cout << "s1.Sheep::m_A = " << s1.Sheep::m_A << endl;
	cout << "s1.Tuo::m_A =" << s1.Tuo::m_A << endl;
	cout << "s1.m_A = " << s1.m_A << endl;
}

int main() {

	test01();

	system("pause");

	return 0;
}