#include<iostream>
using namespace std;
#include<map>

//map容器的构造和赋值

void printMap(const map<int, int>& m) {
	//这里的auto是C++11引入的类型推断关键字，表示自动推断变量类型
	//auto在这里会被推断为map<int, int>::const_iterator
	for (auto it = m.begin(); it != m.end(); ++it) {
		cout << "key: " << it->first << ", value: " << it->second << endl;
	}
}

void test01() {
	//1.默认构造,两个参数分别表示键值类型和值类型
	map<int, int> m1;
	m1.insert(pair<int, int>(1, 10));
	m1.insert(pair<int, int>(2, 20));
	m1.insert(pair<int, int>(3, 30));
	m1.insert(pair<int, int>(4, 40));
	m1.insert(pair<int, int>(5, 50));
	printMap(m1);
	//2.指定范围构造
	map<int, int> m2(m1.begin(), m1.end());
	printMap(m2);
	//3.复制构造
	map<int, int> m3(m2);
	printMap(m3);
	//4.指定比较函数构造,less<int>是一个函数对象，表示使用小于号进行比较
	map<int, int, less<int>> m4;
	//5.指定比较函数和分配器构造,allocator是一个分配器，这里表示使用默认的内存分配器
	map<int, int, less<int>, allocator<pair<const int, int>>> m5;
}

int main() {
	test01();

	system("pause");
	return 0;
}