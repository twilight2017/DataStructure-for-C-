#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include"LinkList.h"

//自定义数据类型，作为单链表的数据域
struct Person {
	char name[64];
	int age;
	int score;
};
//打印函数
void MyPrint(void* data) {
	Person* p = (Person*)data;
	printf("Name:%s Age:%d Score:%d\n", p->name, p->age, p->score);
}
int main()
{
	//创建一个链表
	LinkList* list = Init_LinkList();
	//创建数据
	Person p1 = { "aaa",10,100 };
	Person p2 = { "bbb",18,98 };
	Person p3 = { "ccc",17,87 };
	Person p4 = { "ddd",20,99 };
	Person p5 = { "eee",12,67 };
	//将创建的数据插入链表
	Insert_LinkList(list, 0, &p1);
	Insert_LinkList(list, 0, &p2);
	Insert_LinkList(list, 0, &p3);
	Insert_LinkList(list, 0, &p4);
	Insert_LinkList(list, 0, &p5);
	//打印
	Print_LinkList(list, MyPrint);
	//删除3号位置：p2
	RemoveByPos_LinkList(list, 3);
	printf("\n");
	Print_LinkList(list, MyPrint);
	//返回第一个节点
	printf("----查找结果---\n");
	Person* ret = (Person*)Front_LinkList(list);
	printf("Name:%s Age:%d Score:%d\n", ret->name, ret->age, ret->score);
	//销毁链表
	FreeSpace_LinkList(list);
	printf("\n");
	system("pause");
	return 0;
}