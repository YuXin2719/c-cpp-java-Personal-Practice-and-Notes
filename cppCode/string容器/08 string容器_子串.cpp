//#include<iostream>
//using namespace std;
//#include<string>
//
////string求子串
//void test1() {
//	string str = "hello world";
//	string subStr = str.substr(0, 5); // 从索引0开始，长度为5
//	cout << subStr << endl; // 输出: hello
//}
//
////实用操作
//void test2() {
//	string email = "zhangsan@sina.com";
//	//从邮件地址中获取用户名信息
//	int pos = email.find('@'); // 查找'@'的位置
//	if (pos != string::npos) { // 如果找到了
//		string username = email.substr(0, pos); // 截取从0到'@'的子串
//		cout << "Username: " << username << endl; // 输出用户名
//	}
//	else {
//		cout << "No '@' found in the email." << endl;
//	}
//}
//
//int main() {
//	test1();
//	test2();
//	system("pause");
//	return 0;
//}