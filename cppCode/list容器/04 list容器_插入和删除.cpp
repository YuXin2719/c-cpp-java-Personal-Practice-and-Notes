//#include<iostream>
//using namespace std;
//#include<list>
//
////list容器插入和删除
//
///*
//- `push_back(elem);`//在容器尾部加入一个元素
//- `pop_back();`//删除容器中最后一个元素
//- `push_front(elem);`//在容器开头插入一个元素
//- `pop_front();`//从容器开头移除第一个元素
//- `insert(pos,elem);`//在pos位置插elem元素的拷贝，返回新数据的位置。
//- `insert(pos,n,elem);`//在pos位置插入n个elem数据，无返回值。
//- `insert(pos,beg,end);`//在pos位置插入[beg,end]区间的数据，无返回值。
//- `clear();`//移除容器的所有数据
//- `erase(beg,end);`//删除[beg,end]区间的数据，返回下一个数据的位置。
//- `erase(pos);`//删除pos位置的数据，返回下一个数据的位置。
//- `remove(elem);`//删除容器中所有与elem值匹配的元素。
//*/
//
//void printList(const list<int>& L) {
//	for (list<int>::const_iterator it = L.begin(); it != L.end(); it++) {
//		cout << *it << " ";
//	}
//	cout << endl;
//}
//
//void test01() {
//	list<int> l;
//	//尾插
//	l.push_back(10);
//	l.push_back(20);
//	l.push_back(30);
//	//头插
//	l.push_front(100);
//	l.push_front(200);
//	l.push_front(300);
//	printList(l); //300 200 100 10 20 30
//	//尾删
//	l.pop_back();
//	printList(l); //300 200 100 10 20
//	//头删
//	l.pop_front();
//	printList(l); //200 100 10 20
//	//插入
//	l.insert(l.begin(), 1000);
//	printList(l); //1000 200 100 10 20
//	l.insert(l.begin(), 2, 888);
//	printList(l); //888 888 1000 200 100 10 20
//	//删除
//	l.erase(l.begin());
//	printList(l); //888 1000 200 100 10 20
//	//移除
//	l.remove(888);
//	printList(l); //1000 200 100 10 20
//	//清空
//	l.clear();
//	printList(l); //空
//}
//
//int main() {
//
//	test01();
//
//	system("pause");
//	return 0;
//}