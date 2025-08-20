#include<iostream>
using namespace std;
#include<deque>
#include<algorithm>
#include<vector>
#include<string>
#include<ctime>

//有5名选手：选手ABCDE，10个评委分别对每一名选手打分，去除最高分，去除评委中的最低分，取平均分

//选手类
class Person {
public:
	string name;
	int scores;
	Person(string name, int scores) {
		this->name = name;
		this->scores = scores;
	}
};

void createPersons(vector<Person>& persons) {
	string nameSeed = "ABCDE";
	for (int i = 0; i < 5; i++) {
		string name = "选手";
		name += nameSeed[i];
		Person p(name, 0);
		persons.push_back(p);
	}
}

void setScores(vector<Person>& persons) {
	//模拟10个评委打分
	for (int i = 0; i < persons.size(); i++) {
		deque<int> scores;
		for (int j = 0; j < 10; j++) {
			int score = rand() % 41 + 60; //60-100分
			scores.push_back(score);
		}
		//输出每名选手的分数
		cout << persons[i].name << "的分数为：";
		for (int k = 0; k < scores.size(); k++) {
			cout << scores[k] << " ";
		}
		cout << endl;
		//去除最高分
		sort(scores.begin(), scores.end());
		scores.pop_back();
		//去除最低分
		scores.pop_front();
		//计算平均分
		int sum = 0;
		for (int k = 0; k < scores.size(); k++) {
			sum += scores[k];
		}
		persons[i].scores = sum / scores.size();
	}
}

//显示每名选手的平均分
void showScores(const vector<Person>& persons) {
	cout << "选手平均分：" << endl;
	for (vector<Person>::const_iterator it = persons.begin(); it != persons.end(); it++) {
		cout << it->name << "的平均分为：" << it->scores << endl;
	}
}

int main() {

	//随机数种子
	srand((unsigned int)time(NULL));

	//1.创建5名选手
	vector<Person> persons;
	createPersons(persons);
	//测试
	//for (vector<Person>::iterator it = persons.begin(); it != persons.end(); it++) {
	//	cout << "name:" << it->name << " scores:" << it->scores << endl;
	//}

	//2.给每名选手打分
	setScores(persons);

	//3.显示每名选手的平均分
	showScores(persons);

	system("pause");
	return 0;
}