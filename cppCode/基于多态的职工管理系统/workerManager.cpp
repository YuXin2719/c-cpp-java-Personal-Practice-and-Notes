#include "workerManager.h"

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
}

WorkerManager::~WorkerManager() {
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

//增加职工信息,如果是第一次添加职工信息，就需要创建文件,如果不是第一次添加，就在文件末尾添加数据
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