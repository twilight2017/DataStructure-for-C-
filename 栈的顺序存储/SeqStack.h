#ifndef SEQSTACK_H
#define SEQSTACK_H

#include<stdlib.h>
#include<stdio.h>

//����ģ��ջ��˳��洢
#define MAX_SIZE 1024
#define SEQSTACK_TRUE 1
#define SEQSTACKFALSE 0

struct SeqStack
{
	void* data[MAX_SIZE];
	int size;//ջ�Ĵ�С
};

//��ʼ��ջ
SeqStack* Init_Stack();
//��ջ
void Push_Seq_Stack(SeqStack* stack, void* data);
//��ջ
void Pop_Seq_Stack(SeqStack* stack);
//����ջ��Ԫ��
void* Top_Seq_Stack(SeqStack* stack);
//�ж��Ƿ�Ϊ��
int IsEmpty(SeqStack* stack);
//����ջ��Ԫ�صĸ���
int Size_Stack(SeqStack* stack);
//����ջ�ṹ��
void Free_Space_SeqStack(SeqStack* stack);
//���ջ
void Clear_SeqStack(SeqStack* stack);

#endif
