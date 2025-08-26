#include"speechManager.h"

//���캯��
SpeechManager::SpeechManager()
{
	//��ʼ������
	initSpeech();
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
	//��һ�ֱ���
	//1.��ǩ
	speechDraw();

	//2.����
	speechContest();

	//3.��ʾ�������

	//�ڶ��ֱ���
	//1.��ǩ

	//2.����

	//3.��ʾ���ս��

	//4.�������
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
		cout << "��ţ�" << *it << " ������" << m_Speaker[*it].m_Name << " �ɼ���" << avg << endl;

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
			//չʾ������Ա
			cout << "��" << m_Index << "�ֵ�" << num / 6 << "С�������Ա��" << endl;
			if (m_Index == 1) {
				for (vector<int>::iterator it = v2.begin(); it != v2.end(); it++) {
					cout << "��ţ�" << *it << " ������" << m_Speaker[*it].m_Name << " �ɼ���" << m_Speaker[*it].m_Score[0] << endl;
				}
			}
			else {
				for (vector<int>::iterator it = vVictory.begin(); it != vVictory.end(); it++) {
					cout << "��ţ�" << *it << " ������" << m_Speaker[*it].m_Name << " �ɼ���" << m_Speaker[*it].m_Score[1] << endl;
				}
			}
			cout << "---------------------" << endl;
		}
	}
	cout << "��" << m_Index << "�ֱ�����ϣ�" << endl;
	system("pause");
}