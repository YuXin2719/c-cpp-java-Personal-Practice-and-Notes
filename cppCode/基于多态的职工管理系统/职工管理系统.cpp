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
			wm.Show_Emp(); // 调用显示职工信息的函数
			break;
		case 3: {
			cout << "删除离职职工" << endl;
			wm.Del_Emp(); // 调用删除职工的函数
			break;
		}
		case 4:
			cout << "修改职工信息" << endl;
			wm.Mod_Emp(); // 调用修改职工信息的函数
			break;
		case 5:
			cout << "查找职工信息" << endl;
			wm.Find_Emp(); // 调用查找职工信息的函数
			break;
		case 6:
			cout << "按照编号排序" << endl;
			wm.Sort_Emp(); // 调用排序职工信息的函数
			break;
		case 7:
			cout << "清空所有文档" << endl;
			wm.Clean_File(); // 调用清空文件的函数
			break;
		default:
			system("cls"); // 清屏
			break;
		}
	}
}