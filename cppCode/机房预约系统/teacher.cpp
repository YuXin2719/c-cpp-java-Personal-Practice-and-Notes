#include"teacher.h"

//��ȫ����ʵ��

//Ĭ�Ϲ���
Teacher::Teacher() {
}

//�вι���
Teacher::Teacher(int id, string name, int pwd) {
	//��ʼ������
	this->m_EmpId = id;
	this->m_Name = name;
	this->m_Pwd = pwd;
}

//�˵�����
void Teacher::operMenu() {
	cout << "��ӭ��ʦ��" << this->m_Name << "��¼��" << endl;
	cout << "\t\t ---------------------------------\n";
	cout << "\t\t|                                 |\n";
	cout << "\t\t|          1.�鿴����ԤԼ         |\n";
	cout << "\t\t|                                 |\n";
	cout << "\t\t|          2.���ԤԼ             |\n";
	cout << "\t\t|                                 |\n";
	cout << "\t\t|          0.ע����¼             |\n";
	cout << "\t\t|                                 |\n";
	cout << "\t\t ---------------------------------\n";
	cout << "����������ѡ�� " << endl;
}

//���ԤԼ
void Teacher::validOrder() {
	OrderFile of;
	if (of.m_Size == 0) {
		cout << "��ԤԼ��¼!" << endl;
		system("pause");
		system("cls");
		return;
	}
	cout << "����˵�ԤԼ��¼���£�" << endl;

	vector<int> v; //��Ŵ���˵ļ�¼�±�
	int index = 0; //��¼���
	//ֻ��ʾ����˵�ԤԼ
	for (int i = 0; i < of.m_Size; i++) {
		if (of.m_OrderData[i]["status"] == "1") {
			v.push_back(i); //���±��������
			cout << ++index << ". ԤԼ���ڣ���" << of.m_OrderData[i]["date"];
			if (of.m_OrderData[i]["interval"] == "1") {
				cout << " ����";
			}
			else {
				cout << " ����";
			}
			cout << " ѧ�ţ�" << of.m_OrderData[i]["sutId"];
			cout << " ������" << of.m_OrderData[i]["stuName"];
			cout << " �����ţ�" << of.m_OrderData[i]["roomId"];
			string status = " ״̬��";
			status += "�����";
			cout << status << endl;
		}
	}
	if (index == 0) {
		cout << "�޴���˵�ԤԼ��¼!" << endl;
		system("pause");
		system("cls");
		return;
	}
	cout << "��������Ҫ��˵ļ�¼(0������)�� " << endl;
	int select = 0; //ѡ�����
	cin >> select; //����ѡ��
	if (select < 0 || select > index) {
		cout << "����������������룡" << endl;
		system("pause");
		system("cls");
		return;
	}
	else if (select == 0) {
		system("cls");
		return;
	}
	else {
		int orderIndex = v[select - 1]; //��ȡ��ʵ�ļ�¼�±�
		cout << "��������˽��(1.ͨ�� 2.��ͨ��)�� " << endl;
		int result = 0; //��˽��
		cin >> result; //������˽��
		if (result == 1) {
			of.m_OrderData[orderIndex]["status"] = "2"; //�޸�״̬ΪԤԼ�ɹ�
			of.updateOrder(); //�����ļ�
			cout << "���ͨ����ԤԼ�ɹ���" << endl;
			system("pause");
			system("cls");
			return;
		}
		else if (result == 2) {
			of.m_OrderData[orderIndex]["status"] = "-1"; //�޸�״̬ΪԤԼʧ��
			of.updateOrder(); //�����ļ�
			cout << "��˲�ͨ����ԤԼʧ�ܣ�" << endl;
			system("pause");
			system("cls");
			return;
		}
		else {
			cout << "����������ʧ�ܣ�" << endl;
			system("pause");
			system("cls");
			return;
		}
	}
}

//�鿴����ԤԼ
void Teacher::showAllOrder() {
	OrderFile of;
	if (of.m_Size == 0) {
		cout << "��ԤԼ��¼!" << endl;
		system("pause");
		system("cls");
		return;
	}
	for (int i = 0; i < of.m_Size; i++) {
		cout << "ԤԼ���ڣ���" << of.m_OrderData[i]["date"];
		if (of.m_OrderData[i]["interval"] == "1") {
			cout << " ����";
		}
		else {
			cout << " ����";
		}
		cout << " ѧ�ţ�" << of.m_OrderData[i]["sutId"];
		cout << " ������" << of.m_OrderData[i]["stuName"];
		cout << " �����ţ�" << of.m_OrderData[i]["roomId"];
		string status = " ״̬��";
		if (of.m_OrderData[i]["status"] == "1") {
			status += "�����";
		}
		else if (of.m_OrderData[i]["status"] == "2") {
			status += "ԤԼ�ɹ�";
		}
		else if (of.m_OrderData[i]["status"] == "-1") {
			status += "ԤԼʧ��";
		}
		else {
			status += "��ȡ��";
		}
		cout << status << endl;
	}
	system("pause");
	system("cls");
}