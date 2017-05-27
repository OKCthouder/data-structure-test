#include "multiequ.h"
#include <stdio.h>
//#include <string.h>

Status InitList(LinkList &L){
	//����һ���յ����Ա�
	if (!(L.head=new ElemSet))  return ERROR;
	L.tail=L.head;
	L.head->next=NULL;
	L.length=0;
	return OK;
}

void DestroyList(LinkList &L){
	//�������Ա�L
	ClearList(L);
	delete L.head;
	L.head=L.tail=NULL;
}

void ClearList(LinkList &L){
	//������Ա�L
	ElemSet *p;
	for (p=L.head->next; p; p=L.head->next){
		L.head->next=p->next;
		delete p;
	}//for
	L.tail=L.head;
	L.length=0;
}
		
int ListLength(LinkList L){
	//�������Ա�ĳ���
	return L.length;
}

Status InsertHead(LinkList &L, ElemSet e){
	//��Ԫ��e��Ϊ��һ�������뵽���Ա�L��
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
	//��Ԫ��e��Ϊ���һ�������뵽���Ա�L��
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
	//��Ԫ��e���뵽���Ա�L�ĵ�i�����֮��(0<=i<=L.length)
	ElemSet *p,*q;
	int k;
	if (i<0 || i>L.length)  { printf("ָ�������λ�ò���ȷ��"); return ERROR; }
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
	//�ж����Ա�L�Ƿ�Ϊ�ձ����ǣ�����TRUE�����򷵻�FALSE
	return L.length==0?TRUE: FALSE;
}

Status DelNode(LinkList &L, ListNode &p){
	//ɾ������L��p��ָ�Ľ�㣬��p��ָ�Ľ�㲻�������У��򷵻�ERROR��
	//���򷵻�OK����ʹpָ��ɾ���Ľ��
	ElemSet *q;
	for (q=L.head; q && q->next!=p; q=q->next)   ;
	if (!q)  return ERROR;
	q->next=p->next;
	L.length--;
	if (L.tail==p)   L.tail=q;
	return OK;
}

ElemSet *Locate(LinkList L, int i){
	//��iֵ�Ϸ�(1<=i<=L.length)���򷵻����Ա�L�е�i������ָ�룬���򷵻�NULL
	ElemSet *p;
	int k;
	if (i<1 || i>L.length)	   {printf("λ��ֵ���Ϸ�"); return NULL;}
	for (k=1,p=L.head->next; k!=i ; k++,p=p->next)	;
	return p;
} 

void Arrange(LinkList &L){
	//����ѡ�񷨽�������
	ElemSet *p;
	int i;
	for (i=0; i<L.length; i++){
		p=MaxNode(L,i);   //�ҳ���i�����֮�����н���н��Ԫ����ָ��ֵ���Ľ�㣬
						  //���������з���������Ժ���ֵ���ظý���ָ��
		InsertAfter(L,i,*p);  //��p��ָ�Ľ����뵽�����е�i �����֮��
	}//for 
}

ElemSet * FindNode(LinkList L,ElemSet p){
	//Ѱ�����Ա��к�p.e��ͬ�Ľ�㣬�Ժ���ֵ���ظý���ָ�룬���򷵻�NULL
	ElemSet *q;
	for (q=L.head->next; q && q->e!=p.e; q=q->next)   ;
	return q;
}

void FreeNode(ElemSet *e){
	//�ͷŽ��*e
	delete e;
}