////自己的通用的数组类
//#pragma once
//#include <iostream>
//using namespace std;
//
//template <class T>
//class MyArray {
//public:
//	//有参构造
//	MyArray(int capacity) {
//		//cout << "MyArray(int capacity)构造函数调用" << endl;
//		this->capacity = capacity;
//		this->size = 0;
//		this->pAddress = new T[this->capacity];
//	}
//
//	//拷贝构造
//	MyArray(const MyArray& arr) {
//		//cout << "MyArray(const MyArray& arr)拷贝构造函数调用" << endl;
//		this->capacity = arr.capacity;
//		this->size = arr.size;
//		//深拷贝
//		this->pAddress = new T[arr.capacity];
//		for (int i = 0; i < this->size; i++) {
//			this->pAddress[i] = arr.pAddress[i];
//		}
//	}
//
//	//operator=重载
//	MyArray& operator=(const MyArray& arr) {
//		//cout << "MyArray& operator=(const MyArray& arr)赋值运算符重载函数调用" << endl;
//		if (this != &arr) { //防止自赋值
//			if (this->pAddress != NULL) {
//				delete[] this->pAddress; //释放原有内存
//				this->pAddress = NULL; //避免野指针
//				this->capacity = 0; //重置容量
//				this->size = 0; //重置大小
//			}
//			this->capacity = arr.capacity;
//			this->size = arr.size;
//			//深拷贝
//			this->pAddress = new T[arr.capacity];
//			for (int i = 0; i < this->size; i++) {
//				this->pAddress[i] = arr.pAddress[i];
//			}
//		}
//		return *this;
//	}
//
//	//尾插法
//	void push_back(const T& value) {
//		if (this->size >= this->capacity) {
//			cout << "数组已满，无法添加新元素" << endl;
//			return;
//		}
//		this->pAddress[this->size] = value; //将值添加到数组末尾
//		this->size++; //更新数组大小
//	}
//
//	//尾删法
//	void pop_back() {
//		if (this->size <= 0) {
//			cout << "数组为空，无法删除元素" << endl;
//			return;
//		}
//		//让用户访问不到最后一个元素,逻辑删除
//		this->size--; //减少数组大小
//	}
//
//	//通过下标访问元素
//	T& operator[](int index) {
//		if (index < 0 || index >= this->size) {
//			cout << "下标越界" << endl;
//			exit(-1); //异常处理
//		}
//		return this->pAddress[index]; //返回对应下标的元素
//	}
//
//	//返回数组的大小
//	int getSize() const {
//		return this->size; //返回数组的大小
//	}
//
//	//返回数组的容量
//	int getCapacity() const {
//		return this->capacity; //返回数组的容量
//	}
//
//	//析构函数
//	~MyArray() {
//		//cout << "~MyArray()析构函数调用" << endl;
//		if (this->pAddress != NULL) {
//			delete[] this->pAddress;
//			this->pAddress = NULL;
//		}
//	}
//
//private:
//	T* pAddress; //存放数组的首地址
//	int capacity; //数组的容量
//	int size; //数组的大小
//};