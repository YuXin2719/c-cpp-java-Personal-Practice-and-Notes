//#include<iostream>
//using namespace std;
//
////����ģ��ע������
//
//template <typename T> //typename�����滻Ϊclass
//void mySwap(T& a, T& b) {
//	T temp = a;
//	a = b;
//	b = temp;
//}
//
////1.�Զ������Ƶ��������Ƶ���һ�µ���������T�ſ���ʹ��
//void test01() {
//	int a = 10, b = 20;
//	char c = 'A';
//	mySwap(a, b); //�������Զ��Ƶ���TΪint����
//	//mySwap(a, c); //�������޷��Ƶ���T�����ͣ���Ϊint��char���Ͳ�һ��
//	cout << "a=" << a << ",b=" << b << endl;
//}
//
////2.ģ�����ȷ����T�����Ͳ���ʹ��
//template <typename T>
//void func() {
//	cout << "func() called" << endl;
//}
//
//void test02() {
//	//func(); //�������޷��Ƶ���T������
//	func<int>(); //��ʾָ��T������Ϊint
//	func<double>(); //��ʾָ��T������Ϊdouble
//}
//
//int main() {
//
//	test01();
//	test02();
//
//	system("pause");
//	return 0;
//}