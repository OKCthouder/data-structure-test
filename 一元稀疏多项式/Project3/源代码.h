#include "一元稀疏多项式.h"

typedef struct {
	float coef; //系数
	int expn;  //指数
}ElemType, Term;

typedef struct {
	Term *elem;  //存储空间基址
	int length;  //长度
}Poly;

//构建一元稀疏多项式
Status CreatePoly(Poly &P, Term e[], int n) {
	int i;
	P.elem = (Term*)malloc(sizeof(Term)*n);
	if (NULL == P.elem) return OVERFLOW;
	for (i = 0; i < n; i++) P.elem[i] = e[i];
	P.length = n;
	return OK;
}


//销毁一元稀疏多项式P
Status DestroyPoly(Poly &P) {
	if (P.elem == NULL)
		return OVERFLOW;
	else
		free(P.elem);
	printf("\n销毁成功\n");
	return OK;
}

//打印输出一元稀疏多项式P
Status PrintPoly(Poly P) {
	int i;
	printf("多项式:");
	for (i = 0; i < P.length; i++) {
		if (i == P.length - 1)
			printf("%4.2fx^%d\n", P.elem[i].coef, P.elem[i].expn);
		else
			printf("%4.2fx^%d + ", P.elem[i].coef, P.elem[i].expn);
		
	}
	return OK;
}

//一元稀疏多项式P存在，则返回P中的项数
int PolyLength(Poly P) {
	return P.length;
}

//实现一元稀疏多项式加法
Status AddPoly(Poly pa, Poly pb, Poly &pc) {//两个一元稀疏多项式做加法，即pc=pa+pb
	int i = 0, j = 0, k = 0;
	float c;
	pc.elem = (Term*)malloc((pa.length + pb.length) * sizeof(Term));
	if (NULL == pc.elem) return OVERFLOW;
	while (i < pa.length&&j < pb.length) {//两个多项式均未处理结束
		if (pa.elem[i].expn < pb.elem[j].expn)//pa项的指数较小，添加pc
			pc.elem[k++] = pa.elem[i++];
		else if (pa.elem[i].expn > pb.elem[j].expn)//pb项的指数较小，添加到pc
			pc.elem[k++] = pb.elem[j++];
		else {//pa，pb指数相等
			c = pa.elem[i].coef + pb.elem[j].coef;//系数相加
			if (c != 0) {//系数和不为0，构建和项，并添加到pc
				pc.elem[k].expn = pa.elem[i].expn;
				pc.elem[k].coef = c;
				k++;
			}
			i++;
			j++;//pa和pb均取下一项
		}
	}
	if (i == pa.length)//pa已处理完，将pb剩余部分添加到pc
		while (j < pb.length)
			pc.elem[k++] = pb.elem[j++];
	if (j == pb.length)//pb已处理完，将pa剩余部分加到pc
		while (i < pa.length)
			pc.elem[k++] = pa.elem[i++];
	if (k < pa.length + pb.length)
		if (NULL == (pc.elem = (Term*)realloc(pc.elem, k * sizeof(Term))))
			return OVERFLOW;
	pc.length = k;
}

//两个一元稀疏多项式做减法，即pc = pa - pb
Status SubPoly(Poly pa, Poly pb, Poly &pc) {//两个一元稀疏多项式做减法，即pc=pa-pb
	int i = 0, j = 0, k = 0;
	float c;
	pc.elem = (Term*)malloc((pa.length + pb.length) * sizeof(Term));
	if (NULL == pc.elem) return OVERFLOW;
	while (i < pa.length&&j < pb.length) {//两个多项式均未处理结束
		if (pa.elem[i].expn < pb.elem[j].expn)//pa项的指数较小，添加pc
			pc.elem[k++] = pa.elem[i++];
		else if (pa.elem[i].expn > pb.elem[j].expn)//pb项的指数较小，添加到pc
			pc.elem[k++] = pb.elem[j++];
		else {//pa，pb指数相等
			c = pa.elem[i].coef - pb.elem[j].coef;//系数相减
			if (c != 0) {//系数和不为0，构建和项，并添加到pc
				pc.elem[k].expn = pa.elem[i].expn;
				pc.elem[k].coef = c;
				k++;
			}
			i++;
			j++;//pa和pb均取下一项
		}
	}
	if (i == pa.length)//pa已处理完，将pb剩余部分添加到pc
		while (j < pb.length)
			pc.elem[k++] = pb.elem[j++];
	if (j == pb.length)//pb已处理完，将pa剩余部分加到pc
		while (i < pa.length)
			pc.elem[k++] = pa.elem[i++];
	if (k < pa.length + pb.length)
		if (NULL == (pc.elem = (Term*)realloc(pc.elem, k * sizeof(Term))))
			return OVERFLOW;
	pc.length = k;
}

//两个一元稀疏多项式做乘法，即pc = pa * pb
Status MulPoly(Poly pa, Poly pb, Poly &pc) {//两个一元稀疏多项式做乘法，即pc=pa*pb
	int i = 0, j = 0, k = 0, m = 0;
	int flag;
	float c;
	Poly temp;
	temp.elem = (Term*)malloc((pa.length*pb.length) * sizeof(Term));
	pc.elem = (Term*)malloc((pa.length*pb.length) * sizeof(Term));
	if (NULL == pc.elem || NULL == temp.elem)
		return OVERFLOW;
	while (i < pa.length) {
		while (j < pb.length) {//pa中的每一项去乘于pb中的每一项
			temp.elem[k].coef = (pa.elem[i].coef) * (pb.elem[j].coef);//系数相乘
			temp.elem[k].expn = (pa.elem[i].expn) + (pb.elem[j].expn);//指数相加
			k++;
			j++;//指向下一项
		}
		i++;
		j = 0;//将j重新赋值为0
	}
	while (j < k) {//将一元稀疏多项式temp中可合并的项合并赋给pc
		flag = 1;
		if (temp.elem[j].coef == 0) {
			j++;
			continue;
		}
		i = j + 1;//i指向j的下一项
		while (i < k) {
			if (temp.elem[j].expn == temp.elem[i].expn) {//如果指数相同，则将系数相加
				c = temp.elem[j].coef + temp.elem[i].coef;
				if (c != 0) {//如果系数和不为0，则构建和项，并添加到pc
					pc.elem[m].expn = temp.elem[j].expn;
					pc.elem[m].coef = c;
					temp.elem[i].coef = 0;
					m++;
					flag = 0;
				}
			}
			i++;
		}
		if (flag) 
			pc.elem[m++] = temp.elem[j];
			j++;	
	}
	if (m < pa.length*pb.length)
		if (NULL == (pc.elem = (Term*)realloc(pc.elem, m * sizeof(Term))))
			return OVERFLOW;
	pc.length = m;
	free(temp.elem);
	return OK;
}


//两个一元稀疏多项式做除法，即pc = pa / pb
Status DivPoly(Poly pa, Poly pb, Poly &pc) {//两个一元稀疏多项式做除法，即pc=pa/pb
	int i = 0, j = 0, k = 0, m = 0;
	float c = 0;
	int flag;
	Poly temp;
	temp.elem = pc.elem = (Term*)malloc((pa.length*pb.length) * sizeof(Term));
	if (NULL == pc.elem || NULL == temp.elem)
		return OVERFLOW;
	while (i < pa.length) {
		while (j < pb.length) {//pa中的每一项去除于pb中的每一项
			temp.elem[k].coef = pa.elem[i].coef / pb.elem[j].coef;//系数相除
			temp.elem[k].expn = pa.elem[i].expn - pb.elem[j].expn;//指数相减
			k++;
			j++;//指向下一项
		}
		i++;
		j = 0;//将j重新赋值为0
	}
	while (j < k) {//将一元稀疏多项式temp中可合并的项合并赋给pc
		flag = 1;
		if (temp.elem[j].coef == 0) {
			j++;
			continue;
		}
		i = j + 1;//i指向j的下一项
		while (i<k) {
			if (temp.elem[j].expn == temp.elem[i].expn) {//如果指数相同，则将系数相加
				c = temp.elem[j].coef + temp.elem[i].coef;
				if (c != 0) {//如果系数和不为0，则构建和项，并添加到pc
					pc.elem[m].expn = temp.elem[j].expn;
					pc.elem[m].coef = c;
					m++;
					flag = 0;
				}
			}
			i++;
		}
		if(flag)
		pc.elem[m++] = temp.elem[j];
		j++;
	}
	if (m < pa.length*pb.length)
		if (NULL == (pc.elem = (Term*)realloc(pc.elem, m * sizeof(Term))))
			return OVERFLOW;
	pc.length = m;
	return OK;
}

void menu()  //菜单 
{
	printf("        一元稀疏多项式试验统一界面          \n");
	printf("********************************************\n");
	printf("1 建立一元稀疏多项式!                      *\n");
	printf("2 打印输出一元稀疏多项式                   *\n");
	printf("3 返回一元稀疏多项式P中的项数              *\n");
	printf("4 两个一元稀疏多项式做加法                 *\n");
	printf("5 两个一元稀疏多项式做减法                 *\n");
	printf("6 两个一元稀疏多项式做乘法                 *\n");
	printf("7 两个一元稀疏多项式做除法                 *\n");
	printf("8 销毁一元稀疏多项式!                      *\n");
	printf("0 退出!                                    *\n");
	printf("********************************************\n");
}