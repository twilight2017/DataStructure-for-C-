#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<iostream>


#include"DynamicArray.h"
void test01() {
	//初始化一个动态数组
	MyArray* myArray = My_Array_Init();
	//打印容量
	printf("数组容量：%d", Capacity_Array(myArray));
	printf("数组大小：%d", Size_Array(myArray));
	//插入元素
	for (int i = 0; i < 30; i++) {
		Push_Back_Array(myArray, i);
	}
	printf("数组容量：%d", Capacity_Array(myArray));
	printf("数组大小：%d", Size_Array(myArray));
	//打印
	Print_Array(myArray);
	//删除
	RemoveByPos_Array(myArray, 0);
	RemoveByValue_Array(myArray, 27);
	printf("\n");
	Print_Array(myArray);
	//查找
	int pos = Find_Array(myArray, 5);
	printf("5查找的pos:%d %d\n", pos,At_Array(myArray,pos));
	//销毁
	FreeSpace_Array(myArray);
}
int main()
{
	test01();

	system("pause");
	return 0;
}