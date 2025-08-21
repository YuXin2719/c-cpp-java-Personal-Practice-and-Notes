//#include<iostream>
//using namespace std;
//#include<list>
//
////list容器反转和排序
//
//void showList(const list<int>& l) {
//	for (list<int>::const_iterator it = l.begin(); it != l.end(); it++) {
//		cout << *it << " ";
//	}
//	cout << endl;
//}
//
//bool myCompare(int v1, int v2) {
//	return v1 > v2; //返回true,交换元素
//}
//
//void test01() {
//	list<int> l;
//	l.push_back(1);
//	l.push_back(3);
//	l.push_back(2);
//	l.push_back(4);
//	l.push_back(5);
//	showList(l);
//	//反转操作
//	l.reverse();
//	showList(l);
//	//所有不支持随机访问迭代器的容器,不可以用标准算法 #include<algorithm>
//	//不支持随机访问迭代器容器,内部会提供对应的一些算法
//	//排序操作
//	l.sort(); //默认排序规则,从小到大升序
//	showList(l);
//	//降序排序
//	l.sort(myCompare);
//	showList(l);
//}
//
//int main() {
//	test01();
//
//	system("pause");
//	return 0;
//}