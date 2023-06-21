//#include <iostream>
//#include <string>
//
//using namespace std;
//
////1.创建学生数据类型：包括（姓名，年龄，分数）
////自定义数据类型，一些类型集合组成的一个类型
////语法 struct 类型名称 {成员列表}
//struct Student //放属性的
//{
//	//成员列表
//
//	//姓名
//	string name;
//
//	//年龄
//	int age;
//
//	//分数
//	double score;
//}s3; //顺便创建结构体变量
//
////2.通过学生数据类型创建具体的学生
//
////2.1 struct Student s1;
////2.2 struct Student s2 = {...};
////2.3 在定义结构体时顺便创建结构体变量
//
//int main()
//{
//
////2.1 struct Student s1
//	//struct关键字可以省略
//	/*struct*/ Student s1; //s1算是成员
//	//给 s1 属性赋值，通过 . 访问结构体变量中的属性
//	s1.name = "张三";
//	s1.age = 18;
//	s1.score = 100;
//
//	cout << "姓名：" << s1.name << endl;
//	cout << "年龄：" << s1.age << endl;
//	cout << "成绩：" << s1.score << endl;
//
////2.2 struct Student s2 = {...}
////struct可以省略
//	struct Student s2 = { "李四",20,80 };
//	cout << "姓名：" << s2.name << endl;
//	cout << "年龄：" << s2.age << endl;
//	cout << "成绩：" << s2.score << endl;
//
////2.3 在定义结构体时顺便创建结构体变量（创建代码示例在上面）
////一般不用
//	s3.name = "王五";
//	s3.age = 19;
//	s3.score = 90;
//
//	system("pause");
//	return 0;
//}