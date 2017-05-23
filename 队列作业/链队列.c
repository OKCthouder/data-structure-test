#include<stdio.h>
#include<stdlib.h>
#include"������.h"
void initqueue(linkqueue *q)  //��ʼ������������һ���ն��� 
 {
     q->front=q->rear=(queueptr)malloc(sizeof(node));
     if(!(q->front))
         exit(1);
     q->front->next=0;
 }
 void enqueue(linkqueue *q,char e)  //������Ԫ��e�������в���Ϊ��βԪ�� 
 {
     queueptr p;
     p=(queueptr)malloc(sizeof(node));
     if(!p)exit(1);
     p->data=e;
     p->next=0;
     q->rear->next=p;
     q->rear=p;
 }
 void creatqueue(linkqueue *q) //����һ���������Լ������Ķ��в���ʼ�� 
 {
     int i,length;
     int num;
     queueptr p;
     printf("��������г���:\n");
     scanf("%d",&length);
     printf("��������е�Ԫ��:\n");
     for(i=0;i<length;i++)
     {
         p=(queueptr)malloc(sizeof(node));
         if(!p)exit(1);
         scanf("%d",&num);
         
             p->data=num;
             p->next=0;
             q->rear->next=p;
             q->rear=p;
     }
     yes=1;
 }
 void destroyqueue(linkqueue *q)  //�����д��ڣ��������� 
 {
     if(!q)
     {
         printf("�������Ѿ��ǿն���!\n");
         exit(1);
     }
     while(q->front)
     {
         q->rear=q->front->next;
         free((q->front));
         q->front=q->rear;
         if(!q->rear)
             free(q->rear);
     }
     free(q->front);
 }
     
     void disqueue(linkqueue *q)  //�������Ԫ�� 
     {
         node *r=q->front->next;
         printf("��ʱ�����������:\n");
         while(r)
         {
             printf("%d  ",r->data);
             r=r->next;
         }
         printf("\n");
     }
     void lenqueue(linkqueue *q)  //����г��� 
     {
         node *r=q->front->next;
         int s=0;
         printf("��ʱ�������г���Ϊ:\n");
         while(r)
         {
             r=r->next;
             s++;
         }
         printf("%d\n",s);
     }
     char dequeue(linkqueue *q,int e)  //ɾ�������ж�ͷԪ�أ�����e������ֵ 
     {
         node *p;
         if(q->front==q->rear)
             return -1;
         p=q->front->next;
         e=p->data;
         q->front->next=p->next;
         if(q->rear==p)
             q->rear=q->front;
         free(p);
         return e;
     }
     int queueempty(linkqueue *q) // �ж϶����Ƿ�Ϊ�� 
     {
         if(q->front==q->rear)
             return 1;
         else
             return 0;
     }
     void menu()  //�˵� 
     {
         printf("           ����������ͳһ����               \n");
         printf("********************************************\n");
         printf("1 ����������!                              *\n");
         printf("2 ��������Ӳ���!                          *\n");
         printf("3 �����г��Ӳ���!                          *\n");
         printf("4 �������г���!                            *\n");
         printf("5 �ж��������Ƿ�Ϊ��!                      *\n");
         printf("6 ���������!                              *\n");
         printf("7 ����������!                              *\n");
         printf("0 �˳�!                                    *\n");
         printf("********************************************\n");
     }
