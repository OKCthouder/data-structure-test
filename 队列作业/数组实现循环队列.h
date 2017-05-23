//循环队列（数组实现）  
#include <stdlib.h>  
#include <stdio.h>  
#define MAXSIZE 5  
typedef int T;  
typedef struct tag  
{  
    int front, rear, MaxSize, count; //其实MaxSize变量完全可以不要  
    T elements[MAXSIZE];  
} QUEUE;

void creat( QUEUE *queue );  //创建队列   

int is_empty( QUEUE queue);  //其实最好传指针免得栈开销太大 ，判断队列是否为空 

int is_full( QUEUE queue );  //判断队列是否满了 

void readqueue( QUEUE queue ); //读取队列的首元素的值 

void in_queue( QUEUE *queue, T value ); //进队列 

T out_queue( QUEUE *queue );  //出队列 

void print( QUEUE queue );  //输出队列元素 

void creat( QUEUE *queue )  
{  
    queue -> front = 0;  
    queue -> rear = 0;  
    queue -> count = 0;  
    queue -> MaxSize = MAXSIZE - 1;  
}  
int is_empty( QUEUE queue)  //其实最好传指针免得栈开销太大  
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
    if ( queue.count == 0 )  //可以用前面的is_empty函数进行判断  
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
    if ( queue -> count == MAXSIZE )  //可以利用前面的is_full函数进行判断  
    {  
        printf("sorry! the queue is full! no space is available!/n");  
    }  
    else  
    {  
        if ( queue -> count == 0 )  
        {  
            //主要是处理队列为空时的入队列  
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
    if ( queue -> count == 0 )  //可以利用前面的is_empty函数进行判断  
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
