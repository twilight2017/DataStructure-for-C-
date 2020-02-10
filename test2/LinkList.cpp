#include"LinkList.h"
#include<iostream>

//初始化链表
LinkList* Init_LinkList() {
	LinkList* list = (LinkList *)malloc(sizeof(LinkList));
	list->size = 0;
	//注意，单向链表加头结点是为了便于操作，而不保存任何数据
	list->head = (LinkNode *)malloc(sizeof(LinkNode));
	list->head->data = NULL;
	list->head->next = NULL;
	return list;
}
//在指定位置插入,vlaue是待插入值
void Insert_LinkList(LinkList* list, int pos, void* value) {
	if (list == NULL) {
		return;
	}
	if (value == NULL) {
		NULL;
	}
	//友好的判断处理：pos越界,插入尾部
	if (pos<0||pos>list->size)
	{
		pos = list->size;
	}
	//创建新的节点，才能插入链表中
	LinkNode* newNode = (LinkNode*)malloc(sizeof(LinkNode));
	newNode->data = value;
	newNode->next = NULL;

	//找到pos位置的前一个节点
	//辅助指针变量
	LinkNode* pCurrent = list->head;
	for (int i = 0; i < pos; i++) {
		pCurrent = pCurrent->next;
	}
	//新节点接入链表
	newNode->next = pCurrent->next;
	pCurrent->next = newNode;
	list->size++;
}
//在指定位置删除,
void RemoveByPos_LinkList(LinkList* list, int pos) {
	//首先判断参数的有效性
	if (list == NULL) {
		return;
	}
	if (pos < 0 || pos >= list->size) {
		return;
	}
	//查找待删除节点的前一个节点
	LinkNode* pCurrent = list->head;
	for (int i = 0; i < pos; i++) {
		pCurrent = pCurrent->next;
	}
	LinkNode* pDel = pCurrent->next;//缓存待删除节点
	pCurrent->next = pDel->next;
	//释放删除节点的内容
	free(pDel);
	list->size--;
}
//查找
int Find_LinkList(LinkList* list, void* data) {
	if (list == NULL) {
		return -1;
	}
	if (data == NULL) {
		return -1;
	}
	//遍历查找,首先建立辅助指针
	int i = 0;
	LinkNode* pCurrent = list->head->next;
	while (pCurrent != NULL) {
		if (pCurrent->data == data) {
			break;
		}
		i++;
		pCurrent = pCurrent->next;//节点顺序下移
	}
	return i;
}
//获得链表长度
int Size_LinkList(LinkList* list) {
	return list->size;
}
//返回第一个节点
void* Front_LinkList(LinkList* list) {
	return list->head->next->data;
}
//打印链表节点
void Print_LinkList(LinkList* list, PRINTLINKNODE print) {
	if (list == NULL) {
		return;
	}
	//定义辅助指针变量
	LinkNode* pCurrent = list->head->next;
	while (pCurrent != NULL) {
		print(pCurrent->data);
		pCurrent = pCurrent->next;
	}
}
//释放链表内存
void FreeSpace_LinkList(LinkList* list) {
	if (list == NULL) {
		return;
	}
	//定义辅助指针变量
	LinkNode* pCurrent = list->head;
	while (pCurrent != NULL) {
		//缓存下一个节点
		LinkNode* pNext = pCurrent->next;
		free(pCurrent);
		pCurrent = pNext;
	}
	//释放链表内存
	free(list);
}