#include <stdio.h>
#include <stdlib.h>
#include "˳���.h"
#include "Դ����.h"
//--------------------���������--------------------

int main(){
	SqList L;
	int size, inc;
	int e;
	int a;
	int length; 
	int i;
	int temp;
	int j;
	int ee; 
	printf("\n--------------------˳����ʼ��------------------\n");
	printf("������˳���ĳ���size�Լ���������\n");
	scanf_s("%d %d", &size, &inc);
	InitList_Sq(L, size, inc);
	CreateList_Sq(L);

	printf("\n--------------------�ж��Ƿ�Ϊ��------------------\n");

	if(ListEmpty_Sq(L)){
		printf("��˳���Ϊ��\n"); 
	}
	else
	    printf("��˳���Ϊ��\n");
	    
	printf("\n--------------------����˳���--------------------\n");
	
	printf("��ʱ˳���Ϊ��\n");
	print_Sq(L);
	
	printf("\n--------------------����Ԫ��----------------------\n");

	printf("\n������Ҫ���ҵ�Ԫ�أ�\n");
	scanf_s("%d",&e);
	a = Search_Sq(L, e);
	printf("%dΪ��%dλ��\n",e,a);
	
	printf("\n--------------------�������----------------------\n");

	length = ListLength_Sq(L); 
	printf("˳���ĳ���Ϊ%d\n",length);

	printf("\n----------��˳���L�е�i��Ԫ�ظ�ֵΪtemp----------\n");

	printf("�������i��Ԫ�ص�iֵ��tempֵ��\n");
	scanf_s("%d %d",&i,&temp);
	PutElem_Sq(L, i, temp);
	printf("\n��ʱ˳���Ϊ��\n");
	print_Sq(L);
	
	printf("\n---------------��˳����β���Ԫ��---------------\n");

	printf("\n������Ҫ��ӵ�Ԫ��j��\n");
	scanf_s("%d", &j);
	Append_Sq(L, j);
	printf("\n��ʱ˳���Ϊ��\n");
	print_Sq(L);
	
	printf("\n---------------��˳����βɾ��Ԫ��---------------\n");

	DeleteLast_Sq(L, ee);
	printf("\n��ɾ����Ԫ��Ϊ%d\n",ee);
	printf("��ʱ˳���Ϊ��\n");
	print_Sq(L);

	
	
	printf("\n-------------------���˳���---------------------\n");

	ClearList_Sq(L);
	if(ListEmpty_Sq(L)){
		printf("\n��ճɹ�\n"); 
	} 

	printf("\n------------------����˳���----------------------\n");

	DestroyList_Sq(L); 
/*	int size, inc;
	SqList La, Lb, Lc;

	printf("\n--------------------˳����ʼ��------------------\n");
	printf("������˳���ĳ���size�Լ���������\n");
	scanf_s("%d %d", &size, &inc);
	InitList_Sq(La, size, inc);
	CreateList_Sq(La);
	InitList_Sq(Lb, size, inc);
	CreateList_Sq(Lb);
	InitList_Sq(Lc, size, inc);
	MergeList_Sq(La, Lb, Lc);
	printf("��ʱ˳���Ϊ��\n");
	print_Sq(Lc);*/
	getchar();
	getchar();
	return 0;
}
