//#include<iostream>
//using namespace std;
//#include<string>
//
////string�ĸ�ֵ����
////- `string& operator=(const char* s); ` //char*�����ַ��� ��ֵ����ǰ�ַ���
////- `string& operator=(const char& s); ` //���ַ���s������ǰ�ַ���
////- `string& operator=(char c); ` //���ַ���ֵ����ǰ�ַ���
////- `string& assign(const char* s); ` //���ַ���s������ǰ�ַ���
////- `string& assign(const char* s, int n); ` //���ַ���s��ǰn���ַ�������ǰ�ַ���
////- `string& assign(const char& s); ` //���ַ���s������ǰ�ַ���
////- `string& assign(int n, char c); ` //��n���ַ�c������ǰ�ַ���
//
//void test01() {
//	string str1; //Ĭ�Ϲ��캯��
//	str1 = "hello"; //char*�����ַ��� ��ֵ����ǰ�ַ���
//	cout << "str1: " << str1 << endl;
//
//	string str2; //Ĭ�Ϲ��캯��
//	str2 = str1; //���ַ���str1������ǰ�ַ���
//	cout << "str2: " << str2 << endl;
//
//	string str3; //Ĭ�Ϲ��캯��
//	str3 = 'a'; //���ַ�'a'��ֵ����ǰ�ַ���
//	cout << "str3: " << str3 << endl;
//
//	string str4; //Ĭ�Ϲ��캯��
//	str4.assign("world"); //���ַ���"world"������ǰ�ַ���
//	cout << "str4: " << str4 << endl;
//
//	string str5; //Ĭ�Ϲ��캯��
//	str5.assign("hello world", 5); //���ַ���"hello world"��ǰ5���ַ�������ǰ�ַ���
//	cout << "str5: " << str5 << endl;
//
//	string str6; //Ĭ�Ϲ��캯��
//	str6.assign(str1); //���ַ���str1������ǰ�ַ���
//	cout << "str6: " << str6 << endl;
//
//	string str7; //Ĭ�Ϲ��캯��
//	str7.assign(5, 'x'); //��5���ַ�'x'������ǰ�ַ���
//	cout << "str7: " << str7 << endl;
//}
//
//int main() {
//
//	test01();
//
//	system("pause");
//	return 0;
//}