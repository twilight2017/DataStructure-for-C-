#ifndef SEQQUEUE_H
#define SEQQUEUE_H

#include<stdlib.h>
#include<stdio.h>
#define MAX_SIZE 1024

//������нṹ��
struct SeqQueue {
	void* data[MAX_SIZE];
	int size;//˳����еĴ�С
};
//����Խṹ��Ĳ���
//��ʼ��
SeqQueue* Init_SeqQueue();
//���
void Push_SeqQueue(SeqQueue* queue,void* data);
//���ض�ͷԪ��
void* Front_SeqQueue(SeqQueue* queue);
//����
void Pop_SeqQueue(SeqQueue* queue);
//���ض�β��Ԫ��
void* Back_SeqQueue(SeqQueue* queue);
//���ش�С
int Size_SeqQueue(SeqQueue* queue);
//���ٶ���
void FreeSpace_SeqQueue(SeqQueue* queue);
//��ն���
void Clear_SeqQueue(SeqQueue* queue);
#endif
