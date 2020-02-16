#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include"LinkStack.h"

//�����������ݽṹ
struct Person
{
	LinkNode node;
	char name[64];
	int age;
};
/*�÷����Ե��ڴ�ռ�ʵ��ջ�Ĺ���*/

int main()
{
	//1.����ջ
	LinkStack* stack = Init_Stack();
	//2.��������
	Person p1, p2, p3, p4, p5;
	strcpy(p1.name, "aaa");
	strcpy(p2.name, "bbb");
	strcpy(p3.name, "ccc");
	strcpy(p4.name, "ddd");
	strcpy(p5.name, "eee");

	p1.age = 10;
	p2.age = 11;
	p3.age = 12;
	p4.age = 13;
	p5.age = 14;
	//3.��ջ����
	Push_LinkStack(stack, (LinkNode*)&p1);
	Push_LinkStack(stack, (LinkNode*)&p2);
	Push_LinkStack(stack, (LinkNode*)&p3);
	Push_LinkStack(stack, (LinkNode*)&p4);
	Push_LinkStack(stack, (LinkNode*)&p5);
	//���
	while (Size_LinkStack(stack) > 0) {
		//ȡ��ջ��Ԫ��
		Person* p=(Person*)Top_LinkStack(stack);//��Ҫ����ǿ������ת��
		printf("Name:%s Age:%d\n", p->name, p->age);
		//����ջ��Ԫ��
		Pop_LinkStack(stack);
	}
	//4.����ջ
	FreeSpace_LinkStack(stack);
	printf("\n");
	system("pause");
	return 0;
}