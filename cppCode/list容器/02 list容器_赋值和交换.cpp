//#include<iostream>
//using namespace std;
//#include<list>
//
////list容器赋值和交换
//
//void show(list<int>& l) {
//	for (list<int>::iterator it = l.begin(); it != l.end(); it++) {
//		cout << *it << " ";
//	}
//	cout << endl;
//}
//
//void test01() {
//	//list容器赋值和交换
//	//创建一个list容器
//	list<int> l1;
//	for (int i = 0; i < 10; i++) {
//		l1.push_back(i);
//	}
//	show(l1);
//
//	//赋值操作
//	list<int> l2;
//	l2.assign(l1.begin(), l1.end());
//	show(l2);
//
//	//等号赋值操作
//	list<int> l4;
//	l4 = l1; //等号赋值
//	show(l4);
//
//	//赋值操作
//	list<int> l3;
//	l3.assign(5, 100);
//	show(l1);
//	show(l3);
//
//	//交换操作
//	l1.swap(l3);
//	show(l1);
//	show(l3);
//}
//
//int main() {
//	test01();
//	system("pause");
//	return 0;
//}