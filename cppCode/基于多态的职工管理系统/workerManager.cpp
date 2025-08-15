#include "workerManager.h"

//构造函数
WorkerManager::WorkerManager() {
	//1.文件不存在
	ifstream ifs(FILENAME, ios::in); // 打开文件进行读取
	if (!ifs.is_open()) { // 如果文件打开失败
		cout << "文件不存在或打开失败！" << endl;
		m_EmpNum = 0; // 初始化职工人数为0
		m_EmpArray = nullptr; // 初始化职工数组指针为空
		m_FileIsEmpty = true; // 文件为空标志为真
		ifs.close(); // 关闭文件
		return;
	}

	//2.文件存在，但是没有数据
	char ch;
	ifs >> ch; // 读取一个字符
	if (ifs.eof()) { // 如果读取到文件末尾，说明文件为空
		cout << "文件为空！" << endl;
		m_EmpNum = 0; // 初始化职工人数为0
		m_EmpArray = nullptr; // 初始化职工数组指针为空
		m_FileIsEmpty = true; // 文件为空标志为真
		ifs.close(); // 关闭文件
		return;
	}

	//3.文件存在且有数据
	m_EmpNum = get_EmpNum(); // 统计职工人数
	cout << "职工人数为：" << m_EmpNum << endl; //测试代码

	//根据职工人数开辟空间
	m_EmpArray = new Worker * [m_EmpNum]; // 动态分配职工数组空间
	//初始化职工信息
	init_Emp(); // 从文件中读取职工信息并初始化
	// 测试代码
	//for (int i = 0; i < m_EmpNum; i++) {
	//	cout << "职工编号：" << m_EmpArray[i]->m_Id
	//		<< ", 姓名：" << m_EmpArray[i]->m_Name
	//		<< ", 岗位：" << m_EmpArray[i]->GetDeptName() << endl;
	//}
}

//析构函数
WorkerManager::~WorkerManager() {
	//释放职工数组空间
	if (m_EmpArray != nullptr) {
		for (int i = 0; i < m_EmpNum; i++) {
			delete m_EmpArray[i]; // 释放每个职工对象的内存
		}
		delete[] m_EmpArray; // 释放职工数组的内存
		m_EmpArray = nullptr; // 指针置空
	}
}

//显示菜单
void WorkerManager::Show_Menu() {
	cout << "**********************************" << endl;
	cout << "******* 欢迎使用职工管理系统 *****" << endl;
	cout << "********* 0.退出管理程序 *********" << endl;
	cout << "********* 1.增加职工信息 *********" << endl;
	cout << "********* 2.显示职工信息 *********" << endl;
	cout << "********* 3.删除离职职工 *********" << endl;
	cout << "********* 4.修改职工信息 *********" << endl;
	cout << "********* 5.查找职工信息 *********" << endl;
	cout << "********* 6.按照编号排序 *********" << endl;
	cout << "********* 7.清空所有文档 *********" << endl;
	cout << "**********************************" << endl;
}

//退出系统
void WorkerManager::ExitSystem() {
	cout << "欢迎下次使用！" << endl;
	system("pause");
	exit(0);
}

//保存文件
void WorkerManager::save() {
	ofstream ofs(FILENAME, ios::out | ios::trunc); // 打开文件，清空内容
	if (!ofs.is_open()) {
		cout << "文件打开失败！" << endl;
		return;
	}
	for (int i = 0; i < m_EmpNum; i++) {
		ofs << m_EmpArray[i]->m_Id << " "
			<< m_EmpArray[i]->m_Name << " "
			<< m_EmpArray[i]->m_DeptId << endl;
	}
	ofs.close();
	cout << "数据已保存到文件中！" << endl;
}

//增加职工信息,如果是第一次添加职工信息，就需要创建文件,如果不是第一次添加，就在文件末尾添加数据，检查职工ID是否重复
void WorkerManager::Add_Emp() {
	cout << "请输入添加职工的数量：" << endl;
	int addNum = 0; // 记录添加职工的数量
	cin >> addNum;
	if (addNum > 0) {
		//计算添加新职工后的总人数
		int newSize = m_EmpNum + addNum;
		//开辟新空间
		Worker** newSpace = new Worker * [newSize];
		//将原来空间下的数据拷贝到新空间下
		if (m_EmpArray != nullptr) {
			for (int i = 0; i < m_EmpNum; i++) {
				newSpace[i] = m_EmpArray[i];
			}
		}
		//批量添加新数据
		for (int i = 0; i < addNum; i++) {
			int id; // 职工编号
			string name; // 职工姓名
			int dSelect; // 职工岗位选择
			cout << "请输入第 " << i + 1 << " 个新职工的编号：" << endl;
			cin >> id;
			// 检查职工编号是否重复
			if (IsExist(id) != -1) {
				cout << "职工编号已存在，请重新输入！" << endl;
				i--; // 重复当前循环
				continue; // 跳过当前循环，重新输入
			}
			cout << "请输入第 " << i + 1 << " 个新职工的姓名：" << endl;
			cin >> name;
			cout << "请输入第 " << i + 1 << " 个新职工的岗位：" << endl;
			cout << "1.普通员工" << endl;
			cout << "2.经理" << endl;
			cout << "3.老板" << endl;
			cin >> dSelect;
			Worker* worker = nullptr;
			switch (dSelect) {
			case 1: // 普通员工
				worker = new Employee(id, name, dSelect);
				break;
			case 2: // 经理
				worker = new Manager(id, name, dSelect);
				break;
			case 3: // 老板
				worker = new Boss(id, name, dSelect);
				break;
			default:
				break;
			}
			//将创建的职工对象，保存到数组中
			newSpace[m_EmpNum + i] = worker;
		}
		//释放原有空间
		delete[] m_EmpArray;
		//更改成员属性
		m_EmpArray = newSpace;
		m_EmpNum = newSize;
		m_FileIsEmpty = false; // 文件不为空
		//提示添加成功
		cout << "成功添加 " << addNum << " 名新职工！" << endl;

		//添加成功后,保存到文件中
		save();
	}
	else {
		cout << "输入的职工数量不合法！" << endl;
	}
	system("pause");
	system("cls"); // 清屏
}

//统计人数
int WorkerManager::get_EmpNum() {
	ifstream ifs(FILENAME, ios::in); // 打开文件进行读取

	int id;
	string name;
	int deptId;

	int count = 0; // 统计职工人数

	while (ifs >> id >> name >> deptId) { // 逐行读取职工信息
		count++; // 每读取一行，人数加1
	}
	ifs.close(); // 关闭文件

	return count; // 返回统计的职工人数
}

//初始化员工
void WorkerManager::init_Emp() {
	ifstream ifs(FILENAME, ios::in); // 打开文件进行读取

	int id;
	string name;
	int deptId;

	int index = 0; // 数组索引
	while (ifs >> id >> name >> deptId) { // 逐行读取职工信息
		Worker* worker = nullptr; // 创建职工对象指针
		if (deptId == 1) {
			worker = new Employee(id, name, deptId);
		}
		else if (deptId == 2) {
			worker = new Manager(id, name, deptId);
		}
		else if (deptId == 3) {
			worker = new Boss(id, name, deptId);
		}
		m_EmpArray[index++] = worker; // 将职工对象存入数组
	}
	ifs.close(); // 关闭文件
	m_FileIsEmpty = false; // 文件为空标志为假
}

//显示职工
void WorkerManager::Show_Emp() {
	if (m_FileIsEmpty) {
		cout << "文件不存在或记录为空！" << endl;
	}
	else {
		for (int i = 0; i < m_EmpNum; i++) {
			m_EmpArray[i]->ShowInfo(); // 调用职工的显示信息函数
		}
	}
	system("pause");
	system("cls"); // 清屏
}

//职工是否存在
int WorkerManager::IsExist(int id) {
	int index = -1; // 记录职工在数组中的位置，默认不存在
	for (int i = 0; i < m_EmpNum; i++) {
		if (m_EmpArray[i]->m_Id == id) {
			index = i; // 找到职工，记录位置
			break;
		}
	}
	return index; // 返回职工位置，-1表示不存在
}

//删除职工
void WorkerManager::Del_Emp() {
	if (m_FileIsEmpty) {
		cout << "文件不存在或记录为空！" << endl;
	}
	else {
		cout << "请输入要删除的职工编号：" << endl;
		int id;
		cin >> id;
		int index = IsExist(id); // 判断职工是否存在
		if (index != -1) { // 如果存在
			for (int i = index; i < m_EmpNum - 1; i++) {
				m_EmpArray[i] = m_EmpArray[i + 1]; // 将后面的职工前移
			}
			m_EmpNum--; // 职工人数减1
			save(); // 保存到文件
			cout << "删除成功！" << endl;
		}
		else {
			cout << "职工不存在！" << endl;
		}
	}
	system("pause");
	system("cls"); // 清屏
}

//修改职工信息,检查职工ID是否重复，如果重复则提示重新输入
void WorkerManager::Mod_Emp() {
	if (m_FileIsEmpty) {
		cout << "文件不存在或记录为空！" << endl;
	}
	else {
		cout << "请输入要修改的职工编号：" << endl;
		int id;
		cin >> id;
		int index = IsExist(id); // 判断职工是否存在
		if (index != -1) { // 如果存在
			int newId; // 新职工编号
			string newName; // 新职工姓名
			int dSelect; // 新职工岗位选择
			cout << "请输入新的职工编号：" << endl;
			cin >> newId;
			// 检查新职工编号是否重复
			if (IsExist(newId) != -1) {
				cout << "职工编号已存在，请重新输入！" << endl;
				system("pause");
				return; // 退出修改
			}
			// 删除原有职工对象
			delete m_EmpArray[index];
			cout << "请输入新的职工姓名：" << endl;
			cin >> newName;
			cout << "请输入新的职工岗位：" << endl;
			cout << "1.普通员工" << endl;
			cout << "2.经理" << endl;
			cout << "3.老板" << endl;
			cin >> dSelect;
			Worker* worker = nullptr;
			switch (dSelect) {
			case 1: // 普通员工
				worker = new Employee(newId, newName, dSelect);
				break;
			case 2: // 经理
				worker = new Manager(newId, newName, dSelect);
				break;
			case 3: // 老板
				worker = new Boss(newId, newName, dSelect);
				break;
			default:
				break;
			}
			m_EmpArray[index] = worker; // 更新职工信息
			save(); // 保存到文件
			cout << "修改成功！" << endl;
		}
		else {
			cout << "职工不存在！" << endl;
		}
	}
	system("pause");
	system("cls"); // 清屏
}

//查找职工信息，提供两种方式：按编号查找和按姓名查找
void WorkerManager::Find_Emp() {
	if (m_FileIsEmpty) {
		cout << "文件不存在或记录为空！" << endl;
	}
	else {
		cout << "请选择查找方式：" << endl;
		cout << "1.按职工编号查找" << endl;
		cout << "2.按职工姓名查找" << endl;
		int select = 0;
		cin >> select;
		if (select == 1) { // 按编号查找
			cout << "请输入要查找的职工编号：" << endl;
			int id;
			cin >> id;
			int index = IsExist(id); // 判断职工是否存在
			if (index != -1) { // 如果存在
				cout << "找到该职工，信息如下：" << endl;
				m_EmpArray[index]->ShowInfo(); // 显示职工信息
			}
			else {
				cout << "职工不存在！" << endl;
			}
		}
		else if (select == 2) { // 按姓名查找
			cout << "请输入要查找的职工姓名：" << endl;
			string name;
			cin >> name;
			bool found = false; // 标志是否找到
			for (int i = 0; i < m_EmpNum; i++) {
				if (m_EmpArray[i]->m_Name == name) {
					cout << "找到该职工，信息如下：" << endl;
					m_EmpArray[i]->ShowInfo(); // 显示职工信息
					found = true; // 找到标志设为真
				}
			}
			if (!found) {
				cout << "职工不存在！" << endl;
			}
		}
		else {
			cout << "输入选项有误，请重新选择！" << endl;
		}
	}
	system("pause");
	system("cls"); // 清屏
}

//排序职工信息，按照职工编号排序,提供升序和降序两种方式
void WorkerManager::Sort_Emp() {
	if (m_FileIsEmpty) {
		cout << "文件不存在或记录为空！" << endl;
		system("pause");
		system("cls"); // 清屏
	}
	else {
		cout << "请选择排序方式：" << endl;
		cout << "1.升序" << endl;
		cout << "2.降序" << endl;
		int select = 0;
		cin >> select;
		for (int i = 0; i < m_EmpNum - 1; i++) {
			for (int j = 0; j < m_EmpNum - i - 1; j++) {
				if ((select == 1 && m_EmpArray[j]->m_Id > m_EmpArray[j + 1]->m_Id) ||
					(select == 2 && m_EmpArray[j]->m_Id < m_EmpArray[j + 1]->m_Id)) {
					//交换
					Worker* temp = m_EmpArray[j];
					m_EmpArray[j] = m_EmpArray[j + 1];
					m_EmpArray[j + 1] = temp;
				}
			}
		}
		cout << "排序完成！" << endl;
		Show_Emp(); // 显示排序后的职工信息
	}
}

//清空文件
void WorkerManager::Clean_File() {
	cout << "确认清空文件吗？" << endl;
	cout << "1.确认" << endl;
	cout << "2.取消" << endl;
	int select = 0;
	cin >> select;
	if (select == 1) {
		ofstream ofs(FILENAME, ios::trunc); // 以覆盖方式打开文件
		ofs.close(); // 关闭文件
		if (m_EmpArray != nullptr) {
			for (int i = 0; i < m_EmpNum; i++) {
				delete m_EmpArray[i]; // 释放职工对象内存
			}
			delete[] m_EmpArray; // 释放职工数组内存
			m_EmpArray = nullptr; // 指针置空
			m_EmpNum = 0; // 职工人数置0
			m_FileIsEmpty = true; // 文件为空标志为真
		}
		cout << "文件已清空！" << endl;
	}
	else {
		cout << "取消清空文件操作！" << endl;
	}
	system("pause");
	system("cls"); // 清屏
}