#include<stdio.h>
#include<malloc.h>
#include<stdlib.h>
#define OK 1
 int yes=0;
 typedef struct node
 {
     char data;
     struct node *next;
 }node,*queueptr;
 typedef struct
 {
     queueptr front;
     queueptr rear;
 }linkqueue;