#include <iostream>
#include <string>

using namespace std;

int main()
{

	int a = 0;
	cout << "请输入你的分数：";
	cin >> a;

	if (a > 503) //这里不能有分号
	{
		cout << "你能考上一所一本大学" << endl;
	}
	else
	{
		cout << "你不能考上一本大学" << endl;
	}


	system("pause");

	return 0;
}