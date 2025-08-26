#include<iostream>
using namespace std;
#include<vector>
#include<algorithm>

//���ñ����㷨_transform
void test01() {
	vector<int> v;
	for (int i = 0; i < 10; i++) {
		v.push_back(i);
	}
	//����STL�ṩ�ı任�㷨_transform
	vector<int> v2;
	//back_inserter(v2) ������ ��v2������Ϊ������
	//std::back_inserter�ᴴ��һ��������������������ͨ�������������ֵʱ�����Զ����������� push_back()����
	//���㷨�����У��� transform, copy�ȣ������Ŀ�������ǿյĻ��С���㣬�������������Ǿ�û�и�v2���ٿռ�,ֱ��ʹ����ͨ�������ᵼ��δ������Ϊ��back_inserter�����������⡣
	transform(v.begin(), v.end(), back_inserter(v2), [](int val) {
		return val * 2; //�����ڼ仹�������߼�����
		});
	for (auto& it : v2) {
		cout << it << " ";
	}
	cout << endl;
}

int main() {
	test01();

	system("pause");
	return 0;
}