#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include"SeqQueue.h"

//�����������ͽṹ��
struct Person {
	char name[64];
	int age;
};

int main()
{
	//1.��������
	SeqQueue* queue = Init_SeqQueue();
	//2.��������
	Person p1 = { "aaa",10 };
	Person p2 = { "bbb",11 };
	Person p3 = { "ccc",12 };
	Person p4 = { "ddd",13 };
	Person p5 = { "eee",14 };
	//3.�����ݲ������
	Push_SeqQueue(queue, &p1);
	Push_SeqQueue(queue, &p2);
	Push_SeqQueue(queue, &p3);
	Push_SeqQueue(queue, &p4);
	Push_SeqQueue(queue, &p5);
	//�����βԪ��
	Person* back = (Person*)Back_SeqQueue(queue);
	printf("Name:%s Age:%d\n", back->name, back->age);
	//4.���
	while (Size_SeqQueue(queue)>0)
	{
		//ȡ��ͷԪ��
		Person* p=(Person*)Front_SeqQueue(queue);
		printf("Name:%s Age:%d\n", p->name, p->age);
		//�Ӷ�ͷ����Ԫ��
		Pop_SeqQueue(queue);
	}
	//���ٶ���
	FreeSpace_SeqQueue(queue);
	printf("\n");
	system("pause");
	return 0;
}