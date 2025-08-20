//#include<iostream>
//using namespace std;
//#include<deque>
//
////deque容器数据存取
//void test01() {
//	deque<int> d1;
//	for (int i = 0; i < 10; i++) {
//		d1.push_back(i);
//	}
//	//遍历容器
//	for (deque<int>::iterator it = d1.begin(); it != d1.end(); it++) {
//		cout << *it << " ";
//	}
//	cout << endl;
//	//使用下标访问元素
//	for (int i = 0; i < d1.size(); i++) {
//		cout << d1[i] << " ";
//	}
//	cout << endl;
//	//使用at()访问元素
//	for (int i = 0; i < d1.size(); i++) {
//		cout << d1.at(i) << " ";
//	}
//	cout << endl;
//	//使用front()和back()访问首尾元素
//	cout << "首元素: " << d1.front() << endl;
//	cout << "尾元素: " << d1.back() << endl;
//}
//
//int main() {
//	test01();
//
//	system("pause");
//	return 0;
//}