//#include<iostream>
//using namespace std;
//#include<vector>
//#include<algorithm>
//
////���ü����㷨_set_intersection
//void test01() {
//	vector<int>v1;
//	vector<int>v2;
//	vector<int>v3;
//	for (int i = 0; i < 10; i++) {
//		v1.push_back(i);
//		v2.push_back(i + 5);
//	}
//	//v1:0~9
//	//v2:5~14
//	//v3:5~9
//	//ע�⣺ʹ�ü����㷨�����뱣֤������������
//	sort(v1.begin(), v1.end());
//	sort(v2.begin(), v2.end());
//	//��һ����������һ�����ϵĿ�ʼ������
//	//�ڶ�����������һ�����ϵĽ���������
//	//�������������ڶ������ϵĿ�ʼ������
//	//���ĸ��������ڶ������ϵĽ���������
//	//������������洢�����������Ŀ�ʼ������
//	//����back_inserter(v3)��ʾ��v3������β����ʼ��������,�ײ��ǵ��õ�push_back����
//	//set_intersection�ķ���ֵ��һ��������,ָ�����һ��Ԫ��(���һ��ʵ�����õ�Ԫ��,���������С�ܴ�,�������ľ���Ĭ��ֵ)����һ��λ��,�����Ҫʹ���������ֵ,������һ����������������
//	set_intersection(v1.begin(), v1.end(), v2.begin(), v2.end(), back_inserter(v3));
//	for (vector<int>::iterator it = v3.begin(); it != v3.end(); it++) {
//		cout << *it << " ";
//	}
//	cout << endl;
//}
//
//int main() {
//	test01();
//	system("pause");
//	return 0;
//}