#include "employee.h"

// 构造函数
Employee::Employee(int id, string name, int did) {
	m_Id = id;
	m_Name = name;
	m_DeptId = did;
}

// 显示个人信息
void Employee::ShowInfo() {
	cout << "职工编号：" << m_Id << endl;
	cout << "职工姓名：" << m_Name << endl;
	cout << "职工部门：" << GetDeptName() << endl;
	cout << "岗位职责：完成经理交给的任务" << endl;
}

// 获取岗位名称
string Employee::GetDeptName() {
	return "普通员工";
}
