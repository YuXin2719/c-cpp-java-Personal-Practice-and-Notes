//#include<iostream>
//using namespace std;
//#include<map>
//
////map容器_查找和统计
//void test01() {
//	map<int, int>m;
//	//插入数据
//	m.insert(pair<int, int>(1, 10));
//	m.insert(make_pair(2, 20));
//	m.insert(map<int, int>::value_type(3, 30));
//	m[4] = 40;
//	m[5] = 50;
//	//查找元素find(key)
//	map<int, int>::iterator pos = m.find(3);
//	if (pos != m.end()) {
//		cout << "找到元素 key = " << pos->first << " value = " << pos->second << endl;
//	}
//	else {
//		cout << "未找到元素" << endl;
//	}
//	//统计元素count(key)
//	//map不允许有重复key,所以统计结果要么是0要么是1
//	int num = m.count(3);
//	cout << "num = " << num << endl;
//}
//
//int main() {
//
//	test01();
//
//	system("pause");
//	return 0;
//}