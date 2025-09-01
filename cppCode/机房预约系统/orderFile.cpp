#include"orderFile.h"

//���캯��
OrderFile::OrderFile()
{
	ifstream ifs;
	ifs.open(ORDER_FILE, ios::in);

	string date;		//����
	string interval;	//ʱ���
	string stuId;		//ѧ��
	string stuName;		//����
	string roomId;		//�������
	string status;		//״̬

	m_Size = 0; //��ʼ��ԤԼ��¼����

	if (!ifs.is_open())
	{
		//�ļ�������
		m_Size = 0;
		return;
	}
	while (ifs >> date && ifs >> interval && ifs >> stuId
		&& ifs >> stuName && ifs >> roomId && ifs >> status)
	{
		string key; //��
		string value; //ֵ
		map<string, string> m; //�洢һ��ԤԼ��¼�ļ�ֵ����Ϣ

		int pos = date.find(":");
		if (pos != -1)
		{
			key = date.substr(0, pos);
			value = date.substr(pos + 1, date.size() - pos - 1);
			m.insert(make_pair(key, value));
		}

		pos = interval.find(":");
		if (pos != -1)
		{
			key = interval.substr(0, pos);
			value = interval.substr(pos + 1, interval.size() - pos - 1);
			m.insert(make_pair(key, value));
		}

		pos = stuId.find(":");
		if (pos != -1)
		{
			key = stuId.substr(0, pos);
			value = stuId.substr(pos + 1, stuId.size() - pos - 1);
			m.insert(make_pair(key, value));
		}

		pos = stuName.find(":");
		if (pos != -1)
		{
			key = stuName.substr(0, pos);
			value = stuName.substr(pos + 1, stuName.size() - pos - 1);
			m.insert(make_pair(key, value));
		}

		pos = roomId.find(":");
		if (pos != -1)
		{
			key = roomId.substr(0, pos);
			value = roomId.substr(pos + 1, roomId.size() - pos - 1);
			m.insert(make_pair(key, value));
		}

		pos = status.find(":");
		if (pos != -1)
		{
			key = status.substr(0, pos);
			value = status.substr(pos + 1, status.size() - pos - 1);
			m.insert(make_pair(key, value));
		}
		//��һ��ԤԼ��¼�ļ�ֵ����Ϣ�����뵽ԤԼ��Ϣ������
		m_OrderData.insert(make_pair(m_Size, m));
		m_Size++;

		//���Դ���:��ʾ��ȡ����ԤԼ��¼
		//for (map<string, string>::iterator it = m.begin(); it != m.end(); it++) {
		//	cout << it->first << ":" << it->second << " ";
		//}
	}
	ifs.close();
}

//����ԤԼ��Ϣ
void OrderFile::updateOrder()
{
	if (m_Size == 0)
	{
		//û��ԤԼ��¼
		return;
	}
	ofstream ofs;
	ofs.open(ORDER_FILE, ios::out | ios::trunc); //�������ʽ���ļ�
	if (!ofs.is_open())
	{
		cout << "�ļ������ڻ��ʧ�ܣ�" << endl;
		return;
	}
	//�����������������е�ԤԼ��Ϣд�뵽�ļ���
	for (int i = 0; i < m_Size; i++)
	{
		ofs << "date:" << m_OrderData[i]["date"] << " ";
		ofs << "interval:" << m_OrderData[i]["interval"] << " ";
		ofs << "sutId:" << m_OrderData[i]["sutId"] << " ";
		ofs << "stuName:" << m_OrderData[i]["stuName"] << " ";
		ofs << "roomId:" << m_OrderData[i]["roomId"] << " ";
		ofs << "status:" << m_OrderData[i]["status"] << endl;
	}
	ofs.close();
}