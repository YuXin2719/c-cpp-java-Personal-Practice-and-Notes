//#include<iostream>
//using namespace std;
//#include<string>
//
////string���Ӵ�
//void test1() {
//	string str = "hello world";
//	string subStr = str.substr(0, 5); // ������0��ʼ������Ϊ5
//	cout << subStr << endl; // ���: hello
//}
//
////ʵ�ò���
//void test2() {
//	string email = "zhangsan@sina.com";
//	//���ʼ���ַ�л�ȡ�û�����Ϣ
//	int pos = email.find('@'); // ����'@'��λ��
//	if (pos != string::npos) { // ����ҵ���
//		string username = email.substr(0, pos); // ��ȡ��0��'@'���Ӵ�
//		cout << "Username: " << username << endl; // ����û���
//	}
//	else {
//		cout << "No '@' found in the email." << endl;
//	}
//}
//
//int main() {
//	test1();
//	test2();
//	system("pause");
//	return 0;
//}