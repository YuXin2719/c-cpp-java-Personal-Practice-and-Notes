//#include<iostream>
//using namespace std;
//#include<list>
//
////list容器数据存取
//void test01() {
//	list<int> l1;
//	l1.push_back(10);
//	l1.push_back(20);
//	l1.push_back(30);
//	l1.push_back(40);
//	//l1[0] = 100; //不支持下标访问
//	//l1.at(0) = 100; //不支持at访问
//	//原因是list底层是双向链表结构，不支持随机访问，只能顺序访问。
//	cout << "第一个元素为：" << l1.front() << endl; //访问第一个元素
//	cout << "最后一个元素为：" << l1.back() << endl; //访问最后一个元素
//
//	//验证迭代器是否支持随机访问
//	list<int>::iterator it = l1.begin();
//	it++; //迭代器前进一个位置
//	it--; //迭代器后退一个位置
//	//it += 2; //不支持随机访问,因为这样属于跳跃的访问,不允许
//}
//
//int main() {
//	test01();
//	system("pause");
//	return 0;
//}