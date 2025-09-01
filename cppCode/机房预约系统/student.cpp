#include"student.h"

//��ȫ����ʵ��

//Ĭ�Ϲ���
Student::Student() {

}

//�вι���
Student::Student(int id, string name, int pwd) {
	//��ʼ������
	this->m_Id = id;
	this->m_Name = name;
	this->m_Pwd = pwd;

	//��ȡ������Ϣ
	ifstream ifs;
	ifs.open(COMPUTER_FILE, ios::in); //�����뷽ʽ���ļ�
	if (!ifs.is_open()) {
		cout << "�ļ������ڻ��ʧ�ܣ�" << endl;
		return;
	}
	ComputerRoom c;
	while (ifs >> c.m_ComId && ifs >> c.m_MaxNum) {
		this->vCom.push_back(c);
	}
	ifs.close();
}

//�˵�����
void Student::operMenu() {
	cout << "��ӭѧ����" << this->m_Name << "��¼��" << endl;
	cout << "\t\t ---------------------------------\n";
	cout << "\t\t|                                 |\n";
	cout << "\t\t|          1.����ԤԼ             |\n";
	cout << "\t\t|                                 |\n";
	cout << "\t\t|          2.�鿴�ҵ�ԤԼ         |\n";
	cout << "\t\t|                                 |\n";
	cout << "\t\t|          3.�鿴����ԤԼ         |\n";
	cout << "\t\t|                                 |\n";
	cout << "\t\t|          4.ȡ��ԤԼ             |\n";
	cout << "\t\t|                                 |\n";
	cout << "\t\t|          0.ע����¼             |\n";
	cout << "\t\t|                                 |\n";
	cout << "\t\t ---------------------------------\n";
	cout << "����������ѡ�� " << endl;
}

//����ԤԼ
void Student::applyOrder() {
	cout << "��������ʱ��Ϊ��һ������!" << endl;
	cout << "����������ԤԼ��ʱ��:" << endl;
	cout << "1.��һ" << endl;
	cout << "2.�ܶ�" << endl;
	cout << "3.����" << endl;
	cout << "4.����" << endl;
	cout << "5.����" << endl;
	int date = 0; //ԤԼ����
	int interval = 0; //ʱ���
	int room = 0; //�������

	while (true) {
		cin >> date; //����ԤԼ����
		if (date >= 1 && date <= 5) {
			break;
		}
		else {
			cout << "������������������!" << endl;
		}
	}

	cout << "����������ԤԼ��ʱ���:" << endl;
	cout << "1.����" << endl;
	cout << "2.����" << endl;
	while (true) {
		cin >> interval; //����ԤԼʱ���
		if (interval == 1 || interval == 2) {
			break;
		}
		else {
			cout << "������������������!" << endl;
		}
	}

	cout << "����������ԤԼ�Ļ������:" << endl;
	cout << "1�Ż�������:" << this->vCom[0].m_MaxNum << endl;
	cout << "2�Ż�������:" << this->vCom[1].m_MaxNum << endl;
	cout << "3�Ż�������:" << this->vCom[2].m_MaxNum << endl;
	while (true) {
		cin >> room; //����ԤԼ�������
		if (room >= 1 && room <= 3) {
			break;
		}
		else {
			cout << "������������������!" << endl;
		}
	}

	cout << "ԤԼ����ɹ����ȴ����!" << endl;

	ofstream ofs(ORDER_FILE, ios::app); //��׷�ӷ�ʽ���ļ�
	if (!ofs.is_open()) {
		cout << "�ļ������ڻ��ʧ�ܣ�" << endl;
		return;
	}
	ofs << "date:" << date << " ";
	ofs << "interval:" << interval << " ";
	ofs << "sutId:" << this->m_Id << " ";
	ofs << "stuName:" << this->m_Name << " ";
	ofs << "roomId:" << room << " ";
	ofs << "status:" << 1 << endl; //1��ʾ�����

	ofs.close();
	system("pause");
	system("cls");
}

//�鿴�ҵ�ԤԼ
void Student::showMyOrder() {
	OrderFile of;
	if (of.m_Size == 0) {
		cout << "��ԤԼ��¼!" << endl;
		system("pause");
		system("cls");
		return;
	}
	for (int i = 0; i < of.m_Size; i++) {
		if (of.m_OrderData[i]["sutId"] == to_string(this->m_Id)) {
			cout << "ԤԼ���ڣ���" << of.m_OrderData[i]["date"];
			if (of.m_OrderData[i]["interval"] == "1") {
				cout << " ����";
			}
			else {
				cout << " ����";
			}
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
	}
	system("pause");
	system("cls");
}

//�鿴����ԤԼ
void Student::showAllOrder() {
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

//ȡ��ԤԼ
void Student::cancelOrder() {
	OrderFile of;
	if (of.m_Size == 0) {
		cout << "��ԤԼ��¼!" << endl;
		system("pause");
		system("cls");
		return;
	}
	cout << "����л�ԤԼ�ɹ��ļ�¼����ȡ����������ȡ����ԤԼ��¼" << endl;

	vector<int> v; //��ſ���ȡ����ԤԼ��¼���
	int index = 1; //��¼���
	for (int i = 0; i < of.m_Size; i++) {
		if (of.m_OrderData[i]["sutId"] == to_string(this->m_Id) && (of.m_OrderData[i]["status"] == "1" || of.m_OrderData[i]["status"] == "2")) {
			v.push_back(i);
			cout << "��ţ�" << index++ << " ԤԼ���ڣ���" << of.m_OrderData[i]["date"];
			if (of.m_OrderData[i]["interval"] == "1") {
				cout << " ����";
			}
			else {
				cout << " ����";
			}
			cout << " �����ţ�" << of.m_OrderData[i]["roomId"];
			string status = " ״̬��";
			if (of.m_OrderData[i]["status"] == "1") {
				status += "�����";
			}
			else if (of.m_OrderData[i]["status"] == "2") {
				status += "ԤԼ�ɹ�";
			}
			cout << status << endl;
		}
	}
	if (v.size() == 0) {
		cout << "�޿�ȡ����ԤԼ��¼!" << endl;
		system("pause");
		system("cls");
		return;
	}
	cout << "������ȡ����ԤԼ��¼��ţ�" << endl;
	int select = 0;
	while (true) {
		cin >> select;
		if (select > 0 && select < v.size() + 1) {
			break;
		}
		else {
			cout << "������������������!" << endl;
		}
	}
	of.m_OrderData[v[select - 1]]["status"] = "-2"; //�޸�״̬Ϊ��ȡ��
	of.updateOrder(); //����ԤԼ�ļ�
	cout << "��ȡ����ѡԤԼ!" << endl;
	system("pause");
	system("cls");
}