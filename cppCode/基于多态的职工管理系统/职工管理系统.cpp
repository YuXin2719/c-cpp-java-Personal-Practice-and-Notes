#include<iostream>
using namespace std;
#include"workerManager.h"
#include"worker.h"
#include"employee.h"
#include"manager.h"
#include"boss.h"

////测试添加职工信息
//void test() {
//	//创建职工对象
//	Worker* worker1 = new Employee(1, "张三", 1);
//	Worker* worker2 = new Manager(2, "李四", 2);
//	Worker* worker3 = new Boss(3, "王五", 3);
//	//显示职工信息
//	worker1->ShowInfo();
//	worker2->ShowInfo();
//	worker3->ShowInfo();
//	//释放内存
//	delete worker1;
//	delete worker2;
//	delete worker3;
//}

int main() {
	WorkerManager wm;
	int choice = 0;
	while (true) {
		//展示菜单
		wm.Show_Menu();
		cout << "请输入您的选择：";
		cin >> choice;

		switch (choice) {
		case 0:
			wm.ExitSystem();
		case 1:
			cout << "增加职工信息" << endl;
			//test(); // 测试添加职工信息
			wm.Add_Emp(); // 调用添加职工信息的函数
			break;
		case 2:
			cout << "显示职工信息" << endl;
			// 这里可以添加显示职工信息的代码
			break;
		case 3:
			cout << "删除离职职工" << endl;
			// 这里可以添加删除离职职工的代码
			break;
		case 4:
			cout << "修改职工信息" << endl;
			// 这里可以添加修改职工信息的代码
			break;
		case 5:
			cout << "查找职工信息" << endl;
			// 这里可以添加查找职工信息的代码
			break;
		case 6:
			cout << "按照编号排序" << endl;
			// 这里可以添加按照编号排序的代码
			break;
		case 7:
			cout << "清空所有文档" << endl;
			// 这里可以添加清空所有文档的代码
			break;
		default:
			system("cls"); // 清屏
			break;
		}
	}
}