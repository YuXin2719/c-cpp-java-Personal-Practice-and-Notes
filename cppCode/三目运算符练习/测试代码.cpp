#include <iostream>
#include <stdio.h>
#include <malloc.h>

using namespace std;
/*
1.�˽������
*/

//������һ����
struct Node
{
	char data;	//�������ַ���ʾ
	struct Node* LChild;
	struct Node* RChild;
};

//ɵ��ʽ�洢
//�����ڵ㣺�����ṹ�����
struct Node* createNode(char data)
{
	struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
	if (newNode == NULL)
		return NULL;
	newNode->data = data;
	newNode->LChild = NULL;
	newNode->RChild = NULL;
	return newNode;
}
void insertNode(struct Node* parent, struct Node* LChild, struct Node* RChild)
{
	parent->LChild = LChild;
	parent->LChild = RChild;

}
//������ʽ
//�ݹ����
void preOrder(struct Node* root)
{
	//������
	if (root != NULL)
	{
		printf("%c", root->data);
		preOrder(root->LChild);
		preOrder(root->RChild);
	}
}
void MidOrder(struct Node* root)
{
	//�����
	if (root != NULL)
	{
		MidOrder(root->LChild);
		printf("%c", root->data);
		MidOrder(root->RChild);
	}
}
void LastOrder(struct Node* root)
{
	//���Ҹ�
	if (root != NULL)
	{
		MidOrder(root->LChild);
		MidOrder(root->RChild);
		printf("%c", root->data);
	}
}

//�ǵݹ����


int main()
{

	//����
	struct Node* A = createNode('A');
	struct Node* B = createNode('B');
	struct Node* C = createNode('C');
	struct Node* D = createNode('D');
	struct Node* E = createNode('E');
	struct Node* F = createNode('F');
	struct Node* G = createNode('G');

	//����
	insertNode(A, B, C);
	insertNode(B, D, E);
	insertNode(C, NULL, F);
	insertNode(F, G, NULL);

	system("pause");
	return 0;
}