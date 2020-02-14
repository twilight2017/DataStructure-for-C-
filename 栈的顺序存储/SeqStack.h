#ifndef SEQSTACK_H
#define SEQSTACK_H

#include<stdlib.h>
#include<stdio.h>

//数组模拟栈的顺序存储
#define MAX_SIZE 1024
#define SEQSTACK_TRUE 1
#define SEQSTACKFALSE 0

struct SeqStack
{
	void* data[MAX_SIZE];
	int size;//栈的大小
};

//初始化栈
SeqStack* Init_Stack();
//入栈
void Push_Seq_Stack(SeqStack* stack, void* data);
//出栈
void Pop_Seq_Stack(SeqStack* stack);
//返回栈顶元素
void* Top_Seq_Stack(SeqStack* stack);
//判断是否为空
int IsEmpty(SeqStack* stack);
//返回栈中元素的个数
int Size_Stack(SeqStack* stack);
//销毁栈结构体
void Free_Space_SeqStack(SeqStack* stack);
//清空栈
void Clear_SeqStack(SeqStack* stack);

#endif
