#ifndef DYNAMIC_ARRAY_H
#define DYNAMIC_ARRAY_H

//��Ҫ��̬�����ڴ棬��������ݵ����ݷ��ڶ���
//��ǰ�ڴ治���������ڴ桢�������ݡ��ͷ��ڴ�
//������һ��ϴ���ڴ�ռ�capacity��ָ����ǰ�������ڴ�ռ�Ĵ�С
//size:��¼�����о����Ԫ�ظ���

#include<stdlib.h>
#include<stdio.h>
#include<string>

//���嶯̬����Ľṹ��
 struct MyArray {
	int *pAddr;//��ʾ���������ݵĵ�ַ
	int size;//��ʾ��ǰ������Ԫ�صĸ���
	int capacity;//��ʾ��ǰ�����Ĵ�С
 };

//дһϵ�ж��йؽṹ������ĺ���
//��ʼ��
MyArray * My_Array_Init();
//����
void Push_Back_Array(MyArray * arr, int value);
//����λ��ɾ��
void RemoveByPos_Array(MyArray* arr, int pos);
//����ֵɾ��
void RemoveByValue_Array(MyArray* arr, int value);
//�ͷŶ�̬������ڴ�
void FreeSpace_Array(MyArray* arr);
//����
int Find_Array(MyArray* arr, int value);
//��ӡ
void Print_Array(MyArray* arr);
//�������
void Clear_Array(MyArray* arr);
//�������
int Capacity_Array(MyArray* arr);
//��õ�ǰԪ�ظ���
int Size_Array(MyArray* arr);
//�����������ĳ��λ�õ�Ԫ��
int At_Array(MyArray* arr, int pos);

#endif