#include<iostream>
using namespace std;

int main() {
	int select = 0; //ѡ�����

	while (1) {
		//ʵ�ֲ˵�
		cout << "**********��ӭʹ�û���ԤԼϵͳ**********" << endl;
		cout << endl;
		cout << "������������" << endl;
		cout << "1.ѧ��" << endl;
		cout << "2.��ʦ" << endl;
		cout << "3.����Ա" << endl;
		cout << "0.�˳�" << endl;

		cin >> select; //����ѡ��
		switch (select) {
		case 1:
			cout << "ѧ����¼" << endl;
			break;
		case 2:
			cout << "��ʦ��¼" << endl;
			break;
		case 3:
			cout << "����Ա��¼" << endl;
			break;
		case 0:
			cout << "�˳�ϵͳ" << endl;
			return 0;
		default:
			cout << "�����������������" << endl;
			system("pause");
			system("cls");
			break;
		}
	}

	system("pause");
	return 0;
}