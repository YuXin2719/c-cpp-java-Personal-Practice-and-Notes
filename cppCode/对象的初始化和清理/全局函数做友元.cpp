//#include <iostream>
//using namespace std;
//
//class Building
//{
//	//goodGayȫ�ֺ����� Building�����ѣ����Է���Building��˽�г�Ա
//	friend void goodGay(Building* building);
//
//public:
//	string m_SittingRoom; //����
//
//	Building()
//	{
//		m_SittingRoom = "����";
//		m_BedRoom = "����";
//	}
//
//private:
//	string m_BedRoom; //����
//};
//
////ȫ�ֺ���
//void goodGay(Building *building)
//{
//	cout << "�û���ȫ�ֺ��� ���ڷ��ʣ�" << building->m_SittingRoom << endl;
//
//	cout << "�û���ȫ�ֺ��� ���ڷ��ʣ�" << building->m_BedRoom << endl;
//}
//
//int main()
//{
//
//	Building building;
//	goodGay(&building);
//
//	system("pause");
//	return 0;
//}