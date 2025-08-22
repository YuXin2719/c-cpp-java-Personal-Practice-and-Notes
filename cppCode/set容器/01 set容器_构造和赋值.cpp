//#include<iostream>
//using namespace std;
//#include<set>
//
////set容器构造和赋值
//void showSet(const set<int>& s) {
//	for (set<int>::const_iterator it = s.begin(); it != s.end(); it++) {
//		cout << *it << " ";
//	}
//	cout << endl;
//}
//
//void test01() {
//	set<int> s1; //默认构造函数
//
//	//插入数据,只有insert的方式
//	s1.insert(10);
//	s1.insert(30);
//	s1.insert(20);
//	s1.insert(40);
//	s1.insert(40);
//	//遍历容器
//	//set容器特点：自动排序，且不允许重复元素
//	showSet(s1);
//
//	set<int> s2(s1); //拷贝构造函数
//	showSet(s2);
//	set<int> s3 = s1; //拷贝构造函数
//	showSet(s3);
//	set<int> s4(s1.begin(), s1.end()); //迭代器范围构造函数
//	showSet(s4);
//	set<int> s5{ 10,20,30 }; //列表初始化
//	showSet(s5);
//	//赋值操作
//	s1 = s2; //赋值运算符
//	showSet(s1);
//	s1 = { 100,200,300 }; //列表赋值
//	showSet(s1);
//}
//
//int main() {
//
//	test01();
//
//	system("pause");
//	return 0;
//}