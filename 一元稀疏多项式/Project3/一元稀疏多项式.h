#include<stdio.h>
#include<stdlib.h>
#include<malloc.h>
#define OK 1
#define FLASE 0
#define OVERFLOW -1
typedef int Status;

/*typedef struct {
	float coef; //ϵ��
	int expn;  //ָ��
}ElemType, Term;

typedef struct {
	Term *elem;  //�洢�ռ��ַ
	int length;  //����
}Poly;*/

	/*
	//�ӿڶ���
	Status CreatePoly(Poly &P, Term e[], int n);
	//������e��ǰn���һԪϡ�����ʽP
	Status DestroyPoly(Poly &P);//����һԪϡ�����ʽP
	Status PrintPoly(Poly P);//��ӡ���һԪϡ�����ʽP
	int PolyLength(Poly P);//һԪϡ�����ʽP���ڣ��򷵻�P�е�����
	Status AddPoly(Poly pa, Poly pb, Poly &pc);
	//����һԪϡ�����ʽ���ӷ�����pc = pa + pb
	Status SubPoly(Poly pa, Poly pb, Poly &pc);
	//����һԪϡ�����ʽ����������pc = pa - pb
	Status MulPoly(Poly pa, Poly pb, Poly &pc);
	//����һԪϡ�����ʽ���˷�����pc = pa * pb
	Status DivPoly(Poly pa, Poly pb, Poly &pc);
	//����һԪϡ�����ʽ����������pc = pa / pb
	*/