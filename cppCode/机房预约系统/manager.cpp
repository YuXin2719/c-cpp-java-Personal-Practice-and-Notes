#include"manager.h"

//ȫ����ʵ��

//Ĭ�Ϲ���
Manager::Manager() {
}

//�вι���
Manager::Manager(string name, int pwd) {
	this->m_Name = name;
	this->m_Pwd = pwd;

	//��ʼ������
	this->initVector();

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
	cout << "��������Ϊ��" << this->vCom.size() << endl;
	ifs.close();
}

//�˵�����
void Manager::operMenu() {
	cout << "��ӭ����Ա��" << this->m_Name << "��¼��" << endl;
	cout << "\t\t ---------------------------------\n";
	cout << "\t\t|                                 |\n";
	cout << "\t\t|          1.����˺�             |\n";
	cout << "\t\t|                                 |\n";
	cout << "\t\t|          2.�鿴�˺�             |\n";
	cout << "\t\t|                                 |\n";
	cout << "\t\t|          3.�鿴����             |\n";
	cout << "\t\t|                                 |\n";
	cout << "\t\t|          4.���ԤԼ             |\n";
	cout << "\t\t|                                 |\n";
	cout << "\t\t|          0.ע����¼             |\n";
	cout << "\t\t|                                 |\n";
	cout << "\t\t ---------------------------------\n";
	cout << "����������ѡ�� " << endl;
}

//����˺�
void Manager::addPerson() {
	cout << "����������˺ŵ����ͣ�1.ѧ�� 2.��ʦ" << endl;
	string fileName; //�ļ���
	string tip; //��ʾ
	ofstream ofs; //���������

	int select = 0; //ѡ�����
	cin >> select; //����ѡ��

	string errorTip; //������ʾ

	if (select == 1) {
		//���ѧ��
		fileName = STUDENT_FILE;
		tip = "������ѧ��ѧ�ţ�";
		errorTip = "ѧ���ظ������������룡";
	}
	else {
		//��ӽ�ʦ
		fileName = TEACHER_FILE;
		tip = "�������ʦְ���ţ�";
		errorTip = "ְ�����ظ������������룡";
	}

	ofs.open(fileName, ios::out | ios::app); //��׷�ӷ�ʽ���ļ�
	if (!ofs.is_open()) {
		cout << "�ļ������ڻ��ʧ�ܣ�" << endl;
		return;
	}
	int id; //�˺�
	string name; //����
	int pwd; //����
	cout << tip << endl;
	while (true) {
		cin >> id; //�����˺�
		//����˺��Ƿ��ظ�
		if (this->checkRepeat(id, select)) {
			cout << errorTip << endl;
		}
		else {
			break; //�˺Ų��ظ�������ѭ��
		}
	}
	cout << "������������" << endl;
	cin >> name;
	cout << "���������룺" << endl;
	cin >> pwd;

	//���ļ��������Ϣ
	ofs << id << " " << name << " " << pwd << endl;
	cout << "����˺ųɹ���" << endl;

	system("pause");
	system("cls");

	ofs.close();

	//��ʼ������
	this->initVector();
}

//��ӡѧ����Ϣ
void printStudent(Student& s) {
	cout << "ѧ�ţ�" << s.m_Id << "\t������" << s.m_Name << "\t���룺" << s.m_Pwd << endl;
}

//��ӡ��ʦ��Ϣ
void printTeacher(Teacher& t) {
	cout << "ְ���ţ�" << t.m_EmpId << "\t������" << t.m_Name << "\t���룺" << t.m_Pwd << endl;
}

//�鿴�˺�
void Manager::showPerson() {
	cout << "��ѡ��鿴���ݣ�" << endl;
	cout << "1.�鿴����ѧ��" << endl;
	cout << "2.�鿴���н�ʦ" << endl;

	int select = 0; //ѡ�����
	cin >> select; //����ѡ��

	if (select == 1) {
		//�鿴����ѧ��
		if (this->vStu.size() == 0) {
			cout << "��ǰ��ѧ����Ϣ��" << endl;
			return;
		}
		for (vector<Student>::iterator it = this->vStu.begin(); it != this->vStu.end(); it++) {
			printStudent(*it);
		}
	}
	else {
		//�鿴���н�ʦ
		if (this->vTea.size() == 0) {
			cout << "��ǰ�޽�ʦ��Ϣ��" << endl;
			return;
		}
		for (vector<Teacher>::iterator it = this->vTea.begin(); it != this->vTea.end(); it++) {
			printTeacher(*it);
		}
	}
	system("pause");
	system("cls");
}

//���ԤԼ
void Manager::cleanFile() {
	ofstream ofs(ORDER_FILE, ios::trunc); //����շ�ʽ���ļ�
	if (!ofs.is_open()) {
		cout << "�ļ������ڻ��ʧ�ܣ�" << endl;
		return;
	}
	ofs.close();
	cout << "���ԤԼ�ɹ���" << endl;
	system("pause");
	system("cls");
}

//�鿴������Ϣ
void Manager::showComputer() {
	cout << "������Ϣ���£�" << endl;
	if (this->vCom.size() == 0) {
		cout << "��ǰ�޻�����Ϣ��" << endl;
		return;
	}
	for (vector<ComputerRoom>::iterator it = this->vCom.begin(); it != this->vCom.end(); it++) {
		cout << "������ţ�" << it->m_ComId << "\t�������������" << it->m_MaxNum << endl;
	}
	system("pause");
	system("cls");
}

//��ʼ����������ȡѧ������ʦ�ļ��е���Ϣ���ŵ�������
void Manager::initVector() {
	//��ȡѧ���ļ��е���Ϣ
	ifstream ifs;
	ifs.open(STUDENT_FILE, ios::in); //�����뷽ʽ���ļ�
	if (!ifs.is_open()) {
		cout << "�ļ������ڻ��ʧ�ܣ�" << endl;
		return;
	}

	vStu.clear(); //�������
	vTea.clear();

	Student s;
	while (ifs >> s.m_Id && ifs >> s.m_Name && ifs >> s.m_Pwd) {
		vStu.push_back(s);
	}
	cout << "ѧ������Ϊ��" << vStu.size() << endl;
	ifs.close();

	//��ȡ��ʦ�ļ��е���Ϣ
	ifstream ifs2;
	ifs2.open(TEACHER_FILE, ios::in); //�����뷽ʽ���ļ�
	if (!ifs2.is_open()) {
		cout << "�ļ������ڻ��ʧ�ܣ�" << endl;
		return;
	}

	vTea.clear(); //�������
	Teacher t;
	while (ifs2 >> t.m_EmpId && ifs2 >> t.m_Name && ifs2 >> t.m_Pwd) {
		vTea.push_back(t);
	}
	cout << "��ʦ����Ϊ��" << vTea.size() << endl;
	ifs2.close();
}

//����ظ� ������������id���������ͣ�����ֵ����true�ظ� false���ظ���
bool Manager::checkRepeat(int id, int type) {
	if (type == 1) {
		//ѧ��
		for (vector<Student>::iterator it = vStu.begin(); it != vStu.end(); it++) {
			if (it->m_Id == id) {
				return true; //�ظ�
			}
		}
	}
	else {
		//��ʦ
		for (vector<Teacher>::iterator it = vTea.begin(); it != vTea.end(); it++) {
			if (it->m_EmpId == id) {
				return true; //�ظ�
			}
		}
	}
	return false; //���ظ�
}