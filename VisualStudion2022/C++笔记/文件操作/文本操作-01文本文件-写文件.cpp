//文本操作
# include <iostream>
# include <fstream>//头文件包含

using namespace std;


/*
操作文件的三大类
1.ofstream : 写操作
2.ifstream : 读操作
3.fstream  : 读写操作
*/

int main() {

	//1.包含头文件 fstream
	
	//2.创建流对象
	ofstream ofs;//ofs 是名字随便取

	//3.指定打开方式
	ofs.open("test.txt", ios::out);

	//4.写内容
	ofs << "姓名：张三" << endl;
	ofs << "性别：男" << endl;
	ofs << "年龄：18" << endl;

	//5.关闭文件
	ofs.close();
	

	system("pause");

	return 0;
}