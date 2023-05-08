//#include <iostream>
//#include <string>
//
//using namespace std;
//
//struct hero
//{
//	string name;//名字
//	int age;//年龄
//	string sex;//性别
//};
//
////冒泡排序算法
//void bubbleSort(hero revenger[], int len)
//{
//	for (int i = 0; i < len - 1; i++)
//	{
//		for (int j = 0; j < len - 1; j++)
//		{
//			if (revenger[j].age > revenger[j + 1].age)
//			{
//				hero temp = revenger[j];
//				revenger[j] = revenger[j + 1];
//				revenger[j + 1] = temp;
//			}
//		}
//	}
//}
//
//int main()
//{
//
//	/*
//	设计一个英雄的结构体，包括成员姓名，年龄，性别；创建结构体数组，数组中存放5名英雄。
//
//	通过冒泡排序的算法，将数组中的英雄按照年龄进行升序排序，最终打印排序后的结果。
//	*/
//
//	hero revenger[5] =
//	{
//		{"张三",18,"男"},
//		{"李四",19,"女"},
//		{"王五",20,"男"},
//		{"寅子",40,"男"},
//		{"表哥",23,"男"}
//	};
//	int len = sizeof(revenger) / sizeof(revenger[0]);
//
//	//冒泡排序
//	bubbleSort(revenger, len);
//
//	//打印排序后的结果
//
//	cout << "排序之后的结果为：" << endl << endl;
//
//	for (int i = 0; i < len; i++)
//	{
//		cout << "英雄名字：" << revenger[i].name << endl;
//		cout << "英雄年龄：" << revenger[i].age << endl;
//		cout << "英雄性别：" << revenger[i].sex << endl;
//		cout << endl;
//	}
//
//	system("pause");
//	return 0;
//}