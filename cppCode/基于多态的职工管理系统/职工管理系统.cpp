#include<iostream>
using namespace std;
#include"workerManager.h"
#include"worker.h"
#include"employee.h"
#include"manager.h"
#include"boss.h"

////�������ְ����Ϣ
//void test() {
//	//����ְ������
//	Worker* worker1 = new Employee(1, "����", 1);
//	Worker* worker2 = new Manager(2, "����", 2);
//	Worker* worker3 = new Boss(3, "����", 3);
//	//��ʾְ����Ϣ
//	worker1->ShowInfo();
//	worker2->ShowInfo();
//	worker3->ShowInfo();
//	//�ͷ��ڴ�
//	delete worker1;
//	delete worker2;
//	delete worker3;
//}

int main() {
	WorkerManager wm;
	int choice = 0;
	while (true) {
		//չʾ�˵�
		wm.Show_Menu();
		cout << "����������ѡ��";
		cin >> choice;

		switch (choice) {
		case 0:
			wm.ExitSystem();
		case 1:
			cout << "����ְ����Ϣ" << endl;
			//test(); // �������ְ����Ϣ
			wm.Add_Emp(); // �������ְ����Ϣ�ĺ���
			break;
		case 2:
			cout << "��ʾְ����Ϣ" << endl;
			// ������������ʾְ����Ϣ�Ĵ���
			break;
		case 3:
			cout << "ɾ����ְְ��" << endl;
			// ����������ɾ����ְְ���Ĵ���
			break;
		case 4:
			cout << "�޸�ְ����Ϣ" << endl;
			// �����������޸�ְ����Ϣ�Ĵ���
			break;
		case 5:
			cout << "����ְ����Ϣ" << endl;
			// ���������Ӳ���ְ����Ϣ�Ĵ���
			break;
		case 6:
			cout << "���ձ������" << endl;
			// ���������Ӱ��ձ������Ĵ���
			break;
		case 7:
			cout << "��������ĵ�" << endl;
			// ������������������ĵ��Ĵ���
			break;
		default:
			system("cls"); // ����
			break;
		}
	}
}