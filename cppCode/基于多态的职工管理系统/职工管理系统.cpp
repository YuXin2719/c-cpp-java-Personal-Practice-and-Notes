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
			wm.Show_Emp(); // ������ʾְ����Ϣ�ĺ���
			break;
		case 3: {
			cout << "ɾ����ְְ��" << endl;
			wm.Del_Emp(); // ����ɾ��ְ���ĺ���
			break;
		}
		case 4:
			cout << "�޸�ְ����Ϣ" << endl;
			wm.Mod_Emp(); // �����޸�ְ����Ϣ�ĺ���
			break;
		case 5:
			cout << "����ְ����Ϣ" << endl;
			wm.Find_Emp(); // ���ò���ְ����Ϣ�ĺ���
			break;
		case 6:
			cout << "���ձ������" << endl;
			wm.Sort_Emp(); // ��������ְ����Ϣ�ĺ���
			break;
		case 7:
			cout << "��������ĵ�" << endl;
			wm.Clean_File(); // ��������ļ��ĺ���
			break;
		default:
			system("cls"); // ����
			break;
		}
	}
}