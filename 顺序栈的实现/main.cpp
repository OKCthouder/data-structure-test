//源文件内容
#include <stdio.h>
#include <stdlib.h>
#include "SqStackHeader.h"

//--------------------主函数入口--------------------

int main(){
    SqStack stack;
    int temp=1;
    int getElem=NULL;
    int popElem=NULL;
    
//--------------------栈的初始化--------------------

    InitStack(stack);
    
//--------------------元素的入栈--------------------

    Push(stack,temp);
    Push(stack,2);
    
//--------------------遍历顺序栈--------------------

    printf("此时的栈元素有：\n"); 
    StackTraverse(stack);
    
//-------------------获取栈顶元素-------------------

    GetTop(stack,getElem);
    printf("栈顶元素是：%d\n",getElem);
    
//-------------------判断是否为空-------------------

	bool empty;
    empty=StackEmpty(stack);
    if(empty==true){
    	printf("该栈是空栈\n");
	}
	else{
		printf("该栈不是空栈"); 
	} 
	
//--------------------弹栈测试----------------------

	Pop(stack,popElem);
	printf("弹出的元素是：%d\n",popElem);
	
//------------------栈的清空及销毁------------------

//    ClearStack(stack);
//    DestroyStack(stack);

	printf("此时的栈元素有：\n"); 
    StackTraverse(stack);
//--------------------输出栈长度--------------------

    printf("栈的长度：%d\n",StackLength(stack));
	getchar();
    return 0;
}
