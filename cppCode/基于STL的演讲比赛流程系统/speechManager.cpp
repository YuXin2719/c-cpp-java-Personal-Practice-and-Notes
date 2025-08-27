#include"speechManager.h"

//���캯��
SpeechManager::SpeechManager()
{
	//��ʼ������
	initSpeech();

	//��ȡ�����¼
	loadRecord();
}

//��������
SpeechManager::~SpeechManager()
{

}

//չʾ�˵�
void SpeechManager::showMenu()
{
	cout << "*************************" << endl;
	cout << "*****1.��ʼ�ݽ�����******" << endl;
	cout << "*****2.�鿴�����¼******" << endl;
	cout << "*****3.��ձ�����¼******" << endl;
	cout << "*****0.�˳���������******" << endl;
	cout << "*************************" << endl;
	cout << endl;
}

//�˳���������
void SpeechManager::exitSpeech()
{
	cout << "�˳��������򣬻�ӭ�´�ʹ�ã�" << endl;
	system("pause");
	//ע��exit(0)�ᵼ��������������ִ��ֱ���˳�������Ǻ�return 0�Ĺؼ�����
	exit(0);
}

//��ʼ������
void SpeechManager::initSpeech()
{
	//��ʼ������ѡ��
	//��ʼ������
	v1.clear();
	v2.clear();
	vVictory.clear();
	m_Speaker.clear();
	m_Record.clear();
	//���
	int index = 1001;
	//���ƺ�׺����
	string nameSeed = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";
	//��ʼ��12��ѡ��
	for (int i = 0; i < 12; i++)
	{
		//����ѡ�ֶ���
		Speaker sp;
		//���ֱ��ʹ��"ѡ��" + nameSeed[i]��"ѡ��"��һ�� const char[]�����˻�Ϊ const char*��
		//�ͱ����const char* + charʵ������ָ���������������ַ���ƴ��
		//����һ������ʹ����string�Ĺ��캯��
		//��������ʹ���ַ�����������׺��C++14�����ϣ�
		//sp.m_Name = "ѡ��"s + nameSeed[i];
		sp.m_Name = string("ѡ��") + nameSeed[i];
		//���
		sp.m_Score[0] = 0;
		sp.m_Score[1] = 0;
		//��������
		m_Speaker.insert(make_pair(index, sp));
		//����v1����
		v1.push_back(index);
		//��ŵ���
		index++;
	}
	//��ʼ����������
	m_Index = 1;
}

//��ʼ����
void SpeechManager::startSpeech()
{
	//���������
	srand((unsigned int)time(NULL));

	//��һ�ֱ���
	//1.��ǩ
	speechDraw();
	//2.����
	speechContest();
	//3.��ʾ�������
	showScore();
	//�ڶ��ֱ���
	m_Index++;
	//1.��ǩ
	speechDraw();
	//2.����
	speechContest();
	//3.��ʾ���ս��
	showScore();
	//4.�������
	saveScore();

	cout << "���������������л���Ĺۿ���" << endl;
	system("pause");
	system("cls");
}

//��ǩ
void SpeechManager::speechDraw() {
	cout << "���ڵ�" << m_Index << "�ֱ�����ǩ�����Ժ�......" << endl;
	cout << "---------------------" << endl;
	cout << "��" << m_Index << "�ֱ�����ǩ������£�" << endl;
	if (m_Index == 1) {
		random_shuffle(v1.begin(), v1.end());
		for (vector<int>::iterator it = v1.begin(); it != v1.end(); it++) {
			cout << *it << " ";
		}
		cout << endl;
	}
	else {
		random_shuffle(v2.begin(), v2.end());
		for (vector<int>::iterator it = v2.begin(); it != v2.end(); it++) {
			cout << *it << " ";
		}
		cout << endl;
	}
	cout << "---------------------" << endl;
	system("pause");
	system("cls");
}

//��ʼ����
void SpeechManager::speechContest() {
	cout << "��" << m_Index << "�ֱ�����ʽ��ʼ��-----------------" << endl;
	//��ʱ����������key����valueѡ�ֱ��
	multimap<double, int, greater<int>> group;
	//��¼��Ա����6��Ϊ1��
	int num = 0;
	//������Ա����
	vector<int> v;
	if (m_Index == 1) {
		v = v1;
	}
	else {
		v = v2;
	}
	//��������ѡ�ֱ��
	for (vector<int>::iterator it = v.begin(); it != v.end(); it++) {
		num++;
		//��ί�������
		deque<double> d;
		for (int i = 0; i < 10; i++) {
			double score = (rand() % 401 + 600) / 10.0;
			//cout << score << " ";
			d.push_back(score);
		}
		//sort����
		sort(d.begin(), d.end(), greater<double>());
		//ȥ����ߺ���ͷ�
		d.pop_back();
		d.pop_front();
		//����ƽ����
		double sum = accumulate(d.begin(), d.end(), 0.0);
		double avg = sum / (double)d.size();

		//��ӡÿ���˵ķ���
		//cout << "��ţ�" << *it << " ������" << m_Speaker[*it].m_Name << " �ɼ���" << avg << endl;

		//����ƽ����
		m_Speaker[*it].m_Score[m_Index - 1] = avg;
		//��ƽ���ֺ�ѡ�ֱ�Ų��뵽multimap��
		group.insert(make_pair(avg, *it));
		if (num % 6 == 0) {
			//չʾ��xxС������
			cout << "��" << m_Index << "�ֵ�" << num / 6 << "С����������" << endl;
			for (multimap<double, int, greater<int>>::iterator it = group.begin(); it != group.end(); it++) {
				cout << "��ţ�" << it->second << " ������" << m_Speaker[it->second].m_Name << " �ɼ���" << it->first << endl;
			}
			int count = 0;
			//ȡǰ3��
			for (multimap<double, int, greater<int>>::iterator it = group.begin(); it != group.end() && count < 3; it++, count++) {
				if (m_Index == 1) {
					v2.push_back(it->second);
				}
				else {
					vVictory.push_back(it->second);
				}
			}
			//�����ʱ����
			group.clear();
		}
	}
	cout << "��" << m_Index << "�ֱ�����ϣ�" << endl;
	system("pause");
}

//��ʾ�������
void SpeechManager::showScore() {
	cout << "------------��" << m_Index << "�ֽ���ѡ����Ϣ���£�-------------" << endl;
	vector<int>v;
	if (m_Index == 1) {
		v = v2;
	}
	else {
		v = vVictory;
	}
	for (vector<int>::iterator it = v.begin(); it != v.end(); it++) {
		cout << "��ţ�" << *it << " ������" << m_Speaker[*it].m_Name << " �ɼ���" << m_Speaker[*it].m_Score[m_Index - 1] << endl;
	}
	cout << endl;
	system("pause");
	system("cls");
	this->showMenu();
}

//�������
void SpeechManager::saveScore() {
	ofstream ofs;
	ofs.open("speech.csv", ios::out | ios::app); //׷�ӵķ�ʽд�ļ�

	//������ʤ����ѡ�ֵ�����д�뵽�ļ���
	for (vector<int>::iterator it = vVictory.begin(); it != vVictory.end(); it++) {
		ofs << *it << "," << m_Speaker[*it].m_Name << "," << m_Speaker[*it].m_Score[1] << ",";
	}
	ofs << endl;

	//�ر��ļ�
	ofs.close();

	cout << "��¼����ɹ���" << endl;

	//�м�¼�ˣ��ļ���Ϊ��
	fileIsEmpty = false;
}

//��ȡ��¼
void SpeechManager::loadRecord() {
	ifstream ifs;
	ifs.open("speech.csv", ios::in);
	if (!ifs.is_open()) {
		fileIsEmpty = true;
		cout << "�ļ������ڣ�" << endl;
		ifs.close();
		return;
	}
	//�ļ����ڣ���������Ϊ��
	char ch;
	ifs >> ch;
	if (ifs.eof()) {
		cout << "�ļ�Ϊ�գ�" << endl;
		fileIsEmpty = true;
		ifs.close();
		return;
	}
	//�ļ���Ϊ��
	fileIsEmpty = false;
	//��ȡ�ĵ����ַ��Ż�ȥ
	ifs.putback(ch);

	vector<string> v; //����9���ַ�������
	string data;
	int index = 0;
	while (ifs >> data) { //ÿ�ζ�ȡһ������
		//cout << data << endl;
		int pos = -1; //�ҵ�����λ��
		int start = 0; //��ʼλ��
		while (1) {
			pos = data.find(",", start);
			if (pos == -1) {
				//û���ҵ������
				break;
			}
			string temp = data.substr(start, pos - start);
			//��ʱ��һ�½�ȡ����ֵ
			//cout << temp << endl;
			v.push_back(temp);
			start = pos + 1;
		}
		m_Record.insert(make_pair(index, v));
		v.clear();
		index++;
	}
	ifs.close();
	//�򵥴�ӡһ�����������Ϣ
	//for (map<int, vector<string>>::iterator it = m_Record.begin(); it != m_Record.end(); it++) {
	//	cout << "��" << it->first << "�������" << endl;
	//	cout << "�ھ���ţ�" << it->second[0] << " ������" << it->second[1] << " �ɼ���" << it->second[2] << endl;
	//	cout << "�Ǿ���ţ�" << it->second[3] << " ������" << it->second[4] << " �ɼ���" << it->second[5] << endl;
	//	cout << "������ţ�" << it->second[6] << " ������" << it->second[7] << " �ɼ���" << it->second[8] << endl;
	//	cout << endl;
	//}
}

//��ʾ�����¼
void SpeechManager::showRecord() {
	if (fileIsEmpty) {
		cout << "�ļ�Ϊ�գ�" << endl;
	}
	else {
		cout << "���������¼���£�" << endl;
		for (int i = 1; i <= m_Record.size(); i++) { //����size��map�Ĵ�С���������¼�ĸ���
			cout << "��" << i << "�������" << endl;
			cout << "�ھ���ţ�" << m_Record[i - 1][0] << " ������" << m_Record[i - 1][1] << " �ɼ���" << m_Record[i - 1][2] << endl;
			cout << "�Ǿ���ţ�" << m_Record[i - 1][3] << " ������" << m_Record[i - 1][4] << " �ɼ���" << m_Record[i - 1][5] << endl;
			cout << "������ţ�" << m_Record[i - 1][6] << " ������" << m_Record[i - 1][7] << " �ɼ���" << m_Record[i - 1][8] << endl;
			cout << endl;
		}
	}
	system("pause");
	system("cls");
}

//��ձ�����¼
void SpeechManager::clearRecord() {
	//ȷ���Ƿ����
	char ch;
	cout << "ȷ���Ƿ���ձ�����¼��(Y/N)" << endl;
	cin >> ch;
	if (ch == 'Y' || ch == 'y') {
		//����ļ�
		ofstream ofs;
		ofs.open("speech.csv", ios::out);
		ofs.close();
		//�������
		m_Record.clear();
		//����ļ�״̬
		fileIsEmpty = true;
		cout << "������¼����գ�" << endl;
	}
	else {
		cout << "������ȡ����" << endl;
	}
	system("pause");
	system("cls");
}