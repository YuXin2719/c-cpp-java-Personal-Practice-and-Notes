//#include<iostream>
//using namespace std;
//#include<string>
//
////�ַ���ƴ��
////- `string& operator+=(const char* str); ` //����+=������
////- `string& operator+=(const char c); ` //����+=������
////- `string& operator+=(const string & str); ` //����+=������
////- `string& append(const char* s); ` //���ַ���s���ӵ���ǰ�ַ�����β
////- `string& append(const char* s, int n); ` / ���ַ���s��ǰn���ַ����ӵ���ǰ�ַ�����β
////- `string& append(const char& s); ` ͬoperator += (const string & str)
////- `string& append(const char& s, int pos, int n); ` //���ַ���s�д�pos��ʼ��n���ַ����ӵ��ַ�����β
//
//void test01() {
//	string str1 = "��";
//	str1 += "������Ϸ";
//	cout << str1 << endl; // ���: �Ұ�����Ϸ
//
//	str1 += '!';
//	cout << str1 << endl; // ���: �Ұ�����Ϸ!
//
//	string str2 = "hello bro";
//	str1 += str2;
//	cout << str1 << endl; // ���: �Ұ�����Ϸ!��
//
//	string str3 = "���";
//	str3.append("����Ȥ");
//	cout << str3 << endl; // ���: ��̺���Ȥ
//
//	str3.append("game", 2);
//	cout << str3 << endl; // ���: ��̺���Ȥ����
//
//	str3.append(str2);
//	cout << str3 << endl; // ���: ��̺���Ȥ������
//
//	str3.append(str2, 6, 3); //��������: ��str2�ĵ�6��λ�ÿ�ʼ,ȡ3���ַ�
//	cout << str3 << endl; // ���: ��̺���Ȥ�������
//}
//
//int main() {
//	test01();
//	system("pause");
//	return 0;
//}