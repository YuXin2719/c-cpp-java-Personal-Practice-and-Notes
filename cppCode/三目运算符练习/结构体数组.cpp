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
		{"����",18,100},
		{"����",19,90},
		{"����",18,80}
	};

	system("pause");
	return 0;
}