#include"teacher.h"

//先全部空实现

//默认构造
Teacher::Teacher() {
}

//有参构造
Teacher::Teacher(int id, string name, int pwd) {
	//初始化属性
	this->m_EmpId = id;
	this->m_Name = name;
	this->m_Pwd = pwd;
}

//菜单界面
void Teacher::operMenu() {
	cout << "欢迎教师：" << this->m_Name << "登录！" << endl;
	cout << "\t\t ---------------------------------\n";
	cout << "\t\t|                                 |\n";
	cout << "\t\t|          1.查看所有预约         |\n";
	cout << "\t\t|                                 |\n";
	cout << "\t\t|          2.审核预约             |\n";
	cout << "\t\t|                                 |\n";
	cout << "\t\t|          0.注销登录             |\n";
	cout << "\t\t|                                 |\n";
	cout << "\t\t ---------------------------------\n";
	cout << "请输入您的选择： " << endl;
}

//审核预约
void Teacher::validOrder() {
	OrderFile of;
	if (of.m_Size == 0) {
		cout << "无预约记录!" << endl;
		system("pause");
		system("cls");
		return;
	}
	cout << "待审核的预约记录如下：" << endl;

	vector<int> v; //存放待审核的记录下标
	int index = 0; //记录序号
	//只显示待审核的预约
	for (int i = 0; i < of.m_Size; i++) {
		if (of.m_OrderData[i]["status"] == "1") {
			v.push_back(i); //将下标存入容器
			cout << ++index << ". 预约日期：周" << of.m_OrderData[i]["date"];
			if (of.m_OrderData[i]["interval"] == "1") {
				cout << " 上午";
			}
			else {
				cout << " 下午";
			}
			cout << " 学号：" << of.m_OrderData[i]["sutId"];
			cout << " 姓名：" << of.m_OrderData[i]["stuName"];
			cout << " 机房号：" << of.m_OrderData[i]["roomId"];
			string status = " 状态：";
			status += "审核中";
			cout << status << endl;
		}
	}
	if (index == 0) {
		cout << "无待审核的预约记录!" << endl;
		system("pause");
		system("cls");
		return;
	}
	cout << "请输入您要审核的记录(0代表返回)： " << endl;
	int select = 0; //选择变量
	cin >> select; //输入选择
	if (select < 0 || select > index) {
		cout << "输入错误，请重新输入！" << endl;
		system("pause");
		system("cls");
		return;
	}
	else if (select == 0) {
		system("cls");
		return;
	}
	else {
		int orderIndex = v[select - 1]; //获取真实的记录下标
		cout << "请输入审核结果(1.通过 2.不通过)： " << endl;
		int result = 0; //审核结果
		cin >> result; //输入审核结果
		if (result == 1) {
			of.m_OrderData[orderIndex]["status"] = "2"; //修改状态为预约成功
			of.updateOrder(); //更新文件
			cout << "审核通过，预约成功！" << endl;
			system("pause");
			system("cls");
			return;
		}
		else if (result == 2) {
			of.m_OrderData[orderIndex]["status"] = "-1"; //修改状态为预约失败
			of.updateOrder(); //更新文件
			cout << "审核不通过，预约失败！" << endl;
			system("pause");
			system("cls");
			return;
		}
		else {
			cout << "输入错误，审核失败！" << endl;
			system("pause");
			system("cls");
			return;
		}
	}
}

//查看所有预约
void Teacher::showAllOrder() {
	OrderFile of;
	if (of.m_Size == 0) {
		cout << "无预约记录!" << endl;
		system("pause");
		system("cls");
		return;
	}
	for (int i = 0; i < of.m_Size; i++) {
		cout << "预约日期：周" << of.m_OrderData[i]["date"];
		if (of.m_OrderData[i]["interval"] == "1") {
			cout << " 上午";
		}
		else {
			cout << " 下午";
		}
		cout << " 学号：" << of.m_OrderData[i]["sutId"];
		cout << " 姓名：" << of.m_OrderData[i]["stuName"];
		cout << " 机房号：" << of.m_OrderData[i]["roomId"];
		string status = " 状态：";
		if (of.m_OrderData[i]["status"] == "1") {
			status += "审核中";
		}
		else if (of.m_OrderData[i]["status"] == "2") {
			status += "预约成功";
		}
		else if (of.m_OrderData[i]["status"] == "-1") {
			status += "预约失败";
		}
		else {
			status += "已取消";
		}
		cout << status << endl;
	}
	system("pause");
	system("cls");
}