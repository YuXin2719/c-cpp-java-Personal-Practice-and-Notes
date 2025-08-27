#pragma once
#include<iostream>
using namespace std;
#include<vector>
#include<map>
#include<string>
#include"speaker.h"
#include<algorithm>
#include<deque>
#include<numeric>
#include<fstream>
#include<ctime>

//����ݽ�������
class SpeechManager
{
public:
	SpeechManager(); //���캯��
	~SpeechManager(); //��������
	void showMenu(); //��ʾ�˵�
	void exitSpeech(); //�˳���������
	void initSpeech(); //��ʼ������
	void startSpeech(); //��ʼ����
	void speechDraw(); //��ǩ
	void speechContest(); //����
	void showScore(); //��ʾ�������
	void saveScore(); //������
	void loadRecord(); //��ȡ��¼
	void showRecord(); //��ʾ�����¼
	void clearRecord(); //��ռ�¼

	//����ѡ������ 12��
	vector<int> v1;
	//��һ�ֽ������� 6��
	vector<int> v2;
	//ʤ��ǰ�������� 3��
	vector<int> vVictory;
	//��ű�� �Լ���Ӧ�� ����ѡ�� ����
	map<int, Speaker> m_Speaker;
	//��ű�������
	int m_Index;
	//�ļ�Ϊ�յı�־
	bool fileIsEmpty;
	//�����¼
	map<int, vector<string>> m_Record;
};