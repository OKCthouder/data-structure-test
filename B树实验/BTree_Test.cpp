#include<stdio.h>
#include"BTree.h"

int main() {
	BTree T=NULL;
	result r;
	int choice, k, i, m, n;
	
	do{
		choice = menu();
		if (choice >= 0 && choice <= 7) {
			system("cls");//�Ѳ˵����
			switch (choice) {
			case 1:
				printf("������B���Ľ���m:(3<=m<=20)\n");
				scanf_s("%d", &m);
				printf("������B���ĳ�ʼ���ؼ��ָ���:(0<=n<=10000)\n");
				scanf_s("%d", &n);
				CreatBTree(T, n, m);
				break;
			case 2:
				printf("������Ҫ���ҵĹؼ��֣�\n");
				scanf_s("%d", &k);
				SearchBTree(T, k, r);
				if (r.tag) {
					printf("�ùؼ��ֵ�λ��Ϊ�ý���е�%d���ؼ���\n",r.i);
				}
				else {
					printf("�ùؼ��ֲ����ڣ�\n");
				}
				break;
			case 3:
				printf("������Ҫ����Ĺؼ���k��\n");
				scanf_s("%d", &k);
				SearchBTree(T, k, r);
				InsertBTree(T, k, (&r)->pt, (&r)->i, m);
				printf("����ɹ���\n");
				break;
			case 4:
				printf("������Ҫɾ��B��T�ϵĹؼ��֣�\n");
				scanf_s("%d", &i);
				SearchBTree(T, i, r);
				DeleteBTree(r.pt, r.i, m, T);
				printf("ɾ���ɹ���\n");
				break;
			case 5:
				printf("��ʱ��B������Ϊ��\n");
				PrintBTree(T);
				printf("\n");
				break;
			case 6:
				DestroyBTree(T);
				printf("���ٳɹ���\n");
				break;
			default:;
			}
		}
	}while (choice > 0 && choice < 7);
		return 0;
}
