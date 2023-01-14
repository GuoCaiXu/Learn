//子串获取
# include <iostream>
using namespace std;
# include <string>

//功能描述：从字符串中获取想要的子串

//函数原型：
//         string substr(int pos = 0, int n = npos) const;       返回由pos开始的n个字符组成的字符串

void test01() {

	string str = "abcdef";

	string subStr = str.substr(1, 3);

	cout << "subStr = " << subStr << endl;
}

void test02() {

	string email = "zhangsan@sina.com";

	//从邮箱地址中 获取 用户名信息

	int pos = email.find("@"); //8

	string usrName = email.substr(0, pos);

	cout << "用户名为: " << usrName << endl;
}

int main() {

	//test01();
	test02();

	system("pause");

	return 0;
}

//总结：灵活的运用求子串功能， 可以在实际开发获取有效的信息