#include"ϡ�����.h"

int main()
{
	TSMatrix A, B, C;

	printf("��������A: ");
	CreateSMatrix(&A);
	PrintSMatrix(A);

	printf("�ɾ���A���ƾ���B: ");
	CopySMatrix(A, &B);
	PrintSMatrix(B);

	DestroySMatrix(&B);
	printf("���پ���B��:\n");
	PrintSMatrix(B);

	printf("�ؽ�����B:(ע�������A���С�������ͬ�������������Ĳ���"
		"�С��зֱ�Ϊ%d,%d)\n", A.mu, A.nu);
	CreateSMatrix(&B);
	PrintSMatrix(B);

	printf("����C1(A+B): ");
	AddSMatrix(A, B, &C);
	PrintSMatrix(C);
	DestroySMatrix(&C);

	printf("����C2(A-B): ");
	SubtSMatrix(A, B, &C);
	PrintSMatrix(C);
	DestroySMatrix(&C);

	printf("����C3(A��ת��): ");
	TransposeSMatrix(A, &C);
	PrintSMatrix(C);
	DestroySMatrix(&A);
	DestroySMatrix(&B);
	DestroySMatrix(&C);

	printf("��������A2: ");
	CreateSMatrix(&A);
	PrintSMatrix(A);

	printf("��������B3:(����Ӧ�����A2��������ͬ=%d)\n", A.nu);
	CreateSMatrix(&B);
	PrintSMatrix(B);

	printf("����C5(A*B): ");
	MultSMatrix(A, B, &C);
	PrintSMatrix(C);
	DestroySMatrix(&A);
	DestroySMatrix(&B);
	DestroySMatrix(&C);

	printf("��������A: ");
	CreateSMatrix(&A);
	PrintSMatrix(A);

	FastTransposeSMatrix(A, &B);
	printf("����B(A�Ŀ���ת��): ");
	PrintSMatrix(B);

	DestroySMatrix(&A);
	DestroySMatrix(&B);

	system("pause");
	return 0;
}