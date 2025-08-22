#include<iostream>
using namespace std;
#include<map>

//map�����Ĺ���͸�ֵ

void printMap(const map<int, int>& m) {
	//�����auto��C++11����������ƶϹؼ��֣���ʾ�Զ��ƶϱ�������
	//auto������ᱻ�ƶ�Ϊmap<int, int>::const_iterator
	for (auto it = m.begin(); it != m.end(); ++it) {
		cout << "key: " << it->first << ", value: " << it->second << endl;
	}
}

void test01() {
	//1.Ĭ�Ϲ���,���������ֱ��ʾ��ֵ���ͺ�ֵ����
	map<int, int> m1;
	m1.insert(pair<int, int>(1, 10));
	m1.insert(pair<int, int>(2, 20));
	m1.insert(pair<int, int>(3, 30));
	m1.insert(pair<int, int>(4, 40));
	m1.insert(pair<int, int>(5, 50));
	printMap(m1);
	//2.ָ����Χ����
	map<int, int> m2(m1.begin(), m1.end());
	printMap(m2);
	//3.���ƹ���
	map<int, int> m3(m2);
	printMap(m3);
	//4.ָ���ȽϺ�������,less<int>��һ���������󣬱�ʾʹ��С�ںŽ��бȽ�
	map<int, int, less<int>> m4;
	//5.ָ���ȽϺ����ͷ���������,allocator��һ���������������ʾʹ��Ĭ�ϵ��ڴ������
	map<int, int, less<int>, allocator<pair<const int, int>>> m5;
}

int main() {
	test01();

	system("pause");
	return 0;
}