//#include <iostream>
//#include <string>
//
//using namespace std;
//
////学生结构体定义
//struct student
//{
//	//姓名
//	string name;
//	//年龄
//	int age;
//	//分数
//	int score;
//};
//
////打印学生信息的函数
////1.值传递
//void printStudent1(student s)
//{
//	s.score = 100;
//	cout << "在子函数中 姓名：" << s.name << endl;
//	cout << "在子函数中 年龄：" << s.age << endl;
//	cout << "在子函数中 分数：" << s.score << endl; //100
//}
//
////2.地址传递
//void printStudent2(student* p)
//{
//	p->score = 100;
//	cout << "在子函数2中 姓名：" << p->name << endl;
//	cout << "在子函数2中 年龄：" << p->age << endl;
//	cout << "在子函数2中 分数：" << p->score << endl; //100
//}
//
//int main()
//{
//
//	//结构体做函数参数
//	//将学生传入到一个参数中,打印学生身上的所有信息
//
//	//创建结构体变量
//	student s;
//	s.name = "张三";
//	s.age = 20;
//	s.score = 85;
//
//	printStudent1(s);
//	cout << "main函数中打印 姓名：" << s.name << endl;
//	cout << "main函数中打印 年龄：" << s.age << endl;
//	cout << "main函数中打印 分数：" << s.score << endl; //85
//
//	printStudent2(&s);
//	cout << "main函数中打印 姓名：" << s.name << endl;
//	cout << "main函数中打印 年龄：" << s.age << endl;
//	cout << "main函数中打印 分数：" << s.score << endl;  //100
//
//	system("pause");
//	return 0;
//}