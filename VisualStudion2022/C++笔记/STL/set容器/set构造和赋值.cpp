//set构造和赋值
# include <iostream>
using namespace std;
# include <set>

/*
构造：
     set<T> st;            //默认构造函数
     set(Const set &st);   //拷贝构造函数

赋值：
     set& operator=(const set &st);     //重载等号操作符
*/

void printSet(const set<int>s) {

    for (set<int>::const_iterator it = s.begin(); it != s.end(); it++) {

        cout << *it << " ";
    }
    cout << endl;
}

void test01() {

    set<int>s1;

    //插入数据 只有insert方式
    s1.insert(10);
    s1.insert(40);
    s1.insert(20);
    s1.insert(30);
    s1.insert(30);
    s1.insert(40);

    //遍历容器
    //set容器的特点，所有元素在插入的时候会自动排序
    //set容器不允许插入重复的值
    printSet(s1);   //10 20 30 40

    //拷贝构造
    set<int>s2(s1);
    printSet(s2);

    //赋值
    set<int>s3;
    s3 = s2;
    printSet(s3);
}

int main() {

    test01();

	system("pause");

	return 0;
}