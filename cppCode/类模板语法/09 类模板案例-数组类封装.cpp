//#include<iostream>
//using namespace std;
//#include "MyArray.hpp"
//
//void printArray(MyArray<int>& arr) {
//	for (int i = 0; i < arr.getSize(); i++) {
//		cout << arr[i] << " "; //�������ص�[]����Ԫ��
//	}
//	cout << endl;
//}
//
//void test01() {
//	//����һ��MyArray����
//	MyArray<int> arr(10);
//
//	for (int i = 0; i < 10; i++) {
//		//����push_back���������������Ԫ��
//		arr.push_back(i); //�����������Ԫ��
//	}
//	printArray(arr);
//	//��ӡ�����ʹ�С
//	cout << "����Ϊ��" << arr.getCapacity() << endl;
//	cout << "��СΪ��" << arr.getSize() << endl;
//
//	//����βɾ��
//	MyArray<int> arr2(10);
//	for (int i = 0; i < 10; i++) {
//		arr2.push_back(i + 10); //�����������Ԫ��
//	}
//	arr2.pop_back(); //ɾ�����һ��Ԫ��
//	printArray(arr2);
//	//��ӡ�����ʹ�С
//	cout << "����Ϊ��" << arr2.getCapacity() << endl;
//	cout << "��СΪ��" << arr2.getSize() << endl;
//
//	////ʹ�ÿ������캯��
//	//MyArray<int> arr2(arr);
//	////ʹ�ø�ֵ���������
//	//MyArray<int> arr3(100);
//	//arr3 = arr2;
//}
//
////�����Զ�����������
//class Person {
//public:
//	string name;
//	int age;
//	Person() {};
//	Person(string name, int age) : name(name), age(age) {}
//};
//
//void printPersonArray(MyArray<Person>& arr) {
//	for (int i = 0; i < arr.getSize(); i++) {
//		cout << "Name: " << arr[i].name << ", Age: " << arr[i].age << endl; //�������ص�[]����Ԫ��
//	}
//}
//
//void test02() {
//	MyArray<Person> arr(10);
//	arr.push_back(Person("Alice", 20));
//	arr.push_back(Person("Bob", 25));
//	arr.push_back(Person("Charlie", 30));
//
//	printPersonArray(arr);
//	//��ӡ�����ʹ�С
//	cout << "����Ϊ��" << arr.getCapacity() << endl;
//	cout << "��СΪ��" << arr.getSize() << endl;
//}
//
//int main() {
//	test01();
//	test02();
//	system("pause");
//	return 0;
//}