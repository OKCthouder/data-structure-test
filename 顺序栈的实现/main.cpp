//Դ�ļ�����
#include <stdio.h>
#include <stdlib.h>
#include "SqStackHeader.h"

//--------------------���������--------------------

int main(){
    SqStack stack;
    int temp=1;
    int getElem=NULL;
    int popElem=NULL;
    
//--------------------ջ�ĳ�ʼ��--------------------

    InitStack(stack);
    
//--------------------Ԫ�ص���ջ--------------------

    Push(stack,temp);
    Push(stack,2);
    
//--------------------����˳��ջ--------------------

    printf("��ʱ��ջԪ���У�\n"); 
    StackTraverse(stack);
    
//-------------------��ȡջ��Ԫ��-------------------

    GetTop(stack,getElem);
    printf("ջ��Ԫ���ǣ�%d\n",getElem);
    
//-------------------�ж��Ƿ�Ϊ��-------------------

	bool empty;
    empty=StackEmpty(stack);
    if(empty==true){
    	printf("��ջ�ǿ�ջ\n");
	}
	else{
		printf("��ջ���ǿ�ջ"); 
	} 
	
//--------------------��ջ����----------------------

	Pop(stack,popElem);
	printf("������Ԫ���ǣ�%d\n",popElem);
	
//------------------ջ����ռ�����------------------

//    ClearStack(stack);
//    DestroyStack(stack);

	printf("��ʱ��ջԪ���У�\n"); 
    StackTraverse(stack);
//--------------------���ջ����--------------------

    printf("ջ�ĳ��ȣ�%d\n",StackLength(stack));
	getchar();
    return 0;
}
