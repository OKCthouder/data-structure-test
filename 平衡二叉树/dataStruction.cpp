#include "AVL_head.h"
#include<stdlib.h>

/*��������*/
void Print(BBSTree& T,int t){
	int i=0;
	if(T){
		Print(T->rchild,t+5);
		for(i=0;i<t;i++){
			printf(" ");
		}
		printf("%5d(bf:%d)\n\n",T->data, T->bf);
		Print(T->lchild,t+5);
	}
}

void InitView(){
	printf("\n   ***************************************************************************\n");	
	printf("   *\t\t\t    ��ӭ����ƽ�����������ʾ����                     *\n");
	printf("   *\t\t\t                                                     *\n");
	printf("   *\t\t\t\t1.����һ�÷ǿն�����                         *\n");
	printf("   *\t\t\t\t2.����һ�ÿյĶ�����                         *\n");	
	printf("   *\t\t\t\t3.��ӽ��                                   *\n");
	printf("   *\t\t\t\t4.ɾ�����                                   *\n");
	printf("   *\t\t\t\t5.���ҽ��                                   *\n");
	printf("   *\t\t\t\t6.�ϲ�����ƽ�������                         *\n");
	printf("   *\t\t\t\t7.����һ��ƽ�������                         *\n");	
	printf("   *\t\t\t\t8.�˳�                                       *\n");
	printf("   ***************************************************************************\n\n");	
	printf("˵����1.������ƽ���������Ԫ�ؾ�Ϊ����,����ʱ����������\n");
	printf("      2.��������ʱ,Ԫ��֮����'�ո�'�����ȷ�ϰ�'�س���'\n");
	printf("      3.�������д������Ĳ����������ӣ�ɾ�������Ҳ�����ϵͳ�Զ�����һ�ÿ�����\n");
	printf("      4.�����������빦��һ�����������ģ����޹��������໥����!\n\n");
}

/*ѡ��һ*/
/*����һ�÷ǿն�����*/
BBSTree item_1(){
	BBSTree T = NULL;
	printf("\n\t\t  ����������������������(��'�س���'����):\n");
	printf("\t\t\t   ");
	T = MakeBBSTree();
	system("CLS");
	InitView();
	printf("\n\t\t\t       ���ƽ�������Ϊ:\n");
	printf("\t\t\t      ");
	BraNotationPrint(T);	
	printf("\n");
	printf("   ==========================================================================");
	printf("\n\t\t\t     ***ƽ�������չʾ***");
	printf("\n");
	printf("\n");
	Print(T, 24);
	printf("   ==========================================================================");
	printf("\n");
	if(T!=NULL){
		printf("\n\t\t\t          �����ɹ���\n");
	}else{
		printf("\n\t\t\t          ����ʧ�ܣ�\n"); 
	} 
	printf("\n\t\t\t    �밴�����������һ��...");
	getchar();
	system("CLS");
	InitView();
	return T;
}

/*ѡ���*/
/*����һ�ÿյĶ�����*/
void item_2(BBSTree &T){
	T = NULL;
	system("CLS");
	InitView();
	printf("\t\t\t���ƽ�������Ϊ:");
	BraNotationPrint(T);	
	printf("\n");
	printf("   ==========================================================================");
	printf("\n");
	printf("\n");
	Print(T, 24);
	printf("   ==========================================================================");
	printf("\n");
	printf("\n\t\t\t          �����ɹ���\n");
	printf("\n\t\t\t    �밴�����������һ��...");
	getchar();
	system("CLS");
	InitView();
	
}


/*ѡ����*/
/*��ӽ��*/
void item_3(BBSTree &T){
	Status reasult = FALSE;
	Status taller = TRUE;
	int m;	
	system("CLS");
	InitView();
	printf("\t\t\t���ƽ�������Ϊ:");
	BraNotationPrint(T);	
	printf("\n");
	printf("   ==========================================================================");
	printf("\n");
	printf("\n");;
	Print(T, 24);
	printf("   ==========================================================================");
	printf("\n");
	printf("\n\t\t\t     ������Ҫ��ӵ�Ԫ��:");
	scanf("%d",&m);
	getchar();
	if(InsertAVL(T, m, taller)){
		reasult = TRUE;
	}
	system("CLS");
	InitView();
	printf("\t\t\t���ƽ�������Ϊ:");
	BraNotationPrint(T);	
	printf("\n");
	printf("   ==========================================================================");
	printf("\n");
	printf("\n");;
	Print(T, 24);
	printf("   ==========================================================================");
	printf("\n");
	if(reasult==TRUE){
		printf("\n\t\t\t          ��ӳɹ���\n");
	}else {
		printf("\n\t\t\t          ���ʧ�ܣ�\n");
	}
}

/*ѡ����*/
/*ɾ�����*/
void item_4(BBSTree &T){
	Status reasult = FALSE;
	int m;
	Status shorter = TRUE;
	system("CLS");
	InitView();
	printf("\t\t\t���ƽ�������Ϊ:");
	BraNotationPrint(T);	
	printf("\n");
	printf("   ==========================================================================");
	printf("\n");
	printf("\n");;
	Print(T, 24);
	printf("   ==========================================================================");
	printf("\n");
	printf("\n\t\t\t     ������Ҫɾ����Ԫ��:");
	scanf("%d",&m);
	getchar();
	if(DeleteAVL(T, m, shorter)){
		reasult = TRUE;
	}
	system("CLS");
	InitView();
	printf("\t\t\t���ƽ�������Ϊ:");
	BraNotationPrint(T);	
	printf("\n");
	printf("   ==========================================================================");
	printf("\n");
	printf("\n");;
	Print(T, 24);
	printf("   ==========================================================================");
	printf("\n");
	if(reasult==TRUE){
		printf("\n\t\t\t          ɾ���ɹ���");
	}else {
		printf("\n\t\t\t          ɾ��ʧ�ܣ�");
	}
}

/*ѡ����*/
/*���ҽ��*/
void item_5(BBSTree T){
	int m;
	BBSTree p;
	system("CLS");
	InitView();
	printf("\t\t\t���ƽ�������Ϊ:");
	BraNotationPrint(T);	
	printf("\n");
	printf("   ==========================================================================");
	printf("\n");
	printf("\n");;
	Print(T, 24);
	printf("   ==========================================================================");
	printf("\n");
	printf("\n\t\t\t     ������Ҫ���ҵ�Ԫ��:");
	scanf("%d",&m);
	getchar();
	p = SearchAVL(T, m);
	system("CLS");
	InitView();
	printf("\t\t\t    ���ƽ�������Ϊ:");
	BraNotationPrint(T);	
	printf("\n");
	printf("   ==========================================================================");
	printf("\n");
	printf("\n");;
	Print(T, 24);
	printf("\n\n\t\t\t          ƽ�������\n");
	printf("   ==========================================================================");
	printf("\n\n");
	printf("\t\t\t    ��Ĳ�������Ϊ:");
	BraNotationPrint(T);
	printf("\n");
	printf("   ==========================================================================");
	printf("\n");
	printf("\n");;
	Print(p, 24);
	printf("\n\n\t\t\t          ��������\n");
	printf("   ==========================================================================");
	printf("\n");
	if(p==NULL){
		printf("\n\t\t\t          ����ʧ�ܣ�");
	}else{
 		printf("\n\t\t\t          ���ҳɹ�!");
	}
}

/*ѡ����*/
/*�ϲ�����ƽ�������  */
void item_6(){
	BBSTree TT1, TT2, TT3;
	TT1 = NULL;
	TT2 = NULL;
	system("CLS");
	InitView();
	printf("\n\t\t\t       ���������ѡ��6 \n");
	printf("\n\t\t     ��������T1����������(��'�س���'����):\n");
	printf("\t\t\t   ");	
	TT1 = MakeBBSTree(); 
	printf("\n");
	printf("\n\t\t     ��������T2����������(��'�س���'����):\n");
	printf("\t\t\t   ");	
	TT2 = MakeBBSTree(); 
	system("CLS");
	InitView();
	printf("\n");
	printf("\n   ==========================================================================");
//	printf("\n\t\t\t       ƽ�������T1Ϊ:\n");
//	printf("\t\t\t          ");
	printf("\n     ƽ�������T1Ϊ:  ");
	BraNotationPrint(TT1);
	printf("\n   ==========================================================================");
//	printf("\n\t\t\t       ƽ�������T2Ϊ:\n");
//	printf("\t\t\t          ");
	printf("\n     ƽ�������T2Ϊ:  ");
	BraNotationPrint(TT2);
	printf("\n   ==========================================================================");
	TT3 = Combine2Tree(TT1, TT2);	
//	printf("\n\t\t\t     �ϲ����ƽ�������T3:\n");		
//	printf("\t\t\t       ");
	printf("\n     �ϲ����ƽ�������T3Ϊ:  ");
	BraNotationPrint(TT3);
	printf("\n   ==========================================================================");
	printf("\n");
	printf("\n\t\t\t ���س����鿴T1,T2,T3�İ����...");
	getchar();
	system("CLS");
	InitView();
	printf("\n");
	printf("   ==========================================================================");
	printf("\n\t\t\t       ƽ�������T1Ϊ:\n");
	printf("\t\t\t          \n");
	Print(TT1, 24);
	printf("   ==========================================================================");
	printf("\n\t\t\t       ƽ�������T2Ϊ:\n");
	printf("\t\t\t          \n");
	Print(TT2, 24);
	printf("   ==========================================================================");
	TT3 = Combine2Tree(TT1, TT2);	
	printf("\n\t\t\t    �ϲ����ƽ�������T3Ϊ:\n");		
	printf("\t\t\t       \n");		
	Print(TT3, 24);
	printf("   ==========================================================================");
	printf("\n\t\t\t    �밴�����������һ��...");
	getchar();
	system("CLS");
	InitView();
}

/*ѡ����*/
/*����һ��ƽ������� */
void item_7(){
    BBSTree Tt1, Tt2, Tt3;
    int x;
    Tt1 = NULL;
    Tt2 = NULL;
    Tt3 = NULL;
   	system("CLS");
	InitView();
	printf("\n\t\t\t       ���������ѡ��7 \n");
	printf("\n\t\t     ������������������(��'�س���'����):\n");
	printf("\t\t\t   ");	
    Tt1 = MakeBBSTree();
	printf("\n\t\t     ������ָ���x��ֵ(��'�س���'����):");	
    scanf("%d",&x);
    getchar();
	SplitBBSTree(Tt1, Tt2, Tt3, x);    
	system("CLS");
	InitView();
	printf("\n");
	printf("\n   ==========================================================================");
//	printf("\n\t\t\t      �ָ�ǰ��ƽ�������Ϊ:\n");
//	printf("\t\t\t          ");
	printf("\n     �ָ�ǰ��ƽ�������T1Ϊ:  ");
	BraNotationPrint(Tt1);
	printf("\n   ==========================================================================");
//	printf("\n\t\t\t       ƽ�������T2Ϊ:\n");
//	printf("\t\t\t          ");
	printf("\n     �ָ��С�ڵ���%d��ƽ�������T2Ϊ:  ",x);
	BraNotationPrint(Tt2);
	printf("\n   ==========================================================================");	
//	printf("\n\t\t\t     �ϲ����ƽ�������T3:\n");		
//	printf("\t\t\t       ");
	printf("\n     �ָ�����%d��ƽ�������T3Ϊ:  ",x);
	BraNotationPrint(Tt3);
	printf("\n   ==========================================================================");
	printf("\n");
	printf("\n\t\t\t ���س����鿴T1,T2,T3�İ����...");
	getchar();
	system("CLS");
	InitView();
	printf("\n");
	printf("   ==========================================================================");
	printf("\n");
	printf("\n     �ָ�ǰ��ƽ�������T1Ϊ:  ");
	BraNotationPrint(Tt1);	
	printf("\n\n");
	printf("   ==========================================================================");
	printf("\n\t\t\t       �ָ�ǰ��ƽ�������T1:\n");
	printf("\t\t\t          \n");
	Print(Tt1, 24);
	printf("   ==========================================================================");
	printf("\n");
	printf("\n     �ָ��С�ڵ���%d��ƽ�������T2Ϊ:  ",x);
	BraNotationPrint(Tt1);	
	printf("\n\n");
	printf("   ==========================================================================");
	printf("\n\t\t\t     �ָ��С�ڵ���%d��ƽ�������T2:\n",x);
	printf("\t\t\t          \n");
	Print(Tt2, 24);
	printf("   ==========================================================================");	
	printf("\n");
	printf("\n     �ָ�����%d��ƽ�������T3Ϊ:  ",x);
	BraNotationPrint(Tt1);	
	printf("\n\n");
	printf("   ==========================================================================");
	printf("\n\t\t\t     �ָ�����%d��ƽ�������T3:\n",x);		
	printf("\t\t\t       \n");		
	Print(Tt3, 24);
	printf("   ==========================================================================");
	printf("\n\t\t\t    �밴�����������һ��...");
	getchar();
	system("CLS");
	InitView();
}

/*ѡ���*/
/*�˳�*/
void item_8(){
	BBSTree T = NULL;
	char ch;
	int m;
	printf("\n\n");
	printf("\t\t\t  * * * * * * * * * * * * * * *\n");
	printf("\t\t\t  *                           *\n");		
	printf("\t\t\t  *\t    ȷ���˳���        *\n");
	printf("\t\t\t  *                           *\n");	
	printf("\t\t\t  * * * * * * * * * * * * * * *\n");
	printf("\t\t\t  *             *             *\n");	
	printf("\t\t\t  *\t  Y��   *   N��       *\n"); 
	printf("\t\t\t  *             *             *\n");	
	printf("\t\t\t  * * * * * * * * * * * * * * *");
	printf("\n");
	printf("\n\t\t\t           ��ѡ��");
	scanf("%c",&ch);
	getchar();
	while(ch){
		if(ch=='Y'||ch=='y'){
			exit(0);
		}else if(ch=='N'|| ch=='n'){
			system("CLS");
			InitView();
			printf("\n\t\t\t       ���������ѡ��");
			scanf("%d",&m);
			getchar();
			while(m){
				switch(m){
					case 1:
						T = item_1();
						break;
					case 2:
						item_2(T);
						break;
					case 3:
						item_3(T);
						break;
					case 4:
						item_4(T);
						break;
					case 5:
						item_5(T);
						break;
					case 6:
						item_6();
						break;
					case 7:
						item_7();
						break;
				}
				if(m==8){
					item_8();
					break;
				}else if(m>8||m<1){
					system("CLS");
					InitView();
					printf("\n\t\t\t     �����������������!!\n"); 
				}
				printf("\n\t\t\t       ���������ѡ��");
				scanf("%d",&m);
				getchar();	
			}	
			break;	
		}else{
			system("CLS");
			InitView();
			printf("\n\n");
			printf("\t\t\t  * * * * * * * * * * * * * * *\n");	
			printf("\t\t\t  *                           *\n");		
			printf("\t\t\t  *\t    ȷ���˳���        *\n");
			printf("\t\t\t  *                           *\n");	
			printf("\t\t\t  * * * * * * * * * * * * * * *\n");
			printf("\t\t\t  *             *             *\n");	
			printf("\t\t\t  *\t  Y��   *   N��       *\n"); 
			printf("\t\t\t  *             *             *\n");	
			printf("\t\t\t  * * * * * * * * * * * * * * *");
			printf("\n");
			printf("\n\t\t\t       ���������ѡ��");			
		}	
		scanf("%c",&ch);
		getchar();
	}
}

void SetColor(){
	system("color 0B");
}
	
int main(){
	int m;
	BBSTree T = NULL;
	SetColor();
	InitView();
	printf("\n\t\t\t       ���������ѡ��");
	scanf("%d",&m);
	getchar();
	while(1){
		switch(m){
			case 1:
				T = item_1();
				break;
			case 2:
				item_2(T);
				break;
			case 3:
				item_3(T);
				break;
			case 4:
				item_4(T);
				break;
			case 5:
				item_5(T);
				break;
			case 6:
				item_6();
				break;
			case 7:
				item_7();
				break;
		}
		if(m==8){
			item_8();
			break;
		}else if(m>8||m<1){
			system("CLS");
			InitView();
			printf("\n\t\t\t     �����������������!!\n"); 
		}
		printf("\n\t\t\t       ���������ѡ��");
		scanf("%d",&m);
		getchar();	
	}	
	return 0;
}