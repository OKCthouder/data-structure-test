#include<stdio.h>
#include<malloc.h>
#include<stdlib.h>
#include"������.c" 
int main(void)
     {
         linkqueue ptr;
         int sel;
         int num;
         initqueue(&ptr);
         while(1)
         {
             menu();
             printf("please input command:\n");
             scanf("%d",&sel);
             switch(sel)
             {
             case 1:if(yes==1)
                    {
                        printf("��ʱ���Ѵ���!�����ٴδ���!\n");
                        break;
                    }
                 else
                     creatqueue(&ptr);break;
             case 2:if(yes==0)
                    {
                        printf("��ʱ��δ����!�������!\n");
                        break;
                    }
                 else
                 {
                     printf("������ӵ�Ԫ��ֵ:");
                     scanf("%d",&num);
                         enqueue(&ptr,num);
                     break;
                 }
             case 3:if(yes==0)
                    {
                        printf("��ʱ��Ϊ����!���ܳ���!\n");
                        break;
                    }
                 else
                 {
                     num=dequeue(&ptr,num);
                     printf("Ŀǰ���ӵ�Ԫ����%d",num);
                     break;
                 }
             case 4:if(yes==0)
                    {
                        printf("��ʱ������δ����!�������䳤��!\n");
                        break;
                    }
                 lenqueue(&ptr);
                 break;
             case 5:if(yes==0)
                    {
                        printf("��ʱ��δ����!�����ж��Ƿ�Ϊ��!\n");
                        break;
                    }
                 else
                 {
                     if(queueempty(&ptr))
                         printf("��ʱ����Ϊ�ն���!\n");
                     else

                         printf("��ʱ����Ϊ�ǿն���!\n");

                     break;
                 }
             case 6:if(yes==0)
                    {
                        printf("��ʱ������δ����!�������!\n");
                        break;
                    }
                            disqueue(&ptr);
                            break;
             case 7:if(yes==0)
                    {
                        printf("��ʱ������δ����!��������!\n");
                        break;
                    }
                 destroyqueue(&ptr);
                 printf("���ٳɹ�\n");
                 break;
             case 0:exit(1);break;
             default:printf("�����������!����������:\n");
                 break;
             }
         }
         return OK;
     }
