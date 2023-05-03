#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>
#include <string.h>

//字符串就是一串字符——用双引号括起来的一段字符
//注：字符串的结束标志是一个 \0 的转义字符。在计算字符算长度的时候 \0 是结束标志，不算作字符串内容

int main()
{
	
	"abcdef";

	//字符数组 - 数组是一组相同类型的元素
	//字符串在结尾的位置隐藏了一个\0的字符
	//\0是字符串结束的标志

	char arr[] = "hello";
	char arr1[] = "abc";
	char arr2[] = { 'a','b','c'};
	//打印字符串
	printf("%s\n", arr1);//abc
	printf("%s\n", arr2);//abc烫烫烫烫烫（没结束标志\0）

	//求一下字符串长度
	int len = strlen("abc");//string length
	printf("%d\n", len);
	printf("arr1长度 = %d\n", strlen(arr1));//3
	printf("arr2长度 = %d\n", strlen(arr2));//33-随机值

	return 0;
}