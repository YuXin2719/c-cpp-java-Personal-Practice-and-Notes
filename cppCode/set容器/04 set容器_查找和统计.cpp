//#include<iostream>
//using namespace std;
//#include<set>
//
////set容器 查找和统计
//void test01() {
//	set<int>s1;
//	s1.insert(10);
//	s1.insert(20);
//	s1.insert(30);
//	s1.insert(40);
//	s1.insert(50);
//	set<int>::iterator pos = s1.find(30);
//	if (pos != s1.end()) {
//		cout << "找到元素:" << *pos << endl;
//	}
//	else {
//		cout << "未找到元素" << endl;
//	}
//	int num = s1.count(30);
//	//对于set来说，统计的结果要么是0，要么是1
//	cout << "30的个数为:" << num << endl;
//}
//
//int main() {
//	test01();
//	system("pause");
//	return 0;
//}