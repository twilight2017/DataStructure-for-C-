#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include"DynamicArray.h"

MyArray* My_Array_Init(){
	//�����ڴ�
	MyArray* myArray = (MyArray*)malloc(sizeof(MyArray));
	/*
	p = (int *)malloc(sizeof(int) * 128);
	����128�����ɸ���ʵ����Ҫ�滻����ֵ�����ʹ洢��Ԫ
	������128�����������ʹ洢��Ԫ���׵�ַ�洢��ָ�����p��
	*/
	//��ʼ��
	myArray->size = 0;
	myArray->capacity = 20;
	myArray->pAddr = (int*)malloc(sizeof(int)*myArray->capacity);
	return myArray;
}
//����
void Push_Back_Array(MyArray * arr, int value) {
	if (arr == NULL) {
		return;
	}
	//�жϵ�ǰ�ռ��Ƿ��㹻
	if (arr->size == arr->capacity) {
		//1.����һ�������ڴ�ռ䣬Ĭ���¿ռ��Ǿɿռ������
		int* newSpace = (int *)malloc(sizeof(int)*arr->capacity * 2);
		//2.�����������µ��ڴ�ռ�
		memcpy(newSpace, arr->pAddr, arr->capacity * sizeof(int));
		//�����᷵��ָ��newSpace��ָ��
		//3.�ͷžɿռ���ڴ�
		free(arr->pAddr);
		//��������
		arr->capacity = arr->capacity * 2;
		arr->pAddr = newSpace;//�����׵�ַָ��
		//4.������Ԫ��
		arr->pAddr[arr->size] = value;
		arr->size++;
	}
	else {
		arr->pAddr[arr->size] = value;
		arr->size++;
	}
}
//����λ��ɾ��
void RemoveByPos_Array(MyArray* arr, int pos) {
	if (arr == NULL) {
		return;
	}
	//�ж�λ���Ƿ���Ч
	if (pos < 0 || pos >= arr->size) {
		return;
	}
	for (int i = pos; i < arr->size-1; i++) {
		arr->pAddr[i] = arr->pAddr[i + 1];//����ɾ��
	}
	arr->size--;
}
//����ֵɾ��
void RemoveByValue_Array(MyArray* arr, int value) {
	if (arr == NULL) {
		return;
	}
	//�ҵ���ֵ��Ӧ��λ��
	int pos = -1;
	for (int i = 0; i < arr->size; i++) {
		if (arr->pAddr[i] == value) {
			pos = i;
			break;
		}
		}
		//���ú�������λ��ɾ��
		RemoveByPos_Array(arr, pos);
	}


//�ͷŶ�̬������ڴ�
void FreeSpace_Array(MyArray* arr) {
	if (arr == NULL) {
		return;
	}
	if (arr->pAddr != NULL) {
		free(arr->pAddr);
	}
	free(arr);
}
//����
int Find_Array(MyArray* arr, int value) {
	if (arr == NULL) {
		return -1;
	}
	int pos = -1;
	for (int i = 0; i < arr->size; i++) {
		if (arr->pAddr[i] == value) {
			pos = i;
			break;
		   }
		}
	return pos;
}
//��ӡ
void Print_Array(MyArray* arr) {
	if (arr == NULL) {
		return;
	}
	for (int i = 0; i < arr->size; i++) {
		printf("%d", arr->pAddr[i]);

	}
	printf("\n");
}
//��յ�ǰ����
void Clear_Array(MyArray* arr) {
	if (arr == NULL) {
		return;
	}
	arr->size = 0;
}
//�������
int Capacity_Array(MyArray* arr) {
	if (arr == NULL) {
		return -1;
	}
	return arr->capacity;
}
//��õ�ǰԪ�ظ���
int Size_Array(MyArray* arr) {
	if (arr == NULL) {
		return -1;
	}
	return arr->size;
}
//�����������ĳ��λ�õ�Ԫ��
int At_Array(MyArray* arr, int pos) {
	if (arr == NULL) {
		return -1;
	}
	//pAddrָ��ָ����Ǹö�̬������׵�ַλ��
	return arr->pAddr[pos];
}
