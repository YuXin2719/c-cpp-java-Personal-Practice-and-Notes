//#include<iostream>
//using namespace std;
//#include<string>
//
////�������󣨷º�����
///*
//- ����������ʹ��ʱ����������ͨ�����������ã������в����������з���ֵ
//- �������󳬳���ͨ�����ĸ����������������Լ���״̬
//- �������������Ϊ��������
//*/
//
////1.����������ʹ��ʱ����������ͨ�����������ã������в����������з���ֵ
////��ͨ����
//int add(int a, int b) {
//	return a + b;
//}
////��������
//class Add {
//public:
//	int operator()(int a, int b) {
//		return a + b;
//	}
//};
//
//void test01() {
//	cout << add(10, 20) << endl;
//
//	Add add2;
//	cout << add2(10, 20) << endl;
//}
//
////2.�������󳬳���ͨ�����ĸ����������������Լ���״̬
//class myPrint {
//public:
//	myPrint() {
//		count = 0;
//	}
//	void operator()(string str) {
//		cout << str << endl;
//		count++;
//	}
//	int count; //�ڲ�״̬
//};
//
//void test02() {
//	myPrint p;
//	p("hello world");
//	p("hello world");
//	cout << "p�������󱻵����ˣ�" << p.count << "��" << endl;
//}
//
////3.�������������Ϊ��������
//void doPrint(myPrint& p, string str) {
//	p(str);
//}
//
//void test03() {
//	myPrint p;
//	doPrint(p, "hello");
//	doPrint(p, "world");
//	cout << "p�������󱻵����ˣ�" << p.count << "��" << endl;
//}
//
//int main() {
//	test01();
//	test02();
//	test03();
//	system("pause");
//	return 0;
//}