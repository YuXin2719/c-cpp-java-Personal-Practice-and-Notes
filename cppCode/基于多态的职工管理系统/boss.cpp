#include"boss.h"

Boss::Boss(int id, string name, int did) {
	m_Id = id;
	m_Name = name;
	m_DeptId = did;
}

void Boss::ShowInfo() {
	cout << "职工编号：" << m_Id << endl;
	cout << "职工姓名：" << m_Name << endl;
	cout << "职工部门：" << GetDeptName() << endl;
	cout << "岗位职责：管理公司所有事务" << endl;
}

string Boss::GetDeptName() {
	return "老板";
}