//ѭ�����У�����ʵ�֣�  
#include <stdlib.h>  
#include <stdio.h>  
#define MAXSIZE 5  
typedef int T;  
typedef struct tag  
{  
    int front, rear, MaxSize, count; //��ʵMaxSize������ȫ���Բ�Ҫ  
    T elements[MAXSIZE];  
} QUEUE;

void creat( QUEUE *queue );  //��������   

int is_empty( QUEUE queue);  //��ʵ��ô�ָ�����ջ����̫�� ���ж϶����Ƿ�Ϊ�� 

int is_full( QUEUE queue );  //�ж϶����Ƿ����� 

void readqueue( QUEUE queue ); //��ȡ���е���Ԫ�ص�ֵ 

void in_queue( QUEUE *queue, T value ); //������ 

T out_queue( QUEUE *queue );  //������ 

void print( QUEUE queue );  //�������Ԫ�� 

void creat( QUEUE *queue )  
{  
    queue -> front = 0;  
    queue -> rear = 0;  
    queue -> count = 0;  
    queue -> MaxSize = MAXSIZE - 1;  
}  
int is_empty( QUEUE queue)  //��ʵ��ô�ָ�����ջ����̫��  
{  
    if ( queue.count == 0 )  
    {  
        return 1;  
    }  
    else  
    {  
        return 0;  
    }  
}  
int is_full( QUEUE queue )  
{  
    if ( queue.count == MAXSIZE )  
    {  
        return 1;  
    }  
    else  
    {  
        return 0;  
    }  
}  
void readqueue( QUEUE queue ) //just read the value  
{   
    if ( queue.count == 0 )  //������ǰ���is_empty���������ж�  
    {  
        printf("the queue is empty! no number is available! /n");  
    }  
    else  
    {  
        printf("the first number is %d /n", queue.elements[queue.front]);  
    }  
}  
void in_queue( QUEUE *queue, T value )  
{  
    if ( queue -> count == MAXSIZE )  //��������ǰ���is_full���������ж�  
    {  
        printf("sorry! the queue is full! no space is available!/n");  
    }  
    else  
    {  
        if ( queue -> count == 0 )  
        {  
            //��Ҫ�Ǵ������Ϊ��ʱ�������  
            queue -> elements[queue -> rear] = value;  
            queue -> count += 1;  
        }  
        else  
        {  
            queue -> rear = (queue -> rear + 1) % MAXSIZE;  
            queue -> elements[queue ->rear] = value;  
            queue -> count += 1;  
        }  
    }  
}  
T out_queue( QUEUE *queue )  
{  
    if ( queue -> count == 0 )  //��������ǰ���is_empty���������ж�  
    {  
        printf("sorry! the queue is empty! no number is available! /n");  
        exit(EXIT_FAILURE);  
    }  
    else  
    {  
        queue -> front = (queue -> front + 1) % MAXSIZE;  
        queue -> count -= 1;    
    }  
}  
//print queue  
void print( QUEUE queue )  
{  
    int i = 1/*, count*/;  
    if ( queue.count == 0 )  
    {  
        printf("the queue is empty! no number can be printed! \n");  
    }  
    else  
    {  
        //count = queue.count;  
        printf("the number of queue is %d \n", queue.count);  
        for ( i; i <= queue.count; i++ )  
        {  
            printf("the %d number is %d \n", i, queue.elements[(queue.front + i - 1) % MAXSIZE]);  
            //printf("the %d number is %d \n", i, queue.elements[queue.front + i - 1]);  
        }  
    }  
}  
//test functions  
