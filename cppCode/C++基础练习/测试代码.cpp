#include <iostream>

using namespace std;

int main()
{

	int arr[] = { 1,2,3,4,5 };
	int start = 0;
	int end = (sizeof(arr) / sizeof(arr[0]) - 1);
	while (1) {
		if (end > start) {
			int tmp;
			tmp = arr[end];
			arr[end] = arr[start];
			arr[start] = tmp;
			end -= 1;
			start += 1;
		}
		else {
			break;
		}
	}

	for (int i = 0; i < sizeof(arr) / sizeof(arr[0]); i++) {
		cout << arr[i];
	}

	system("pause");
	return 0;
}