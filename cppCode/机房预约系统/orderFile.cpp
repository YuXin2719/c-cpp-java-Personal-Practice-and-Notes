#include"orderFile.h"

//构造函数
OrderFile::OrderFile()
{
	ifstream ifs;
	ifs.open(ORDER_FILE, ios::in);

	string date;		//日期
	string interval;	//时间段
	string stuId;		//学号
	string stuName;		//姓名
	string roomId;		//机房编号
	string status;		//状态

	m_Size = 0; //初始化预约记录条数

	if (!ifs.is_open())
	{
		//文件不存在
		m_Size = 0;
		return;
	}
	while (ifs >> date && ifs >> interval && ifs >> stuId
		&& ifs >> stuName && ifs >> roomId && ifs >> status)
	{
		string key; //键
		string value; //值
		map<string, string> m; //存储一条预约记录的键值对信息

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
		//将一条预约记录的键值对信息，插入到预约信息容器中
		m_OrderData.insert(make_pair(m_Size, m));
		m_Size++;

		//测试代码:显示读取到的预约记录
		//for (map<string, string>::iterator it = m.begin(); it != m.end(); it++) {
		//	cout << it->first << ":" << it->second << " ";
		//}
	}
	ifs.close();
}

//更新预约信息
void OrderFile::updateOrder()
{
	if (m_Size == 0)
	{
		//没有预约记录
		return;
	}
	ofstream ofs;
	ofs.open(ORDER_FILE, ios::out | ios::trunc); //以输出方式打开文件
	if (!ofs.is_open())
	{
		cout << "文件不存在或打开失败！" << endl;
		return;
	}
	//遍历容器，将容器中的预约信息写入到文件中
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