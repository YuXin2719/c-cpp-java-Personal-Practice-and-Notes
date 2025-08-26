//#include<iostream>
//using namespace std;
//#include<vector>
//#include<algorithm>
//
////常用集合算法_set_intersection
//void test01() {
//	vector<int>v1;
//	vector<int>v2;
//	vector<int>v3;
//	for (int i = 0; i < 10; i++) {
//		v1.push_back(i);
//		v2.push_back(i + 5);
//	}
//	//v1:0~9
//	//v2:5~14
//	//v3:5~9
//	//注意：使用集合算法，必须保证两个集合有序
//	sort(v1.begin(), v1.end());
//	sort(v2.begin(), v2.end());
//	//第一个参数：第一个集合的开始迭代器
//	//第二个参数：第一个集合的结束迭代器
//	//第三个参数：第二个集合的开始迭代器
//	//第四个参数：第二个集合的结束迭代器
//	//第五个参数：存储交集的容器的开始迭代器
//	//其中back_inserter(v3)表示从v3容器的尾部开始插入数据,底层是调用的push_back方法
//	//set_intersection的返回值是一个迭代器,指向最后一个元素(最后一个实际有用的元素,如果容器大小很大,其他填充的就是默认值)的下一个位置,如果需要使用这个返回值,可以用一个迭代器变量接收
//	set_intersection(v1.begin(), v1.end(), v2.begin(), v2.end(), back_inserter(v3));
//	for (vector<int>::iterator it = v3.begin(); it != v3.end(); it++) {
//		cout << *it << " ";
//	}
//	cout << endl;
//}
//
//int main() {
//	test01();
//	system("pause");
//	return 0;
//}