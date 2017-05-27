#include "multiequ.h"
#include <string.h>
#include <stdio.h>


void Help(){
	//��ʾ������Ϣ
	int i;
	char *Msg[13]={
		"�������ʽ���set f     ����   set g",
		"�������ʽ���f=    ����    g=",
		"�����f'=     ����    g'=",
		"������f+g=    ����    g+f=",
		"������g-f=    ����    f-g=",
		"������g*f=    ����   f*g=",
		"�����ʽf(x)��x0����ֵ��f(x0)=    ����    g(x0)=",
		"�˳�ϵͳ��quit    ����    QUIT",
		"�򿪰����ļ���HELP      ����    help",
		"      ע��1���������������set����һ���ո��⣬���಻���пո�",
		"          2���ӷ��ͳ˷������У��Ի�f��g��Ӱ����ʽ����ֵ��",
		"          3������f(x0)=�е�x0���ַ�����x0����������ո�����󣬻�Ҫ����",
		"             ������x0�ĸ�����ֵ��Ȼ�����㲢������"
	};

	for (i=0; i<13; i++){
		if (i<9)
			x_print(15,' ');
		if (i==9)	putchar('\n');
		printf("%s\n",Msg[i]);
	}
}

void x_print(int n,char ch){
	//��ʽ�����
	int i;
	for (i=0; i<n; i++){
		putchar(ch);
	}
}

ElemSet * MaxNode(LinkList &L, int i){
	ElemSet *p,*q;
	p=Locate(L,i+1);
	for (q=p,p=p->next; p; p=p->next){
		if (q->e<p->e)	   q=p;
	}//for
	DelNode(L,q);
	return q;
}
