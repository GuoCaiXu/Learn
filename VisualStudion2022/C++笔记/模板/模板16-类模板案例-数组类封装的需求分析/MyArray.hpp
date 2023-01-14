//自己的通用数组类
# pragma once
# include <iostream>
using namespace std;

template<class T>
class MyArray {

private:
	T* pAddress; //指针指向堆区开辟的真实数组
	int m_Capacity; //容量
	int m_Size; //大小

public:
	//构造函数
	MyArray(int capacity) {
		this->m_Capacity = capacity;
		this->m_Size = 0;
		this->pAddress = new T[this->m_Capacity];
	}

	//拷贝函数
	MyArray(const MyArray& arr) {
		this->m_Capacity = arr.m_Capacity;
		this->m_Size = arr.m_Size;
		this->pAddress = new T[arr.m_Capacity];
		for (int i = 0; i < arr.m_Size; i++) {

			this->pAddress[i] = arr.pAddress[i];
		}
	}

	//赋值运算符重载， 防止浅拷贝问题
	MyArray& operator=(const MyArray& arr) {
		//先判断原来堆区是否有数据， 如果有先释放
		if (this->pAddress != NULL) {

			delete[] this->pAddress;
			this->pAddress = NULL;
			this->m_Size = 0;
			this->m_Capacity = 0;
		}

		//深拷贝
		this->m_Capacity = arr.m_Capacity;
		this->m_Size = arr.m_Size;
		this->pAddress = new T[arr.m_Capacity];
		for (int i = 0; i < arr.m_Size; i++) {

			this->pAddress[i] = arr.pAddress[i];
		}

		return *this;
	}

	//析构函数
	~MyArray() {
		if (this->pAddress != NULL) {
			delete[] this->pAddress;
			this->pAddress = NULL;
		}
	}

	//尾插法
	void Push_Back(const T& val) {
		if (this->m_Size == this->m_Capacity) {
			return;
		}
		this->pAddress[this->m_Size] = val;
		this->m_Size++;
	}

	//尾删法
	void Del_Back() {
		if (this->m_Size == 0) {
			return;
		}

		this->m_Size--;
	}

	//通过下标访问元素
	T& operator[](int index) {
		return this->pAddress[index];
	}

	//获取当前元素个数
	int getSize() {
		return this->m_Size;
	}

	//获取数组容量
	int getCapacity() {
		return this->m_Capacity;
	}
};
