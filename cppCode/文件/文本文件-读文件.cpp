//#include <iostream>
//using namespace std;
//#include <fstream>
//#include <string>
//
////�ı��ļ� ���ļ�
//void test01() {
//	//1.����ͷ�ļ�
//
//	//2.��������������
//	ifstream ifs;
//
//	//3.���ļ�
//	ifs.open("test.txt", ios::in);
//
//	//4.�ж��ļ��Ƿ�򿪳ɹ�
//	if (!ifs.is_open()) {
//		cout << "�ļ���ʧ��" << endl;
//		return;
//	}
//
//	//5.������
//	////	��һ�ַ�ʽ
//	//char buf[1024] = { 0 };
//	//while (ifs >> buf) {
//	//	cout << buf << endl;
//	//}
//
//	////	�ڶ��ַ�ʽ
//	//char buf2[1024] = { 0 };
//	//while (ifs.getline(buf2, sizeof(buf2))) {
//	//	cout << buf2 << endl;
//	//}
//
//	//	�����ַ�ʽ
//	string str;
//	while (getline(ifs, str)) {
//		cout << str << endl;
//	}
//
//	//  �����ַ�ʽ
//	//char c;
//	//while ((c = ifs.get()) != EOF) { //EOF���ļ������� end of file
//	//	cout << c;
//	//}
//
//	//6.�ر��ļ�
//	ifs.close();
//}
//
//int main()
//{
//
//	test01();
//
//	system("pause");
//	return 0;
//}