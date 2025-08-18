//#include<iostream>
//using namespace std;
//#include<vector>
//#include<algorithm> //for_each需要包含的头文件
//
//
////打印函数
//void myPrint(int val) {
//	cout << val << " ";
//}
//
////vector容器存放内置数据类型
//
//void test01() {
//	vector<int> v; //定义一个int类型的vector容器
//	//向容器中添加数据
//	v.push_back(10); //在容器末尾添加数据
//	v.push_back(20);
//	v.push_back(30);
//	//通过迭代器访问容器中的数据
//	//第一种遍历方式
//	vector<int>::iterator it = v.begin(); //起始迭代器，指向容器的第一个元素
//	while (it != v.end()) { //end()返回一个迭代器，指向容器的末尾
//		cout << *it << " ";
//		++it;
//	}
//	cout << endl;
//
//	//第二种遍历方式
//	for (vector<int>::iterator it = v.begin(); it != v.end(); it++) {
//		cout << *it << " ";
//	}
//	cout << endl;
//
//	//第三种遍历方式
//	for (int i = 0; i < v.size(); i++) { //size()返回容器中元素的个数
//		cout << v[i] << " "; //通过[]访问容器中的元素
//	}
//	cout << endl;
//
//	//第四种遍历方式（C++11新特性）
//	for (auto e : v) { //e依次表示容器中的每个元素
//		cout << e << " ";
//	}
//	cout << endl;
//
//	//第五种遍历方式，利用STL提供的算法for_each
//	for_each(v.begin(), v.end(), myPrint);
//}
//
//int main() {
//
//	test01(); //调用测试函数
//
//	system("pause");
//	return 0;
//}