//#include<iostream>
//using namespace std;
//#include<set>
//
////set容器 排序
//
//class myCompare {
//public:
//	bool operator()(int v1, int v2) const { //重载()运算符
//		return v1 > v2;
//	}
//};
//
//void test01() {
//	set<int> s1;
//	s1.insert(10);
//	s1.insert(20);
//	s1.insert(30);
//	s1.insert(40);
//	s1.insert(50);
//	//set容器默认是升序排列
//	for (set<int>::iterator it = s1.begin(); it != s1.end(); it++) {
//		cout << *it << " ";
//	}
//	cout << endl;
//	//降序排列
//	//set<int, greater<int>> s2; //greater是一个函数对象 仿函数,系统提供的,可以直接使用
//	//或者自己定义一个仿函数
//	set<int, myCompare> s2; //放数据类型,仿函数本质上是一个数据类型
//	s2.insert(10);
//	s2.insert(20);
//	s2.insert(30);
//	s2.insert(40);
//	s2.insert(50);
//	for (set<int, myCompare>::iterator it = s2.begin(); it != s2.end(); it++) {
//		cout << *it << " ";
//	}
//	cout << endl;
//}
//
//
//int main() {
//	test01();
//	system("pause");
//	return 0;
//}