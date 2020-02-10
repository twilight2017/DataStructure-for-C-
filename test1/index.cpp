#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include"DynamicArray.h"

MyArray* My_Array_Init(){
	//申请内存
	MyArray* myArray = (MyArray*)malloc(sizeof(MyArray));
	/*
	p = (int *)malloc(sizeof(int) * 128);
	分配128个（可根据实际需要替换该数值）整型存储单元
	并将这128个连续的整型存储单元的首地址存储到指针变量p中
	*/
	//初始化
	myArray->size = 0;
	myArray->capacity = 20;
	myArray->pAddr = (int*)malloc(sizeof(int)*myArray->capacity);
	return myArray;
}
//插入
void Push_Back_Array(MyArray * arr, int value) {
	if (arr == NULL) {
		return;
	}
	//判断当前空间是否足够
	if (arr->size == arr->capacity) {
		//1.申请一块更大的内存空间，默认新空间是旧空间的两倍
		int* newSpace = (int *)malloc(sizeof(int)*arr->capacity * 2);
		//2.拷贝数据至新的内存空间
		memcpy(newSpace, arr->pAddr, arr->capacity * sizeof(int));
		//函数会返回指向newSpace的指针
		//3.释放旧空间的内存
		free(arr->pAddr);
		//更新容量
		arr->capacity = arr->capacity * 2;
		arr->pAddr = newSpace;//更改首地址指向
		//4.插入新元素
		arr->pAddr[arr->size] = value;
		arr->size++;
	}
	else {
		arr->pAddr[arr->size] = value;
		arr->size++;
	}
}
//根据位置删除
void RemoveByPos_Array(MyArray* arr, int pos) {
	if (arr == NULL) {
		return;
	}
	//判断位置是否有效
	if (pos < 0 || pos >= arr->size) {
		return;
	}
	for (int i = pos; i < arr->size-1; i++) {
		arr->pAddr[i] = arr->pAddr[i + 1];//覆盖删除
	}
	arr->size--;
}
//根据值删除
void RemoveByValue_Array(MyArray* arr, int value) {
	if (arr == NULL) {
		return;
	}
	//找到该值对应的位置
	int pos = -1;
	for (int i = 0; i < arr->size; i++) {
		if (arr->pAddr[i] == value) {
			pos = i;
			break;
		}
		}
		//调用函数根据位置删除
		RemoveByPos_Array(arr, pos);
	}


//释放动态数组的内存
void FreeSpace_Array(MyArray* arr) {
	if (arr == NULL) {
		return;
	}
	if (arr->pAddr != NULL) {
		free(arr->pAddr);
	}
	free(arr);
}
//查找
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
//打印
void Print_Array(MyArray* arr) {
	if (arr == NULL) {
		return;
	}
	for (int i = 0; i < arr->size; i++) {
		printf("%d", arr->pAddr[i]);

	}
	printf("\n");
}
//清空当前数组
void Clear_Array(MyArray* arr) {
	if (arr == NULL) {
		return;
	}
	arr->size = 0;
}
//获得容量
int Capacity_Array(MyArray* arr) {
	if (arr == NULL) {
		return -1;
	}
	return arr->capacity;
}
//获得当前元素个数
int Size_Array(MyArray* arr) {
	if (arr == NULL) {
		return -1;
	}
	return arr->size;
}
//根据索引获得某个位置的元素
int At_Array(MyArray* arr, int pos) {
	if (arr == NULL) {
		return -1;
	}
	//pAddr指针指向的是该动态数组的首地址位置
	return arr->pAddr[pos];
}
