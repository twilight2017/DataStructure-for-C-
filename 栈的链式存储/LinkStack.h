#ifndef LINKSTACK_H
#define LINKSTACK_H

#include<stdlib.h>
#include<stdio.h>

//��ʽջ�Ľ��
struct LinkNode {
	LinkNode* next;//ʵ����ʽջ��nextָ��
};
//��ʽջ
struct LinkStack{
	LinkNode head;//ͷ�ڵ�,���������κ���Ϣ��ֻ��Ϊ�˱��ڲ���
	int size;
};
//��ʼ������
LinkStack* Init_Stack();
//��ջ
void Push_LinkStack(LinkStack* stack, LinkNode* data);
//��ջ
void Pop_LinkStack(LinkStack* stack);
//����ջ��Ԫ��
LinkNode* Top_LinkStack(LinkStack* stack);
//����ջ��Ԫ�صĸ���
int Size_LinkStack(LinkStack* stack);
//���ջ
void Clear_LinkStack(LinkStack* stack);
//����ջ
void FreeSpace_LinkStack(LinkStack* stack);
#endif