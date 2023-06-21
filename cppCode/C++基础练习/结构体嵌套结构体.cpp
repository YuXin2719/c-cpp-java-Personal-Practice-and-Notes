//#include <iostream>
//#include <string>
//
//using namespace std;
//
////学生结构体的定义
//struct student
//{
//	string name;	//学生姓名
//	int age;		//学生年龄
//	int score;		//学生分数
//};
//
////教师结构体的定义
//struct teacher
//{
//	int id;			//职工id
//	string name;	//职工姓名
//	int age;		//职工年龄
//	student stu1;	//子结构体 教的学生
//};
//
//int main()
//{
//
//	teacher t;
//	t.id = 10000;
//	t.name = "老王";
//	t.age = 50;
//	t.stu1.name = "小王";
//	t.stu1.age = 20;
//	t.stu1.score = 60;
//
//	cout << "老师编号：" << t.id << endl;
//	cout << "老师名字：" << t.name << endl;
//	cout << "老师年龄：" << t.age << endl;
//	cout << "老师辅导的学生姓名：" << t.stu1.name << endl;
//	cout << "老师辅导的学生年龄：" << t.stu1.age << endl;
//	cout << "老师辅导的学生分数：" << t.stu1.score << endl;
//
//	system("pause");
//	return 0;
//}