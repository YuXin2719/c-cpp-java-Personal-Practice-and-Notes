#include <string>
#include <iostream>

using namespace std;

int main()
{

	//����ֻС��ABC����ֱ�������ֻС������أ������ж���ֻС�����أ�
	
	//1.������ֻС�������
	int arr[3] = {0};

	int i;
	for (i = 0; i < 3; i++)
	{
		cout << "�������" << i + 1 << "ֻС������أ�" << endl;
		cin >> arr[i];
		cout << "������ĵ�" << i + 1 << "��С�������Ϊ��" << arr[i] << endl;
	}

	//2.�ж���ֻС����ֻ����
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
			cout << "��" << i + 1 << "ֻС�����أ���������Ϊ" << arr[i] << endl;
		}
	}

	system("pause");
	return 0;
}