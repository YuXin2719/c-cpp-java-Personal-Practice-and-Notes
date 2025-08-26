#include"speechManager.h"

//构造函数
SpeechManager::SpeechManager()
{
	//初始化比赛
	initSpeech();
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
	//第一轮比赛
	//1.抽签
	speechDraw();

	//2.比赛
	speechContest();

	//3.显示晋级结果

	//第二轮比赛
	//1.抽签

	//2.比赛

	//3.显示最终结果

	//4.保存分数
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
		cout << "编号：" << *it << " 姓名：" << m_Speaker[*it].m_Name << " 成绩：" << avg << endl;

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
			//展示晋级人员
			cout << "第" << m_Index << "轮第" << num / 6 << "小组晋级人员：" << endl;
			if (m_Index == 1) {
				for (vector<int>::iterator it = v2.begin(); it != v2.end(); it++) {
					cout << "编号：" << *it << " 姓名：" << m_Speaker[*it].m_Name << " 成绩：" << m_Speaker[*it].m_Score[0] << endl;
				}
			}
			else {
				for (vector<int>::iterator it = vVictory.begin(); it != vVictory.end(); it++) {
					cout << "编号：" << *it << " 姓名：" << m_Speaker[*it].m_Name << " 成绩：" << m_Speaker[*it].m_Score[1] << endl;
				}
			}
			cout << "---------------------" << endl;
		}
	}
	cout << "第" << m_Index << "轮比赛完毕！" << endl;
	system("pause");
}