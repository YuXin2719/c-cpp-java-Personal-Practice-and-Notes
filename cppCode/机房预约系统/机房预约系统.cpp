#include<iostream>
using namespace std;
#include"identity.h"
#include<fstream>
#include"globalFile.h"
#include"student.h"
#include"teacher.h"
#include"manager.h"

void managerMenu(Identity*& manager);
void studentMenu(Identity*& student);
void teacherMenu(Identity*& teacher);

//��¼����  ����1 �������ļ��� ����2 �����������
void LoginIn(string fileName, int identityType) {
	Identity* person = NULL; //����ָ�룬����ָ���������
	//���ļ�
	ifstream file;
	file.open(fileName, ios::in); //���������ļ�
	//�ж��ļ��Ƿ����
	if (!file.is_open()) {
		cout << "�ļ�������" << endl;
		file.close();
		return;
	}
	//׼�������û�������Ϣ
	int id = 0; //����/ѧ��
	string name; //����
	int pwd = 0; //����
	//�ж����
	if (identityType == 1) {
		cout << "������ѧ��" << endl;
		cin >> id;
	}
	else if (identityType == 2) {
		cout << "�����빤��" << endl;
		cin >> id;
	}
	cout << "�������û���" << endl;
	cin >> name;
	cout << "����������" << endl;
	cin >> pwd;
	//��֤��Ϣ
	if (identityType == 1) {
		//ѧ�������֤
		int fId; //�ļ���ѧ��
		string fName; //�ļ�������
		int fPwd; //�ļ�������
		while (file >> fId && file >> fName && file >> fPwd) {
			if (fId == id && fName == name && fPwd == pwd) {
				cout << "ѧ�������֤��¼�ɹ���" << endl;
				system("pause");
				system("cls");
				person = new Student(id, name, pwd); //����ѧ������
				studentMenu(person); //����ѧ���˵�
				return;
			}
		}
	}
	else if (identityType == 2) {
		//��ʦ�����֤
		int fId; //�ļ��й���
		string fName; //�ļ�������
		int fPwd; //�ļ�������
		while (file >> fId && file >> fName && file >> fPwd) {
			if (fId == id && fName == name && fPwd == pwd) {
				cout << "��ʦ�����֤��¼�ɹ���" << endl;
				system("pause");
				system("cls");
				person = new Teacher(id, name, pwd); //������ʦ����
				//������ʦ�˵�
				teacherMenu(person);
				return;
			}
		}
	}
	else if (identityType == 3) {
		//����Ա�����֤
		string fName; //�ļ�������
		int fPwd; //�ļ�������
		while (file >> fName && file >> fPwd) {
			if (fName == name && fPwd == pwd) {
				cout << "����Ա�����֤��¼�ɹ���" << endl;
				system("pause");
				system("cls");
				person = new Manager(name, pwd); //��������Ա����
				//���ù���Ա�˵�
				managerMenu(person);
				return;
			}
		}
	}
	cout << "��֤��¼ʧ�ܣ�" << endl;
	system("pause");
	system("cls");
	file.close();
}

//����Ա�˵�
void managerMenu(Identity*& manager) {
	while (1) {
		manager->operMenu(); //���ù���Ա�˵�
		Manager* man = (Manager*)manager; //����ת��
		int select = 0; //ѡ�����
		cin >> select; //����ѡ��
		if (select == 1) { //����˺�
			cout << "����˺�" << endl;
			man->addPerson();
		}
		else if (select == 2) { //�鿴�˺�
			cout << "�鿴�˺�" << endl;
			man->showPerson();
		}
		else if (select == 3) { //�鿴����
			cout << "�鿴����" << endl;
			man->showComputer();
		}
		else if (select == 4) { //���ԤԼ
			cout << "���ԤԼ" << endl;
			man->cleanFile();
		}
		else {
			delete manager;
			cout << "ע���ɹ�" << endl;
			system("pause");
			system("cls");
			return;
		}
	}
}

//ѧ���˵�
void studentMenu(Identity*& student) {
	while (1) {
		student->operMenu(); //����ѧ���˵�
		Student* stu = (Student*)student; //����ת��
		int select = 0; //ѡ�����
		cin >> select; //����ѡ��
		if (select == 1) { //����ԤԼ
			cout << "����ԤԼ" << endl;
			stu->applyOrder();
		}
		else if (select == 2) { //�鿴�ҵ�ԤԼ
			cout << "�鿴�ҵ�ԤԼ" << endl;
			stu->showMyOrder();
		}
		else if (select == 3) { //�鿴����ԤԼ
			cout << "�鿴����ԤԼ" << endl;
			stu->showAllOrder();
		}
		else if (select == 4) { //ȡ��ԤԼ
			cout << "ȡ��ԤԼ" << endl;
			stu->cancelOrder();
		}
		else {
			delete student;
			cout << "ע���ɹ�" << endl;
			system("pause");
			system("cls");
			return;
		}
	}
}

//��ʦ�˵�
void teacherMenu(Identity*& teacher) {
	while (1) {
		teacher->operMenu(); //���ý�ʦ�˵�
		Teacher* tea = (Teacher*)teacher; //����ת��
		int select = 0; //ѡ�����
		cin >> select; //����ѡ��
		if (select == 1) { //�鿴����ԤԼ
			cout << "�鿴����ԤԼ" << endl;
			tea->showAllOrder();
		}
		else if (select == 2) { //���ԤԼ
			cout << "���ԤԼ" << endl;
			tea->validOrder();
		}
		else {
			delete teacher;
			cout << "ע���ɹ�" << endl;
			system("pause");
			system("cls");
			return;
		}
	}
}

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
			LoginIn(STUDENT_FILE, 1);
			break;
		case 2:
			cout << "��ʦ��¼" << endl;
			LoginIn(TEACHER_FILE, 2);
			break;
		case 3:
			cout << "����Ա��¼" << endl;
			LoginIn(ADMIN_FILE, 3);
			break;
		case 0:
			cout << "�˳�ϵͳ,��ӭ�´�ʹ��" << endl;
			system("pause");
			return 0;
			break;
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