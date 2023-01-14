# include <iostream>
using namespace std;

//抽象不同零件的类
//抽象CPU类
class CPU {

public :
	//抽象的计算函数
	virtual void calculate() = 0;
};

//抽象显卡类
class VideoCard {

public:
	//抽象的显卡函数
	virtual void display() = 0;
};
//抽象内存条类 
class Memory {

public:
	//抽象的储存函数
	virtual void storage() = 0;
};

//电脑类
class Computer {

public:

	Computer(CPU* cpu, VideoCard * vc, Memory* mem) {

		m_cpu = cpu;
		m_vc = vc;
		m_mem = mem;
	}

	~Computer() {

		if (m_cpu != NULL) {
			delete m_cpu;
			m_cpu = NULL;
		}
		if (m_vc != NULL) {
			delete m_vc;
			m_vc = NULL;
		}
		if (m_mem != NULL) {
			delete m_mem;
			m_mem = NULL;
		}
	}

	//工作函数
	void work() {

		//让零件工作起来， 调用接口
		m_cpu->calculate();
		m_vc->display();
		m_mem->storage();
	}

private:
	CPU * m_cpu;//cpu零件指针
	VideoCard * m_vc;//显卡零件指针
	Memory * m_mem;//内存条零件指针
};

//具体的厂商
//Intel厂商
class IntelCPU : public CPU {
public :
	void calculate() {

		cout << "Intel的CPU开始计算了！" << endl;
	}
};

class IntelVideoCard : public VideoCard {
public:

	void display() {

		cout << "Intel的显卡开始显示了！" << endl;
	}
};

class IntelMemory : public Memory {
public:

	void storage() {

		cout << "Intel的内存条开始储存了！" << endl;
	}
};

//Lenovo
class LenovoCPU : public CPU {
public:
	void calculate() {

		cout << "Lenovo的CPU开始计算了！" << endl;
	}
};

class LenovoVideoCard : public VideoCard {
public:

	void display() {

		cout << "Lenovo的显卡开始显示了！" << endl;
	}
};

class LenovoMemory : public Memory {
public:

	void storage() {

		cout << "Lenovo的内存条开始储存了！" << endl;
	}
};

void test01() {

	//第一台电脑组装
	cout << "第二台电脑开始工作" << endl;
	CPU* intelCPU = new IntelCPU;
	VideoCard* intelVideoCard = new IntelVideoCard;
	Memory* intelMemory = new IntelMemory;

	Computer* computer1 = new Computer(intelCPU, intelVideoCard, intelMemory);
	computer1->work();
	delete computer1;

	cout << "-----------------------------------------------------------" << endl;
	//第二台电脑组装
	cout << "第二台电脑开始工作" << endl;
	Computer* computer2 = new Computer(new LenovoCPU, new LenovoVideoCard, new LenovoMemory);
	computer2->work();
	delete computer2;

	cout << "--------------------------------------" << endl;
	//第三台电脑组装
	cout << "第三台电脑开始工作" << endl;
	Computer* computer3 = new Computer(new IntelCPU, new LenovoVideoCard, new LenovoMemory);
	computer3->work();
	delete computer3;
}
int main() {

	test01();

	system("Pause");

	return 0;
}