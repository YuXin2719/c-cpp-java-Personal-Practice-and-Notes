//#include<iostream>
//using namespace std;
//
////��ͨ�����ͺ���ģ�������
//
////1.��ͨ�������Է�����ʽ����ת����������ģ�岻����
////2.����ģ�� ���Զ������Ƶ�,�����Է�����ʽ����ת��
////2.����ģ�� ����ʾָ������,���Է�����ʽ����ת��
//
////��ͨ����
//int add1(int a, int b) {
//	return a + b;
//}
//
////����ģ��
//template<typename T>
//T add2(T a, T b) {
//	return a + b;
//}
//
//void test01() {
//	int a = 10;
//	int b = 20;
//	char c = 'A'; //char���͵�'A'��Ӧ��ASCII����65
//	//cout << add(a, b) << endl; //30
//	cout << add1(a, c) << endl; //30
//
//	//�Զ������Ƶ�,���ᷢ����ʽ����ת��
//	cout << add2(a, b) << endl; //30
//	//��ʾָ������,���Է�����ʽ����ת��
//	cout << add2<int>(a, c) << endl; //75
//}
//
//int main() {
//
//	test01();
//
//	system("pause");
//	return 0;
//}