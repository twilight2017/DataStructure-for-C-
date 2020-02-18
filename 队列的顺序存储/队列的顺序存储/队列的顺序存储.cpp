#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include"SeqQueue.h"

//基本数据类型结构体
struct Person {
	char name[64];
	int age;
};

int main()
{
	//1.创建队列
	SeqQueue* queue = Init_SeqQueue();
	//2.创建数据
	Person p1 = { "aaa",10 };
	Person p2 = { "bbb",11 };
	Person p3 = { "ccc",12 };
	Person p4 = { "ddd",13 };
	Person p5 = { "eee",14 };
	//3.将数据插入队列
	Push_SeqQueue(queue, &p1);
	Push_SeqQueue(queue, &p2);
	Push_SeqQueue(queue, &p3);
	Push_SeqQueue(queue, &p4);
	Push_SeqQueue(queue, &p5);
	//输出队尾元素
	Person* back = (Person*)Back_SeqQueue(queue);
	printf("Name:%s Age:%d\n", back->name, back->age);
	//4.输出
	while (Size_SeqQueue(queue)>0)
	{
		//取队头元素
		Person* p=(Person*)Front_SeqQueue(queue);
		printf("Name:%s Age:%d\n", p->name, p->age);
		//从队头弹出元素
		Pop_SeqQueue(queue);
	}
	//销毁队列
	FreeSpace_SeqQueue(queue);
	printf("\n");
	system("pause");
	return 0;
}