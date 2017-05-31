                 /*
 (1)���������ַ�������һ��ƽ�������
   BBSTree MakeBBSTree();  
 (2)ƽ�����������Ԫ�ز���
   Status InsertAVL(BBSTree &T, RcdType e, Status &taller); 
 (3)��α������������ 
   void LevelOrederTraverse_Print(BBSTree T); 
 (4)���ű�ʾ����������� 
   void BraNotationPrint(BBSTree T);
 (5)ƽ�������ɾ��Ԫ�ز���
    Status DeleteAVL(BBSTree &t, RcdType e, Status &shorter);
 (6)��ƽ������������
    int BBSTreeDepth(BBSTree T); 
 (7)�������н�����������
    void ExchangeSubTree(BBSTree &T) 
 (8)�ݹ��������
    Status PreOrder_RecTraverse(BBSTree T)�� 
 (9)�ݹ��������
    Status InOrder_RecTraverse(BBSTree T);
(10)�ݹ������� 
    Status LastOrder_RecTraverse(BBSTree T);
(11)�ǵݹ��������
    void PreOrderTraverse_I(BBSTree T);
(12)�ǵݹ��������
    void InOrderTraverse_I(BBSTree T);
(13)�ǵݹ������� 
    void LastOrderTraverse_I(BBSTree T);
 
*/
#include<stdio.h>
#include<malloc.h>

#define OVERFLOW -1
#define OK 1
#define ERROR 0
#define TRUE 1
#define FALSE 0

#define LH +1  //��� 
#define EH 0   //�ȸ� 
#define RH -1  //�Ҹ� 

typedef int RcdType;
typedef int Status;

/*����������ݵ�����ṹ��*/
typedef struct ArrayNode{
    RcdType data;
    ArrayNode *next; 
}ArrayNode, *Array;

/*ƽ��������ṹ��*/
typedef struct BBSTNode{
    RcdType data;
    int bf;
    BBSTNode *lchild, *rchild;
}BBSTNode,*BBSTree;

/*�����нṹ��*/
typedef struct LQNode{
    BBSTree elem;
    struct LQNode *next;
}LQNode, *QueuePtr;

/*���н��ṹ��*/
typedef struct{
    QueuePtr front;
    QueuePtr rear;
}LQueue;

/*ջ���ṹ��*/
typedef struct LSNode{
    BBSTree data;         //������ 
    struct LSNode *next;   //ָ���� 
}LSNode, *LStack;          //������ջ����


/*��ʼ��һ����ջ*/
Status InitStack_LS(LStack &S){
    S = NULL; 
} 


/*��ջ����*/
Status Push_LS(LStack &S, BBSTree e){
    LSNode *t;
    t = (LSNode*)malloc(sizeof(LSNode));
    if(NULL==t) return OVERFLOW;
    t->data = e;
    t->next = S;
    S = t;
    return OK;
}

/*��ջ����*/
Status Pop_LS(LStack &S, BBSTree &e){
    LSNode *t;
    if(S==NULL) return ERROR;
    t = S;
    e = t->data;
    S = S->next;
    return OK;    
}


/*���ջ��Ԫ��*/
Status GetTop_LS(LStack S, BBSTree &e){
    if(NULL==S) return ERROR;
    else{
        e = S->data;
        return OK;
    }    
}

/*�ж�ջ�Ƿ�Ϊ��*/
Status StackEmpty_LS(LStack S){
    if(NULL==S) return TRUE;
    else return FALSE;
}

/*��ʼ��������*/
void InitQueue_LQ(LQueue &Q){
    Q.front = NULL;
    Q.rear= NULL;    
}

/*�����н��Ӳ���*/
Status EnQueue_LQ(LQueue &Q, BBSTree e){
    LQNode *p;
    p = (LQNode*)malloc(sizeof(LQNode));
    if(NULL==p) return OVERFLOW;
    p->elem = e;
    p->next = NULL;
    if(NULL==Q.front) Q.front = p;  //e����ն��� 
    else Q.rear->next = p;  //e����ǿն��� 
    Q.rear = p;  //��βָ��ָ���µĶ�β 
    return OK;
}

/*�����г�ջ����*/
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


/*��ƽ������������*/
int BBSTreeDepth(BBSTree T){
    int depthLeft, depthRight;
    if(NULL==T) return 0;
    else{
        depthLeft = BBSTreeDepth(T->lchild);
        depthRight = BBSTreeDepth(T->rchild);
        return 1+(depthLeft > depthRight ? depthLeft : depthRight);
    }
}

/*�������������н�����������*/
void ExchangeSubTree(BBSTree &T){
    BBSTree temp;
    if(NULL!=T){
        ExchangeSubTree(T->lchild);   //ʹ�õݹ齻��������
        ExchangeSubTree(T->rchild);   //ʹ�õݹ齻��������
        if((T->lchild!=NULL)||(T->rchild!=NULL)){    //���T��������һ����Ϊ�գ��򽻻���������
            temp = T->lchild;
            T->lchild = T->rchild;
            T->rchild = temp;
        }
    }

}

/*��������*/
void L_Rotate(BBSTree &p){
    BBSTree rc = p->rchild;
    p->rchild = rc->lchild;
    rc->lchild = p;
    p = rc;
}

/*��������*/
void R_Rotate(BBSTree &p){
    BBSTree lc = p->lchild;
    p->lchild = lc->rchild;
    lc->rchild = p;
    p = lc;
}


/*��ƽ�⴦�����*/
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
        case EH:                    //deleteAVL��Ҫ��insertAVL�ò��� 
            T->bf = LH;
            lc->bf = RH;
            R_Rotate(T);
            break;     
    }
}

/*��ƽ�⴦�����*/
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
        case EH:                //deleteAVL��Ҫ��insertAVL�ò��� 
            T->bf = RH;
            rd->bf = LH;
            L_Rotate(T);
            break;
    }  
}


/*ƽ��������Ĳ������*/
Status InsertAVL(BBSTree &T, RcdType e, Status &taller){
    if(NULL==T){
        T = (BBSTree)malloc(sizeof(BBSTNode));
        T->data = e;
        T->bf = EH; 
        T->lchild = NULL; 
        T->rchild = NULL;
    }else if(e==T->data){ //�����Ѵ��ں�e��ȵĽ�� 
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

/*ƽ���������ɾ������*/
Status DeleteAVL(BBSTree &t, RcdType e, Status &shorter){         
 //����ɾ��������������ӣ�����ǰ�����������ʱ��tag=1
    static int tag = 0;
    if(t == NULL){            
        return FALSE;    //���������Ԫ�أ�����ʧ��
    }else if(e==t->data){
        BBSTNode *q = NULL;
        //����ý��ֻ��һ�����ӣ���������ȡ���ý�� 
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
        //�����ɾ������������ӣ����ҵ�����ǰ����㣬
        //����ǰ������ֵ�����ý�㣬Ȼ��ɾ��ǰ�����
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
    }else if(e<t->data){        //�������м�������  
        if(!DeleteAVL(t->lchild, e, shorter)){  
            return FALSE;   
        }  
        //ɾ������֮�󣬵�������ƽ������ 
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
                //������������������ϸߣ�ɾ��֮��Ͳ�ƽ�⣬��Ҫ����ƽ�����    
                case RH:  
                    RightBalance(t);    //��ƽ�⴦��
                    if(t->rchild->bf == EH) 
                        shorter = FALSE;
                    else  
                        shorter = TRUE;
                    break;  
            }  
        }  
    }else if(e>t->data){ //�������м�������      
        if(!DeleteAVL(t->rchild, e, shorter)){  
            return FALSE;
        }  
        //ɾ������֮�󣬵�������ƽ������ 
        if(shorter&&(tag==0))  {
            switch(t->bf){  
                case LH:  
                    LeftBalance(t);     //��ƽ�⴦��
                    if(t->lchild->bf == EH)//ע�������ͼ˼��һ��   
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

/*ƽ��������Ĳ��Ҳ���*/
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


/*��ȡ����浽����a*/
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
    return head;  //���ش�����ݵ�ͷָ�� 
}

/*����������ַ�����һ��ƽ�������*/
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

/*�ݹ��������*/
Status PreOrder_RecTraverse(BBSTree T){
    if(NULL==T) return OK;
    printf("%d ",T->data);
    PreOrder_RecTraverse(T->lchild);
    PreOrder_RecTraverse(T->rchild);
}

/*�ݹ��������*/
Status InOrder_RecTraverse(BBSTree T){
    if(T->lchild)
        InOrder_RecTraverse(T->lchild);
    printf("%d ",T->data);
    if(T->rchild)
        InOrder_RecTraverse(T->rchild);
}

/*�ݹ�������*/
Status LastOrder_RecTraverse(BBSTree T){
    if(T->lchild)
        LastOrder_RecTraverse(T->lchild);
    if(T->rchild)
        LastOrder_RecTraverse(T->rchild);
    printf("%d ",T->data);
}

/*�ҵ�������*/
BBSTree GoFarLeft(BBSTree T, LStack &S){
    if(NULL==T) return NULL;
    while(T->lchild!=NULL){
        Push_LS(S, T);
        T = T->lchild;
    }
    return T;
}

/*�ǵݹ��������*/
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
    if(NULL==T) return NULL;      //���TΪ�գ��򷵻ؿ�
    printf("%d ",T->data);            //�����ȶ�ȡ�������
    while(T->lchild!=NULL){
        Push_LS(S, T);               //��ջ
        T = T->lchild;            //������һ��������
        printf("%d ", T->data);           //��һ�����Ķ�ȡ����
    }
    return T;
}

/*�ǵݹ��������*/
void PreOrderTravese_I(BBSTree T){
    LStack S;
    InitStack_LS(S);
    BBSTree p;
    p = VisitFarLeft(T, S);       //�Ƚ���ߵ����������ȡ
    while(p!=NULL){
        if(p->rchild!=NULL)              //��������½�����������Ϊ��
            p = VisitFarLeft(p->rchild, S);   //ִ�б����ý���������
        else if(StackEmpty_LS(S)!=TRUE) Pop_LS(S,p);    //���S��Ϊ��ջ����ջ
        else p = NULL;    //���Ϊ��ջ��p�����
    }
}

/*�ǵݹ�������*/
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

/*�ǵݹ��α������һ�ö�����*/
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

/*���ű�ʾ�����ƽ�������*/
void BraNotationPrint(BBSTree T){
    if(NULL==T){
        printf(" ��!");
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


/*��һ����ת��Ϊһ������*/
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

/*������ƽ��������ϲ���һ��ƽ�������*/
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

/*��һ��ƽ����������ѳ�����ƽ�������*/
/*
	����1��Ҫ���з��ѵ���
	����2�����ѳ�����С�ڵ���x������
	����3�����ѳ����� ����x������ 
	����4���ؼ���x 
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