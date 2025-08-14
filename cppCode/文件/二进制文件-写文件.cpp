//#include <iostream>
//using namespace std;
//#include <fstream>
//
////二进制文件  写文件
//class Person {
//public:
//	char name[64];
//	int age;
//};
//
//void test01() {
//	//1.包含头文件
//	//2.创建文件流对象
//	ofstream ofs("person.txt", ios::out | ios::binary);
//
//	//3.打开文件
//	//ofs.open("person.txt", ios::out | ios::binary);
//
//	//4.写文件
//	Person p = { "Tom", 20 };
//	ofs.write((const char*)&p, sizeof(Person));
//
//	//5.关闭文件
//	ofs.close();
//}
//
//
//int main()
//{
//
//	test01();
//
//	system("pause");
//	return 0;
//}