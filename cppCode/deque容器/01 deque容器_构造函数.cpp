//#include<iostream>
//using namespace std;
//#include<deque>
//
//void printDeque(const deque<int>& d) {
//	for (deque<int>::const_iterator it = d.begin(); it != d.end(); it++) {
//		cout << *it << " ";
//	}
//	cout << endl;
//}
//
////deque容器 构造函数
//void test() {
//	deque<int> d1; //默认构造 无参构造
//	for (int i = 0; i < 10; i++) {
//		d1.push_back(i);
//	}
//	printDeque(d1);
//	deque<int> d2(d1); //拷贝构造
//	printDeque(d2);
//	deque<int> d3(d2.begin(), d2.end()); //区间构造
//	printDeque(d3);
//	deque<int> d4(10, 100); //n个elem
//	printDeque(d4);
//}
//
//int main() {
//	test();
//	system("pause");
//	return 0;
//}