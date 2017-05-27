#include "multiequ.h"
#include <stdio.h>
#include <math.h>

Status InitMultiEqu(MultiEqu &E){
	//建立多项式	
	Node p,*q;
	int n,i;
	DestroyMultiEqu(E);
	EmptyMultiEqu(E);
	scanf("%d",&n);	//输入多项式的项数
	getchar();
	for (i=1; i<=n; i++){
		scanf("%lf%d",&p.c, &p.e);    //输入多项式的系数和指数
		if (p.c!=0){
			q=FindNode(E,p);		//寻找是否存在
			if (q){
				q->c+=p.c; 
				if (q->c==0)	DelNode(E,q);
				continue;
			}
			if (!InsertHead(E,p)){
				printf("内存不足，无法继续创建！\n");
				return ERROR;
			}
		}
	}//for
	Arrange(E);
	getchar();
	printf("表达式建立成功\n");
	return OK;	
}
		
Status EmptyMultiEqu(MultiEqu &E){
	//创建一个零多项式
	InitList(E);
	return OK;
}
	
void DestroyMultiEqu(MultiEqu &E){
	//销毁多项式
	DestroyList(E);
}
		
void Output(MultiEqu E){
	//输出多项式
	int i;
	ElemSet *p;
	printf("    ");
	if (E.length==0){
		printf("0");
	}//if
	else{
		for (i=1,p=E.head->next; p; i++,p=p->next){
			if (p->e==0){
				if (p->c>0){
					if (i!=1)	putchar('+');
				}
				printf("%.3f",p->c);
			}//if
			else{
				if (p->c==1){
					if (i!=1)	putchar('+');
				}
				else if (p->c==-1){
					putchar('-');
				}
				else{
					if (p->c>0){
						if (i!=1)    putchar('+');
					}
					printf("%.3f",p->c);
				}
				putchar('x');
				if (p->e!=1){
				if (p->e>0)		printf("^%d",p->e);
					else		printf("^(%d)",p->e);
				}
			}//else
		}//for
	}//else
	putchar('\n');
}

//------在多项式进行各种运算之前，所有均已按指数降序排列-------
Status Add(MultiEqu &E1, MultiEqu &E2, MultiEqu &E3, int x){
	//进行多项式加法运算，运算成功返回OK，否则返回ERROR
	//x为控制参数，当x＝1时,进行加法运算，当x=-1,进行减法运算
	ElemSet data,*p1,*p2;
	DestroyMultiEqu(E3);
	EmptyMultiEqu(E3);
	for (p1=E1.head->next, p2=E2.head->next; p1 && p2 ;) {
		if (p1->e==p2->e){
			data.e=p1->e;
			data.c=p1->c+(x)*p2->c;
			p1=p1->next;
			p2=p2->next;
			if  ( data.c==0)   continue;
		}//if
		else if (p1->e<p2->e){
			data.e=p2->e;
			data.c=(x)*p2->c;
			p2=p2->next;
		}//elseif
		else{
			data.e=p1->e;
			data.c=p1->c;
			p1=p1->next;
		}//else
		data.next=NULL;
		if  (!InsertTail(E3, data)){    //把一个结点插入到E3的表尾
			printf("运算不成功！\n");
			return ERROR;
		}
		E3.length++;
	}//for
	if  (p1){  // p1以后的结点复制到E3的表尾
		while(p1){
			InsertTail(E3,*p1);
			p1=p1->next;
		}
	}
	if  (p2){  //p2以后的结点复制到E3的表尾
		while(p2){
			ElemSet temp;
			temp=*p2;
			temp.c*=x;
			InsertTail(E3,temp);
			p2=p2->next;
		}
	}
	Output(E3);
	return OK;
}

Status Minus(MultiEqu E1, MultiEqu E2, MultiEqu &E3){
	//进行多项式减法运算，运算成功返回OK，否则返回ERROR
	if  (Add(E1,E2,E3,-1))   return OK;
	else    return ERROR;
}

Status Multiply(MultiEqu E1, MultiEqu E2, MultiEqu &E3){
	//进行多项式乘法运算，运算成功返回OK，否则返回ERROR
	ElemSet data,*p1,*p2,*temp;
	DestroyMultiEqu(E3);
	EmptyMultiEqu(E3);
	for (p1=E1.head->next; p1; p1=p1->next){
		for (p2=E2.head->next; p2; p2=p2->next){
			data.e=p1->e+p2->e; 
			data.c=p1->c*p2->c;
			while(temp=FindNode(E3,data)){//若存在指数相同的项，合并
				DelNode(E3,temp);
				data.c+=temp->c;
				FreeNode(temp);
			}
			if  (!InsertTail(E3,data)){
				printf("运算出错！\n");
				return ERROR;
		    }//if
		}//for
	}//for
	Arrange(E3);    //对表达式按指数降序排列
	Output(E3);    //输出表达式
	return OK;
}

void Diff(MultiEqu &E1){
	//对多项式（函数）求导
	ElemSet *pre,*p;
	for (pre=E1.head, p=E1.head->next; p; pre=p, p=p->next){
		p->c*=p->e;
		p->e--;
		if (p->c==0){     //求导后系数为零，释放该结点
			pre->next=p->next;
			FreeNode(p);
			E1.length--;
			p=pre;
			if (!(pre->next))   break;
		}//if
	}//for
	Output(E1);    //输出多项式
}

Status Calculate(MultiEqu E, double x0,char ch){
	//计算多项式（函数）在x0处的函数值
	double sum=0;
	ElemSet *p;
	printf("请输入自变量值x0= ");
	scanf("%lf",&x0);
	getchar();
	for (p=E.head->next; p; p=p->next){
		if (x0==0 && p->e<0){
			printf("除数不能能为零\n");
			return ERROR;
		}
		sum+=p->c*pow(x0,p->e);
	}//for
	printf("%c(%.3f)= %.3f\n",ch,x0,sum);
	return OK;
}


