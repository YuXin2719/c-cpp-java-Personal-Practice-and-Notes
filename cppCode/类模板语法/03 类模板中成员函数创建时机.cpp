//#include<iostream>
//using namespace std;
//
////��ģ���г�Ա��������ʱ��
////��ģ���г�Ա�����ڵ���ʱ�Ŵ���
//
//class Person1 {
//public:
//	//��Ա����
//	void showPerson1() {
//		cout << "showPerson1����" << endl;
//	}
//};
//
//class Person2 {
//public:
//	//��Ա����
//	void showPerson2() {
//		cout << "showPerson2����" << endl;
//	}
//};
//
//template<class T>
//class MyClass {
//public:
//	T obj;
//	//��Ա����
//	void func1() {
//		cout << "func1����" << endl;
//		obj.showPerson1();
//	}
//
//	void func2() {
//		cout << "func2����" << endl;
//		obj.showPerson2();
//	}
//};
//
//void test01() {
//	//������ģ�����
//	MyClass<Person1> myClass1;
//	//���ó�Ա����
//	myClass1.func1();
//
//	//������ģ�����
//	MyClass<Person2> myClass2;
//	//���ó�Ա����
//	myClass2.func2();
//}
//
//int main() {
//	test01();
//	system("pause");
//	return 0;
//}