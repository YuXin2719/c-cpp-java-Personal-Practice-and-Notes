#include<iostream>
using namespace std;

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
			break;
		case 2:
			cout << "老师登录" << endl;
			break;
		case 3:
			cout << "管理员登录" << endl;
			break;
		case 0:
			cout << "退出系统" << endl;
			return 0;
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