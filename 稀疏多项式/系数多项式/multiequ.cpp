#include "multiequ.h"
#include <stdio.h>
#include <math.h>

Status InitMultiEqu(MultiEqu &E){
	//��������ʽ	
	Node p,*q;
	int n,i;
	DestroyMultiEqu(E);
	EmptyMultiEqu(E);
	scanf("%d",&n);	//�������ʽ������
	getchar();
	for (i=1; i<=n; i++){
		scanf("%lf%d",&p.c, &p.e);    //�������ʽ��ϵ����ָ��
		if (p.c!=0){
			q=FindNode(E,p);		//Ѱ���Ƿ����
			if (q){
				q->c+=p.c; 
				if (q->c==0)	DelNode(E,q);
				continue;
			}
			if (!InsertHead(E,p)){
				printf("�ڴ治�㣬�޷�����������\n");
				return ERROR;
			}
		}
	}//for
	Arrange(E);
	getchar();
	printf("���ʽ�����ɹ�\n");
	return OK;	
}
		
Status EmptyMultiEqu(MultiEqu &E){
	//����һ�������ʽ
	InitList(E);
	return OK;
}
	
void DestroyMultiEqu(MultiEqu &E){
	//���ٶ���ʽ
	DestroyList(E);
}
		
void Output(MultiEqu E){
	//�������ʽ
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

//------�ڶ���ʽ���и�������֮ǰ�����о��Ѱ�ָ����������-------
Status Add(MultiEqu &E1, MultiEqu &E2, MultiEqu &E3, int x){
	//���ж���ʽ�ӷ����㣬����ɹ�����OK�����򷵻�ERROR
	//xΪ���Ʋ�������x��1ʱ,���мӷ����㣬��x=-1,���м�������
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
		if  (!InsertTail(E3, data)){    //��һ�������뵽E3�ı�β
			printf("���㲻�ɹ���\n");
			return ERROR;
		}
		E3.length++;
	}//for
	if  (p1){  // p1�Ժ�Ľ�㸴�Ƶ�E3�ı�β
		while(p1){
			InsertTail(E3,*p1);
			p1=p1->next;
		}
	}
	if  (p2){  //p2�Ժ�Ľ�㸴�Ƶ�E3�ı�β
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
	//���ж���ʽ�������㣬����ɹ�����OK�����򷵻�ERROR
	if  (Add(E1,E2,E3,-1))   return OK;
	else    return ERROR;
}

Status Multiply(MultiEqu E1, MultiEqu E2, MultiEqu &E3){
	//���ж���ʽ�˷����㣬����ɹ�����OK�����򷵻�ERROR
	ElemSet data,*p1,*p2,*temp;
	DestroyMultiEqu(E3);
	EmptyMultiEqu(E3);
	for (p1=E1.head->next; p1; p1=p1->next){
		for (p2=E2.head->next; p2; p2=p2->next){
			data.e=p1->e+p2->e; 
			data.c=p1->c*p2->c;
			while(temp=FindNode(E3,data)){//������ָ����ͬ����ϲ�
				DelNode(E3,temp);
				data.c+=temp->c;
				FreeNode(temp);
			}
			if  (!InsertTail(E3,data)){
				printf("�������\n");
				return ERROR;
		    }//if
		}//for
	}//for
	Arrange(E3);    //�Ա��ʽ��ָ����������
	Output(E3);    //������ʽ
	return OK;
}

void Diff(MultiEqu &E1){
	//�Զ���ʽ����������
	ElemSet *pre,*p;
	for (pre=E1.head, p=E1.head->next; p; pre=p, p=p->next){
		p->c*=p->e;
		p->e--;
		if (p->c==0){     //�󵼺�ϵ��Ϊ�㣬�ͷŸý��
			pre->next=p->next;
			FreeNode(p);
			E1.length--;
			p=pre;
			if (!(pre->next))   break;
		}//if
	}//for
	Output(E1);    //�������ʽ
}

Status Calculate(MultiEqu E, double x0,char ch){
	//�������ʽ����������x0���ĺ���ֵ
	double sum=0;
	ElemSet *p;
	printf("�������Ա���ֵx0= ");
	scanf("%lf",&x0);
	getchar();
	for (p=E.head->next; p; p=p->next){
		if (x0==0 && p->e<0){
			printf("����������Ϊ��\n");
			return ERROR;
		}
		sum+=p->c*pow(x0,p->e);
	}//for
	printf("%c(%.3f)= %.3f\n",ch,x0,sum);
	return OK;
}


