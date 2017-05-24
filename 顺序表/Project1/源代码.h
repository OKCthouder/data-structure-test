#include "˳���.h"

//����˳�������
typedef struct {
	Elemtype *elem;
	int length;
	int listsize;
	int increment;
}SqList;

//��ʼ��˳���
Status InitList_Sq(SqList &L,int size,int inc) {
	
	L.elem = (Elemtype *)malloc(size * sizeof(Elemtype));
	L.length = 0;
	L.listsize = size;
	L.increment = inc;
	return TRUE;
}

//����˳���
Status CreateList_Sq(SqList &L) {
	int i;
	printf("��������Ҫ������˳���Ԫ�ظ�����\n");
	scanf_s("%d", &L.length);
	if (L.length >= L.listsize) {
		L.elem = (Elemtype *)realloc(L.elem, (L.listsize + L.increment) * sizeof(Elemtype));
	}
	if (!L.elem) {
		return FLASE;
	}
	printf("��������Ҫ������˳���\n");
	for (i = 0; i<L.length; i++) {
		scanf_s("%d", &L.elem[i]);
	}
}

//����˳���
void print_Sq(SqList &L) {
	int i;
	for (i = 0; i<L.length; i++) {
		printf("%4d", L.elem[i]);
	}
}

//����Ԫ�ص�λ��
int Search_Sq(SqList L, Elemtype e) {
	int i = 0;
	while (L.elem[i] != e&&i<L.length) {
		i++;
	}
	if (i>L.length)
		return -1;
	else
		return i + 1;//��ΪC�����Ǵ��±�Ϊ0��ʼ�ģ���i=0ʱ��ʾ��һ��Ԫ�� 
}

//����˳���
Status DestroyList_Sq(SqList &L) {
	if (L.elem == NULL)
		return -1;
	else
		free(L.elem);
	printf("\n���ٳɹ�\n");
	return TRUE;
}

//���˳���
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

//�ж�˳����Ƿ�Ϊ��
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

//��˳���ĳ���
int ListLength_Sq(SqList L) {
	return L.length;
}

//��e����˳���L�е�i��Ԫ�ص�ֵ
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

//��˳���L�е�i��Ԫ�ظ�ֵΪe
Status PutElem_Sq(SqList &L, int i, Elemtype e) {
	L.elem[i - 1] = e;
	return TRUE;
}

//��˳���L��β���Ԫ��e
Status Append_Sq(SqList &L, Elemtype e) {
	
	L.elem[L.length] = e;
	L.length++;
	L.listsize += L.increment;
	return TRUE;
}

//ɾ��˳���L��βԪ��
	Status DeleteLast_Sq(SqList &L, Elemtype &e) {
	e = L.elem[L.length - 1];
	L.length--;
	return TRUE;
}

//����˳���Ĺ鲢
	void MergeList_Sq(SqList La, SqList Lb, SqList &Lc) {
		int i = 0, j = 0, size, increment = 10;
		Elemtype ai, bj;
		Lc.listsize= La.length + Lb.length;
		InitList_Sq(Lc, Lc.listsize, increment);// �����ձ�Lc 
		CreateList_Sq(Lc);
		while (i<La.length && j<Lb.length) { // ��La��Lb���ǿ� 
			GetElem_Sq(La, i, ai);
			GetElem_Sq(Lb, j, bj);
			if (ai <= bj) { Append_Sq(Lc, ai);   ++i; }
			else { Append_Sq(Lc, bj);   ++j; }
		}
		while (i< La.length) { // ��Lb��   
			GetElem_Sq(La, i++, ai);   Append_Sq(Lc, ai);
		}
		while (j< Lb.length) { // ��La��    
			GetElem_Sq(Lb, j++, bj);   Append_Sq(Lc, bj);
		}
	}
