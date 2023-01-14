//二进制写文件
# include <iostream>
# include <fstream>
using namespace std;

class Person {
public:
	
	char m_Name[64];// 姓名
	int m_Age;//年龄
};

void test01() {

	//1.包含头文件

	//2.创建流对象
	ofstream ofs;  //也可以ofstream ofs("person.txt", ios::out | ios::binary); 方式写省略第三步
	//3.打开文件
	ofs.open("person.txt", ios::out | ios::binary);
	//4.写文件
	Person p = {"张三", 18 };
	ofs.write((const char*)&p, sizeof(Person));
	//5.关闭文件
	ofs.close();
}

int main() {

	test01();

	system("Pause");

	return 0;
}