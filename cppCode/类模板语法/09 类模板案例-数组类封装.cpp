//#include<iostream>
//using namespace std;
//#include "MyArray.hpp"
//
//void printArray(MyArray<int>& arr) {
//	for (int i = 0; i < arr.getSize(); i++) {
//		cout << arr[i] << " "; //利用重载的[]访问元素
//	}
//	cout << endl;
//}
//
//void test01() {
//	//创建一个MyArray对象
//	MyArray<int> arr(10);
//
//	for (int i = 0; i < 10; i++) {
//		//利用push_back方法向数组中添加元素
//		arr.push_back(i); //向数组中添加元素
//	}
//	printArray(arr);
//	//打印容量和大小
//	cout << "容量为：" << arr.getCapacity() << endl;
//	cout << "大小为：" << arr.getSize() << endl;
//
//	//测试尾删法
//	MyArray<int> arr2(10);
//	for (int i = 0; i < 10; i++) {
//		arr2.push_back(i + 10); //向数组中添加元素
//	}
//	arr2.pop_back(); //删除最后一个元素
//	printArray(arr2);
//	//打印容量和大小
//	cout << "容量为：" << arr2.getCapacity() << endl;
//	cout << "大小为：" << arr2.getSize() << endl;
//
//	////使用拷贝构造函数
//	//MyArray<int> arr2(arr);
//	////使用赋值运算符重载
//	//MyArray<int> arr3(100);
//	//arr3 = arr2;
//}
//
////测试自定义数据类型
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
//		cout << "Name: " << arr[i].name << ", Age: " << arr[i].age << endl; //利用重载的[]访问元素
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
//	//打印容量和大小
//	cout << "容量为：" << arr.getCapacity() << endl;
//	cout << "大小为：" << arr.getSize() << endl;
//}
//
//int main() {
//	test01();
//	test02();
//	system("pause");
//	return 0;
//}