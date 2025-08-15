#include "workerManager.h"

//���캯��
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

	//����ְ���������ٿռ�
	m_EmpArray = new Worker * [m_EmpNum]; // ��̬����ְ������ռ�
	//��ʼ��ְ����Ϣ
	init_Emp(); // ���ļ��ж�ȡְ����Ϣ����ʼ��
	// ���Դ���
	//for (int i = 0; i < m_EmpNum; i++) {
	//	cout << "ְ����ţ�" << m_EmpArray[i]->m_Id
	//		<< ", ������" << m_EmpArray[i]->m_Name
	//		<< ", ��λ��" << m_EmpArray[i]->GetDeptName() << endl;
	//}
}

//��������
WorkerManager::~WorkerManager() {
	//�ͷ�ְ������ռ�
	if (m_EmpArray != nullptr) {
		for (int i = 0; i < m_EmpNum; i++) {
			delete m_EmpArray[i]; // �ͷ�ÿ��ְ��������ڴ�
		}
		delete[] m_EmpArray; // �ͷ�ְ��������ڴ�
		m_EmpArray = nullptr; // ָ���ÿ�
	}
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

//����ְ����Ϣ,����ǵ�һ�����ְ����Ϣ������Ҫ�����ļ�,������ǵ�һ����ӣ������ļ�ĩβ������ݣ����ְ��ID�Ƿ��ظ�
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
			// ���ְ������Ƿ��ظ�
			if (IsExist(id) != -1) {
				cout << "ְ������Ѵ��ڣ����������룡" << endl;
				i--; // �ظ���ǰѭ��
				continue; // ������ǰѭ������������
			}
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

//��ʾְ��
void WorkerManager::Show_Emp() {
	if (m_FileIsEmpty) {
		cout << "�ļ������ڻ��¼Ϊ�գ�" << endl;
	}
	else {
		for (int i = 0; i < m_EmpNum; i++) {
			m_EmpArray[i]->ShowInfo(); // ����ְ������ʾ��Ϣ����
		}
	}
	system("pause");
	system("cls"); // ����
}

//ְ���Ƿ����
int WorkerManager::IsExist(int id) {
	int index = -1; // ��¼ְ���������е�λ�ã�Ĭ�ϲ�����
	for (int i = 0; i < m_EmpNum; i++) {
		if (m_EmpArray[i]->m_Id == id) {
			index = i; // �ҵ�ְ������¼λ��
			break;
		}
	}
	return index; // ����ְ��λ�ã�-1��ʾ������
}

//ɾ��ְ��
void WorkerManager::Del_Emp() {
	if (m_FileIsEmpty) {
		cout << "�ļ������ڻ��¼Ϊ�գ�" << endl;
	}
	else {
		cout << "������Ҫɾ����ְ����ţ�" << endl;
		int id;
		cin >> id;
		int index = IsExist(id); // �ж�ְ���Ƿ����
		if (index != -1) { // �������
			for (int i = index; i < m_EmpNum - 1; i++) {
				m_EmpArray[i] = m_EmpArray[i + 1]; // �������ְ��ǰ��
			}
			m_EmpNum--; // ְ��������1
			save(); // ���浽�ļ�
			cout << "ɾ���ɹ���" << endl;
		}
		else {
			cout << "ְ�������ڣ�" << endl;
		}
	}
	system("pause");
	system("cls"); // ����
}

//�޸�ְ����Ϣ,���ְ��ID�Ƿ��ظ�������ظ�����ʾ��������
void WorkerManager::Mod_Emp() {
	if (m_FileIsEmpty) {
		cout << "�ļ������ڻ��¼Ϊ�գ�" << endl;
	}
	else {
		cout << "������Ҫ�޸ĵ�ְ����ţ�" << endl;
		int id;
		cin >> id;
		int index = IsExist(id); // �ж�ְ���Ƿ����
		if (index != -1) { // �������
			int newId; // ��ְ�����
			string newName; // ��ְ������
			int dSelect; // ��ְ����λѡ��
			cout << "�������µ�ְ����ţ�" << endl;
			cin >> newId;
			// �����ְ������Ƿ��ظ�
			if (IsExist(newId) != -1) {
				cout << "ְ������Ѵ��ڣ����������룡" << endl;
				system("pause");
				return; // �˳��޸�
			}
			// ɾ��ԭ��ְ������
			delete m_EmpArray[index];
			cout << "�������µ�ְ��������" << endl;
			cin >> newName;
			cout << "�������µ�ְ����λ��" << endl;
			cout << "1.��ͨԱ��" << endl;
			cout << "2.����" << endl;
			cout << "3.�ϰ�" << endl;
			cin >> dSelect;
			Worker* worker = nullptr;
			switch (dSelect) {
			case 1: // ��ͨԱ��
				worker = new Employee(newId, newName, dSelect);
				break;
			case 2: // ����
				worker = new Manager(newId, newName, dSelect);
				break;
			case 3: // �ϰ�
				worker = new Boss(newId, newName, dSelect);
				break;
			default:
				break;
			}
			m_EmpArray[index] = worker; // ����ְ����Ϣ
			save(); // ���浽�ļ�
			cout << "�޸ĳɹ���" << endl;
		}
		else {
			cout << "ְ�������ڣ�" << endl;
		}
	}
	system("pause");
	system("cls"); // ����
}

//����ְ����Ϣ���ṩ���ַ�ʽ������Ų��ҺͰ���������
void WorkerManager::Find_Emp() {
	if (m_FileIsEmpty) {
		cout << "�ļ������ڻ��¼Ϊ�գ�" << endl;
	}
	else {
		cout << "��ѡ����ҷ�ʽ��" << endl;
		cout << "1.��ְ����Ų���" << endl;
		cout << "2.��ְ����������" << endl;
		int select = 0;
		cin >> select;
		if (select == 1) { // ����Ų���
			cout << "������Ҫ���ҵ�ְ����ţ�" << endl;
			int id;
			cin >> id;
			int index = IsExist(id); // �ж�ְ���Ƿ����
			if (index != -1) { // �������
				cout << "�ҵ���ְ������Ϣ���£�" << endl;
				m_EmpArray[index]->ShowInfo(); // ��ʾְ����Ϣ
			}
			else {
				cout << "ְ�������ڣ�" << endl;
			}
		}
		else if (select == 2) { // ����������
			cout << "������Ҫ���ҵ�ְ��������" << endl;
			string name;
			cin >> name;
			bool found = false; // ��־�Ƿ��ҵ�
			for (int i = 0; i < m_EmpNum; i++) {
				if (m_EmpArray[i]->m_Name == name) {
					cout << "�ҵ���ְ������Ϣ���£�" << endl;
					m_EmpArray[i]->ShowInfo(); // ��ʾְ����Ϣ
					found = true; // �ҵ���־��Ϊ��
				}
			}
			if (!found) {
				cout << "ְ�������ڣ�" << endl;
			}
		}
		else {
			cout << "����ѡ������������ѡ��" << endl;
		}
	}
	system("pause");
	system("cls"); // ����
}

//����ְ����Ϣ������ְ���������,�ṩ����ͽ������ַ�ʽ
void WorkerManager::Sort_Emp() {
	if (m_FileIsEmpty) {
		cout << "�ļ������ڻ��¼Ϊ�գ�" << endl;
		system("pause");
		system("cls"); // ����
	}
	else {
		cout << "��ѡ������ʽ��" << endl;
		cout << "1.����" << endl;
		cout << "2.����" << endl;
		int select = 0;
		cin >> select;
		for (int i = 0; i < m_EmpNum - 1; i++) {
			for (int j = 0; j < m_EmpNum - i - 1; j++) {
				if ((select == 1 && m_EmpArray[j]->m_Id > m_EmpArray[j + 1]->m_Id) ||
					(select == 2 && m_EmpArray[j]->m_Id < m_EmpArray[j + 1]->m_Id)) {
					//����
					Worker* temp = m_EmpArray[j];
					m_EmpArray[j] = m_EmpArray[j + 1];
					m_EmpArray[j + 1] = temp;
				}
			}
		}
		cout << "������ɣ�" << endl;
		Show_Emp(); // ��ʾ������ְ����Ϣ
	}
}

//����ļ�
void WorkerManager::Clean_File() {
	cout << "ȷ������ļ���" << endl;
	cout << "1.ȷ��" << endl;
	cout << "2.ȡ��" << endl;
	int select = 0;
	cin >> select;
	if (select == 1) {
		ofstream ofs(FILENAME, ios::trunc); // �Ը��Ƿ�ʽ���ļ�
		ofs.close(); // �ر��ļ�
		if (m_EmpArray != nullptr) {
			for (int i = 0; i < m_EmpNum; i++) {
				delete m_EmpArray[i]; // �ͷ�ְ�������ڴ�
			}
			delete[] m_EmpArray; // �ͷ�ְ�������ڴ�
			m_EmpArray = nullptr; // ָ���ÿ�
			m_EmpNum = 0; // ְ��������0
			m_FileIsEmpty = true; // �ļ�Ϊ�ձ�־Ϊ��
		}
		cout << "�ļ�����գ�" << endl;
	}
	else {
		cout << "ȡ������ļ�������" << endl;
	}
	system("pause");
	system("cls"); // ����
}