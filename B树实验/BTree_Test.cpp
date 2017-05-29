#include<stdio.h>
#include"BTree.h"

int main() {
	BTree T=NULL;
	result r;
	int choice, k, i, m, n;
	
	do{
		choice = menu();
		if (choice >= 0 && choice <= 7) {
			system("cls");//把菜单清除
			switch (choice) {
			case 1:
				printf("请输入B树的阶数m:(3<=m<=20)\n");
				scanf_s("%d", &m);
				printf("请输入B树的初始化关键字个数:(0<=n<=10000)\n");
				scanf_s("%d", &n);
				CreatBTree(T, n, m);
				break;
			case 2:
				printf("请输入要查找的关键字：\n");
				scanf_s("%d", &k);
				SearchBTree(T, k, r);
				if (r.tag) {
					printf("该关键字的位置为该结点中第%d个关键字\n",r.i);
				}
				else {
					printf("该关键字不存在！\n");
				}
				break;
			case 3:
				printf("请输入要插入的关键字k：\n");
				scanf_s("%d", &k);
				SearchBTree(T, k, r);
				InsertBTree(T, k, (&r)->pt, (&r)->i, m);
				printf("插入成功！\n");
				break;
			case 4:
				printf("请输入要删除B树T上的关键字：\n");
				scanf_s("%d", &i);
				SearchBTree(T, i, r);
				DeleteBTree(r.pt, r.i, m, T);
				printf("删除成功！\n");
				break;
			case 5:
				printf("此时的B树序列为：\n");
				PrintBTree(T);
				printf("\n");
				break;
			case 6:
				DestroyBTree(T);
				printf("销毁成功！\n");
				break;
			default:;
			}
		}
	}while (choice > 0 && choice < 7);
		return 0;
}
