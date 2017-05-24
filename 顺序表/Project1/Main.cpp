#include <stdio.h>
#include <stdlib.h>
#include "顺序表.h"
#include "源代码.h"
//--------------------主函数入口--------------------

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
	printf("\n--------------------顺序表初始化------------------\n");
	printf("请输入顺序表的长度size以及扩容量：\n");
	scanf_s("%d %d", &size, &inc);
	InitList_Sq(L, size, inc);
	CreateList_Sq(L);

	printf("\n--------------------判断是否为空------------------\n");

	if(ListEmpty_Sq(L)){
		printf("该顺序表为空\n"); 
	}
	else
	    printf("该顺序表不为空\n");
	    
	printf("\n--------------------遍历顺序表--------------------\n");
	
	printf("此时顺序表为：\n");
	print_Sq(L);
	
	printf("\n--------------------查找元素----------------------\n");

	printf("\n请输入要查找的元素：\n");
	scanf_s("%d",&e);
	a = Search_Sq(L, e);
	printf("%d为第%d位：\n",e,a);
	
	printf("\n--------------------输出长度----------------------\n");

	length = ListLength_Sq(L); 
	printf("顺序表的长度为%d\n",length);

	printf("\n----------将顺序表L中第i个元素赋值为temp----------\n");

	printf("请输入第i个元素的i值和temp值：\n");
	scanf_s("%d %d",&i,&temp);
	PutElem_Sq(L, i, temp);
	printf("\n此时顺序表为：\n");
	print_Sq(L);
	
	printf("\n---------------在顺序表表尾添加元素---------------\n");

	printf("\n请输入要添加的元素j：\n");
	scanf_s("%d", &j);
	Append_Sq(L, j);
	printf("\n此时顺序表为：\n");
	print_Sq(L);
	
	printf("\n---------------在顺序表表尾删除元素---------------\n");

	DeleteLast_Sq(L, ee);
	printf("\n被删除的元素为%d\n",ee);
	printf("此时顺序表为：\n");
	print_Sq(L);

	
	
	printf("\n-------------------清空顺序表---------------------\n");

	ClearList_Sq(L);
	if(ListEmpty_Sq(L)){
		printf("\n清空成功\n"); 
	} 

	printf("\n------------------销毁顺序表----------------------\n");

	DestroyList_Sq(L); 
/*	int size, inc;
	SqList La, Lb, Lc;

	printf("\n--------------------顺序表初始化------------------\n");
	printf("请输入顺序表的长度size以及扩容量：\n");
	scanf_s("%d %d", &size, &inc);
	InitList_Sq(La, size, inc);
	CreateList_Sq(La);
	InitList_Sq(Lb, size, inc);
	CreateList_Sq(Lb);
	InitList_Sq(Lc, size, inc);
	MergeList_Sq(La, Lb, Lc);
	printf("此时顺序表为：\n");
	print_Sq(Lc);*/
	getchar();
	getchar();
	return 0;
}
