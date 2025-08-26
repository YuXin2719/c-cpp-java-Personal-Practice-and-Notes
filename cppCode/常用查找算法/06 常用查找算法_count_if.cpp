#include<iostream>
using namespace std;
#include<vector>
#include<algorithm>
#include<string>

//常用查找算法_count_if
//统计内置数据类型
void test01() {
	vector<int> v;
	v.push_back(10);
	v.push_back(20);
	v.push_back(30);
	v.push_back(40);
	v.push_back(50);
	v.push_back(60);
	//统计容器中大于30的元素个数
	int num = count_if(v.begin(), v.end(), [](int val) {
		return val > 30;
		});
	cout << "num = " << num << endl;
	//或者通过仿函数统计
	class Greater30 {
	public:
		bool operator()(int val) {
			return val > 30;
		}
	};
	num = count_if(v.begin(), v.end(), Greater30());
	cout << "num = " << num << endl;
}

//统计自定义数据类型
void test02() {
	//创建学生类
	class Student {
	public:
		Student(string name, int age) {
			this->name = name;
			this->age = age;
		}
		string name;
		int age;
	};
	vector<Student> v;
	Student s1("张三", 20);
	Student s2("李四", 30);
	Student s3("王五", 40);
	Student s4("赵六", 50);
	v.push_back(s1);
	v.push_back(s2);
	v.push_back(s3);
	v.push_back(s4);
	//统计年龄大于30的学生人数
	int num = count_if(v.begin(), v.end(), [](Student s) {
		return s.age > 30;
		});
	cout << "num = " << num << endl;
	//或者通过仿函数统计
	class Greater30 {
	public:
		bool operator()(Student s) {
			return s.age > 30;
		}
	};
	num = count_if(v.begin(), v.end(), Greater30());
	cout << "num = " << num << endl;
}

int main() {
	test01();
	test02();
	system("pause");
	return 0;
}