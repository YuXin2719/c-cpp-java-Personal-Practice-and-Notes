//#include<iostream>
//using namespace std;
//
////����ģ��
//
////�����������ν����ĺ���
//void swap(int& a, int& b) {
//	int temp = a;
//	a = b;
//	b = temp;
//}
//
////�������������͵ĺ���
//void swap(float& a, float& b) {
//	float temp = a;
//	a = b;
//	b = temp;
//}
//
////����ģ��Ķ���
//template <typename T> //����һ��ģ������T�����߱�������T��һ�����Ͳ���
//void mySwap(T& a, T& b) {
//	T temp = a;
//	a = b;
//	b = temp;
//}
//
//void test01() {
//	int a = 10, b = 20;
//	float c = 1.1f, d = 2.2f;
//
//	//swap(a, b); //�������εĽ�������
//	//swap(c, d); //���ø����͵Ľ�������
//
//	//ʹ�ú���ģ��
//	//���ַ�ʽʹ�ú���ģ��
//	//1.��ʾָ������
//	mySwap<int>(a, b); //��ʾָ������Ϊint
//	//2.�������Զ��Ƶ�����
//	mySwap(c, d); //�������Զ��Ƶ�����Ϊfloat
//
//	cout << "a=" << a << ",b=" << b << endl;
//	cout << "c=" << c << ",d=" << d << endl;
//}
//
//int main() {
//	test01();
//	system("pause");
//	return 0;
//}