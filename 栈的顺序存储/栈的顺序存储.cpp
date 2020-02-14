#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include"SeqStack.h"
struct Person {
	char name[30];
	int age;
};

int main() 
{
	//��ʼ��ջ
	SeqStack* stack = Init_Stack();
	//��������
	Person p1 = { "aaa",10 };
	Person p2 = { "bbb",11 };
	Person p3 = { "ccc",9 };
	Person p4 = { "ddd",15 };
	Person p5 = { "eee",20 };
	//������ջ
	Push_Seq_Stack(stack, &p1);
	Push_Seq_Stack(stack, &p2);
	Push_Seq_Stack(stack, &p3);
	Push_Seq_Stack(stack, &p4);
	Push_Seq_Stack(stack, &p5);
	//���
	while (Size_Stack(stack) > 0) {
		Person* person = (Person*)Top_Seq_Stack(stack);//ǿ������ת��������
		printf("Name:%s Age:%d\n", person->name, person->age);
		//����ջ��Ԫ��
		Pop_Seq_Stack(stack);
	}
	//�ͷ��ڴ�
	Free_Space_SeqStack(stack);
	system("pause");
	return 0;
}