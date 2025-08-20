//#include<iostream>
//using namespace std;
//#include<string>
//
////string的赋值操作
////- `string& operator=(const char* s); ` //char*类型字符串 赋值给当前字符串
////- `string& operator=(const char& s); ` //把字符串s赋给当前字符串
////- `string& operator=(char c); ` //把字符赋值给当前字符串
////- `string& assign(const char* s); ` //把字符串s赋给当前字符串
////- `string& assign(const char* s, int n); ` //把字符串s的前n个字符赋给当前字符串
////- `string& assign(const char& s); ` //把字符串s赋给当前字符串
////- `string& assign(int n, char c); ` //用n个字符c赋给当前字符串
//
//void test01() {
//	string str1; //默认构造函数
//	str1 = "hello"; //char*类型字符串 赋值给当前字符串
//	cout << "str1: " << str1 << endl;
//
//	string str2; //默认构造函数
//	str2 = str1; //把字符串str1赋给当前字符串
//	cout << "str2: " << str2 << endl;
//
//	string str3; //默认构造函数
//	str3 = 'a'; //把字符'a'赋值给当前字符串
//	cout << "str3: " << str3 << endl;
//
//	string str4; //默认构造函数
//	str4.assign("world"); //把字符串"world"赋给当前字符串
//	cout << "str4: " << str4 << endl;
//
//	string str5; //默认构造函数
//	str5.assign("hello world", 5); //把字符串"hello world"的前5个字符赋给当前字符串
//	cout << "str5: " << str5 << endl;
//
//	string str6; //默认构造函数
//	str6.assign(str1); //把字符串str1赋给当前字符串
//	cout << "str6: " << str6 << endl;
//
//	string str7; //默认构造函数
//	str7.assign(5, 'x'); //用5个字符'x'赋给当前字符串
//	cout << "str7: " << str7 << endl;
//}
//
//int main() {
//
//	test01();
//
//	system("pause");
//	return 0;
//}