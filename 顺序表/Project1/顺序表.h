#include<stdio.h>
#include<stdlib.h>
#include<malloc.h>
#define LIST_INIT_SIZE 100
#define LISTINCREMENT 10
#define TRUE 1
#define FLASE 0
typedef int Elemtype;
typedef int Status;



/*接口定义
Status InitList_Sq(SqList &L,int size,int inc);
void CreateList_Sq(SqList &L);
void print_Sq(SqList &L);
int Search_Sq(SqList L, Elemtype e);
Status DestroyList_Sq(SqList &L);
Status ClearList_Sq(SqList &L);
Status ListEmpty_Sq(SqList L);
int ListLength_Sq(SqList L);
Status GetElem_Sq(SqList L, int i, Elemtype &e);
Status PutElem_Sq(SqList &L, int i, Elemtype e);
Status Append_Sq(SqList &L, Elemtype e);
Status DeleteLast_Sq(SqList &L, Elemtype &e);
*/

