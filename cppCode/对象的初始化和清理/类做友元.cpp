//#include <iostream>
//using namespace std;
//
////������Ԫ
//
//class Building;
//class GoodGay
//{
//public:
//	GoodGay();
//
//	void visit(); //�ιۺ��� ����Building�е�����
//
//	Building* building;
//};
//
//class Building
//{
//	//GoodGay���Ǳ���ĺ����ѣ����Է��ʱ����е�˽�г�Ա
//	friend class GoodGay;
//
//public:
//	string m_SittingRoom; //����
//
//	Building();
//
//private:
//	string m_BedRoom; //����
//};
//
////����д��Ա����
//Building::Building()
//{
//	m_SittingRoom = "����";
//	m_BedRoom = "����";
//}
//
//GoodGay::GoodGay()
//{
//	//����һ�����������
//	building = new Building;
//}
//
//void GoodGay::visit()
//{
//	cout << "�û��������ڷ��ʣ�" << building->m_SittingRoom << endl;
//
//	cout << "�û��������ڷ��ʣ�" << building->m_BedRoom << endl;
//}
//
//void test01()
//{
//	GoodGay gg;
//	gg.visit();
//}
//
//int main()
//{
//
//	test01();
//
//	system("pause");
//	return 0;
//}