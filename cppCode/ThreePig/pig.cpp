#include <string>
#include <iostream>

using namespace std;

int main()
{

	//有三只小猪ABC，请分别输入三只小猪的体重，并且判断哪只小猪最重？
	
	//1.输入三只小猪的体重
	int arr[3] = {0};

	int i;
	for (i = 0; i < 3; i++)
	{
		cout << "请输入第" << i + 1 << "只小猪的体重：" << endl;
		cin >> arr[i];
		cout << "您输入的第" << i + 1 << "个小猪的体重为：" << arr[i] << endl;
	}

	//2.判断三只小猪哪只最重
	int max = arr[0];
	for (i = 1; i < 3; i++)
	{
		if (arr[i] > max)
		{
			max = arr[i];
		}
	}
	for (i = 0; i < 3; i++)
	{
		if (arr[i] == max)
		{
			cout << "第" << i + 1 << "只小猪最重，它的体重为" << arr[i] << endl;
		}
	}

	system("pause");
	return 0;
}