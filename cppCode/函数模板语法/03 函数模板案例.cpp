//#include<iostream>
//using namespace std;
//
////ʵ��ͨ�ö������������ĺ���
////���� �Ӵ�С
////�㷨 ѡ������
////���� char����,int����
//
////�����㷨,ѡ������
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
////�ṩ��ӡ�����ģ��
//template<typename T>
//void printArray(T arr[], int len) {
//	for (int i = 0; i < len; i++) {
//		cout << arr[i] << " ";
//	}
//	cout << endl;
//}
//
//void test01() {
//	//����char����
//	char arr[] = "badcfe";
//	int len = sizeof(arr) / sizeof(arr[0]) - 1; // -1����Ϊֻ��������������ַ����������'\0'�����\0����Ҫ����,{'a','b','c'}����������ַ���û��'\0'
//	sortArray(arr, len);
//	printArray(arr, len);
//
//	//����int����
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