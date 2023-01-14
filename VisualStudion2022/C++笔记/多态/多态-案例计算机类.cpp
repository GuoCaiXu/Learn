# include <iostream>
using namespace std;

//多态好处：
//1.组织结构清晰
//2.可读性强
//3.对于前期和后期扩展及维修

//实现计算机抽象类
class AbstractCalculator {
public:

	virtual int getResut() {

		return 0;
	}

	int m_Num1;
	int m_Num2;
};

//加法计算机类
class AddCalculator : public AbstractCalculator {

public:
	int getResut() {
		return m_Num1 + m_Num2;
	}
};

//减法计算机类
class SubCalculator : public AbstractCalculator {

public:
	int getResut() {
		return m_Num1 - m_Num2;
	}
};

//乘法计算机类
class MulCalculat : public AbstractCalculator {

public:
	int getResut() {
		return m_Num1 * m_Num2;
	}
};

void test() {

	//多态的使用条件
	//父类指针或引用指向子类对象

	//加法运算
	AbstractCalculator* abc = new AddCalculator;
	abc->m_Num1 = 10;
	abc->m_Num2 = 10;

	cout << abc->m_Num1 << "+" << abc->m_Num2 << "=" << abc->getResut() << endl;

	delete abc; //用完后记得销毁

	//减法运算
	abc = new SubCalculator;
	abc->m_Num1 = 100;
	abc->m_Num2 = 10;

	cout << abc->m_Num1 << "-" << abc->m_Num2 << "=" << abc->getResut() << endl;

	delete abc;

	//乘法运算
	abc = new MulCalculat;
	abc->m_Num1 = 100;
	abc->m_Num2 = 10;

	cout << abc->m_Num1 << "*" << abc->m_Num2 << "=" << abc->getResut() << endl;

	delete abc;
}

int main() {

	test();

	system("pause");

	return 0;
}