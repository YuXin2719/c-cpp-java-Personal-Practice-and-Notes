#include<iostream>
using namespace std;
#include"speechManager.h"

int main() {
	//�������������
	SpeechManager sm;

	//����12��ѡ��״̬
	//for (auto v : sm.m_Speaker) {
	//	cout << "ѡ�ֱ�ţ�" << v.first << " ������" << v.second.m_Name << " �ɼ���" << v.second.m_Score[0] << endl;
	//}

	int select = 0; //�����洢�û���ѡ��
	while (true) {
		sm.showMenu();
		cout << "����������ѡ��";
		cin >> select;
		switch (select)
		{
		case 1: //��ʼ�ݽ�����
			sm.startSpeech();
			sm.initSpeech();
			break;
		case 2: //�鿴�����¼
			sm.loadRecord();
			sm.showRecord();
			break;

		case 3: //��ձ�����¼
			sm.clearRecord();
			break;

		case 0: //�˳�����
			sm.exitSpeech();
			break;
		default:
			cout << "�����������������룡" << endl;
			system("pause");
			system("cls");
			break;
		}
	}

	system("pause");
	return 0;
}