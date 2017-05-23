#include<stdio.h>
#include<stdlib.h>
#include"链队列.h"
void initqueue(linkqueue *q)  //初始化操作，建立一个空队列 
 {
     q->front=q->rear=(queueptr)malloc(sizeof(node));
     if(!(q->front))
         exit(1);
     q->front->next=0;
 }
 void enqueue(linkqueue *q,char e)  //插入新元素e到队列中并成为队尾元素 
 {
     queueptr p;
     p=(queueptr)malloc(sizeof(node));
     if(!p)exit(1);
     p->data=e;
     p->next=0;
     q->rear->next=p;
     q->rear=p;
 }
 void creatqueue(linkqueue *q) //创建一个长度由自己决定的队列并初始化 
 {
     int i,length;
     int num;
     queueptr p;
     printf("请输入队列长度:\n");
     scanf("%d",&length);
     printf("请输入队列的元素:\n");
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
 void destroyqueue(linkqueue *q)  //若队列存在，则销毁它 
 {
     if(!q)
     {
         printf("链队列已经是空队列!\n");
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
     
     void disqueue(linkqueue *q)  //输出队列元素 
     {
         node *r=q->front->next;
         printf("此时的链队列输出:\n");
         while(r)
         {
             printf("%d  ",r->data);
             r=r->next;
         }
         printf("\n");
     }
     void lenqueue(linkqueue *q)  //求队列长度 
     {
         node *r=q->front->next;
         int s=0;
         printf("此时的链队列长度为:\n");
         while(r)
         {
             r=r->next;
             s++;
         }
         printf("%d\n",s);
     }
     char dequeue(linkqueue *q,int e)  //删除队列中队头元素，并用e返回其值 
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
     int queueempty(linkqueue *q) // 判断队列是否为空 
     {
         if(q->front==q->rear)
             return 1;
         else
             return 0;
     }
     void menu()  //菜单 
     {
         printf("           链队列试验统一界面               \n");
         printf("********************************************\n");
         printf("1 建立链队列!                              *\n");
         printf("2 链队列入队操作!                          *\n");
         printf("3 链队列出队操作!                          *\n");
         printf("4 求链队列长度!                            *\n");
         printf("5 判断链队列是否为空!                      *\n");
         printf("6 输出链队列!                              *\n");
         printf("7 销毁链队列!                              *\n");
         printf("0 退出!                                    *\n");
         printf("********************************************\n");
     }
