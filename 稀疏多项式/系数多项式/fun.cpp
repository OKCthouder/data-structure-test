#include "multiequ.h"
#include <string.h>
#include <stdio.h>


void Help(){
	//显示帮助信息
	int i;
	char *Msg[13]={
		"构造多项式命令：set f     或者   set g",
		"输出多项式命令：f=    或者    g=",
		"求导命令：f'=     或者    g'=",
		"相加命令：f+g=    或者    g+f=",
		"相减命令：g-f=    或者    f-g=",
		"相乘命令：g*f=    或者   f*g=",
		"求多项式f(x)在x0的数值：f(x0)=    或者    g(x0)=",
		"退出系统：quit    或者    QUIT",
		"打开帮助文件：HELP      或者    help",
		"      注：1、上述的命令除了set后有一个空格外，其余不能有空格。",
		"          2、加法和乘法命令中，对换f、g不影响表达式的求值。",
		"          3、命令f(x0)=中的x0是字符串‘x0’，程序接收该命令后，会要求用",
		"             户输入x0的浮点数值，然后会计算并输出结果"
	};

	for (i=0; i<13; i++){
		if (i<9)
			x_print(15,' ');
		if (i==9)	putchar('\n');
		printf("%s\n",Msg[i]);
	}
}

void x_print(int n,char ch){
	//格式符输出
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
