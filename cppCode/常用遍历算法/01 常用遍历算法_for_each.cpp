//#include<iostream>
//using namespace std;
//#include<vector>
//#include<algorithm>
//
////常用遍历算法_for_each
//
////普通函数
//void myPrint(int val) {
//	cout << val << " ";
//}
//
////仿函数
//class MyPrint {
//public:
//	void operator()(int val) {
//		cout << val << " ";
//	}
//};
//
//void test01() {
//	vector<int> v;
//	for (int i = 0; i < 10; i++) {
//		v.push_back(i);
//	}
//	//利用for和迭代器遍历容器
//	for (vector<int>::iterator it = v.begin(); it != v.end(); it++) {
//		cout << *it << " ";
//	}
//	cout << endl;
//	//利用STL提供的遍历算法_for_each
//	for_each(v.begin(), v.end(), [](int val) {
//		cout << val << " ";
//		}); //解释语法:[](int val){}; 这是一个匿名函数,没有名字,只能使用一次
//	cout << endl;
//	//使用自己写的普通函数遍历
//	for_each(v.begin(), v.end(), myPrint);
//	cout << endl;
//	//使用自己写的仿函数遍历
//	for_each(v.begin(), v.end(), MyPrint());
//	cout << endl;
//}
//
//int main() {
//	test01();
//
//	system("pause");
//	return 0;
//}