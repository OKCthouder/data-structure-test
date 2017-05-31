                 /*
 (1)根据输入字符串创建一棵平衡二叉树
   BBSTree MakeBBSTree();  
 (2)平衡二叉树插入元素操作
   Status InsertAVL(BBSTree &T, RcdType e, Status &taller); 
 (3)层次遍历输出二叉树 
   void LevelOrederTraverse_Print(BBSTree T); 
 (4)括号表示法输出二叉树 
   void BraNotationPrint(BBSTree T);
 (5)平衡二叉树删除元素操作
    Status DeleteAVL(BBSTree &t, RcdType e, Status &shorter);
 (6)求平衡二叉树的深度
    int BBSTreeDepth(BBSTree T); 
 (7)交换所有结点的左右子树
    void ExchangeSubTree(BBSTree &T) 
 (8)递归先序遍历
    Status PreOrder_RecTraverse(BBSTree T)； 
 (9)递归中序遍历
    Status InOrder_RecTraverse(BBSTree T);
(10)递归后序遍历 
    Status LastOrder_RecTraverse(BBSTree T);
(11)非递归先序遍历
    void PreOrderTraverse_I(BBSTree T);
(12)非递归中序遍历
    void InOrderTraverse_I(BBSTree T);
(13)非递归后序遍历 
    void LastOrderTraverse_I(BBSTree T);
 
*/
#include<stdio.h>
#include<malloc.h>

#define OVERFLOW -1
#define OK 1
#define ERROR 0
#define TRUE 1
#define FALSE 0

#define LH +1  //左高 
#define EH 0   //等高 
#define RH -1  //右高 

typedef int RcdType;
typedef int Status;

/*存放输入数据的数组结构体*/
typedef struct ArrayNode{
    RcdType data;
    ArrayNode *next; 
}ArrayNode, *Array;

/*平衡二叉树结构体*/
typedef struct BBSTNode{
    RcdType data;
    int bf;
    BBSTNode *lchild, *rchild;
}BBSTNode,*BBSTree;

/*链队列结构体*/
typedef struct LQNode{
    BBSTree elem;
    struct LQNode *next;
}LQNode, *QueuePtr;

/*队列结点结构体*/
typedef struct{
    QueuePtr front;
    QueuePtr rear;
}LQueue;

/*栈结点结构体*/
typedef struct LSNode{
    BBSTree data;         //数据域 
    struct LSNode *next;   //指针域 
}LSNode, *LStack;          //结点和链栈类型


/*初始化一个链栈*/
Status InitStack_LS(LStack &S){
    S = NULL; 
} 


/*进栈操作*/
Status Push_LS(LStack &S, BBSTree e){
    LSNode *t;
    t = (LSNode*)malloc(sizeof(LSNode));
    if(NULL==t) return OVERFLOW;
    t->data = e;
    t->next = S;
    S = t;
    return OK;
}

/*出栈操作*/
Status Pop_LS(LStack &S, BBSTree &e){
    LSNode *t;
    if(S==NULL) return ERROR;
    t = S;
    e = t->data;
    S = S->next;
    return OK;    
}


/*获得栈顶元素*/
Status GetTop_LS(LStack S, BBSTree &e){
    if(NULL==S) return ERROR;
    else{
        e = S->data;
        return OK;
    }    
}

/*判断栈是否为空*/
Status StackEmpty_LS(LStack S){
    if(NULL==S) return TRUE;
    else return FALSE;
}

/*初始化链队列*/
void InitQueue_LQ(LQueue &Q){
    Q.front = NULL;
    Q.rear= NULL;    
}

/*链队列进队操作*/
Status EnQueue_LQ(LQueue &Q, BBSTree e){
    LQNode *p;
    p = (LQNode*)malloc(sizeof(LQNode));
    if(NULL==p) return OVERFLOW;
    p->elem = e;
    p->next = NULL;
    if(NULL==Q.front) Q.front = p;  //e插入空队列 
    else Q.rear->next = p;  //e插入非空队列 
    Q.rear = p;  //队尾指针指向新的队尾 
    return OK;
}

/*链队列出栈操作*/
Status DeQueue_LQ(LQueue &Q, BBSTree &e){
    LQNode *p;
    if(NULL==Q.front) return ERROR;
    p = Q.front;
    e = p->elem;
    Q.front = p->next;
    if(Q.rear==p) Q.rear = NULL;
    free(p);
    return OK;
}


/*求平衡二叉树的深度*/
int BBSTreeDepth(BBSTree T){
    int depthLeft, depthRight;
    if(NULL==T) return 0;
    else{
        depthLeft = BBSTreeDepth(T->lchild);
        depthRight = BBSTreeDepth(T->rchild);
        return 1+(depthLeft > depthRight ? depthLeft : depthRight);
    }
}

/*交换二叉树所有结点的左右子树*/
void ExchangeSubTree(BBSTree &T){
    BBSTree temp;
    if(NULL!=T){
        ExchangeSubTree(T->lchild);   //使用递归交换左子树
        ExchangeSubTree(T->rchild);   //使用递归交换右子树
        if((T->lchild!=NULL)||(T->rchild!=NULL)){    //如果T的子树有一个不为空，则交换左右子树
            temp = T->lchild;
            T->lchild = T->rchild;
            T->rchild = temp;
        }
    }

}

/*左旋调整*/
void L_Rotate(BBSTree &p){
    BBSTree rc = p->rchild;
    p->rchild = rc->lchild;
    rc->lchild = p;
    p = rc;
}

/*右旋调整*/
void R_Rotate(BBSTree &p){
    BBSTree lc = p->lchild;
    p->lchild = lc->rchild;
    lc->rchild = p;
    p = lc;
}


/*左平衡处理操作*/
void LeftBalance(BBSTree &T){
    BBSTree lc, rd;
    lc = T->lchild;
    switch(lc->bf){
        case LH:
            T->bf = lc->bf = EH; R_Rotate(T); break;
        case RH:
            rd = lc->rchild;
            switch(rd->bf){
                case LH: T->bf = RH; lc->bf = EH; break;
                case EH: T->bf = lc->bf = EH; break;
                case RH: T->bf = EH; lc->bf = LH; break;                
            }
            rd->bf = EH;
            L_Rotate(T->lchild);
            R_Rotate(T);
            break;             
        case EH:                    //deleteAVL需要，insertAVL用不着 
            T->bf = LH;
            lc->bf = RH;
            R_Rotate(T);
            break;     
    }
}

/*右平衡处理操作*/
void RightBalance(BBSTree &T){
    BBSTree rd,lc;
    rd=T->rchild;
    switch(rd->bf)
    {
        case RH:
            T->bf=rd->bf=EH; L_Rotate(T); break;
        case LH:
            lc=rd->lchild;
            switch(lc->bf){
                case RH:T->bf=LH;rd->bf=EH;break;
                case EH:T->bf=rd->bf=EH;break;
                case LH:T->bf=EH;rd->bf=RH;break;
            }
            lc->bf=EH;
            R_Rotate(T->rchild);
            L_Rotate(T);
            break;
        case EH:                //deleteAVL需要，insertAVL用不着 
            T->bf = RH;
            rd->bf = LH;
            L_Rotate(T);
            break;
    }  
}


/*平衡二叉树的插入操作*/
Status InsertAVL(BBSTree &T, RcdType e, Status &taller){
    if(NULL==T){
        T = (BBSTree)malloc(sizeof(BBSTNode));
        T->data = e;
        T->bf = EH; 
        T->lchild = NULL; 
        T->rchild = NULL;
    }else if(e==T->data){ //书中已存在和e相等的结点 
        taller = FALSE; return FALSE;        
    }else if(e<T->data){
        if(FALSE==InsertAVL(T->lchild, e, taller)) return FALSE;
        if(TRUE==taller){
            switch(T->bf){
                case LH: LeftBalance(T); taller = FALSE; break;
                case EH: T->bf = LH; taller = TRUE; break;
                case RH: T->bf = EH; taller = FALSE; break;
            }
        }
    }else{
        if(FALSE==InsertAVL(T->rchild, e, taller)) return FALSE;
        if(TRUE==taller){
            switch(T->bf){
                case LH: T->bf = EH; taller = FALSE; break;
                case EH: T->bf = RH; taller = TRUE; break;
                case RH: RightBalance(T); taller = FALSE; break;
            }
        }
    }
    return TRUE;
}

/*平衡二叉树的删除操作*/
Status DeleteAVL(BBSTree &t, RcdType e, Status &shorter){         
 //当被删结点是有两个孩子，且其前驱结点是左孩子时，tag=1
    static int tag = 0;
    if(t == NULL){            
        return FALSE;    //如果不存在元素，返回失败
    }else if(e==t->data){
        BBSTNode *q = NULL;
        //如果该结点只有一个孩子，则将自子树取代该结点 
        if(t->lchild == NULL){           
            q = t;  
            t = t->rchild;  
            free(q);   
            shorter = TRUE;     
        }  
        else if(t->rchild == NULL){  
            q = t;  
            t = t->lchild;  
            free(q);
            shorter = TRUE;
        }  
        //如果被删结点有两个孩子，则找到结点的前驱结点，
        //并将前驱结点的值赋给该结点，然后删除前驱结点
        else{  
            q = t->lchild;              
            while(q->rchild){  
                q = q->rchild;  
            }  
            t->data = q->data;
            if(t->lchild->data==q->data){
                tag = 1;
            }
            DeleteAVL(t->lchild, q->data, shorter);
            if(tag==1){
                BBSTree r = t->rchild;
                if(NULL==r) t->bf = 0;
                else{
                    switch(r->bf){
                        case EH: t->bf=-1;break;
                        default: RightBalance(t);break;
                    }
                }
            }
        }  
    }else if(e<t->data){        //左子树中继续查找  
        if(!DeleteAVL(t->lchild, e, shorter)){  
            return FALSE;   
        }  
        //删除完结点之后，调整结点的平衡因子 
        if(shorter&&(tag==0))  {
            switch(t->bf){  
                case LH:  
                    t->bf = EH;  
                    shorter = TRUE;
                    break;  
                case EH:  
                    t->bf = RH;  
                    shorter = FALSE;
                    break;  
                //如果本来就是右子树较高，删除之后就不平衡，需要做右平衡操作    
                case RH:  
                    RightBalance(t);    //右平衡处理
                    if(t->rchild->bf == EH) 
                        shorter = FALSE;
                    else  
                        shorter = TRUE;
                    break;  
            }  
        }  
    }else if(e>t->data){ //右子树中继续查找      
        if(!DeleteAVL(t->rchild, e, shorter)){  
            return FALSE;
        }  
        //删除完结点之后，调整结点的平衡因子 
        if(shorter&&(tag==0))  {
            switch(t->bf){  
                case LH:  
                    LeftBalance(t);     //左平衡处理
                    if(t->lchild->bf == EH)//注意这里，画图思考一下   
                        shorter = FALSE;
                    else  
                        shorter = TRUE;
                    break;  
                case EH:  
                    t->bf = LH;  
                    shorter = FALSE;
                    break;  
                case RH:  
                    t->bf = EH;  
                    shorter = TRUE;
                    break;  
            }  
        }  
        if(tag==1){
            int depthLeft = BBSTreeDepth(t->lchild);
            int depthRight = BBSTreeDepth(t->rchild);
            t->bf = depthLeft - depthRight;
        }
        int depthLeft = BBSTreeDepth(t->lchild);
        int depthRight = BBSTreeDepth(t->rchild);
        t->bf = depthLeft - depthRight;
    }  
    return TRUE;     
}  

/*平衡二叉树的查找操作*/
BBSTree SearchAVL(BBSTree T, RcdType e){
    if(T==NULL) return NULL;
    if(e==T->data){
            return T;
    }else if(e>T->data){
        return SearchAVL(T->rchild, e);
    }else {
        return SearchAVL(T->lchild, e);
    }
    
}


/*获取输入存到数组a*/
Array GetInputToArray(){
    Array head, p, q;
    char k;
    head = p = q = NULL;
    int m;
    if(k!='\n'){
        scanf("%d",&m);
        p = (ArrayNode*)malloc(sizeof(ArrayNode));
        head = p;
        p->data = m;
        k = getchar();
    }    
    while(k!='\n'){
        scanf("%d",&m);
        q = (ArrayNode*)malloc(sizeof(ArrayNode));
        q->data = m;
        p->next = q;
        p = p->next;
        k = getchar();
    }
    if(p!=NULL){
        p->next = NULL;        
    }
    return head;  //返回存放数据的头指针 
}

/*根据输入的字符串建一棵平衡二叉树*/
BBSTree MakeBBSTree( ){
    int i=0;
    Status taller = TRUE;  
    BBSTree T = NULL;
    Array a;
    a = GetInputToArray();
    while(a!=NULL){
        taller = TRUE;
        InsertAVL(T, a->data, taller);
        a = a->next;
    }
    return T;
}

/*递归先序遍历*/
Status PreOrder_RecTraverse(BBSTree T){
    if(NULL==T) return OK;
    printf("%d ",T->data);
    PreOrder_RecTraverse(T->lchild);
    PreOrder_RecTraverse(T->rchild);
}

/*递归中序遍历*/
Status InOrder_RecTraverse(BBSTree T){
    if(T->lchild)
        InOrder_RecTraverse(T->lchild);
    printf("%d ",T->data);
    if(T->rchild)
        InOrder_RecTraverse(T->rchild);
}

/*递归后序遍历*/
Status LastOrder_RecTraverse(BBSTree T){
    if(T->lchild)
        LastOrder_RecTraverse(T->lchild);
    if(T->rchild)
        LastOrder_RecTraverse(T->rchild);
    printf("%d ",T->data);
}

/*找到最左结点*/
BBSTree GoFarLeft(BBSTree T, LStack &S){
    if(NULL==T) return NULL;
    while(T->lchild!=NULL){
        Push_LS(S, T);
        T = T->lchild;
    }
    return T;
}

/*非递归中序遍历*/
void InOrderTraverse_I(BBSTree T){
    LStack S;
    InitStack_LS(S);
    BBSTree p = NULL;
    p = GoFarLeft(T, S);
    while(p!=NULL){
        printf("%d ",p->data);
        if(p->rchild!=NULL){
            p = GoFarLeft(p->rchild, S);
        }
        else if(StackEmpty_LS(S)!=TRUE) Pop_LS(S, p);
        else p = NULL;
    }        
}

BBSTree VisitFarLeft(BBSTree T, LStack &S){
    if(NULL==T) return NULL;      //如果T为空，则返回空
    printf("%d ",T->data);            //先序，先读取结点数据
    while(T->lchild!=NULL){
        Push_LS(S, T);               //入栈
        T = T->lchild;            //遍历下一个左子树
        printf("%d ", T->data);           //下一个结点的读取数据
    }
    return T;
}

/*非递归先序遍历*/
void PreOrderTravese_I(BBSTree T){
    LStack S;
    InitStack_LS(S);
    BBSTree p;
    p = VisitFarLeft(T, S);       //先将左边的数据先序读取
    while(p!=NULL){
        if(p->rchild!=NULL)              //如果最左下结点的右子树不为空
            p = VisitFarLeft(p->rchild, S);   //执行遍历该结点的左子树
        else if(StackEmpty_LS(S)!=TRUE) Pop_LS(S,p);    //如果S不为空栈，出栈
        else p = NULL;    //如果为空栈，p赋予空
    }
}

/*非递归后序遍历*/
void LastOrderTravese_I(BBSTree root){
    BBSTree p = root;
    BBSTree stack[30];
    int num=0;
    BBSTree have_visited = NULL;
    while(NULL!=p||num>0){
        while(NULL!=p){
            stack[num++]=p;
            p=p->lchild;        
        }
        p=stack[num-1];
        if(NULL==p->rchild||have_visited==p->rchild){
            printf("%d  ",p->data);
            num--;
            have_visited=p;
            p=NULL;
        }
        else{
            p=p->rchild;
        }
    }
    printf("\n");
}

/*非递归层次遍历输出一棵二叉树*/
void LevelOrederTraverse_Print(BBSTree T){ 
    if(T==NULL){
        printf("The tree is empty!");
    }
    if(T!=NULL){
        LQueue Q;
        InitQueue_LQ(Q);
        BBSTree p = T;
        printf("%d ",p->data);
        EnQueue_LQ(Q,p);
        while(DeQueue_LQ(Q,p)){
            if(p->lchild!=NULL){
                printf("%d ", p->lchild->data);
                EnQueue_LQ(Q, p->lchild);
            }
            if(p->rchild!=NULL){
                printf("%d ", p->rchild->data);
                EnQueue_LQ(Q, p->rchild);
            }
        }
    }
}

/*括号表示法输出平衡二叉树*/
void BraNotationPrint(BBSTree T){
    if(NULL==T){
        printf(" 空!");
    }else{
        if(T!=NULL){
            if(T!=NULL){
                printf("%i",T->data);
                if(T->lchild||T->rchild){
                    printf("(");
                }
            }
        }
        if(T->lchild||T->rchild){
            if(T->lchild){
                BraNotationPrint(T->lchild);    
            }else if(T->rchild){
                printf("#");
            }
            printf(",");
            if(T->rchild){
                BraNotationPrint(T->rchild);
             }else if(T->lchild){
                 printf("#");
             }
            printf(")");
        }
    }
}


/*将一棵树转换为一个数组*/
Array GetArrayFromTree(BBSTree T){
    Status firstTime = TRUE;
    Array head = NULL;
    ArrayNode *b  = NULL;
    ArrayNode *q = NULL;
    if(T==NULL){
        printf("The tree is empty!");
    }
    if(T!=NULL){
        LQueue Q;
        InitQueue_LQ(Q);
        BBSTree p = T;
        q = (Array)malloc(sizeof(ArrayNode));
        q->data = p->data;
        if(firstTime==TRUE){
            head = q;
            firstTime = FALSE;
            b = q;
        }else{
            b->next = q;
            b = b->next;
        }
        EnQueue_LQ(Q,p);
        while(DeQueue_LQ(Q,p)){
            if(p->lchild!=NULL){
                q = (Array)malloc(sizeof(ArrayNode));
                q->data = p->lchild->data;
                b->next = q;
                b = b->next;
                EnQueue_LQ(Q, p->lchild);
            }
            if(p->rchild!=NULL){
                q = (Array)malloc(sizeof(ArrayNode));
                q->data = p->rchild->data;
                b->next = q;
                b = b->next;
                EnQueue_LQ(Q, p->rchild);
            }
        }
        if(b!=NULL){
        	b->next = NULL;	
        }
    }    
    return head;
}

/*将两棵平衡二叉树合并成一颗平衡二叉树*/
BBSTree Combine2Tree(BBSTree T1, BBSTree T2){
    Status taller = TRUE;
    Array a = NULL;
    a = GetArrayFromTree(T2);
    while(a!=NULL){
        taller = TRUE;
        InsertAVL(T1, a->data, taller);
        a = a->next;
    }
    return T1;    
}

/*将一棵平衡二叉树分裂成两棵平衡二叉树*/
/*
	参数1：要进行分裂的树
	参数2：分裂出来的小于等于x的子树
	参数3：分裂出来的 大于x的子树 
	参数4：关键字x 
*/
Status SplitBBSTree(BBSTree Tt1, BBSTree &Tt2, BBSTree &Tt3, int x){
    Array a = NULL;
    Status taller; 
    a = GetArrayFromTree(Tt1);
    if(Tt1==NULL) return FALSE;
    else{
         while(a!=NULL){
            if(a->data<=x){
                  taller = TRUE;
                InsertAVL(Tt2, a->data, taller);    
                a = a->next;
            }else {
                taller = TRUE;
                InsertAVL(Tt3, a->data, taller);    
                a = a->next;    
            }
         }
    }       
    return TRUE;
}