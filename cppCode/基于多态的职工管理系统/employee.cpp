#include "employee.h"

// ���캯��
Employee::Employee(int id, string name, int did) {
	m_Id = id;
	m_Name = name;
	m_DeptId = did;
}

// ��ʾ������Ϣ
void Employee::ShowInfo() {
	cout << "ְ����ţ�" << m_Id << endl;
	cout << "ְ��������" << m_Name << endl;
	cout << "ְ�����ţ�" << GetDeptName() << endl;
	cout << "��λְ����ɾ�����������" << endl;
}

// ��ȡ��λ����
string Employee::GetDeptName() {
	return "��ͨԱ��";
}
