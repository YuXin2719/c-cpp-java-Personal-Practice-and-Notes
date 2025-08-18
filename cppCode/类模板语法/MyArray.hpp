////�Լ���ͨ�õ�������
//#pragma once
//#include <iostream>
//using namespace std;
//
//template <class T>
//class MyArray {
//public:
//	//�вι���
//	MyArray(int capacity) {
//		//cout << "MyArray(int capacity)���캯������" << endl;
//		this->capacity = capacity;
//		this->size = 0;
//		this->pAddress = new T[this->capacity];
//	}
//
//	//��������
//	MyArray(const MyArray& arr) {
//		//cout << "MyArray(const MyArray& arr)�������캯������" << endl;
//		this->capacity = arr.capacity;
//		this->size = arr.size;
//		//���
//		this->pAddress = new T[arr.capacity];
//		for (int i = 0; i < this->size; i++) {
//			this->pAddress[i] = arr.pAddress[i];
//		}
//	}
//
//	//operator=����
//	MyArray& operator=(const MyArray& arr) {
//		//cout << "MyArray& operator=(const MyArray& arr)��ֵ��������غ�������" << endl;
//		if (this != &arr) { //��ֹ�Ը�ֵ
//			if (this->pAddress != NULL) {
//				delete[] this->pAddress; //�ͷ�ԭ���ڴ�
//				this->pAddress = NULL; //����Ұָ��
//				this->capacity = 0; //��������
//				this->size = 0; //���ô�С
//			}
//			this->capacity = arr.capacity;
//			this->size = arr.size;
//			//���
//			this->pAddress = new T[arr.capacity];
//			for (int i = 0; i < this->size; i++) {
//				this->pAddress[i] = arr.pAddress[i];
//			}
//		}
//		return *this;
//	}
//
//	//β�巨
//	void push_back(const T& value) {
//		if (this->size >= this->capacity) {
//			cout << "�����������޷������Ԫ��" << endl;
//			return;
//		}
//		this->pAddress[this->size] = value; //��ֵ��ӵ�����ĩβ
//		this->size++; //���������С
//	}
//
//	//βɾ��
//	void pop_back() {
//		if (this->size <= 0) {
//			cout << "����Ϊ�գ��޷�ɾ��Ԫ��" << endl;
//			return;
//		}
//		//���û����ʲ������һ��Ԫ��,�߼�ɾ��
//		this->size--; //���������С
//	}
//
//	//ͨ���±����Ԫ��
//	T& operator[](int index) {
//		if (index < 0 || index >= this->size) {
//			cout << "�±�Խ��" << endl;
//			exit(-1); //�쳣����
//		}
//		return this->pAddress[index]; //���ض�Ӧ�±��Ԫ��
//	}
//
//	//��������Ĵ�С
//	int getSize() const {
//		return this->size; //��������Ĵ�С
//	}
//
//	//�������������
//	int getCapacity() const {
//		return this->capacity; //�������������
//	}
//
//	//��������
//	~MyArray() {
//		//cout << "~MyArray()������������" << endl;
//		if (this->pAddress != NULL) {
//			delete[] this->pAddress;
//			this->pAddress = NULL;
//		}
//	}
//
//private:
//	T* pAddress; //���������׵�ַ
//	int capacity; //���������
//	int size; //����Ĵ�С
//};