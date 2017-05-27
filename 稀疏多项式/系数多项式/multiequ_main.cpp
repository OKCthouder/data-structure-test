#include "multiequ.h"
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int main(){
	MultiEqu L1,L2,L3;	
	char promt[100]="提示：输入help或HELP获得帮助，quit或QUIT退出\n";
	char cmd[20];
	int x0 =0;


//	freopen("in.txt","r",stdin);

	x_print(80,'*');	//显示一排*号
	putchar('\n');	
	x_print(20,' ');  
	printf("%s\n",promt);	//输出提示信息
	x_print(80,'*');  
	putchar('\n');

	EmptyMultiEqu(L2);
	EmptyMultiEqu(L1);
	EmptyMultiEqu(L3);

	do{
		printf("就绪：");
		gets(cmd);	//等待用户输入命令
		if QUIT
			break;
		else if HELP
			Help();		//显示帮助信息
		else if SET_f
			InitMultiEqu(L1);	//建立多项式f
		else if SET_g		
			InitMultiEqu(L2);	//建立多项式g
		else if OUT_f		
			Output(L1);		//输出多项式f
		else if OUT_g
			Output(L2);	  //输出多项式g	
		else if (ADD_f_g || ADD_g_f)
			Add(L1,L2,L3,1);	//计算f+g
		else if MINUS_f_g
			Minus(L1,L2,L3);	//计算f－g
		else if MINUS_g_f
			Minus(L2,L1,L3);	//计算g-f
		else if DIFF_f
			Diff(L1);	//求f'
		else if DIFF_g
			Diff(L2);	//求g'
		else if (MULTIPLE_f_g || MULTIPLE_g_f)
			Multiply(L1,L2,L3);	//计算f*g
		else if CALCULATE_f
			Calculate(L1,x0,'f');	//计算f(x0)
		else if CALCULATE_g
			Calculate(L2,x0,'g');	//计算g(x0)
		else if CLS
			system("cls");	//清屏
		else{
			printf("非法命令...\n");
		}
	}while(1);

	DestroyMultiEqu(L1);
	DestroyMultiEqu(L2);
	DestroyMultiEqu(L3);
	return 1;
}