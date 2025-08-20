//#include<iostream>
//using namespace std;
//#include<string>
//
////字符串查找和替换
//
////1.查找
//void test01() {
//	string str = "hello world";
//	//查找字符串
//	int pos = str.find("world");
//	if (pos != string::npos) {
//		cout << "找到字符串 'world'，位置：" << pos << endl;
//	}
//	else {
//		cout << "未找到字符串 'world'" << endl;
//	}
//
//	//rfind 从后向前查找
//	pos = str.rfind("hello");
//	if (pos != string::npos) {
//		cout << "从后向前找到字符串 'hello'，位置：" << pos << endl;
//	}
//	else {
//		cout << "未找到字符串 'hello'" << endl;
//	}
//}
//
////2.替换
//void test02() {
//	string str = "hello world";
//	//替换字符串
//	str.replace(6, 5, "C++"); //从位置6开始，替换5个字符为"C++"
//	cout << "替换后的字符串：" << str << endl;
//}
//
//int main() {
//	test01();
//	test02();
//	system("pause");
//	return 0;
//}