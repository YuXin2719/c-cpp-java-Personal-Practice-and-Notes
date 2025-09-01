#include<iostream>
using namespace std;
#include"identity.h"
#include<fstream>
#include"globalFile.h"
#include"student.h"
#include"teacher.h"
#include"manager.h"

void managerMenu(Identity*& manager);
void studentMenu(Identity*& student);
void teacherMenu(Identity*& teacher);

//登录功能  参数1 操作的文件名 参数2 操作身份类型
void LoginIn(string fileName, int identityType) {
	Identity* person = NULL; //父类指针，用于指向子类对象
	//读文件
	ifstream file;
	file.open(fileName, ios::in); //输入流打开文件
	//判断文件是否存在
	if (!file.is_open()) {
		cout << "文件不存在" << endl;
		file.close();
		return;
	}
	//准备接受用户输入信息
	int id = 0; //工号/学号
	string name; //姓名
	int pwd = 0; //密码
	//判断身份
	if (identityType == 1) {
		cout << "请输入学号" << endl;
		cin >> id;
	}
	else if (identityType == 2) {
		cout << "请输入工号" << endl;
		cin >> id;
	}
	cout << "请输入用户名" << endl;
	cin >> name;
	cout << "请输入密码" << endl;
	cin >> pwd;
	//验证信息
	if (identityType == 1) {
		//学生身份验证
		int fId; //文件中学号
		string fName; //文件中姓名
		int fPwd; //文件中密码
		while (file >> fId && file >> fName && file >> fPwd) {
			if (fId == id && fName == name && fPwd == pwd) {
				cout << "学生身份验证登录成功！" << endl;
				system("pause");
				system("cls");
				person = new Student(id, name, pwd); //创建学生对象
				studentMenu(person); //调用学生菜单
				return;
			}
		}
	}
	else if (identityType == 2) {
		//老师身份验证
		int fId; //文件中工号
		string fName; //文件中姓名
		int fPwd; //文件中密码
		while (file >> fId && file >> fName && file >> fPwd) {
			if (fId == id && fName == name && fPwd == pwd) {
				cout << "老师身份验证登录成功！" << endl;
				system("pause");
				system("cls");
				person = new Teacher(id, name, pwd); //创建老师对象
				//调用老师菜单
				teacherMenu(person);
				return;
			}
		}
	}
	else if (identityType == 3) {
		//管理员身份验证
		string fName; //文件中姓名
		int fPwd; //文件中密码
		while (file >> fName && file >> fPwd) {
			if (fName == name && fPwd == pwd) {
				cout << "管理员身份验证登录成功！" << endl;
				system("pause");
				system("cls");
				person = new Manager(name, pwd); //创建管理员对象
				//调用管理员菜单
				managerMenu(person);
				return;
			}
		}
	}
	cout << "验证登录失败！" << endl;
	system("pause");
	system("cls");
	file.close();
}

//管理员菜单
void managerMenu(Identity*& manager) {
	while (1) {
		manager->operMenu(); //调用管理员菜单
		Manager* man = (Manager*)manager; //向下转型
		int select = 0; //选择变量
		cin >> select; //输入选择
		if (select == 1) { //添加账号
			cout << "添加账号" << endl;
			man->addPerson();
		}
		else if (select == 2) { //查看账号
			cout << "查看账号" << endl;
			man->showPerson();
		}
		else if (select == 3) { //查看机房
			cout << "查看机房" << endl;
			man->showComputer();
		}
		else if (select == 4) { //清空预约
			cout << "清空预约" << endl;
			man->cleanFile();
		}
		else {
			delete manager;
			cout << "注销成功" << endl;
			system("pause");
			system("cls");
			return;
		}
	}
}

//学生菜单
void studentMenu(Identity*& student) {
	while (1) {
		student->operMenu(); //调用学生菜单
		Student* stu = (Student*)student; //向下转型
		int select = 0; //选择变量
		cin >> select; //输入选择
		if (select == 1) { //申请预约
			cout << "申请预约" << endl;
			stu->applyOrder();
		}
		else if (select == 2) { //查看我的预约
			cout << "查看我的预约" << endl;
			stu->showMyOrder();
		}
		else if (select == 3) { //查看所有预约
			cout << "查看所有预约" << endl;
			stu->showAllOrder();
		}
		else if (select == 4) { //取消预约
			cout << "取消预约" << endl;
			stu->cancelOrder();
		}
		else {
			delete student;
			cout << "注销成功" << endl;
			system("pause");
			system("cls");
			return;
		}
	}
}

//教师菜单
void teacherMenu(Identity*& teacher) {
	while (1) {
		teacher->operMenu(); //调用教师菜单
		Teacher* tea = (Teacher*)teacher; //向下转型
		int select = 0; //选择变量
		cin >> select; //输入选择
		if (select == 1) { //查看所有预约
			cout << "查看所有预约" << endl;
			tea->showAllOrder();
		}
		else if (select == 2) { //审核预约
			cout << "审核预约" << endl;
			tea->validOrder();
		}
		else {
			delete teacher;
			cout << "注销成功" << endl;
			system("pause");
			system("cls");
			return;
		}
	}
}

int main() {
	int select = 0; //选择变量

	while (1) {
		//实现菜单
		cout << "**********欢迎使用机房预约系统**********" << endl;
		cout << endl;
		cout << "请输入你的身份" << endl;
		cout << "1.学生" << endl;
		cout << "2.老师" << endl;
		cout << "3.管理员" << endl;
		cout << "0.退出" << endl;

		cin >> select; //输入选择
		switch (select) {
		case 1:
			cout << "学生登录" << endl;
			LoginIn(STUDENT_FILE, 1);
			break;
		case 2:
			cout << "老师登录" << endl;
			LoginIn(TEACHER_FILE, 2);
			break;
		case 3:
			cout << "管理员登录" << endl;
			LoginIn(ADMIN_FILE, 3);
			break;
		case 0:
			cout << "退出系统,欢迎下次使用" << endl;
			system("pause");
			return 0;
			break;
		default:
			cout << "输入错误，请重新输入" << endl;
			system("pause");
			system("cls");
			break;
		}
	}

	system("pause");
	return 0;
}