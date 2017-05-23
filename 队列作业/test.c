#include<stdio.h>
#include<malloc.h>
#include<stdlib.h>
#include"链队列.c" 
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
                        printf("此时表已创建!不能再次创建!\n");
                        break;
                    }
                 else
                     creatqueue(&ptr);break;
             case 2:if(yes==0)
                    {
                        printf("此时表未创建!不能入队!\n");
                        break;
                    }
                 else
                 {
                     printf("请输入队的元素值:");
                     scanf("%d",&num);
                         enqueue(&ptr,num);
                     break;
                 }
             case 3:if(yes==0)
                    {
                        printf("此时表为创建!不能出队!\n");
                        break;
                    }
                 else
                 {
                     num=dequeue(&ptr,num);
                     printf("目前出队的元素是%d",num);
                     break;
                 }
             case 4:if(yes==0)
                    {
                        printf("此时链队列未创建!不能求其长度!\n");
                        break;
                    }
                 lenqueue(&ptr);
                 break;
             case 5:if(yes==0)
                    {
                        printf("此时表未创建!不能判断是否为空!\n");
                        break;
                    }
                 else
                 {
                     if(queueempty(&ptr))
                         printf("此时队列为空队列!\n");
                     else

                         printf("此时队列为非空队列!\n");

                     break;
                 }
             case 6:if(yes==0)
                    {
                        printf("此时链队列未创建!不能输出!\n");
                        break;
                    }
                            disqueue(&ptr);
                            break;
             case 7:if(yes==0)
                    {
                        printf("此时链队列未创建!不能销毁!\n");
                        break;
                    }
                 destroyqueue(&ptr);
                 printf("销毁成功\n");
                 break;
             case 0:exit(1);break;
             default:printf("输入命令错误!请重新输入:\n");
                 break;
             }
         }
         return OK;
     }
