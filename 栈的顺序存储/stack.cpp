/*ջ��˳��洢�Ļ������
    ����һ���ַ�������ڴ浥Ԫ���δ����ջ����ջ�׵�����Ԫ��*/
//���ʣ�������ģ��ջ

#include "SeqStack.h"
#include<iostream>


//��������

//��ʼ��ջ
SeqStack* Init_Stack() {
	SeqStack* stack = (SeqStack*)malloc(sizeof(SeqStack));//�����ڴ�ռ�
	for (int i = 0; i < MAX_SIZE; i++) {
		stack->data[i] = NULL;
	}
	stack->size = 0;//��ʼ��ջ��Ԫ�صĸ���
	return stack;//����ָ����һƬ�ڴ�ռ��ָ��stack
}
//��ջ
void Push_Seq_Stack(SeqStack* stack, void* data) {
	if (stack == NULL) {
		return;//ջ�����ڣ�����
	}
	if (stack->size==MAX_SIZE) {
		return;//ջ�����޷���ջ
	}
	if (data == NULL) {
		return;//�޲���ֵ������
	}
	//��ʼ������ջ����
	stack->data[stack->size] = data;
	stack->size++;//�޸�ջ�е�Ԫ�ظ���
}
//��ջ
void Pop_Seq_Stack(SeqStack* stack) {
	if (stack == NULL) {
		return;//ջ�����ڣ�����
	}
	if (stack->size == 0) {
		return;//ջ�в������κ�Ԫ�أ�ֱ�ӷ���
	}
	stack->data[stack->size--] = NULL;
}
//����ջ��Ԫ��
void* Top_Seq_Stack(SeqStack* stack) {
	if (stack == NULL) {
		return NULL;//ջ�����ڣ�����
	}
	if (stack->size == 0) {
		return NULL;//ջ�в������κ�Ԫ�أ����ؿ�ֵ
	}
	int top = stack->size - 1;
	return stack->data[top];
}
//�ж��Ƿ�Ϊ��
int IsEmpty(SeqStack* stack) {
	if (stack == NULL) {
		return -1;//ջ�����ڣ�������Чֵ
	}
	if (stack->size == 0) {
		return SEQSTACK_TRUE;
	}
	return SEQSTACKFALSE;
}
//����ջ��Ԫ�صĸ���
int Size_Stack(SeqStack* stack) {
	if (stack == NULL) {
		return -1;//ջ�����ڣ�������Чֵ
	}
	return stack->size;
}
//����ջ�ṹ��
void Free_Space_SeqStack(SeqStack* stack) {
	if (stack == NULL) {
		return;//ջ�����ڣ�����
	}
	free(stack);//�ͷ��ڴ�ռ�
}
//���ջ
void Clear_SeqStack(SeqStack* stack) {
	if (stack == NULL) {
		return;//ջ�����ڣ�����
	}
	for (int i = 0; i < stack->size; i++) {
		stack->data[i] == NULL;
	}
	stack->size = 0;
}