#include"boss.h"

Boss::Boss(int id, string name, int did) {
	m_Id = id;
	m_Name = name;
	m_DeptId = did;
}

void Boss::ShowInfo() {
	cout << "ְ����ţ�" << m_Id << endl;
	cout << "ְ��������" << m_Name << endl;
	cout << "ְ�����ţ�" << GetDeptName() << endl;
	cout << "��λְ�𣺹���˾��������" << endl;
}

string Boss::GetDeptName() {
	return "�ϰ�";
}