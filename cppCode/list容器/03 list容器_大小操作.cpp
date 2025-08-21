//#include<iostream>
//using namespace std;
//#include<list>
//
////list容器大小操作
//
//void printList(const list<int>& l) {
//	for (list<int>::const_iterator it = l.begin(); it != l.end(); it++) {
//		cout << *it << " ";
//	}
//	cout << endl;
//}
//
//void test01() {
//	list<int>l;
//	//尾插
//	l.push_back(10);
//	l.push_back(20);
//	l.push_back(30);
//	printList(l);
//	//1.判断容器是否为空
//	if (l.empty()) {
//		cout << "容器为空" << endl;
//	}
//	else {
//		cout << "容器不为空" << endl;
//	}
//	//2.返回容器大小
//	cout << "容器大小为：" << l.size() << endl;
//	//3.重新指定容器大小
//	l.resize(10); //默认填充0
//	printList(l);
//	l.resize(15, 100); //指定填充数字100
//	printList(l);
//	l.resize(5);
//	printList(l);
//}
//
//int main() {
//	test01();
//
//	system("pause");
//	return 0;
//}