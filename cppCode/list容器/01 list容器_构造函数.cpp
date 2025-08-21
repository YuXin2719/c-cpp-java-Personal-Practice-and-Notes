//#include<iostream>
//using namespace std;
//#include<list> //list容器头文件
//
//void showList(const list<int>& l) {
//	for (list<int>::const_iterator it = l.begin(); it != l.end(); it++) {
//		cout << *it << " ";
//	}
//	cout << endl;
//}
//
////list容器_构造函数
//void test01() {
//	//默认构造
//	list<int> l1;
//	showList(l1);
//	//区间方式构造
//	int arr[] = { 1,2,3,4,5 };
//	list<int> l2(arr, arr + sizeof(arr) / sizeof(int));
//	showList(l2);
//	list<int> l5(l1.begin(), l1.end()); //使用l1的迭代器区间构造
//	showList(l5);
//	//拷贝构造
//	list<int> l3(l2);
//	showList(l3);
//	//n个elem方式构造
//	list<int> l4(10, 100); //10个100
//	showList(l4);
//}
//
//int main() {
//	test01();
//
//	system("pause");
//	return 0;
//}