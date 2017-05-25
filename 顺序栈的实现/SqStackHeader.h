//ͷ�ļ�����
//--------------------ջ��˳��洢�ṹ--------------------

#define STACK_INIT_SIZE 100
#define STACKINCREACE 10
typedef int Elemtype;//��ͷ�ļ���˵��
typedef int Status;
typedef struct{
    Elemtype *base;
    Elemtype *top;
    int stacksize;
}SqStack;

//----------------------������������----------------------

Status InitStack(SqStack &S);
Status Push(SqStack &S,Elemtype e);
Status Pop(SqStack &S,Elemtype &e);
Status GetTop(SqStack S,Elemtype &e);
Status StackEmpty(SqStack S);
int StackLength(SqStack S);
Status StackTraverse(SqStack S);
Status ClearStack(SqStack &S);
Status DestroyStack(SqStack &S);

//------------------ջ�ĳ�ʼ������------------------

Status InitStack(SqStack &S){
    S.base = (Elemtype *)malloc(STACK_INIT_SIZE*sizeof(Elemtype));
    if(!S.base){
        return false;
    }
    S.stacksize=STACK_INIT_SIZE;
    S.top=S.base;
    return true;
}

//---------------------��ջ����---------------------

Status Push(SqStack &S,Elemtype e){
//�ж��Ƿ����
    if(S.top-S.base>=S.stacksize){        
        S.base=(Elemtype *)realloc(S.base,(S.stacksize+STACKINCREACE)*sizeof(Elemtype));
        if(!S.base){
            return false;
        }
        S.top=S.base+S.stacksize;//ע����Ϊ�����ջ��ָ��ĸı䣬����ջ��ָ����֮�ı�
        S.stacksize+=STACKINCREACE;
    }
//ѹջ����
    *S.top=e;
    S.top++;//ջ��ָ���һ 
    return true;
}

//---------------------��ջ����---------------------

Status Pop(SqStack &S,Elemtype &e){
//�Ƿ��ж�
    if(S.base==S.top){
        return false;
    }
    S.top--;    //ע��������Ϊtopָ��ջ�е�ǰԪ�ص���һ���ռ䣬����Ҫ�Ƚ���λ�ü�һ
    e=*S.top;
    return true;
    }
    
//-------------------�鿴ջ��Ԫ��-------------------

Status GetTop(SqStack S,Elemtype &e){
    if(S.base==S.top ){
        return false;
    }
    e=*(S.top-1);
    return true;
}

//------------------�ж�ջ�Ƿ�Ϊ��------------------

Status StackEmpty(SqStack S){
    if(S.base==S.top){
        return true;
    }
    return false;
}

//------------------����ջԪ�ظ���------------------

int StackLength(SqStack S){
    if(S.base==S.top){
        return 0;
    }
    return S.top-S.base;
}

//--------------------����ջ------------------------

Status StackTraverse(SqStack S){//��ջ�׵�ջ���ķ���
    if(S.top==S.base){
        return false;
    }
    while(S.base <S.top ){
        printf("%d\t",*(S.base++));
    }
    printf("\n");
    return true;
}

//--------------------���ջ------------------------

Status ClearStack(SqStack &S){//���ջ��ʱ���ý�stacksize���¸�ֵ
    S.top=S.base;             //��Ϊ����realloc�������·���ռ��(stacksize��С�ı�)��
    return true;            //S.baseָ�����һ��stacksize��С�������洢�ռ�             
                            //��ʹ�������ã�ʣ��Ŀռ�Ҳ�����õ�(˳�����Ҳֻ�Ǿ���ǰ������Ϊ0)             
    }
       
//--------------------����ջ------------------------

Status DestroyStack(SqStack &S){
    free(S.base);
    free(S.top);
    S.base=NULL;
    return true;
}



