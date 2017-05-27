#include<stdio.h>
#include<stdlib.h>
#include<malloc.h>
#include "一元稀疏多项式.h"
#include "源代码.h"

int main() {
	ElemType *e,*e2;
	Poly pa,pb,pc;
	int i;
	int n,length,order;
	//建立pa
	printf("\n请输入多项式的项数\n");
	scanf_s("%d", &n);
	printf("请输入%d个项，按照先系数后项数的顺序：\n", n);
	e= (Term*)malloc(n*sizeof(Term));
	for (i = 0; i < n; i++) {
		scanf_s("%f %d", &e[i].coef, &e[i].expn);
	}
	CreatePoly(pa, e, n);
	PrintPoly(pa);

	//建立pb
	printf("\n请输入多项式的项数\n");
	scanf_s("%d", &n);
	printf("请输入%d个项，按照先系数后项数的顺序：\n", n);
	e2 = (Term*)malloc(n * sizeof(Term));
	for (i = 0; i < n; i++) {
		scanf_s("%f %d", &e2[i].coef, &e2[i].expn);
	}
	CreatePoly(pb, e2, n);
	PrintPoly(pb);

	menu();//输出菜单
	while (1) {
		printf("\n请输入你要操作的序号：\n");
		scanf_s("%d", &order);
		switch (order)
		{
		case 1:CreatePoly(pa, e, n); break;
		case 2:PrintPoly(pc); break;
		case 3:length = PolyLength(pa);
			    printf("\nP的项数为:%d\n", length); break;
		case 4:AddPoly(pa, pb, pc);
				PrintPoly(pc); break;
		case 5:SubPoly(pa, pb, pc);
				PrintPoly(pc); break;
		case 6:MulPoly(pa, pb, pc);
				PrintPoly(pc); break;
		case 7:DivPoly(pa, pb, pc); 
				PrintPoly(pc); break;
		case 8:DestroyPoly(pc); break;
		case 0:exit(1); break;
		default:printf("输入命令错误!请重新输入:\n");
			break;
		}
	}
	
	return 0;
}