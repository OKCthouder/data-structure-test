#include<stdio.h>
#include<stdlib.h>
#include<malloc.h>
#include "һԪϡ�����ʽ.h"
#include "Դ����.h"

int main() {
	ElemType *e,*e2;
	Poly pa,pb,pc;
	int i;
	int n,length,order;
	//����pa
	printf("\n���������ʽ������\n");
	scanf_s("%d", &n);
	printf("������%d���������ϵ����������˳��\n", n);
	e= (Term*)malloc(n*sizeof(Term));
	for (i = 0; i < n; i++) {
		scanf_s("%f %d", &e[i].coef, &e[i].expn);
	}
	CreatePoly(pa, e, n);
	PrintPoly(pa);

	//����pb
	printf("\n���������ʽ������\n");
	scanf_s("%d", &n);
	printf("������%d���������ϵ����������˳��\n", n);
	e2 = (Term*)malloc(n * sizeof(Term));
	for (i = 0; i < n; i++) {
		scanf_s("%f %d", &e2[i].coef, &e2[i].expn);
	}
	CreatePoly(pb, e2, n);
	PrintPoly(pb);

	menu();//����˵�
	while (1) {
		printf("\n��������Ҫ��������ţ�\n");
		scanf_s("%d", &order);
		switch (order)
		{
		case 1:CreatePoly(pa, e, n); break;
		case 2:PrintPoly(pc); break;
		case 3:length = PolyLength(pa);
			    printf("\nP������Ϊ:%d\n", length); break;
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
		default:printf("�����������!����������:\n");
			break;
		}
	}
	
	return 0;
}