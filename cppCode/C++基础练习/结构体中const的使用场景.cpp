//#include <iostream>
//#include <string>
//
//using namespace std;
//
////const的使用场景
//
//struct student
//{
//	string name;//姓名
//	int age;//年龄
//	int score;//分数
//};
//
////将函数中的形参改为指针，可以减少内存空间，而且不会复制新的副本出来
//void printStudent(const student* p) //指针只占4个字节
//{
//	//p->name = "李四"; 不行 加入const之后，一旦有修改的操作就会报错，可以防止我们误操作
//	cout << "学生姓名为：" << p->name << endl; // (*p).name 也可以
//	cout << "学生年龄为：" << p->age << endl;
//	cout << "学生分数为：" << p->score << endl;
//}
//
//int main()
//{
//
//	//创建结构体变量
//	student s = { "张三",15,70 };
//
//	//通过函数打印结构体变量的信息
//	printStudent(&s);
//
//	system("pause");
//	return 0;
//}