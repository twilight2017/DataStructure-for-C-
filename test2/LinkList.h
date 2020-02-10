#pragma once
#ifndef LINKLIST_H
#define LINKLIST_H

//链表节点
struct LinkNode {
	void* data;//指向任何类型的数据
    LinkNode* next;//指向下一节点的指针
};

//链表结构体
struct LinkList
{
	LinkNode* head;//头节点
	int size;//指明链表中元素的个数
	//需要容量吗？不用，因为无需连续的一段内存空间
};

//打印回调函数指针
typedef void(*PRINTLINKNODE)(void *);

//各功能函数

//初始化链表
LinkList* Init_LinkList();
//在指定位置插入,vlaue是待插入值
void Insert_LinkList(LinkList* list,int pos,void* value);
//在指定位置删除,
void RemoveByPos_LinkList(LinkList* list, int pos);
//查找
int Find_LinkList(LinkList* list, void* data);
//获得链表长度
int Size_LinkList(LinkList* list);
//返回第一个节点
void* Front_LinkList(LinkList* list);
//打印链表节点
void Print_LinkList(LinkList* list, PRINTLINKNODE print);
//释放链表内存
void FreeSpace_LinkList(LinkList* list);
#endif