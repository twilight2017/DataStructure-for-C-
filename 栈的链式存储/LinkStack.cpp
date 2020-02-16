#include"LinkStack.h"
#include<iostream>

//初始化函数
LinkStack* Init_Stack() {
	LinkStack* stack = (LinkStack*)malloc(sizeof(LinkStack));//开辟内存空间
	stack->head.next = NULL;//防止出现野指针
	stack->size = 0;
	return stack;//返回刚分配的内存空间
}
//入栈
void Push_LinkStack(LinkStack* stack, LinkNode* data) {
	if (stack == NULL) {
		return;
	}
	if (data == NULL) {
		return;
	}
	data->next = stack->head.next;//链入栈顶
	stack->head.next = data;
	stack->size++;

}
//出栈
void Pop_LinkStack(LinkStack* stack) {
	if (stack == NULL) {
		return;
	}
	//定义一个有效结点便于操作
	LinkNode* pNext = stack->head.next;
	stack->head.next = pNext->next;
	stack->size--;
}
//返回栈顶元素
LinkNode* Top_LinkStack(LinkStack* stack) {
	if (stack == NULL) {
		return NULL;
	}
	if (stack->size == 0) {
		return NULL;
	}
	return stack->head.next;
}
//返回栈中元素的个数
int Size_LinkStack(LinkStack* stack) {
	if (stack == NULL) {
		return -1;//栈不存在，返回无效值
	}
	return stack->size;
}
//清空栈
void Clear_LinkStack(LinkStack* stack) {
	if (stack == NULL) {
		return;
	}
	stack->head.next = NULL;//把头节点单独拿出来
	stack->size = 0;
}
//销毁栈
void FreeSpace_LinkStack(LinkStack* stack) {
	if (stack == NULL) {
		return;
	}
	free(stack);
}