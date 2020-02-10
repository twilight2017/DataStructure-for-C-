#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include"LinkList.h"

//�Զ����������ͣ���Ϊ�������������
struct Person {
	char name[64];
	int age;
	int score;
};
//��ӡ����
void MyPrint(void* data) {
	Person* p = (Person*)data;
	printf("Name:%s Age:%d Score:%d\n", p->name, p->age, p->score);
}
int main()
{
	//����һ������
	LinkList* list = Init_LinkList();
	//��������
	Person p1 = { "aaa",10,100 };
	Person p2 = { "bbb",18,98 };
	Person p3 = { "ccc",17,87 };
	Person p4 = { "ddd",20,99 };
	Person p5 = { "eee",12,67 };
	//�����������ݲ�������
	Insert_LinkList(list, 0, &p1);
	Insert_LinkList(list, 0, &p2);
	Insert_LinkList(list, 0, &p3);
	Insert_LinkList(list, 0, &p4);
	Insert_LinkList(list, 0, &p5);
	//��ӡ
	Print_LinkList(list, MyPrint);
	//ɾ��3��λ�ã�p2
	RemoveByPos_LinkList(list, 3);
	printf("\n");
	Print_LinkList(list, MyPrint);
	//���ص�һ���ڵ�
	printf("----���ҽ��---\n");
	Person* ret = (Person*)Front_LinkList(list);
	printf("Name:%s Age:%d Score:%d\n", ret->name, ret->age, ret->score);
	//��������
	FreeSpace_LinkList(list);
	printf("\n");
	system("pause");
	return 0;
}