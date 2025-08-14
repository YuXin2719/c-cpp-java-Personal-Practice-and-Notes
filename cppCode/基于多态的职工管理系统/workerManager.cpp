#include "workerManager.h"

WorkerManager::WorkerManager() {
	//1.�ļ�������
	ifstream ifs(FILENAME, ios::in); // ���ļ����ж�ȡ
	if (!ifs.is_open()) { // ����ļ���ʧ��
		cout << "�ļ������ڻ��ʧ�ܣ�" << endl;
		m_EmpNum = 0; // ��ʼ��ְ������Ϊ0
		m_EmpArray = nullptr; // ��ʼ��ְ������ָ��Ϊ��
		m_FileIsEmpty = true; // �ļ�Ϊ�ձ�־Ϊ��
		ifs.close(); // �ر��ļ�
		return;
	}

	//2.�ļ����ڣ�����û������
	char ch;
	ifs >> ch; // ��ȡһ���ַ�
	if (ifs.eof()) { // �����ȡ���ļ�ĩβ��˵���ļ�Ϊ��
		cout << "�ļ�Ϊ�գ�" << endl;
		m_EmpNum = 0; // ��ʼ��ְ������Ϊ0
		m_EmpArray = nullptr; // ��ʼ��ְ������ָ��Ϊ��
		m_FileIsEmpty = true; // �ļ�Ϊ�ձ�־Ϊ��
		ifs.close(); // �ر��ļ�
		return;
	}

	//3.�ļ�������������
	m_EmpNum = get_EmpNum(); // ͳ��ְ������
	cout << "ְ������Ϊ��" << m_EmpNum << endl; //���Դ���
}

WorkerManager::~WorkerManager() {
}

//��ʾ�˵�
void WorkerManager::Show_Menu() {
	cout << "**********************************" << endl;
	cout << "******* ��ӭʹ��ְ������ϵͳ *****" << endl;
	cout << "********* 0.�˳�������� *********" << endl;
	cout << "********* 1.����ְ����Ϣ *********" << endl;
	cout << "********* 2.��ʾְ����Ϣ *********" << endl;
	cout << "********* 3.ɾ����ְְ�� *********" << endl;
	cout << "********* 4.�޸�ְ����Ϣ *********" << endl;
	cout << "********* 5.����ְ����Ϣ *********" << endl;
	cout << "********* 6.���ձ������ *********" << endl;
	cout << "********* 7.��������ĵ� *********" << endl;
	cout << "**********************************" << endl;
}

//�˳�ϵͳ
void WorkerManager::ExitSystem() {
	cout << "��ӭ�´�ʹ�ã�" << endl;
	system("pause");
	exit(0);
}

//�����ļ�
void WorkerManager::save() {
	ofstream ofs(FILENAME, ios::out | ios::trunc); // ���ļ����������
	if (!ofs.is_open()) {
		cout << "�ļ���ʧ�ܣ�" << endl;
		return;
	}
	for (int i = 0; i < m_EmpNum; i++) {
		ofs << m_EmpArray[i]->m_Id << " "
			<< m_EmpArray[i]->m_Name << " "
			<< m_EmpArray[i]->m_DeptId << endl;
	}
	ofs.close();
	cout << "�����ѱ��浽�ļ��У�" << endl;
}

//����ְ����Ϣ,����ǵ�һ�����ְ����Ϣ������Ҫ�����ļ�,������ǵ�һ����ӣ������ļ�ĩβ�������
void WorkerManager::Add_Emp() {
	cout << "���������ְ����������" << endl;
	int addNum = 0; // ��¼���ְ��������
	cin >> addNum;
	if (addNum > 0) {
		//���������ְ�����������
		int newSize = m_EmpNum + addNum;
		//�����¿ռ�
		Worker** newSpace = new Worker * [newSize];
		//��ԭ���ռ��µ����ݿ������¿ռ���
		if (m_EmpArray != nullptr) {
			for (int i = 0; i < m_EmpNum; i++) {
				newSpace[i] = m_EmpArray[i];
			}
		}
		//�������������
		for (int i = 0; i < addNum; i++) {
			int id; // ְ�����
			string name; // ְ������
			int dSelect; // ְ����λѡ��
			cout << "������� " << i + 1 << " ����ְ���ı�ţ�" << endl;
			cin >> id;
			cout << "������� " << i + 1 << " ����ְ����������" << endl;
			cin >> name;
			cout << "������� " << i + 1 << " ����ְ���ĸ�λ��" << endl;
			cout << "1.��ͨԱ��" << endl;
			cout << "2.����" << endl;
			cout << "3.�ϰ�" << endl;
			cin >> dSelect;
			Worker* worker = nullptr;
			switch (dSelect) {
			case 1: // ��ͨԱ��
				worker = new Employee(id, name, dSelect);
				break;
			case 2: // ����
				worker = new Manager(id, name, dSelect);
				break;
			case 3: // �ϰ�
				worker = new Boss(id, name, dSelect);
				break;
			default:
				break;
			}
			//��������ְ�����󣬱��浽������
			newSpace[m_EmpNum + i] = worker;
		}
		//�ͷ�ԭ�пռ�
		delete[] m_EmpArray;
		//���ĳ�Ա����
		m_EmpArray = newSpace;
		m_EmpNum = newSize;
		m_FileIsEmpty = false; // �ļ���Ϊ��
		//��ʾ��ӳɹ�
		cout << "�ɹ���� " << addNum << " ����ְ����" << endl;

		//��ӳɹ���,���浽�ļ���
		save();
	}
	else {
		cout << "�����ְ���������Ϸ���" << endl;
	}
	system("pause");
	system("cls"); // ����
}

//ͳ������
int WorkerManager::get_EmpNum() {
	ifstream ifs(FILENAME, ios::in); // ���ļ����ж�ȡ

	int id;
	string name;
	int deptId;

	int count = 0; // ͳ��ְ������

	while (ifs >> id >> name >> deptId) { // ���ж�ȡְ����Ϣ
		count++; // ÿ��ȡһ�У�������1
	}
	ifs.close(); // �ر��ļ�

	return count; // ����ͳ�Ƶ�ְ������
}

//��ʼ��Ա��
void WorkerManager::init_Emp() {
	ifstream ifs(FILENAME, ios::in); // ���ļ����ж�ȡ

	int id;
	string name;
	int deptId;

	int index = 0; // ��������
	while (ifs >> id >> name >> deptId) { // ���ж�ȡְ����Ϣ
		Worker* worker = nullptr; // ����ְ������ָ��
		if (deptId == 1) {
			worker = new Employee(id, name, deptId);
		}
		else if (deptId == 2) {
			worker = new Manager(id, name, deptId);
		}
		else if (deptId == 3) {
			worker = new Boss(id, name, deptId);
		}
		m_EmpArray[index++] = worker; // ��ְ�������������
	}
	ifs.close(); // �ر��ļ�
	m_FileIsEmpty = false; // �ļ�Ϊ�ձ�־Ϊ��
}