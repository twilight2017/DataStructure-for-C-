/*栈的顺序存储的基本概念：
    利用一组地址连续的内存单元依次存放自栈顶到栈底的数据元素*/
//本质：用数组模拟栈

#include "SeqStack.h"
#include<iostream>


//函数定义

//初始化栈
SeqStack* Init_Stack() {
	SeqStack* stack = (SeqStack*)malloc(sizeof(SeqStack));//分配内存空间
	for (int i = 0; i < MAX_SIZE; i++) {
		stack->data[i] = NULL;
	}
	stack->size = 0;//初始化栈中元素的个数
	return stack;//返回指向这一片内存空间的指针stack
}
//入栈
void Push_Seq_Stack(SeqStack* stack, void* data) {
	if (stack == NULL) {
		return;//栈不存在，返回
	}
	if (stack->size==MAX_SIZE) {
		return;//栈满，无法入栈
	}
	if (data == NULL) {
		return;//无插入值，返回
	}
	//开始进行入栈操作
	stack->data[stack->size] = data;
	stack->size++;//修改栈中的元素个数
}
//出栈
void Pop_Seq_Stack(SeqStack* stack) {
	if (stack == NULL) {
		return;//栈不存在，返回
	}
	if (stack->size == 0) {
		return;//栈中不包含任何元素，直接返回
	}
	stack->data[stack->size--] = NULL;
}
//返回栈顶元素
void* Top_Seq_Stack(SeqStack* stack) {
	if (stack == NULL) {
		return NULL;//栈不存在，返回
	}
	if (stack->size == 0) {
		return NULL;//栈中不包含任何元素，返回空值
	}
	int top = stack->size - 1;
	return stack->data[top];
}
//判断是否为空
int IsEmpty(SeqStack* stack) {
	if (stack == NULL) {
		return -1;//栈不存在，返回无效值
	}
	if (stack->size == 0) {
		return SEQSTACK_TRUE;
	}
	return SEQSTACKFALSE;
}
//返回栈中元素的个数
int Size_Stack(SeqStack* stack) {
	if (stack == NULL) {
		return -1;//栈不存在，返回无效值
	}
	return stack->size;
}
//销毁栈结构体
void Free_Space_SeqStack(SeqStack* stack) {
	if (stack == NULL) {
		return;//栈不存在，返回
	}
	free(stack);//释放内存空间
}
//清空栈
void Clear_SeqStack(SeqStack* stack) {
	if (stack == NULL) {
		return;//栈不存在，返回
	}
	for (int i = 0; i < stack->size; i++) {
		stack->data[i] == NULL;
	}
	stack->size = 0;
}