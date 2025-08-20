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
////deque容器插入和删除
//void test01() {
//	deque<int> d;
//	//尾部插入
//	d.push_back(10);
//	d.push_back(20);
//	d.push_back(30);
//	printDeque(d);
//	//头部插入
//	d.push_front(100);
//	d.push_front(200);
//	d.push_front(300);
//	printDeque(d);
//	//尾部删除
//	d.pop_back();
//	printDeque(d);
//	//头部删除
//	d.pop_front();
//	printDeque(d);
//	//清空容器
//	d.clear();
//	printDeque(d);
//}
//
//void test02() {
//	deque<int> d;
//	//尾部插入
//	d.push_back(10);
//	d.push_back(20);
//	d.push_back(30);
//	//头部插入
//	d.push_front(100);
//	d.push_front(200);
//	d.push_front(300);
//	printDeque(d);
//	//insert插入
//	d.insert(d.begin(), 1000); //在头部插入1000
//	printDeque(d);
//	d.insert(d.begin(), 2, 1000); //在头部插入2个1000
//	printDeque(d);
//	//按照区间插入
//	deque<int> d2;
//	d2.push_back(10000);
//	d2.push_back(20000);
//	d2.push_back(30000);
//	d.insert(d.begin(), d2.begin(), d2.end()); //在头部插入d2的所有元素
//	printDeque(d);
//}
//
//void test03() {
//	deque<int> d;
//	//尾部插入
//	d.push_back(10);
//	d.push_back(20);
//	d.push_back(30);
//	//头部插入
//	d.push_front(100);
//	d.push_front(200);
//	d.push_front(300);
//	printDeque(d);
//	//erase删除
//	d.erase(d.begin()); //删除头部元素
//	printDeque(d);
//	d.erase(d.begin(), d.end() - 1); //删除除最后一个元素外的所有元素
//	printDeque(d);
//	//清空容器
//	d.clear();
//	printDeque(d);
//}
//
//int main() {
//	test01();
//	test02();
//	test03();
//	system("pause");
//	return 0;
//}