#include"manager.h"

Manager::Manager(int id, string name, int did) {
	m_Id = id;
	m_Name = name;
	m_DeptId = did;
}

void Manager::ShowInfo() {
	cout << "ְ����ţ�" << m_Id << endl;
	cout << "ְ��������" << m_Name << endl;
	cout << "ְ�����ţ�" << GetDeptName() << endl;
	cout << "��λְ�𣺹�������Ա��" << endl;
}

string Manager::GetDeptName() {
	return "����";
}
