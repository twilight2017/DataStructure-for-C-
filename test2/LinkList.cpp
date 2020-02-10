#include"LinkList.h"
#include<iostream>

//��ʼ������
LinkList* Init_LinkList() {
	LinkList* list = (LinkList *)malloc(sizeof(LinkList));
	list->size = 0;
	//ע�⣬���������ͷ�����Ϊ�˱��ڲ��������������κ�����
	list->head = (LinkNode *)malloc(sizeof(LinkNode));
	list->head->data = NULL;
	list->head->next = NULL;
	return list;
}
//��ָ��λ�ò���,vlaue�Ǵ�����ֵ
void Insert_LinkList(LinkList* list, int pos, void* value) {
	if (list == NULL) {
		return;
	}
	if (value == NULL) {
		NULL;
	}
	//�Ѻõ��жϴ���posԽ��,����β��
	if (pos<0||pos>list->size)
	{
		pos = list->size;
	}
	//�����µĽڵ㣬���ܲ���������
	LinkNode* newNode = (LinkNode*)malloc(sizeof(LinkNode));
	newNode->data = value;
	newNode->next = NULL;

	//�ҵ�posλ�õ�ǰһ���ڵ�
	//����ָ�����
	LinkNode* pCurrent = list->head;
	for (int i = 0; i < pos; i++) {
		pCurrent = pCurrent->next;
	}
	//�½ڵ��������
	newNode->next = pCurrent->next;
	pCurrent->next = newNode;
	list->size++;
}
//��ָ��λ��ɾ��,
void RemoveByPos_LinkList(LinkList* list, int pos) {
	//�����жϲ�������Ч��
	if (list == NULL) {
		return;
	}
	if (pos < 0 || pos >= list->size) {
		return;
	}
	//���Ҵ�ɾ���ڵ��ǰһ���ڵ�
	LinkNode* pCurrent = list->head;
	for (int i = 0; i < pos; i++) {
		pCurrent = pCurrent->next;
	}
	LinkNode* pDel = pCurrent->next;//�����ɾ���ڵ�
	pCurrent->next = pDel->next;
	//�ͷ�ɾ���ڵ������
	free(pDel);
	list->size--;
}
//����
int Find_LinkList(LinkList* list, void* data) {
	if (list == NULL) {
		return -1;
	}
	if (data == NULL) {
		return -1;
	}
	//��������,���Ƚ�������ָ��
	int i = 0;
	LinkNode* pCurrent = list->head->next;
	while (pCurrent != NULL) {
		if (pCurrent->data == data) {
			break;
		}
		i++;
		pCurrent = pCurrent->next;//�ڵ�˳������
	}
	return i;
}
//���������
int Size_LinkList(LinkList* list) {
	return list->size;
}
//���ص�һ���ڵ�
void* Front_LinkList(LinkList* list) {
	return list->head->next->data;
}
//��ӡ����ڵ�
void Print_LinkList(LinkList* list, PRINTLINKNODE print) {
	if (list == NULL) {
		return;
	}
	//���帨��ָ�����
	LinkNode* pCurrent = list->head->next;
	while (pCurrent != NULL) {
		print(pCurrent->data);
		pCurrent = pCurrent->next;
	}
}
//�ͷ������ڴ�
void FreeSpace_LinkList(LinkList* list) {
	if (list == NULL) {
		return;
	}
	//���帨��ָ�����
	LinkNode* pCurrent = list->head;
	while (pCurrent != NULL) {
		//������һ���ڵ�
		LinkNode* pNext = pCurrent->next;
		free(pCurrent);
		pCurrent = pNext;
	}
	//�ͷ������ڴ�
	free(list);
}