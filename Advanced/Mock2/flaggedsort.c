#include<stdio.h>
#include<stdlib.h>
#include<string.h>

struct book
{
    char callnum[16];//字符串留一个位置给'\0'
    char name[41];
    char isbn[13];
    int quantity;
    double price;
};

struct book *bk[10000];
int count = 1000;

void sort(struct book *bk[])
{
    int i, flag = 1;
    struct book *temp;

    while(flag)
    {
        flag =0;
        for(i=0;i<count-1;i++)
        {
            if(strcmp(bk[i]->callnum , bk[i+1]->callnum) > 0)
            {
                temp = bk[i];
                bk[i] = bk[i+1];
                bk[i+1] = temp;
                flag = 1;
            }
        }

        count--;
    }
}