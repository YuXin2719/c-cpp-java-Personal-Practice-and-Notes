//#include<iostream>
//using namespace std;
//#include<vector>
//
//void printVector(const vector<int>& v) {
//	//const_iterator是一个只读迭代器，不能修改元素
//	for (vector<int>::const_iterator it = v.begin(); it != v.end(); it++) {
//		cout << *it << " ";
//	}
//	cout << endl;
//}
//
////vector容器构造
//void test01() {
//	//默认构造
//	vector<int> v1;
//	for (int i = 0; i < 10; i++) {
//		v1.push_back(i);
//	}
//	printVector(v1);
//
//	//n个elem的构造
//	vector<int> v2(10, 100);
//	printVector(v2);
//
//	//区间方式构造
//	vector<int> v3(v2.begin(), v2.end());
//	printVector(v3);
//
//	//拷贝构造
//	vector<int> v4(v3);
//	printVector(v4);
//
//}
//
//int main() {
//
//	test01();
//
//	system("pause");
//	return 0;
//}