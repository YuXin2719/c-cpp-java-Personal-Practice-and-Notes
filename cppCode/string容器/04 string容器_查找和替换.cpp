//#include<iostream>
//using namespace std;
//#include<string>
//
////�ַ������Һ��滻
//
////1.����
//void test01() {
//	string str = "hello world";
//	//�����ַ���
//	int pos = str.find("world");
//	if (pos != string::npos) {
//		cout << "�ҵ��ַ��� 'world'��λ�ã�" << pos << endl;
//	}
//	else {
//		cout << "δ�ҵ��ַ��� 'world'" << endl;
//	}
//
//	//rfind �Ӻ���ǰ����
//	pos = str.rfind("hello");
//	if (pos != string::npos) {
//		cout << "�Ӻ���ǰ�ҵ��ַ��� 'hello'��λ�ã�" << pos << endl;
//	}
//	else {
//		cout << "δ�ҵ��ַ��� 'hello'" << endl;
//	}
//}
//
////2.�滻
//void test02() {
//	string str = "hello world";
//	//�滻�ַ���
//	str.replace(6, 5, "C++"); //��λ��6��ʼ���滻5���ַ�Ϊ"C++"
//	cout << "�滻����ַ�����" << str << endl;
//}
//
//int main() {
//	test01();
//	test02();
//	system("pause");
//	return 0;
//}