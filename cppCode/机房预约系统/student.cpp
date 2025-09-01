#include"student.h"

//先全部空实现

//默认构造
Student::Student() {

}

//有参构造
Student::Student(int id, string name, int pwd) {
	//初始化属性
	this->m_Id = id;
	this->m_Name = name;
	this->m_Pwd = pwd;

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
	ifs.close();
}

//菜单界面
void Student::operMenu() {
	cout << "欢迎学生：" << this->m_Name << "登录！" << endl;
	cout << "\t\t ---------------------------------\n";
	cout << "\t\t|                                 |\n";
	cout << "\t\t|          1.申请预约             |\n";
	cout << "\t\t|                                 |\n";
	cout << "\t\t|          2.查看我的预约         |\n";
	cout << "\t\t|                                 |\n";
	cout << "\t\t|          3.查看所有预约         |\n";
	cout << "\t\t|                                 |\n";
	cout << "\t\t|          4.取消预约             |\n";
	cout << "\t\t|                                 |\n";
	cout << "\t\t|          0.注销登录             |\n";
	cout << "\t\t|                                 |\n";
	cout << "\t\t ---------------------------------\n";
	cout << "请输入您的选择： " << endl;
}

//申请预约
void Student::applyOrder() {
	cout << "机房开放时间为周一到周五!" << endl;
	cout << "请输入申请预约的时间:" << endl;
	cout << "1.周一" << endl;
	cout << "2.周二" << endl;
	cout << "3.周三" << endl;
	cout << "4.周四" << endl;
	cout << "5.周五" << endl;
	int date = 0; //预约日期
	int interval = 0; //时间段
	int room = 0; //机房编号

	while (true) {
		cin >> date; //输入预约日期
		if (date >= 1 && date <= 5) {
			break;
		}
		else {
			cout << "输入有误，请重新输入!" << endl;
		}
	}

	cout << "请输入申请预约的时间段:" << endl;
	cout << "1.上午" << endl;
	cout << "2.下午" << endl;
	while (true) {
		cin >> interval; //输入预约时间段
		if (interval == 1 || interval == 2) {
			break;
		}
		else {
			cout << "输入有误，请重新输入!" << endl;
		}
	}

	cout << "请输入申请预约的机房编号:" << endl;
	cout << "1号机房容量:" << this->vCom[0].m_MaxNum << endl;
	cout << "2号机房容量:" << this->vCom[1].m_MaxNum << endl;
	cout << "3号机房容量:" << this->vCom[2].m_MaxNum << endl;
	while (true) {
		cin >> room; //输入预约机房编号
		if (room >= 1 && room <= 3) {
			break;
		}
		else {
			cout << "输入有误，请重新输入!" << endl;
		}
	}

	cout << "预约申请成功，等待审核!" << endl;

	ofstream ofs(ORDER_FILE, ios::app); //以追加方式打开文件
	if (!ofs.is_open()) {
		cout << "文件不存在或打开失败！" << endl;
		return;
	}
	ofs << "date:" << date << " ";
	ofs << "interval:" << interval << " ";
	ofs << "sutId:" << this->m_Id << " ";
	ofs << "stuName:" << this->m_Name << " ";
	ofs << "roomId:" << room << " ";
	ofs << "status:" << 1 << endl; //1表示审核中

	ofs.close();
	system("pause");
	system("cls");
}

//查看我的预约
void Student::showMyOrder() {
	OrderFile of;
	if (of.m_Size == 0) {
		cout << "无预约记录!" << endl;
		system("pause");
		system("cls");
		return;
	}
	for (int i = 0; i < of.m_Size; i++) {
		if (of.m_OrderData[i]["sutId"] == to_string(this->m_Id)) {
			cout << "预约日期：周" << of.m_OrderData[i]["date"];
			if (of.m_OrderData[i]["interval"] == "1") {
				cout << " 上午";
			}
			else {
				cout << " 下午";
			}
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
	}
	system("pause");
	system("cls");
}

//查看所有预约
void Student::showAllOrder() {
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

//取消预约
void Student::cancelOrder() {
	OrderFile of;
	if (of.m_Size == 0) {
		cout << "无预约记录!" << endl;
		system("pause");
		system("cls");
		return;
	}
	cout << "审核中或预约成功的记录可以取消，请输入取消的预约记录" << endl;

	vector<int> v; //存放可以取消的预约记录序号
	int index = 1; //记录序号
	for (int i = 0; i < of.m_Size; i++) {
		if (of.m_OrderData[i]["sutId"] == to_string(this->m_Id) && (of.m_OrderData[i]["status"] == "1" || of.m_OrderData[i]["status"] == "2")) {
			v.push_back(i);
			cout << "序号：" << index++ << " 预约日期：周" << of.m_OrderData[i]["date"];
			if (of.m_OrderData[i]["interval"] == "1") {
				cout << " 上午";
			}
			else {
				cout << " 下午";
			}
			cout << " 机房号：" << of.m_OrderData[i]["roomId"];
			string status = " 状态：";
			if (of.m_OrderData[i]["status"] == "1") {
				status += "审核中";
			}
			else if (of.m_OrderData[i]["status"] == "2") {
				status += "预约成功";
			}
			cout << status << endl;
		}
	}
	if (v.size() == 0) {
		cout << "无可取消的预约记录!" << endl;
		system("pause");
		system("cls");
		return;
	}
	cout << "请输入取消的预约记录序号：" << endl;
	int select = 0;
	while (true) {
		cin >> select;
		if (select > 0 && select < v.size() + 1) {
			break;
		}
		else {
			cout << "输入有误，请重新输入!" << endl;
		}
	}
	of.m_OrderData[v[select - 1]]["status"] = "-2"; //修改状态为已取消
	of.updateOrder(); //更新预约文件
	cout << "已取消所选预约!" << endl;
	system("pause");
	system("cls");
}