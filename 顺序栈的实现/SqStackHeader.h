//头文件内容
//--------------------栈的顺序存储结构--------------------

#define STACK_INIT_SIZE 100
#define STACKINCREACE 10
typedef int Elemtype;//在头文件中说明
typedef int Status;
typedef struct{
    Elemtype *base;
    Elemtype *top;
    int stacksize;
}SqStack;

//----------------------函数声明部分----------------------

Status InitStack(SqStack &S);
Status Push(SqStack &S,Elemtype e);
Status Pop(SqStack &S,Elemtype &e);
Status GetTop(SqStack S,Elemtype &e);
Status StackEmpty(SqStack S);
int StackLength(SqStack S);
Status StackTraverse(SqStack S);
Status ClearStack(SqStack &S);
Status DestroyStack(SqStack &S);

//------------------栈的初始化函数------------------

Status InitStack(SqStack &S){
    S.base = (Elemtype *)malloc(STACK_INIT_SIZE*sizeof(Elemtype));
    if(!S.base){
        return false;
    }
    S.stacksize=STACK_INIT_SIZE;
    S.top=S.base;
    return true;
}

//---------------------入栈函数---------------------

Status Push(SqStack &S,Elemtype e){
//判断是否溢出
    if(S.top-S.base>=S.stacksize){        
        S.base=(Elemtype *)realloc(S.base,(S.stacksize+STACKINCREACE)*sizeof(Elemtype));
        if(!S.base){
            return false;
        }
        S.top=S.base+S.stacksize;//注意因为这里的栈底指针的改变，导致栈顶指针随之改变
        S.stacksize+=STACKINCREACE;
    }
//压栈部分
    *S.top=e;
    S.top++;//栈顶指针加一 
    return true;
}

//---------------------出栈函数---------------------

Status Pop(SqStack &S,Elemtype &e){
//非法判断
    if(S.base==S.top){
        return false;
    }
    S.top--;    //注意这里因为top指向栈中当前元素的上一个空间，所以要先将其位置减一
    e=*S.top;
    return true;
    }
    
//-------------------查看栈顶元素-------------------

Status GetTop(SqStack S,Elemtype &e){
    if(S.base==S.top ){
        return false;
    }
    e=*(S.top-1);
    return true;
}

//------------------判断栈是否为空------------------

Status StackEmpty(SqStack S){
    if(S.base==S.top){
        return true;
    }
    return false;
}

//------------------返回栈元素个数------------------

int StackLength(SqStack S){
    if(S.base==S.top){
        return 0;
    }
    return S.top-S.base;
}

//--------------------遍历栈------------------------

Status StackTraverse(SqStack S){//从栈底到栈顶的方向
    if(S.top==S.base){
        return false;
    }
    while(S.base <S.top ){
        printf("%d\t",*(S.base++));
    }
    printf("\n");
    return true;
}

//--------------------清空栈------------------------

Status ClearStack(SqStack &S){//清空栈的时候不用将stacksize重新赋值
    S.top=S.base;             //因为经过realloc函数重新分配空间后(stacksize大小改变)，
    return true;            //S.base指向的是一段stacksize大小的连续存储空间             
                            //即使将他重置，剩余的空间也是闲置的(顺序表里也只是经当前长度置为0)             
    }
       
//--------------------销毁栈------------------------

Status DestroyStack(SqStack &S){
    free(S.base);
    free(S.top);
    S.base=NULL;
    return true;
}



