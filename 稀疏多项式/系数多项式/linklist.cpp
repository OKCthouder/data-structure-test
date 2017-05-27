#include "multiequ.h"
#include <stdio.h>
//#include <string.h>

Status InitList(LinkList &L){
	//构造一个空的线性表
	if (!(L.head=new ElemSet))  return ERROR;
	L.tail=L.head;
	L.head->next=NULL;
	L.length=0;
	return OK;
}

void DestroyList(LinkList &L){
	//销毁线性表L
	ClearList(L);
	delete L.head;
	L.head=L.tail=NULL;
}

void ClearList(LinkList &L){
	//清空线性表L
	ElemSet *p;
	for (p=L.head->next; p; p=L.head->next){
		L.head->next=p->next;
		delete p;
	}//for
	L.tail=L.head;
	L.length=0;
}
		
int ListLength(LinkList L){
	//返回线性表的长度
	return L.length;
}

Status InsertHead(LinkList &L, ElemSet e){
	//把元素e作为第一个结点插入到线性表L中
	ElemSet *p;
	p=new ElemSet;
	if (!p)  return ERROR;
	*p=e;
	p->next=L.head->next;
	L.head->next=p;
	L.length++;
	return OK;
}

Status InsertTail(LinkList &L, ElemSet e){
	//把元素e作为最后一个结点插入到线性表L中
	ElemSet *p;
	p=new ElemSet;
	if (!p)  return ERROR;
	*p=e;
	p->next=NULL;
	L.tail->next=p;
	L.tail=p;
	L.length++;
	return OK;
}
		
Status InsertAfter(LinkList &L,int i, ElemSet e){
	//把元素e插入到线性表L的第i个结点之后(0<=i<=L.length)
	ElemSet *p,*q;
	int k;
	if (i<0 || i>L.length)  { printf("指定插入的位置不正确！"); return ERROR; }
	for (k=0, p=L.head; k!=i ; k++, p=p->next)  ;
	q=new Node;
	if (!q)	return ERROR;
	*q=e;
	q->next=p->next;
	p->next=q;
	L.length++;
	return OK;
}

int ListEmpty(LinkList L){
	//判断线性表L是否为空表，若是，返回TRUE，否则返回FALSE
	return L.length==0?TRUE: FALSE;
}

Status DelNode(LinkList &L, ListNode &p){
	//删除链表L中p所指的结点，若p所指的结点不在链表中，则返回ERROR，
	//否则返回OK，并使p指向被删除的结点
	ElemSet *q;
	for (q=L.head; q && q->next!=p; q=q->next)   ;
	if (!q)  return ERROR;
	q->next=p->next;
	L.length--;
	if (L.tail==p)   L.tail=q;
	return OK;
}

ElemSet *Locate(LinkList L, int i){
	//若i值合法(1<=i<=L.length)，则返回线性表L中第i个结点的指针，否则返回NULL
	ElemSet *p;
	int k;
	if (i<1 || i>L.length)	   {printf("位置值不合法"); return NULL;}
	for (k=1,p=L.head->next; k!=i ; k++,p=p->next)	;
	return p;
} 

void Arrange(LinkList &L){
	//采用选择法进行排序
	ElemSet *p;
	int i;
	for (i=0; i<L.length; i++){
		p=MaxNode(L,i);   //找出第i个结点之后所有结点中结点元素中指数值最大的结点，
						  //并从链表中分离出来，以函数值返回该结点的指针
		InsertAfter(L,i,*p);  //将p所指的结点插入到链表中第i 个结点之后
	}//for 
}

ElemSet * FindNode(LinkList L,ElemSet p){
	//寻找线性表中和p.e相同的结点，以函数值返回该结点的指针，否则返回NULL
	ElemSet *q;
	for (q=L.head->next; q && q->e!=p.e; q=q->next)   ;
	return q;
}

void FreeNode(ElemSet *e){
	//释放结点*e
	delete e;
}