#include<stdio.h>
#include<stdlib.h>
#include<malloc.h>
typedef int ElemType;

// ϡ��������Ԫ��˳���洢��ʾ 

#define MAXSIZE 100 // ����Ԫ���������ֵ 
typedef struct
{
	int i, j;        // ���±�,���±� 
	ElemType e; // ����Ԫ��ֵ 
}Triple;

typedef struct
{
	Triple data[MAXSIZE + 1]; // ����Ԫ��Ԫ���,data[0]δ�� 
	int mu, nu, tu;                   // ����������������ͷ���Ԫ���� 
}TSMatrix;

//�ӿڶ���
int CreateSMatrix(TSMatrix *M);
void DestroySMatrix(TSMatrix *M);
void PrintSMatrix(TSMatrix M);
int CopySMatrix(TSMatrix M, TSMatrix *T);
int comp(int c1, int c2);
int AddSMatrix(TSMatrix M, TSMatrix N, TSMatrix *Q);
int SubtSMatrix(TSMatrix M, TSMatrix N, TSMatrix *Q);
int MultSMatrix(TSMatrix M, TSMatrix N, TSMatrix *Q);
int TransposeSMatrix(TSMatrix M, TSMatrix *T);
int FastTransposeSMatrix(TSMatrix M, TSMatrix *T);

