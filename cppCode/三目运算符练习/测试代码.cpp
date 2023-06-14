#include <iostream>
#include <stdio.h>
#include <malloc.h>

using namespace std;
/*
1.了解二叉树
*/

//描述单一个体
struct Node
{
	char data;	//数据域字符表示
	struct Node* LChild;
	struct Node* RChild;
};

//傻瓜式存储
//创建节点：创建结构体变量
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
//遍历方式
//递归遍历
void preOrder(struct Node* root)
{
	//根左右
	if (root != NULL)
	{
		printf("%c", root->data);
		preOrder(root->LChild);
		preOrder(root->RChild);
	}
}
void MidOrder(struct Node* root)
{
	//左根右
	if (root != NULL)
	{
		MidOrder(root->LChild);
		printf("%c", root->data);
		MidOrder(root->RChild);
	}
}
void LastOrder(struct Node* root)
{
	//左右根
	if (root != NULL)
	{
		MidOrder(root->LChild);
		MidOrder(root->RChild);
		printf("%c", root->data);
	}
}

//非递归遍历


int main()
{

	//创建
	struct Node* A = createNode('A');
	struct Node* B = createNode('B');
	struct Node* C = createNode('C');
	struct Node* D = createNode('D');
	struct Node* E = createNode('E');
	struct Node* F = createNode('F');
	struct Node* G = createNode('G');

	//连接
	insertNode(A, B, C);
	insertNode(B, D, E);
	insertNode(C, NULL, F);
	insertNode(F, G, NULL);

	system("pause");
	return 0;
}