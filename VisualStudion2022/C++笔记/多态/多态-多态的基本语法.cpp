//多态
# include <iostream>
using namespace std;

//动物类
class Animal {
public:
	//virtual 是虚函数
	virtual void speak() {

		cout << "动物在说话" << endl;
	}
};

class Cat : public Animal {

public:
	//重写  函数返回值类型  函数名  函数列表  完全相同
	void speak() {          //子类也可以加virtual可写可不写不影响
		cout << "猫在说话" << endl;
	}
};

class Dog : public Animal {

public:
	void speak() {
		cout << "狗在说话" << endl;
	}
};

//执行说话函数
//地址早绑定  在编译阶段确定函数地址
//如果下执行猫说话， 那么这个函数地址就不能提前绑定， 需要运行阶段进行绑定， 也就是地址晚绑定

//动态多态满足条件
//1.有继承关系
//2.子类重写父类的虚函数
void doSpeak(Animal& animal) {
	animal.speak();
}

void test01() {
	Cat cat;

	doSpeak(cat);

	Dog dog;

	doSpeak(dog);
}


int main() {

	test01();

	system("pause");

	return 0;
}