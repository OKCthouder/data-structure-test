#define TRUE 1
#define FALSE 0
#define OK 1
#define ERROR 0
#define ElemSet Node
#define Status bool

#define CLS (strcmp(cmd,"CLS")==0 || strcmp(cmd,"cls")==0)
#define QUIT (strcmp(cmd,"QUIT")==0 || strcmp(cmd,"quit")==0)
	//�˳�
#define HELP (strcmp(cmd,"help")==0 || strcmp(cmd,"HELP")==0)
	//��ð���
#define DIFF_f (strcmp(cmd,"f'=")==0)
#define DIFF_g (strcmp(cmd,"g'=")==0)
	//��f',g'
#define ADD_f_g (strcmp(cmd,"f+g=")==0) 
#define ADD_g_f (strcmp(cmd,"g+f=")==0) 
	//���x+y
#define MINUS_f_g (strcmp(cmd,"f-g=")==0)
#define MINUS_g_f (strcmp(cmd,"g-f=")==0)
	//���x-y
#define MULTIPLE_f_g (strcmp(cmd,"f*g=")==0)
#define MULTIPLE_g_f (strcmp(cmd,"g*f=")==0)
	//���
#define SET_f (strcmp(cmd,"set f")==0)
#define SET_g (strcmp(cmd,"set g")==0)
	//��������ʽf,g
#define OUT_f (strcmp(cmd,"f=")==0)
#define OUT_g (strcmp(cmd,"g=")==0)
	//��ʾ����ʽf,g
#define CALCULATE_f (strcmp(cmd,"f(x0)=")==0)
#define CALCULATE_g (strcmp(cmd,"g(x0)=")==0)
	//�������ʽf,g��x0����ֵ


//�������Ա���Ľṹ��
typedef struct Node{
	double c;			//ϵ��
	int e;			//ָ��
	struct Node *next;		//ָ����һ�����
}Node,*ListNode;
//�������Ա�Ľṹ��
typedef struct LinkList{
	Node  *head,*tail;		//���Ա�ͷ���ͱ�β���
	int length;		//���Ա�L���ȣ���������ʽ��������
}LinkList;
//�������ʽ
typedef LinkList MultiEqu;

//------������--------����ʽģ�鶨�壭������������������������
Status InitMultiEqu(MultiEqu &E);

Status EmptyMultiEqu(MultiEqu &E);

void DestroyMultiEqu(MultiEqu &E);

void Output(MultiEqu E);

//------�ڶ���ʽ���и�������֮ǰ�����о��Ѱ�ָ����������-------
Status Add(MultiEqu &E1, MultiEqu &E2, MultiEqu &E3, int x);

Status Minus(MultiEqu E1, MultiEqu E2, MultiEqu &E3);

Status Multiply(MultiEqu E1, MultiEqu E2, MultiEqu &E3);

void Diff(MultiEqu &E1);

Status Calculate(MultiEqu E, double x0,char ch);

void FreeNode(ElemSet *e);

//---------------------���Ա�ģ��ʵ��------------------------------
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

//---------------------���帨������--------------------------------
		
void Help();

ElemSet * MaxNode(LinkList &L, int i); 

void x_print(int n,char ch);

