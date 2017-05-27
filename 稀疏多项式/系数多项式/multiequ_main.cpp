#include "multiequ.h"
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int main(){
	MultiEqu L1,L2,L3;	
	char promt[100]="��ʾ������help��HELP��ð�����quit��QUIT�˳�\n";
	char cmd[20];
	int x0 =0;


//	freopen("in.txt","r",stdin);

	x_print(80,'*');	//��ʾһ��*��
	putchar('\n');	
	x_print(20,' ');  
	printf("%s\n",promt);	//�����ʾ��Ϣ
	x_print(80,'*');  
	putchar('\n');

	EmptyMultiEqu(L2);
	EmptyMultiEqu(L1);
	EmptyMultiEqu(L3);

	do{
		printf("������");
		gets(cmd);	//�ȴ��û���������
		if QUIT
			break;
		else if HELP
			Help();		//��ʾ������Ϣ
		else if SET_f
			InitMultiEqu(L1);	//��������ʽf
		else if SET_g		
			InitMultiEqu(L2);	//��������ʽg
		else if OUT_f		
			Output(L1);		//�������ʽf
		else if OUT_g
			Output(L2);	  //�������ʽg	
		else if (ADD_f_g || ADD_g_f)
			Add(L1,L2,L3,1);	//����f+g
		else if MINUS_f_g
			Minus(L1,L2,L3);	//����f��g
		else if MINUS_g_f
			Minus(L2,L1,L3);	//����g-f
		else if DIFF_f
			Diff(L1);	//��f'
		else if DIFF_g
			Diff(L2);	//��g'
		else if (MULTIPLE_f_g || MULTIPLE_g_f)
			Multiply(L1,L2,L3);	//����f*g
		else if CALCULATE_f
			Calculate(L1,x0,'f');	//����f(x0)
		else if CALCULATE_g
			Calculate(L2,x0,'g');	//����g(x0)
		else if CLS
			system("cls");	//����
		else{
			printf("�Ƿ�����...\n");
		}
	}while(1);

	DestroyMultiEqu(L1);
	DestroyMultiEqu(L2);
	DestroyMultiEqu(L3);
	return 1;
}