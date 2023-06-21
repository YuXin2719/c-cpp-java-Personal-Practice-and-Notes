//#include <iostream>
//#include <string>
//#include <ctime>
//
//using namespace std;
//
///*
//学校正在做毕设项目，每名老师带领5个学生，总共有3名老师，需求如下：
//
//设计学生和老师的结构体，其中在老师的结构体中，有老师姓名和一个存放5名学生的数组作为成员
//
//学生的成员有姓名、考试分数，创建数组存放3名老师，通过函数给每个老师及所带的学生赋值
//
//最终打印出老师数据以及老师所带的学生数据
//*/
//
////创建老师结构体
//struct student
//{
//	string name;//学生姓名
//	int score;//学生分数
//};
//
////创建学生结构体
//struct teacher
//{
//	string name;//老师姓名
//	student student[5];
//};
//
////创建赋值函数
//void assign(teacher teacher[], int len)
//{
//	string nameSeed = "ABCDE";
//	//给老师赋值
//	for (int i = 0; i < len; i++)
//	{
//		teacher[i].name = "teacher_";
//		teacher[i].name += nameSeed[i];
//
//		//给学生赋值
//		for (int j = 0; j < 5; j++)
//		{
//			teacher[i].student[j].name = "student_";
//			teacher[i].student[j].name += nameSeed[j];
//
//			int random = rand() % 101; //随机数
//
//			teacher[i].student[j].score = random;
//		}
//	}
//}
//
//
////打印所有信息
//void printInfo(teacher teacher[], int len)
//{
//	for (int i = 0; i < 3; i++)
//	{
//
//		cout << "教师姓名：" << teacher[i].name << endl;
//		cout << "学生信息：" << endl;
//
//		for (int j = 0; j < 5; j++)
//		{
//			cout << "学生姓名：" << teacher[i].student[j].name << endl;
//			cout << "学生成绩：" << teacher[i].student[j].score << endl;
//		}
//	}
//}
//
//int main()
//{
//	//随机数种子
//	srand((unsigned int)time(NULL));
//	//srand是C语言中的随机数种子函数，它与rand()函数一同使用，用来产生随机数。
//	//无符号整数（Unsigned Integer）是一种整数类型，用于存储正整数或零。它与有符号整数类型相似，但有一个重要的区别，即它不允许存储负数。
//	//time(NULL)函数返回当前时间的UTC时间戳，以秒为单位。
//	//记得包含头文件 #include <ctime>
//
//	//给学生和老师赋值
//	teacher teacher[3];
//	int len = sizeof(teacher) / sizeof(teacher[0]);
//	assign(teacher,len);
//	
//	//打印所有老师和学生的信息
//	printInfo(teacher, len);
//
//	system("pause");
//	return 0;
//}