#include<stdio.h>
#include"����ʵ��ѭ������.h" 
int main()  
{  
    QUEUE queue;  
    creat(&queue);  
    //out_queue(&queue);  
    in_queue(&queue, 2);  
    print(queue);  
    in_queue(&queue, 4);  
    print(queue);  
    in_queue(&queue, 5);  
    print(queue);  
    in_queue(&queue, 6);  
    print(queue);  
    in_queue(&queue, 1);  
    print(queue);  
    out_queue(&queue);  
    print(queue);  
    in_queue(&queue, 9);  
    print(queue);  
    //out_queue(&queue);  
    //print(queue);  
    in_queue(&queue, 7);  
    //print(queue);  
}  
