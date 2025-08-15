//#include<iostream>
//using namespace std;
//
////实现通用对数组进行排序的函数
////规则 从大到小
////算法 选择排序
////测试 char数组,int数组
//
////排序算法,选择排序
//template<typename T>
//void sortArray(T arr[], int len) {
//	for (int i = 0; i < len - 1; i++) {
//		int maxIndex = i;
//		for (int j = i + 1; j < len; j++) {
//			if (arr[j] > arr[maxIndex]) {
//				maxIndex = j;
//			}
//		}
//		if (maxIndex != i) {
//			T temp = arr[i];
//			arr[i] = arr[maxIndex];
//			arr[maxIndex] = temp;
//		}
//	}
//}
//
////提供打印数组的模板
//template<typename T>
//void printArray(T arr[], int len) {
//	for (int i = 0; i < len; i++) {
//		cout << arr[i] << " ";
//	}
//	cout << endl;
//}
//
//void test01() {
//	//测试char数组
//	char arr[] = "badcfe";
//	int len = sizeof(arr) / sizeof(arr[0]) - 1; // -1是因为只有字面量定义的字符串的最后有'\0'，这个\0不需要排序,{'a','b','c'}这样定义的字符串没有'\0'
//	sortArray(arr, len);
//	printArray(arr, len);
//
//	//测试int数组
//	int arr2[] = { 5, 2, 9, 1, 5, 6 };
//	int len2 = sizeof(arr2) / sizeof(arr2[0]);
//	sortArray(arr2, len2);
//	printArray(arr2, len2);
//}
//
//int main() {
//
//	test01();
//
//	system("pause");
//	return 0;
//}