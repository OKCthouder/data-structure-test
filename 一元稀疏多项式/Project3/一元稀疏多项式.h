#include<stdio.h>
#include<stdlib.h>
#include<malloc.h>
#define OK 1
#define FLASE 0
#define OVERFLOW -1
typedef int Status;

/*typedef struct {
	float coef; //系数
	int expn;  //指数
}ElemType, Term;

typedef struct {
	Term *elem;  //存储空间基址
	int length;  //长度
}Poly;*/

	/*
	//接口定义
	Status CreatePoly(Poly &P, Term e[], int n);
	//有数组e的前n项构建一元稀疏多项式P
	Status DestroyPoly(Poly &P);//销毁一元稀疏多项式P
	Status PrintPoly(Poly P);//打印输出一元稀疏多项式P
	int PolyLength(Poly P);//一元稀疏多项式P存在，则返回P中的项数
	Status AddPoly(Poly pa, Poly pb, Poly &pc);
	//两个一元稀疏多项式做加法，即pc = pa + pb
	Status SubPoly(Poly pa, Poly pb, Poly &pc);
	//两个一元稀疏多项式做减法，即pc = pa - pb
	Status MulPoly(Poly pa, Poly pb, Poly &pc);
	//两个一元稀疏多项式做乘法，即pc = pa * pb
	Status DivPoly(Poly pa, Poly pb, Poly &pc);
	//两个一元稀疏多项式做除法，即pc = pa / pb
	*/