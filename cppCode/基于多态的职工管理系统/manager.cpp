#include"manager.h"

Manager::Manager(int id, string name, int did) {
	m_Id = id;
	m_Name = name;
	m_DeptId = did;
}

void Manager::ShowInfo() {
	cout << "职工编号：" << m_Id << endl;
	cout << "职工姓名：" << m_Name << endl;
	cout << "职工部门：" << GetDeptName() << endl;
	cout << "岗位职责：管理本部门员工" << endl;
}

string Manager::GetDeptName() {
	return "经理";
}
