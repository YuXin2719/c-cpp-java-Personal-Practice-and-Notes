//#include <iostream>
//#include <string>
//
//using namespace std;
//
////结构体指针
//
////定义学生的结构体
//struct student
//{
//	string name;
//	int age;
//	int score;
//};
//
//int main()
//{
//
//	//创建学生的结构体变量
//	student s = { "张三",18,100 };
//
//	//通过指针指向结构体变量
//	student* p = &s;
//
//	//通过指针访问结构体变量中的数据
//	//通过结构体指针 访问结构体中的属性，需要利用 '->'
//	cout << "姓名：" << p->name << endl;
//	cout << "年龄：" << p->age << endl;
//	cout << "成绩：" << p->score << endl;
//
//	system("pause");
//	return 0;
//}