#ifndef DYNAMIC_ARRAY_H
#define DYNAMIC_ARRAY_H

//需要动态增长内存，将存放数据的内容放在堆上
//当前内存不够，申请内存、拷贝数据、释放内存
//先申请一块较大的内存空间capacity，指代当前错申请内存空间的大小
//size:记录数组中具体的元素个数

#include<stdlib.h>
#include<stdio.h>
#include<string>

//定义动态数组的结构体
 struct MyArray {
	int *pAddr;//表示具体存放数据的地址
	int size;//表示当前数组中元素的个数
	int capacity;//表示当前容器的大小
 };

//写一系列对有关结构体操作的函数
//初始化
MyArray * My_Array_Init();
//插入
void Push_Back_Array(MyArray * arr, int value);
//根据位置删除
void RemoveByPos_Array(MyArray* arr, int pos);
//根据值删除
void RemoveByValue_Array(MyArray* arr, int value);
//释放动态数组的内存
void FreeSpace_Array(MyArray* arr);
//查找
int Find_Array(MyArray* arr, int value);
//打印
void Print_Array(MyArray* arr);
//清空数组
void Clear_Array(MyArray* arr);
//获得容量
int Capacity_Array(MyArray* arr);
//获得当前元素个数
int Size_Array(MyArray* arr);
//根据索引获得某个位置的元素
int At_Array(MyArray* arr, int pos);

#endif