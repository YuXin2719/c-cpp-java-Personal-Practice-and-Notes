//#include<iostream>
//using namespace std;
//#include<deque>
//#include<algorithm> //包含sort函数的头文件
//
////deque容器排序
//void test01() {
//	deque<int> d;
//	d.push_back(10);
//	d.push_back(40);
//	d.push_back(50);
//	d.push_back(20);
//	d.push_back(30);
//	//使用sort函数对deque容器进行排序,默认是从小到大排序
//	//对于支持随机访问的迭代器的容器都可以使用sort算法
//	//vector、deque、array都可以使用sort算法
//	sort(d.begin(), d.end());
//	//输出排序后的结果
//	for (deque<int>::iterator it = d.begin(); it != d.end(); it++) {
//		cout << *it << " ";
//	}
//	cout << endl;
//}
//
//int main() {
//
//	test01();
//
//	system("pause");
//	return 0;
//}