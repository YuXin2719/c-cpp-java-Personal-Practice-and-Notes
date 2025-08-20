//#include<iostream>
//using namespace std;
//#include<string>
//
////字符串拼接
////- `string& operator+=(const char* str); ` //重载+=操作符
////- `string& operator+=(const char c); ` //重载+=操作符
////- `string& operator+=(const string & str); ` //重载+=操作符
////- `string& append(const char* s); ` //把字符串s连接到当前字符串结尾
////- `string& append(const char* s, int n); ` / 把字符串s的前n个字符连接到当前字符串结尾
////- `string& append(const char& s); ` 同operator += (const string & str)
////- `string& append(const char& s, int pos, int n); ` //把字符串s中从pos开始的n个字符连接到字符串结尾
//
//void test01() {
//	string str1 = "我";
//	str1 += "爱玩游戏";
//	cout << str1 << endl; // 输出: 我爱玩游戏
//
//	str1 += '!';
//	cout << str1 << endl; // 输出: 我爱玩游戏!
//
//	string str2 = "hello bro";
//	str1 += str2;
//	cout << str1 << endl; // 输出: 我爱玩游戏!你
//
//	string str3 = "编程";
//	str3.append("很有趣");
//	cout << str3 << endl; // 输出: 编程很有趣
//
//	str3.append("game", 2);
//	cout << str3 << endl; // 输出: 编程很有趣好玩
//
//	str3.append(str2);
//	cout << str3 << endl; // 输出: 编程很有趣好玩你
//
//	str3.append(str2, 6, 3); //参数含义: 从str2的第6个位置开始,取3个字符
//	cout << str3 << endl; // 输出: 编程很有趣好玩你好
//}
//
//int main() {
//	test01();
//	system("pause");
//	return 0;
//}