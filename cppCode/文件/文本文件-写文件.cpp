//#include <iostream>
//using namespace std;
//#include <fstream> //包含头文件fstream
//
////文本文件 写文件
//
//void test01() {
//	//1.包含头文件 fstream
//
//	//2.创建流对象
//	ofstream ofs; //创建输出流对象
//
//	//3.打开文件
//	ofs.open("test.txt", ios::out); //打开文件，指定打开方式为写模式
//
//	//4.判断文件是否打开成功
//	if (!ofs.is_open()) {
//		cout << "文件打开失败" << endl;
//		return; //如果打开失败，直接返回
//	}
//
//	//5.写数据到文件
//	ofs << "hello world" << endl; //向文件写入数据
//
//	//6.关闭文件
//	ofs.close(); //关闭文件流
//}
//
//int main()
//{
//
//	test01(); //调用函数执行写文件操作
//
//	system("pause");
//	return 0;
//}