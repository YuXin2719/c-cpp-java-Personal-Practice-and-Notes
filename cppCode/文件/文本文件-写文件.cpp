#include <iostream>
using namespace std;
#include <fstream> //����ͷ�ļ�fstream

//�ı��ļ� д�ļ�

void test01() {
	//1.����ͷ�ļ� fstream

	//2.����������
	ofstream ofs; //�������������

	//3.���ļ�
	ofs.open("test.txt", ios::out); //���ļ���ָ���򿪷�ʽΪдģʽ

	//4.�ж��ļ��Ƿ�򿪳ɹ�
	if (!ofs.is_open()) {
		cout << "�ļ���ʧ��" << endl;
		return; //�����ʧ�ܣ�ֱ�ӷ���
	}

	//5.д���ݵ��ļ�
	ofs << "hello world" << endl; //���ļ�д������

	//6.�ر��ļ�
	ofs.close(); //�ر��ļ���
}

int main()
{

	test01(); //���ú���ִ��д�ļ�����

	system("pause");
	return 0;
}