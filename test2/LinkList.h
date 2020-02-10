#pragma once
#ifndef LINKLIST_H
#define LINKLIST_H

//����ڵ�
struct LinkNode {
	void* data;//ָ���κ����͵�����
    LinkNode* next;//ָ����һ�ڵ��ָ��
};

//����ṹ��
struct LinkList
{
	LinkNode* head;//ͷ�ڵ�
	int size;//ָ��������Ԫ�صĸ���
	//��Ҫ�����𣿲��ã���Ϊ����������һ���ڴ�ռ�
};

//��ӡ�ص�����ָ��
typedef void(*PRINTLINKNODE)(void *);

//�����ܺ���

//��ʼ������
LinkList* Init_LinkList();
//��ָ��λ�ò���,vlaue�Ǵ�����ֵ
void Insert_LinkList(LinkList* list,int pos,void* value);
//��ָ��λ��ɾ��,
void RemoveByPos_LinkList(LinkList* list, int pos);
//����
int Find_LinkList(LinkList* list, void* data);
//���������
int Size_LinkList(LinkList* list);
//���ص�һ���ڵ�
void* Front_LinkList(LinkList* list);
//��ӡ����ڵ�
void Print_LinkList(LinkList* list, PRINTLINKNODE print);
//�ͷ������ڴ�
void FreeSpace_LinkList(LinkList* list);
#endif