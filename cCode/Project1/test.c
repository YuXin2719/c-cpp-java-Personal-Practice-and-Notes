#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>
#include <string.h>

//�ַ�������һ���ַ�������˫������������һ���ַ�
//ע���ַ����Ľ�����־��һ�� \0 ��ת���ַ����ڼ����ַ��㳤�ȵ�ʱ�� \0 �ǽ�����־���������ַ�������

int main()
{
	
	"abcdef";

	//�ַ����� - ������һ����ͬ���͵�Ԫ��
	//�ַ����ڽ�β��λ��������һ��\0���ַ�
	//\0���ַ��������ı�־

	char arr[] = "hello";
	char arr1[] = "abc";
	char arr2[] = { 'a','b','c'};
	//��ӡ�ַ���
	printf("%s\n", arr1);//abc
	printf("%s\n", arr2);//abc���������̣�û������־\0��

	//��һ���ַ�������
	int len = strlen("abc");//string length
	printf("%d\n", len);
	printf("arr1���� = %d\n", strlen(arr1));//3
	printf("arr2���� = %d\n", strlen(arr2));//33-���ֵ

	return 0;
}