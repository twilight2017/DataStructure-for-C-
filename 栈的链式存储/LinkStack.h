#ifndef LINKSTACK_H
#define LINKSTACK_H

#include<stdlib.h>
#include<stdio.h>

//链式栈的结点
struct LinkNode {
	LinkNode* next;//实现链式栈的next指针
};
//链式栈
struct LinkStack{
	LinkNode head;//头节点,本身不保存任何信息，只是为了便于操作
	int size;
};
//初始化函数
LinkStack* Init_Stack();
//入栈
void Push_LinkStack(LinkStack* stack, LinkNode* data);
//出栈
void Pop_LinkStack(LinkStack* stack);
//返回栈顶元素
LinkNode* Top_LinkStack(LinkStack* stack);
//返回栈中元素的个数
int Size_LinkStack(LinkStack* stack);
//清空栈
void Clear_LinkStack(LinkStack* stack);
//销毁栈
void FreeSpace_LinkStack(LinkStack* stack);
#endif