#include"SeqQueue.h"
#include<iostream>

//定义对结构体的操作
//初始化
SeqQueue* Init_SeqQueue() {
	SeqQueue* queue = (SeqQueue*)malloc(sizeof(SeqQueue));
	for (int i = 0; i < MAX_SIZE; i++) {
		queue->data[i] = NULL;//进行初始化
	}
	queue->size = 0;
	return queue;
}
//入队
void Push_SeqQueue(SeqQueue* queue, void* data) {
	//定义数组的最左端为队头
	if (queue == NULL) {
		return;
	}
	if (data == NULL) {
		return;
	}
	if (queue->size == MAX_SIZE) {
		return;
	}
	//插入时直接插入队尾
	queue->data[queue->size] = data;
	queue->size++;

}
//返回队头元素
void* Front_SeqQueue(SeqQueue* queue) {
	if (queue == NULL) {
		return NULL;
	}
	if (queue->size == 0) {
		return NULL;
	}
	return queue->data[0];
}
//出队
void Pop_SeqQueue(SeqQueue* queue) {
	if (queue == NULL) {
		return;
	}
	if (queue->size == 0) {
		return;
	}
	//从队头出队，涉及元素移动
	for (int i = 0; i < queue->size - 1; i++) {
		queue->data[i] = queue->data[i + 1];
	}
	queue->size--;//不要忘记修改队列中元素的个数
}
//返回队尾的元素
void* Back_SeqQueue(SeqQueue* queue) {
	if (queue == NULL) {
		return NULL;
	}
	if (queue->size == 0) {
		return NULL;
	}
	return queue->data[queue->size-1];
}
//返回大小
int Size_SeqQueue(SeqQueue* queue) {
	if (queue == NULL) {
		return -1;//队列不存在，返回无效参数
	}
	return queue->size;
}
//销毁队列
void FreeSpace_SeqQueue(SeqQueue* queue) {
	if (queue == NULL) {
		return;
	}
	free(queue);
}
//清空队列
void Clear_SeqQueue(SeqQueue* queue) {
	if (queue == NULL) {
		return;
	}
	for (int i = 0; i < queue->size; i++) {
		queue->data[i] = NULL;
	}
	queue->size = 0;//修改队列大小即可
}