#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<iostream>


#include"DynamicArray.h"
void test01() {
	//��ʼ��һ����̬����
	MyArray* myArray = My_Array_Init();
	//��ӡ����
	printf("����������%d", Capacity_Array(myArray));
	printf("�����С��%d", Size_Array(myArray));
	//����Ԫ��
	for (int i = 0; i < 30; i++) {
		Push_Back_Array(myArray, i);
	}
	printf("����������%d", Capacity_Array(myArray));
	printf("�����С��%d", Size_Array(myArray));
	//��ӡ
	Print_Array(myArray);
	//ɾ��
	RemoveByPos_Array(myArray, 0);
	RemoveByValue_Array(myArray, 27);
	printf("\n");
	Print_Array(myArray);
	//����
	int pos = Find_Array(myArray, 5);
	printf("5���ҵ�pos:%d %d\n", pos,At_Array(myArray,pos));
	//����
	FreeSpace_Array(myArray);
}
int main()
{
	test01();

	system("pause");
	return 0;
}