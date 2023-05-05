#include <iostream>
#include <string>

using namespace std;

int main()
{

	//利用嵌套循环实现星图

	//打印一行星图
	for (int i = 0; i < 10; i++)
	{
		for (int i = 0; i < 10; i++)
		{
			cout << "* ";
		}
		cout << endl;
	}

	system("pause");
	return 0;
}