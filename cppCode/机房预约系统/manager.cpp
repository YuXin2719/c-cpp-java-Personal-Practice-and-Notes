#include"manager.h"

//全部空实现

//默认构造
Manager::Manager() {
}

//有参构造
Manager::Manager(string name, int pwd) {
	this->m_Name = name;
	this->m_Pwd = pwd;

	//初始化容器
	this->initVector();

	//获取机房信息
	ifstream ifs;
	ifs.open(COMPUTER_FILE, ios::in); //以输入方式打开文件
	if (!ifs.is_open()) {
		cout << "文件不存在或打开失败！" << endl;
		return;
	}
	ComputerRoom c;
	while (ifs >> c.m_ComId && ifs >> c.m_MaxNum) {
		this->vCom.push_back(c);
	}
	cout << "机房数量为：" << this->vCom.size() << endl;
	ifs.close();
}

//菜单界面
void Manager::operMenu() {
	cout << "欢迎管理员：" << this->m_Name << "登录！" << endl;
	cout << "\t\t ---------------------------------\n";
	cout << "\t\t|                                 |\n";
	cout << "\t\t|          1.添加账号             |\n";
	cout << "\t\t|                                 |\n";
	cout << "\t\t|          2.查看账号             |\n";
	cout << "\t\t|                                 |\n";
	cout << "\t\t|          3.查看机房             |\n";
	cout << "\t\t|                                 |\n";
	cout << "\t\t|          4.清空预约             |\n";
	cout << "\t\t|                                 |\n";
	cout << "\t\t|          0.注销登录             |\n";
	cout << "\t\t|                                 |\n";
	cout << "\t\t ---------------------------------\n";
	cout << "请输入您的选择： " << endl;
}

//添加账号
void Manager::addPerson() {
	cout << "请输入添加账号的类型：1.学生 2.教师" << endl;
	string fileName; //文件名
	string tip; //提示
	ofstream ofs; //输出流对象

	int select = 0; //选择变量
	cin >> select; //输入选择

	string errorTip; //错误提示

	if (select == 1) {
		//添加学生
		fileName = STUDENT_FILE;
		tip = "请输入学生学号：";
		errorTip = "学号重复，请重新输入！";
	}
	else {
		//添加教师
		fileName = TEACHER_FILE;
		tip = "请输入教师职工号：";
		errorTip = "职工号重复，请重新输入！";
	}

	ofs.open(fileName, ios::out | ios::app); //以追加方式打开文件
	if (!ofs.is_open()) {
		cout << "文件不存在或打开失败！" << endl;
		return;
	}
	int id; //账号
	string name; //姓名
	int pwd; //密码
	cout << tip << endl;
	while (true) {
		cin >> id; //输入账号
		//检测账号是否重复
		if (this->checkRepeat(id, select)) {
			cout << errorTip << endl;
		}
		else {
			break; //账号不重复，跳出循环
		}
	}
	cout << "请输入姓名：" << endl;
	cin >> name;
	cout << "请输入密码：" << endl;
	cin >> pwd;

	//向文件中添加信息
	ofs << id << " " << name << " " << pwd << endl;
	cout << "添加账号成功！" << endl;

	system("pause");
	system("cls");

	ofs.close();

	//初始化容器
	this->initVector();
}

//打印学生信息
void printStudent(Student& s) {
	cout << "学号：" << s.m_Id << "\t姓名：" << s.m_Name << "\t密码：" << s.m_Pwd << endl;
}

//打印教师信息
void printTeacher(Teacher& t) {
	cout << "职工号：" << t.m_EmpId << "\t姓名：" << t.m_Name << "\t密码：" << t.m_Pwd << endl;
}

//查看账号
void Manager::showPerson() {
	cout << "请选择查看内容：" << endl;
	cout << "1.查看所有学生" << endl;
	cout << "2.查看所有教师" << endl;

	int select = 0; //选择变量
	cin >> select; //输入选择

	if (select == 1) {
		//查看所有学生
		if (this->vStu.size() == 0) {
			cout << "当前无学生信息！" << endl;
			return;
		}
		for (vector<Student>::iterator it = this->vStu.begin(); it != this->vStu.end(); it++) {
			printStudent(*it);
		}
	}
	else {
		//查看所有教师
		if (this->vTea.size() == 0) {
			cout << "当前无教师信息！" << endl;
			return;
		}
		for (vector<Teacher>::iterator it = this->vTea.begin(); it != this->vTea.end(); it++) {
			printTeacher(*it);
		}
	}
	system("pause");
	system("cls");
}

//清空预约
void Manager::cleanFile() {
	ofstream ofs(ORDER_FILE, ios::trunc); //以清空方式打开文件
	if (!ofs.is_open()) {
		cout << "文件不存在或打开失败！" << endl;
		return;
	}
	ofs.close();
	cout << "清空预约成功！" << endl;
	system("pause");
	system("cls");
}

//查看机房信息
void Manager::showComputer() {
	cout << "机房信息如下：" << endl;
	if (this->vCom.size() == 0) {
		cout << "当前无机房信息！" << endl;
		return;
	}
	for (vector<ComputerRoom>::iterator it = this->vCom.begin(); it != this->vCom.end(); it++) {
		cout << "机房编号：" << it->m_ComId << "\t机房最大容量：" << it->m_MaxNum << endl;
	}
	system("pause");
	system("cls");
}

//初始化容器，读取学生和老师文件中的信息，放到容器中
void Manager::initVector() {
	//读取学生文件中的信息
	ifstream ifs;
	ifs.open(STUDENT_FILE, ios::in); //以输入方式打开文件
	if (!ifs.is_open()) {
		cout << "文件不存在或打开失败！" << endl;
		return;
	}

	vStu.clear(); //清空容器
	vTea.clear();

	Student s;
	while (ifs >> s.m_Id && ifs >> s.m_Name && ifs >> s.m_Pwd) {
		vStu.push_back(s);
	}
	cout << "学生人数为：" << vStu.size() << endl;
	ifs.close();

	//读取教师文件中的信息
	ifstream ifs2;
	ifs2.open(TEACHER_FILE, ios::in); //以输入方式打开文件
	if (!ifs2.is_open()) {
		cout << "文件不存在或打开失败！" << endl;
		return;
	}

	vTea.clear(); //清空容器
	Teacher t;
	while (ifs2 >> t.m_EmpId && ifs2 >> t.m_Name && ifs2 >> t.m_Pwd) {
		vTea.push_back(t);
	}
	cout << "教师人数为：" << vTea.size() << endl;
	ifs2.close();
}

//检测重复 参数：（传入id，传入类型）返回值：（true重复 false不重复）
bool Manager::checkRepeat(int id, int type) {
	if (type == 1) {
		//学生
		for (vector<Student>::iterator it = vStu.begin(); it != vStu.end(); it++) {
			if (it->m_Id == id) {
				return true; //重复
			}
		}
	}
	else {
		//教师
		for (vector<Teacher>::iterator it = vTea.begin(); it != vTea.end(); it++) {
			if (it->m_EmpId == id) {
				return true; //重复
			}
		}
	}
	return false; //不重复
}