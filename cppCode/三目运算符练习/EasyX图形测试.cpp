//#include <iostream>
//#include <string>
//#include <graphics.h>
//
//using namespace std;
//
//int main()
//{
//	//����һ�����ڣ�ȷ�����ڴ�С��show console ��ʾ����̨
//	initgraph(640,480,SHOWCONSOLE);
//
//	//���ñ������������ز�����
//	//���ñ�����ɫ
//	setbkcolor(YELLOW);
//	cleardevice();//�����������ɫ����
//
//	//�����Σ�Բ
//	setlinestyle(PS_SOLID, 5);//����������ʽ
//	setfillcolor(GREEN);//���������ɫ
//	setlinecolor(BLUE);//����������ɫ
//	circle(50, 50, 50);
//	fillcircle(50, 150, 50);
//	solidcircle(50, 250, 50);
//
//	//����������ɫ
//	settextcolor(BLACK);
//
//	//����������ʽ����С������..
//	settextstyle(20, 0, "����");
//
//	//���ñ���ģʽ transparent-͸��
//	setbkmode(TRANSPARENT);
//
//	//����������ɫ
//	settextcolor(RGB(85, 177, 85));
//
//	//��������
//	outtextxy(50, 50, 'a');//�����ַ�
//
//	outtextxy(60, 50, "��Һ�");//�����ַ���
//
//	//�����־���
//	fillrectangle(200, 50, 500, 100);//���һ�����Σ�����Ϊ ���Ͻ�����+���½�����
//	settextcolor(RGB(30, 30, 30));
//	char arr[] = "������ʾ����";
//
//	int width = textwidth(arr);//������ռ���
//	int height = textheight(arr);//������ռ�߶�
//
//	outtextxy(300 / 2 - width / 2 + 200, 50 / 2 - height / 2 + 50, "������ʾ����");//�����ַ���
//
//
//	//������������Ҳ�����Ӧ�ĺ���
//	//�������ַ������µģ���ô�������������
//	// 
//	//1.���ַ���ǰ��Ӵ�д��L           ����
//	//outtextxy(50, 50, L"��Һ�");
//	// 
//	//2.��TEXT()���ַ���������
//	//outtextxy(50, 50, TEXT("��Һ�"));
//	//
//	//3.��__TEXT()���ַ���������
//	//
//	//ʵ���� TEXT() -> __TEXT() -> L"�ı�"
//	//
//	//4.��������κδ��룬�� ��Ŀ -> ���� -> �������� -> ���� -> �ַ��� -> ��Ϊ���ֽ��ַ���    �Ƽ�ʹ�������
//	int maye = 0;
//	cin >> maye;
//	cout << maye << endl;
//
//	//�رմ���
//	closegraph();
//
//	system("pause");
//	return 0;
//}