//#include<iostream>
//using namespace std;
//#include<set>
//
////set和multiset的区别
//
////模板函数
//template<typename T>
//void show(const T& s) {
//	for (auto it = s.begin(); it != s.end(); it++) {
//		cout << *it << " ";
//	}
//	cout << endl;
//}
//
//void test01() {
//	set<int> s1;
//	s1.insert(10);
//	pair<set<int>::iterator, bool> ret = s1.insert(10);
//	if (ret.second) {
//		cout << "插入成功:" << *ret.first << endl;
//	}
//	else {
//		cout << "插入失败:" << *ret.first << endl;
//	}
//	s1.insert(20);
//	s1.insert(30);
//	s1.insert(40);
//	s1.insert(50);
//	cout << "set容器中的元素为:";
//	show(s1);
//
//	multiset<int> s2;
//	//multiset允许插入重复元素
//	s2.insert(10);
//	s2.insert(20);
//	s2.insert(30);
//	s2.insert(40);
//	s2.insert(50);
//	s2.insert(30);
//	cout << "multiset容器中的元素为:";
//	show(s2);
//}
//
//int main() {
//	test01();
//	system("pause");
//	return 0;
//}