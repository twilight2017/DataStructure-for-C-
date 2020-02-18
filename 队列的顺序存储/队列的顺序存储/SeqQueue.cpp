#include"SeqQueue.h"
#include<iostream>

//����Խṹ��Ĳ���
//��ʼ��
SeqQueue* Init_SeqQueue() {
	SeqQueue* queue = (SeqQueue*)malloc(sizeof(SeqQueue));
	for (int i = 0; i < MAX_SIZE; i++) {
		queue->data[i] = NULL;//���г�ʼ��
	}
	queue->size = 0;
	return queue;
}
//���
void Push_SeqQueue(SeqQueue* queue, void* data) {
	//��������������Ϊ��ͷ
	if (queue == NULL) {
		return;
	}
	if (data == NULL) {
		return;
	}
	if (queue->size == MAX_SIZE) {
		return;
	}
	//����ʱֱ�Ӳ����β
	queue->data[queue->size] = data;
	queue->size++;

}
//���ض�ͷԪ��
void* Front_SeqQueue(SeqQueue* queue) {
	if (queue == NULL) {
		return NULL;
	}
	if (queue->size == 0) {
		return NULL;
	}
	return queue->data[0];
}
//����
void Pop_SeqQueue(SeqQueue* queue) {
	if (queue == NULL) {
		return;
	}
	if (queue->size == 0) {
		return;
	}
	//�Ӷ�ͷ���ӣ��漰Ԫ���ƶ�
	for (int i = 0; i < queue->size - 1; i++) {
		queue->data[i] = queue->data[i + 1];
	}
	queue->size--;//��Ҫ�����޸Ķ�����Ԫ�صĸ���
}
//���ض�β��Ԫ��
void* Back_SeqQueue(SeqQueue* queue) {
	if (queue == NULL) {
		return NULL;
	}
	if (queue->size == 0) {
		return NULL;
	}
	return queue->data[queue->size-1];
}
//���ش�С
int Size_SeqQueue(SeqQueue* queue) {
	if (queue == NULL) {
		return -1;//���в����ڣ�������Ч����
	}
	return queue->size;
}
//���ٶ���
void FreeSpace_SeqQueue(SeqQueue* queue) {
	if (queue == NULL) {
		return;
	}
	free(queue);
}
//��ն���
void Clear_SeqQueue(SeqQueue* queue) {
	if (queue == NULL) {
		return;
	}
	for (int i = 0; i < queue->size; i++) {
		queue->data[i] = NULL;
	}
	queue->size = 0;//�޸Ķ��д�С����
}