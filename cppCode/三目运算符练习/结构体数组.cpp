#include <iostream>
#include <string>

using namespace std;

struct student
{
	string name;
	int age;
	double score;
};

int main()
{

	struct student arr[3] =
	{
		{"张三",18,100},
		{"李四",19,90},
		{"王五",18,80}
	};

	system("pause");
	return 0;
}