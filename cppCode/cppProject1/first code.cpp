#include <iostream>
#include <string>

using namespace std;

int main()
{

/*
要求：
	- 提示用户输入一个高考考试分数，根据分数做如下判断
	- 分数如果大于600分视为考上一本，大于500分考上二本，大于400分考上三本，其余视为未考上本科
	- 在一本分数中，如果大于700分，考入北大，大于650，考入清华，大于600，考入人大
*/

	//输入分数
	int fen = 0;
	cout << "请输入你的分数：" << endl;
	cin >> fen;
	cout << "你输入的分数为 " << fen << endl;

	//判断一本600
	if (fen > 600)
	{
		cout << "恭喜你可以考上一本" << endl;

		//判断北大
		if (fen > 700)
		{
			cout << "恭喜你可以考上北大！" << endl;
		}

		//判断清华
		else if (fen > 650)
		{
			cout << "恭喜你可以考上清华！" << endl;
		}

		//判断人大
		else if (fen > 600)
		{
			cout << "恭喜你可以考上人大！" << endl;
		}
	}

	//判断二本500
	else if (fen > 500)
	{
		cout << "恭喜你可以考上二本" << endl;
	}

	//判断三本400
	else if (fen > 400)
	{
		cout << "恭喜你可以考上二本" << endl;
	}
	else
	{
		cout << "你啥jb也没考上兄弟" << endl;
	}

	system("pause");

	return 0;
}