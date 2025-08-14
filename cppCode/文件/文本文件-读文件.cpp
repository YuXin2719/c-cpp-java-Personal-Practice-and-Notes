//#include <iostream>
//using namespace std;
//#include <fstream>
//#include <string>
//
////文本文件 读文件
//void test01() {
//	//1.包含头文件
//
//	//2.创建输入流对象
//	ifstream ifs;
//
//	//3.打开文件
//	ifs.open("test.txt", ios::in);
//
//	//4.判断文件是否打开成功
//	if (!ifs.is_open()) {
//		cout << "文件打开失败" << endl;
//		return;
//	}
//
//	//5.读数据
//	////	第一种方式
//	//char buf[1024] = { 0 };
//	//while (ifs >> buf) {
//	//	cout << buf << endl;
//	//}
//
//	////	第二种方式
//	//char buf2[1024] = { 0 };
//	//while (ifs.getline(buf2, sizeof(buf2))) {
//	//	cout << buf2 << endl;
//	//}
//
//	//	第三种方式
//	string str;
//	while (getline(ifs, str)) {
//		cout << str << endl;
//	}
//
//	//  第四种方式
//	//char c;
//	//while ((c = ifs.get()) != EOF) { //EOF是文件结束符 end of file
//	//	cout << c;
//	//}
//
//	//6.关闭文件
//	ifs.close();
//}
//
//int main()
//{
//
//	test01();
//
//	system("pause");
//	return 0;
//}