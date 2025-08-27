#include"speechManager.h"

//构造函数
SpeechManager::SpeechManager()
{
	//初始化比赛
	initSpeech();

	//获取往届记录
	loadRecord();
}

//析构函数
SpeechManager::~SpeechManager()
{

}

//展示菜单
void SpeechManager::showMenu()
{
	cout << "*************************" << endl;
	cout << "*****1.开始演讲比赛******" << endl;
	cout << "*****2.查看往届记录******" << endl;
	cout << "*****3.清空比赛记录******" << endl;
	cout << "*****0.退出比赛程序******" << endl;
	cout << "*************************" << endl;
	cout << endl;
}

//退出比赛程序
void SpeechManager::exitSpeech()
{
	cout << "退出比赛程序，欢迎下次使用！" << endl;
	system("pause");
	//注意exit(0)会导致析构函数不被执行直接退出，这就是和return 0的关键区别
	exit(0);
}

//初始化比赛
void SpeechManager::initSpeech()
{
	//初始化比赛选手
	//初始化容器
	v1.clear();
	v2.clear();
	vVictory.clear();
	m_Speaker.clear();
	m_Record.clear();
	//编号
	int index = 1001;
	//名称后缀种子
	string nameSeed = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";
	//初始化12名选手
	for (int i = 0; i < 12; i++)
	{
		//创建选手对象
		Speaker sp;
		//如果直接使用"选手" + nameSeed[i]，"选手"是一个 const char[]（会退化为 const char*）
		//就变成了const char* + char实际上是指针算术，而不是字符串拼接
		//方法一：这里使用了string的构造函数
		//方法二：使用字符串字面量后缀（C++14及以上）
		//sp.m_Name = "选手"s + nameSeed[i];
		sp.m_Name = string("选手") + nameSeed[i];
		//编号
		sp.m_Score[0] = 0;
		sp.m_Score[1] = 0;
		//放入容器
		m_Speaker.insert(make_pair(index, sp));
		//放入v1容器
		v1.push_back(index);
		//编号递增
		index++;
	}
	//初始化比赛轮数
	m_Index = 1;
}

//开始比赛
void SpeechManager::startSpeech()
{
	//随机数种子
	srand((unsigned int)time(NULL));

	//第一轮比赛
	//1.抽签
	speechDraw();
	//2.比赛
	speechContest();
	//3.显示晋级结果
	showScore();
	//第二轮比赛
	m_Index++;
	//1.抽签
	speechDraw();
	//2.比赛
	speechContest();
	//3.显示最终结果
	showScore();
	//4.保存分数
	saveScore();

	cout << "本届比赛结束，感谢您的观看！" << endl;
	system("pause");
	system("cls");
}

//抽签
void SpeechManager::speechDraw() {
	cout << "正在第" << m_Index << "轮比赛抽签，请稍后......" << endl;
	cout << "---------------------" << endl;
	cout << "第" << m_Index << "轮比赛抽签结果如下：" << endl;
	if (m_Index == 1) {
		random_shuffle(v1.begin(), v1.end());
		for (vector<int>::iterator it = v1.begin(); it != v1.end(); it++) {
			cout << *it << " ";
		}
		cout << endl;
	}
	else {
		random_shuffle(v2.begin(), v2.end());
		for (vector<int>::iterator it = v2.begin(); it != v2.end(); it++) {
			cout << *it << " ";
		}
		cout << endl;
	}
	cout << "---------------------" << endl;
	system("pause");
	system("cls");
}

//开始比赛
void SpeechManager::speechContest() {
	cout << "第" << m_Index << "轮比赛正式开始：-----------------" << endl;
	//临时容器，保存key分数value选手编号
	multimap<double, int, greater<int>> group;
	//记录人员数，6个为1组
	int num = 0;
	//比赛人员容器
	vector<int> v;
	if (m_Index == 1) {
		v = v1;
	}
	else {
		v = v2;
	}
	//遍历所有选手编号
	for (vector<int>::iterator it = v.begin(); it != v.end(); it++) {
		num++;
		//评委打分容器
		deque<double> d;
		for (int i = 0; i < 10; i++) {
			double score = (rand() % 401 + 600) / 10.0;
			//cout << score << " ";
			d.push_back(score);
		}
		//sort排序
		sort(d.begin(), d.end(), greater<double>());
		//去除最高和最低分
		d.pop_back();
		d.pop_front();
		//计算平均分
		double sum = accumulate(d.begin(), d.end(), 0.0);
		double avg = sum / (double)d.size();

		//打印每个人的分数
		//cout << "编号：" << *it << " 姓名：" << m_Speaker[*it].m_Name << " 成绩：" << avg << endl;

		//保存平均分
		m_Speaker[*it].m_Score[m_Index - 1] = avg;
		//将平均分和选手编号插入到multimap中
		group.insert(make_pair(avg, *it));
		if (num % 6 == 0) {
			//展示第xx小组名次
			cout << "第" << m_Index << "轮第" << num / 6 << "小组比赛结果：" << endl;
			for (multimap<double, int, greater<int>>::iterator it = group.begin(); it != group.end(); it++) {
				cout << "编号：" << it->second << " 姓名：" << m_Speaker[it->second].m_Name << " 成绩：" << it->first << endl;
			}
			int count = 0;
			//取前3名
			for (multimap<double, int, greater<int>>::iterator it = group.begin(); it != group.end() && count < 3; it++, count++) {
				if (m_Index == 1) {
					v2.push_back(it->second);
				}
				else {
					vVictory.push_back(it->second);
				}
			}
			//清空临时容器
			group.clear();
		}
	}
	cout << "第" << m_Index << "轮比赛完毕！" << endl;
	system("pause");
}

//显示比赛结果
void SpeechManager::showScore() {
	cout << "------------第" << m_Index << "轮晋级选手信息如下：-------------" << endl;
	vector<int>v;
	if (m_Index == 1) {
		v = v2;
	}
	else {
		v = vVictory;
	}
	for (vector<int>::iterator it = v.begin(); it != v.end(); it++) {
		cout << "编号：" << *it << " 姓名：" << m_Speaker[*it].m_Name << " 成绩：" << m_Speaker[*it].m_Score[m_Index - 1] << endl;
	}
	cout << endl;
	system("pause");
	system("cls");
	this->showMenu();
}

//保存分数
void SpeechManager::saveScore() {
	ofstream ofs;
	ofs.open("speech.csv", ios::out | ios::app); //追加的方式写文件

	//将最终胜出的选手的数据写入到文件中
	for (vector<int>::iterator it = vVictory.begin(); it != vVictory.end(); it++) {
		ofs << *it << "," << m_Speaker[*it].m_Name << "," << m_Speaker[*it].m_Score[1] << ",";
	}
	ofs << endl;

	//关闭文件
	ofs.close();

	cout << "记录保存成功！" << endl;

	//有记录了，文件不为空
	fileIsEmpty = false;
}

//读取记录
void SpeechManager::loadRecord() {
	ifstream ifs;
	ifs.open("speech.csv", ios::in);
	if (!ifs.is_open()) {
		fileIsEmpty = true;
		cout << "文件不存在！" << endl;
		ifs.close();
		return;
	}
	//文件存在，但是内容为空
	char ch;
	ifs >> ch;
	if (ifs.eof()) {
		cout << "文件为空！" << endl;
		fileIsEmpty = true;
		ifs.close();
		return;
	}
	//文件不为空
	fileIsEmpty = false;
	//读取的单个字符放回去
	ifs.putback(ch);

	vector<string> v; //保存9个字符串数据
	string data;
	int index = 0;
	while (ifs >> data) { //每次读取一行数据
		//cout << data << endl;
		int pos = -1; //找到逗号位置
		int start = 0; //开始位置
		while (1) {
			pos = data.find(",", start);
			if (pos == -1) {
				//没有找到的情况
				break;
			}
			string temp = data.substr(start, pos - start);
			//暂时看一下截取到的值
			//cout << temp << endl;
			v.push_back(temp);
			start = pos + 1;
		}
		m_Record.insert(make_pair(index, v));
		v.clear();
		index++;
	}
	ifs.close();
	//简单打印一下往届获奖者信息
	//for (map<int, vector<string>>::iterator it = m_Record.begin(); it != m_Record.end(); it++) {
	//	cout << "第" << it->first << "届比赛：" << endl;
	//	cout << "冠军编号：" << it->second[0] << " 姓名：" << it->second[1] << " 成绩：" << it->second[2] << endl;
	//	cout << "亚军编号：" << it->second[3] << " 姓名：" << it->second[4] << " 成绩：" << it->second[5] << endl;
	//	cout << "季军编号：" << it->second[6] << " 姓名：" << it->second[7] << " 成绩：" << it->second[8] << endl;
	//	cout << endl;
	//}
}

//显示往届记录
void SpeechManager::showRecord() {
	if (fileIsEmpty) {
		cout << "文件为空！" << endl;
	}
	else {
		cout << "往届比赛记录如下：" << endl;
		for (int i = 1; i <= m_Record.size(); i++) { //这里size是map的大小，即往届记录的个数
			cout << "第" << i << "届比赛：" << endl;
			cout << "冠军编号：" << m_Record[i - 1][0] << " 姓名：" << m_Record[i - 1][1] << " 成绩：" << m_Record[i - 1][2] << endl;
			cout << "亚军编号：" << m_Record[i - 1][3] << " 姓名：" << m_Record[i - 1][4] << " 成绩：" << m_Record[i - 1][5] << endl;
			cout << "季军编号：" << m_Record[i - 1][6] << " 姓名：" << m_Record[i - 1][7] << " 成绩：" << m_Record[i - 1][8] << endl;
			cout << endl;
		}
	}
	system("pause");
	system("cls");
}

//清空比赛记录
void SpeechManager::clearRecord() {
	//确认是否清空
	char ch;
	cout << "确认是否清空比赛记录？(Y/N)" << endl;
	cin >> ch;
	if (ch == 'Y' || ch == 'y') {
		//清空文件
		ofstream ofs;
		ofs.open("speech.csv", ios::out);
		ofs.close();
		//清空容器
		m_Record.clear();
		//清空文件状态
		fileIsEmpty = true;
		cout << "比赛记录已清空！" << endl;
	}
	else {
		cout << "操作已取消！" << endl;
	}
	system("pause");
	system("cls");
}