//#include<iostream>
//using namespace std;
//#include<set>
//
//// Set容器的插入和删除操作
//
//void test01() {
//	set<int> s1;
//	s1.insert(10);
//	s1.insert(30);
//	s1.insert(20);
//	s1.insert(40);
//	//删除操作
//	s1.erase(20); //删除指定元素
//	s1.erase(s1.begin()); //删除第一个元素
//	//遍历容器
//	for (set<int>::iterator it = s1.begin(); it != s1.end(); it++) {
//		cout << *it << " ";
//	}
//	cout << endl;
//	//清空容器
//	s1.clear();
//	if (s1.empty()) {
//		cout << "s1 is empty!" << endl;
//	} else {
//		cout << "s1 is not empty!" << endl;
//	}
//}
//
//int main() {
//	test01();
//	system("pause");
//	return 0;
//}