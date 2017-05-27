#define TRUE 1
#define FALSE 0
#define OK 1
#define ERROR 0
#define ElemSet Node
#define Status bool

#define CLS (strcmp(cmd,"CLS")==0 || strcmp(cmd,"cls")==0)
#define QUIT (strcmp(cmd,"QUIT")==0 || strcmp(cmd,"quit")==0)
	//退出
#define HELP (strcmp(cmd,"help")==0 || strcmp(cmd,"HELP")==0)
	//获得帮助
#define DIFF_f (strcmp(cmd,"f'=")==0)
#define DIFF_g (strcmp(cmd,"g'=")==0)
	//求导f',g'
#define ADD_f_g (strcmp(cmd,"f+g=")==0) 
#define ADD_g_f (strcmp(cmd,"g+f=")==0) 
	//相加x+y
#define MINUS_f_g (strcmp(cmd,"f-g=")==0)
#define MINUS_g_f (strcmp(cmd,"g-f=")==0)
	//相减x-y
#define MULTIPLE_f_g (strcmp(cmd,"f*g=")==0)
#define MULTIPLE_g_f (strcmp(cmd,"g*f=")==0)
	//相乘
#define SET_f (strcmp(cmd,"set f")==0)
#define SET_g (strcmp(cmd,"set g")==0)
	//建立多项式f,g
#define OUT_f (strcmp(cmd,"f=")==0)
#define OUT_g (strcmp(cmd,"g=")==0)
	//显示多项式f,g
#define CALCULATE_f (strcmp(cmd,"f(x0)=")==0)
#define CALCULATE_g (strcmp(cmd,"g(x0)=")==0)
	//计算多项式f,g在x0处的值


//定义线性表结点的结构：
typedef struct Node{
	double c;			//系数
	int e;			//指数
	struct Node *next;		//指向下一个结点
}Node,*ListNode;
//定义线性表的结构：
typedef struct LinkList{
	Node  *head,*tail;		//线性表头结点和表尾结点
	int length;		//线性表L长度（即：多项式的项数）
}LinkList;
//定义多项式
typedef LinkList MultiEqu;

//------－－－--------多项式模块定义－－－－－－－－－－－－－
Status InitMultiEqu(MultiEqu &E);

Status EmptyMultiEqu(MultiEqu &E);

void DestroyMultiEqu(MultiEqu &E);

void Output(MultiEqu E);

//------在多项式进行各种运算之前，所有均已按指数降序排列-------
Status Add(MultiEqu &E1, MultiEqu &E2, MultiEqu &E3, int x);

Status Minus(MultiEqu E1, MultiEqu E2, MultiEqu &E3);

Status Multiply(MultiEqu E1, MultiEqu E2, MultiEqu &E3);

void Diff(MultiEqu &E1);

Status Calculate(MultiEqu E, double x0,char ch);

void FreeNode(ElemSet *e);

//---------------------线性表模块实现------------------------------
Status InitList(LinkList &L);

void DestroyList(LinkList &L);

void ClearList(LinkList &L);

int ListLength(LinkList L);

Status InsertHead(LinkList &L, ElemSet e);

Status InsertTail(LinkList &L, ElemSet e);

Status InsertAfter(LinkList &L,int i, ElemSet e);

int ListEmpty(LinkList L);

Status DelNode(LinkList &L, ListNode &p);

void Arrange(LinkList &L);

ElemSet *Locate(LinkList L, int i);

ElemSet *Locate(LinkList L, int i);

ElemSet * FindNode(LinkList L,ElemSet p);

//---------------------定义辅助函数--------------------------------
		
void Help();

ElemSet * MaxNode(LinkList &L, int i); 

void x_print(int n,char ch);

