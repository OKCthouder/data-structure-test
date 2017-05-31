#include "AVL_head.h"
#include<stdlib.h>

/*凹入表输出*/
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
	printf("   *\t\t\t    欢迎来到平衡二叉树的演示界面                     *\n");
	printf("   *\t\t\t                                                     *\n");
	printf("   *\t\t\t\t1.创建一棵非空二叉树                         *\n");
	printf("   *\t\t\t\t2.创建一棵空的二叉树                         *\n");	
	printf("   *\t\t\t\t3.添加结点                                   *\n");
	printf("   *\t\t\t\t4.删除结点                                   *\n");
	printf("   *\t\t\t\t5.查找结点                                   *\n");
	printf("   *\t\t\t\t6.合并两棵平衡二叉树                         *\n");
	printf("   *\t\t\t\t7.分裂一颗平衡二叉树                         *\n");	
	printf("   *\t\t\t\t8.退出                                       *\n");
	printf("   ***************************************************************************\n\n");	
	printf("说明：1.本程序平衡二叉树的元素均为数字,输入时请输入数字\n");
	printf("      2.输入数据时,元素之间用'空格'间隔，确认按'回车键'\n");
	printf("      3.若不进行创建树的操作便进行添加，删除，查找操作，系统自动创建一棵空树！\n");
	printf("      4.功能六，七与功能一，二，三，四，五无关联，并相互独立!\n\n");
}

/*选项一*/
/*创建一棵非空二叉树*/
BBSTree item_1(){
	BBSTree T = NULL;
	printf("\n\t\t  请输入生成树的数字序列(按'回车键'结束):\n");
	printf("\t\t\t   ");
	T = MakeBBSTree();
	system("CLS");
	InitView();
	printf("\n\t\t\t       你的平衡二叉树为:\n");
	printf("\t\t\t      ");
	BraNotationPrint(T);	
	printf("\n");
	printf("   ==========================================================================");
	printf("\n\t\t\t     ***平衡二叉树展示***");
	printf("\n");
	printf("\n");
	Print(T, 24);
	printf("   ==========================================================================");
	printf("\n");
	if(T!=NULL){
		printf("\n\t\t\t          创建成功！\n");
	}else{
		printf("\n\t\t\t          创建失败！\n"); 
	} 
	printf("\n\t\t\t    请按任意键返回上一层...");
	getchar();
	system("CLS");
	InitView();
	return T;
}

/*选项二*/
/*创建一棵空的二叉树*/
void item_2(BBSTree &T){
	T = NULL;
	system("CLS");
	InitView();
	printf("\t\t\t你的平衡二叉树为:");
	BraNotationPrint(T);	
	printf("\n");
	printf("   ==========================================================================");
	printf("\n");
	printf("\n");
	Print(T, 24);
	printf("   ==========================================================================");
	printf("\n");
	printf("\n\t\t\t          创建成功！\n");
	printf("\n\t\t\t    请按任意键返回上一层...");
	getchar();
	system("CLS");
	InitView();
	
}


/*选项三*/
/*添加结点*/
void item_3(BBSTree &T){
	Status reasult = FALSE;
	Status taller = TRUE;
	int m;	
	system("CLS");
	InitView();
	printf("\t\t\t你的平衡二叉树为:");
	BraNotationPrint(T);	
	printf("\n");
	printf("   ==========================================================================");
	printf("\n");
	printf("\n");;
	Print(T, 24);
	printf("   ==========================================================================");
	printf("\n");
	printf("\n\t\t\t     请输入要添加的元素:");
	scanf("%d",&m);
	getchar();
	if(InsertAVL(T, m, taller)){
		reasult = TRUE;
	}
	system("CLS");
	InitView();
	printf("\t\t\t你的平衡二叉树为:");
	BraNotationPrint(T);	
	printf("\n");
	printf("   ==========================================================================");
	printf("\n");
	printf("\n");;
	Print(T, 24);
	printf("   ==========================================================================");
	printf("\n");
	if(reasult==TRUE){
		printf("\n\t\t\t          添加成功！\n");
	}else {
		printf("\n\t\t\t          添加失败！\n");
	}
}

/*选项四*/
/*删除结点*/
void item_4(BBSTree &T){
	Status reasult = FALSE;
	int m;
	Status shorter = TRUE;
	system("CLS");
	InitView();
	printf("\t\t\t你的平衡二叉树为:");
	BraNotationPrint(T);	
	printf("\n");
	printf("   ==========================================================================");
	printf("\n");
	printf("\n");;
	Print(T, 24);
	printf("   ==========================================================================");
	printf("\n");
	printf("\n\t\t\t     请输入要删除的元素:");
	scanf("%d",&m);
	getchar();
	if(DeleteAVL(T, m, shorter)){
		reasult = TRUE;
	}
	system("CLS");
	InitView();
	printf("\t\t\t你的平衡二叉树为:");
	BraNotationPrint(T);	
	printf("\n");
	printf("   ==========================================================================");
	printf("\n");
	printf("\n");;
	Print(T, 24);
	printf("   ==========================================================================");
	printf("\n");
	if(reasult==TRUE){
		printf("\n\t\t\t          删除成功！");
	}else {
		printf("\n\t\t\t          删除失败！");
	}
}

/*选项五*/
/*查找结点*/
void item_5(BBSTree T){
	int m;
	BBSTree p;
	system("CLS");
	InitView();
	printf("\t\t\t你的平衡二叉树为:");
	BraNotationPrint(T);	
	printf("\n");
	printf("   ==========================================================================");
	printf("\n");
	printf("\n");;
	Print(T, 24);
	printf("   ==========================================================================");
	printf("\n");
	printf("\n\t\t\t     请输入要查找的元素:");
	scanf("%d",&m);
	getchar();
	p = SearchAVL(T, m);
	system("CLS");
	InitView();
	printf("\t\t\t    你的平衡二叉树为:");
	BraNotationPrint(T);	
	printf("\n");
	printf("   ==========================================================================");
	printf("\n");
	printf("\n");;
	Print(T, 24);
	printf("\n\n\t\t\t          平衡二叉树\n");
	printf("   ==========================================================================");
	printf("\n\n");
	printf("\t\t\t    你的查找子树为:");
	BraNotationPrint(T);
	printf("\n");
	printf("   ==========================================================================");
	printf("\n");
	printf("\n");;
	Print(p, 24);
	printf("\n\n\t\t\t          查找子树\n");
	printf("   ==========================================================================");
	printf("\n");
	if(p==NULL){
		printf("\n\t\t\t          查找失败！");
	}else{
 		printf("\n\t\t\t          查找成功!");
	}
}

/*选项六*/
/*合并两棵平衡二叉树  */
void item_6(){
	BBSTree TT1, TT2, TT3;
	TT1 = NULL;
	TT2 = NULL;
	system("CLS");
	InitView();
	printf("\n\t\t\t       请输入你的选择：6 \n");
	printf("\n\t\t     请输入树T1的数字序列(按'回车键'结束):\n");
	printf("\t\t\t   ");	
	TT1 = MakeBBSTree(); 
	printf("\n");
	printf("\n\t\t     请输入树T2的数字序列(按'回车键'结束):\n");
	printf("\t\t\t   ");	
	TT2 = MakeBBSTree(); 
	system("CLS");
	InitView();
	printf("\n");
	printf("\n   ==========================================================================");
//	printf("\n\t\t\t       平衡二叉树T1为:\n");
//	printf("\t\t\t          ");
	printf("\n     平衡二叉树T1为:  ");
	BraNotationPrint(TT1);
	printf("\n   ==========================================================================");
//	printf("\n\t\t\t       平衡二叉树T2为:\n");
//	printf("\t\t\t          ");
	printf("\n     平衡二叉树T2为:  ");
	BraNotationPrint(TT2);
	printf("\n   ==========================================================================");
	TT3 = Combine2Tree(TT1, TT2);	
//	printf("\n\t\t\t     合并后的平衡二叉书T3:\n");		
//	printf("\t\t\t       ");
	printf("\n     合并后的平衡二叉树T3为:  ");
	BraNotationPrint(TT3);
	printf("\n   ==========================================================================");
	printf("\n");
	printf("\n\t\t\t 按回车键查看T1,T2,T3的凹入表...");
	getchar();
	system("CLS");
	InitView();
	printf("\n");
	printf("   ==========================================================================");
	printf("\n\t\t\t       平衡二叉树T1为:\n");
	printf("\t\t\t          \n");
	Print(TT1, 24);
	printf("   ==========================================================================");
	printf("\n\t\t\t       平衡二叉树T2为:\n");
	printf("\t\t\t          \n");
	Print(TT2, 24);
	printf("   ==========================================================================");
	TT3 = Combine2Tree(TT1, TT2);	
	printf("\n\t\t\t    合并后的平衡二叉树T3为:\n");		
	printf("\t\t\t       \n");		
	Print(TT3, 24);
	printf("   ==========================================================================");
	printf("\n\t\t\t    请按任意键返回上一层...");
	getchar();
	system("CLS");
	InitView();
}

/*选项七*/
/*分裂一颗平衡二叉树 */
void item_7(){
    BBSTree Tt1, Tt2, Tt3;
    int x;
    Tt1 = NULL;
    Tt2 = NULL;
    Tt3 = NULL;
   	system("CLS");
	InitView();
	printf("\n\t\t\t       请输入你的选择：7 \n");
	printf("\n\t\t     请输入树的数字序列(按'回车键'结束):\n");
	printf("\t\t\t   ");	
    Tt1 = MakeBBSTree();
	printf("\n\t\t     请输入分割树x的值(按'回车键'结束):");	
    scanf("%d",&x);
    getchar();
	SplitBBSTree(Tt1, Tt2, Tt3, x);    
	system("CLS");
	InitView();
	printf("\n");
	printf("\n   ==========================================================================");
//	printf("\n\t\t\t      分割前的平衡二叉树为:\n");
//	printf("\t\t\t          ");
	printf("\n     分割前的平衡二叉树T1为:  ");
	BraNotationPrint(Tt1);
	printf("\n   ==========================================================================");
//	printf("\n\t\t\t       平衡二叉树T2为:\n");
//	printf("\t\t\t          ");
	printf("\n     分割后小于等于%d的平衡二叉树T2为:  ",x);
	BraNotationPrint(Tt2);
	printf("\n   ==========================================================================");	
//	printf("\n\t\t\t     合并后的平衡二叉书T3:\n");		
//	printf("\t\t\t       ");
	printf("\n     分割后大于%d的平衡二叉树T3为:  ",x);
	BraNotationPrint(Tt3);
	printf("\n   ==========================================================================");
	printf("\n");
	printf("\n\t\t\t 按回车键查看T1,T2,T3的凹入表...");
	getchar();
	system("CLS");
	InitView();
	printf("\n");
	printf("   ==========================================================================");
	printf("\n");
	printf("\n     分割前的平衡二叉树T1为:  ");
	BraNotationPrint(Tt1);	
	printf("\n\n");
	printf("   ==========================================================================");
	printf("\n\t\t\t       分割前的平衡二叉树T1:\n");
	printf("\t\t\t          \n");
	Print(Tt1, 24);
	printf("   ==========================================================================");
	printf("\n");
	printf("\n     分割后小于等于%d的平衡二叉树T2为:  ",x);
	BraNotationPrint(Tt1);	
	printf("\n\n");
	printf("   ==========================================================================");
	printf("\n\t\t\t     分割后小于等于%d的平衡二叉树T2:\n",x);
	printf("\t\t\t          \n");
	Print(Tt2, 24);
	printf("   ==========================================================================");	
	printf("\n");
	printf("\n     分割后大于%d的平衡二叉树T3为:  ",x);
	BraNotationPrint(Tt1);	
	printf("\n\n");
	printf("   ==========================================================================");
	printf("\n\t\t\t     分割后大于%d的平衡二叉树T3:\n",x);		
	printf("\t\t\t       \n");		
	Print(Tt3, 24);
	printf("   ==========================================================================");
	printf("\n\t\t\t    请按任意键返回上一层...");
	getchar();
	system("CLS");
	InitView();
}

/*选项八*/
/*退出*/
void item_8(){
	BBSTree T = NULL;
	char ch;
	int m;
	printf("\n\n");
	printf("\t\t\t  * * * * * * * * * * * * * * *\n");
	printf("\t\t\t  *                           *\n");		
	printf("\t\t\t  *\t    确定退出？        *\n");
	printf("\t\t\t  *                           *\n");	
	printf("\t\t\t  * * * * * * * * * * * * * * *\n");
	printf("\t\t\t  *             *             *\n");	
	printf("\t\t\t  *\t  Y是   *   N否       *\n"); 
	printf("\t\t\t  *             *             *\n");	
	printf("\t\t\t  * * * * * * * * * * * * * * *");
	printf("\n");
	printf("\n\t\t\t           请选择：");
	scanf("%c",&ch);
	getchar();
	while(ch){
		if(ch=='Y'||ch=='y'){
			exit(0);
		}else if(ch=='N'|| ch=='n'){
			system("CLS");
			InitView();
			printf("\n\t\t\t       请输入你的选择：");
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
					printf("\n\t\t\t     输入错误，请重新输入!!\n"); 
				}
				printf("\n\t\t\t       请输入你的选择：");
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
			printf("\t\t\t  *\t    确定退出？        *\n");
			printf("\t\t\t  *                           *\n");	
			printf("\t\t\t  * * * * * * * * * * * * * * *\n");
			printf("\t\t\t  *             *             *\n");	
			printf("\t\t\t  *\t  Y是   *   N否       *\n"); 
			printf("\t\t\t  *             *             *\n");	
			printf("\t\t\t  * * * * * * * * * * * * * * *");
			printf("\n");
			printf("\n\t\t\t       输入错误，请选择：");			
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
	printf("\n\t\t\t       请输入你的选择：");
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
			printf("\n\t\t\t     输入错误，请重新输入!!\n"); 
		}
		printf("\n\t\t\t       请输入你的选择：");
		scanf("%d",&m);
		getchar();	
	}	
	return 0;
}