#include<iostream>
using namespace std;
#include<queue>
#include<string>

//队列 queue
class Person {
public:
	Person(string n, int a) : name(n), age(a) {}
	string name;
	int age;
};

void test01() {
	//创建队列
	queue<Person> q;
	//添加数据
	q.push(Person("张三", 20));
	q.push(Person("李四", 22));
	q.push(Person("王五", 25));
	//判断只要队列不为空,查看队头,查看队尾,出队
	while (!q.empty()) {
		//查看队头
		cout << "队头姓名: " << q.front().name << " 年龄: " << q.front().age << endl;
		//查看队尾
		cout << "队尾姓名: " << q.back().name << " 年龄: " << q.back().age << endl;
		//出队
		q.pop();
		cout << "出队后队列大小为: " << q.size() << endl;
	}
}

int main() {
	test01();
	system("pause");
	return 0;
}