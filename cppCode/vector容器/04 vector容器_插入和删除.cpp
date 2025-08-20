//#include<iostream>
//using namespace std;
//#include<vector>
//
////插入和删除元素
///*
//- `push_back(ele);` //尾部插入元素ele
//- `pop_back();` //删除最后一个元素
//- `insert(const_iterator pos, ele);` //迭代器指向位置pos插入元素ele
//- `insert(const_iterator pos, int count, ele);` //迭代器指向位置pos插入count个元素ele
//- `erase(const_iterator pos);` //删除迭代器指向的元素
//- `erase(const_iterator start, const_iterator end);` //删除迭代器从start到end之间的元素
//- `clear();` //删除容器中所有的元素
//*/
//
//void printVector(const vector<int>& v) {
//	for (vector<int>::const_iterator it = v.begin(); it != v.end(); ++it) {
//		cout << *it << " ";
//	}
//	cout << endl;
//}
//
//void test01() {
//	vector<int> v;
//	//尾部插入元素
//	v.push_back(10);
//	v.push_back(20);
//	v.push_back(30);
//	printVector(v); // 10 20 30
//
//	//删除最后一个元素
//	v.pop_back();
//	printVector(v); // 10 20
//
//	//迭代器指向位置pos插入元素ele
//	vector<int>::iterator it = v.begin();
//	v.insert(it, 100); //在第一个位置插入100
//	printVector(v); // 100 10 20
//
//	//迭代器指向位置pos插入count个元素ele
//	it = v.begin(); // 重新获取迭代器
//	v.insert(it, 2, 200); //在第一个位置插入两个200
//	printVector(v); // 200 200 100 10 20
//
//	//删除迭代器指向的元素
//	it = v.begin(); // 重新获取迭代器
//	v.erase(it);
//	printVector(v); // 200 100 10 20
//
//	//删除迭代器从start到end之间的元素
//	vector<int>::iterator start = v.begin();
//	vector<int>::iterator end = v.end();
//	v.erase(start, end);
//	printVector(v); // (空行)
//
//	//删除容器中所有的元素
//	v.push_back(10);
//	v.push_back(20);
//	v.push_back(30);
//	v.clear();
//	printVector(v); // (空行)
//}
//
//int main() {
//	test01();
//
//	system("pause");
//	return 0;
//}