#include "顺序表.h"

//定义顺序表类型
typedef struct {
	Elemtype *elem;
	int length;
	int listsize;
	int increment;
}SqList;

//初始化顺序表
Status InitList_Sq(SqList &L,int size,int inc) {
	
	L.elem = (Elemtype *)malloc(size * sizeof(Elemtype));
	L.length = 0;
	L.listsize = size;
	L.increment = inc;
	return TRUE;
}

//创建顺序表
Status CreateList_Sq(SqList &L) {
	int i;
	printf("请输入你要创建的顺序表元素个数：\n");
	scanf_s("%d", &L.length);
	if (L.length >= L.listsize) {
		L.elem = (Elemtype *)realloc(L.elem, (L.listsize + L.increment) * sizeof(Elemtype));
	}
	if (!L.elem) {
		return FLASE;
	}
	printf("请输入你要创建的顺序表：\n");
	for (i = 0; i<L.length; i++) {
		scanf_s("%d", &L.elem[i]);
	}
}

//遍历顺序表
void print_Sq(SqList &L) {
	int i;
	for (i = 0; i<L.length; i++) {
		printf("%4d", L.elem[i]);
	}
}

//查找元素的位置
int Search_Sq(SqList L, Elemtype e) {
	int i = 0;
	while (L.elem[i] != e&&i<L.length) {
		i++;
	}
	if (i>L.length)
		return -1;
	else
		return i + 1;//因为C语言是从下标为0开始的，当i=0时表示第一个元素 
}

//销毁顺序表
Status DestroyList_Sq(SqList &L) {
	if (L.elem == NULL)
		return -1;
	else
		free(L.elem);
	printf("\n销毁成功\n");
	return TRUE;
}

//清空顺序表
Status ClearList_Sq(SqList &L) {
	if (L.elem == NULL)
		exit(0);
	int i;
	Elemtype *p_elem = L.elem;
	for (i = 0; i<L.length; i++) {
		*L.elem = NULL;
		L.elem++;
	}
	L.elem = p_elem;
}

//判断顺序表是否为空
Status ListEmpty_Sq(SqList L) {
	int i;
	Elemtype* p_elem = L.elem;
	for (i = 0; i<L.length; i++) {
		if (*L.elem != 0) {
			L.elem = p_elem;
			return FLASE;
		}
		L.elem++;
	}
	return TRUE;
}

//求顺序表的长度
int ListLength_Sq(SqList L) {
	return L.length;
}

//用e返回顺序表L中第i个元素的值
Status GetElem_Sq(SqList L, int i, Elemtype &e) {
	int j;
	Elemtype* p_elem = L.elem;
	if (i<1 || i>L.length)
		return FLASE;
	for (j = 1; j <= i; j++)
		L.elem++;
	e = *L.elem;
	L.elem = p_elem;
	return TRUE;
}

//将顺序表L中第i个元素赋值为e
Status PutElem_Sq(SqList &L, int i, Elemtype e) {
	L.elem[i - 1] = e;
	return TRUE;
}

//在顺序表L表尾添加元素e
Status Append_Sq(SqList &L, Elemtype e) {
	
	L.elem[L.length] = e;
	L.length++;
	L.listsize += L.increment;
	return TRUE;
}

//删除顺序表L表尾元素
	Status DeleteLast_Sq(SqList &L, Elemtype &e) {
	e = L.elem[L.length - 1];
	L.length--;
	return TRUE;
}

//有序顺序表的归并
	void MergeList_Sq(SqList La, SqList Lb, SqList &Lc) {
		int i = 0, j = 0, size, increment = 10;
		Elemtype ai, bj;
		Lc.listsize= La.length + Lb.length;
		InitList_Sq(Lc, Lc.listsize, increment);// 创建空表Lc 
		CreateList_Sq(Lc);
		while (i<La.length && j<Lb.length) { // 表La和Lb均非空 
			GetElem_Sq(La, i, ai);
			GetElem_Sq(Lb, j, bj);
			if (ai <= bj) { Append_Sq(Lc, ai);   ++i; }
			else { Append_Sq(Lc, bj);   ++j; }
		}
		while (i< La.length) { // 表Lb空   
			GetElem_Sq(La, i++, ai);   Append_Sq(Lc, ai);
		}
		while (j< Lb.length) { // 表La空    
			GetElem_Sq(Lb, j++, bj);   Append_Sq(Lc, bj);
		}
	}
