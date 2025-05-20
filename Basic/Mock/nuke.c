#include<stdio.h>
#include<string.h>

int main()
{
    int max,min,sum,times,num[9],temp2;
    char country[9][9];
    char temp[9],maxC[9],minC[9];

    FILE *indata, *outdata;

    indata = fopen("/Users/kemingliu/Desktop/nukes.txt","r");
    outdata = fopen("/Users/kemingliu/Desktop/superpowers.txt","w");

    if(indata == NULL || outdata == NULL)
    {
        printf("Invalid file");
        return 1;
    }

    times = 0;
    max = 0;
    min = 1000000;
    sum = 0;
    while(fscanf(indata,"%s %d", temp, &temp2) == 2)
    {
        if(temp2 > max) 
        {
            max = temp2;
            strcpy(maxC,temp);
        }

        if(temp2 < min) 
        {
            min = temp2;
            strcpy(minC,temp);
        }

        sum += temp2;

        if(temp2 > 1000) 
        {
            num[times] = temp2;
            strcpy(country[times], temp);
        }
        times++;
    }

    fprintf(outdata,"sum of nukes: %d",sum);
    fprintf(outdata,"\nmean of nukes: %d",sum = sum /times);
    fprintf(outdata,"\nmax nukes: %s (%d)",maxC,max);
    fprintf(outdata,"\nmin nukes: %s (%d)",minC,min);

    fclose(indata);
    fclose(outdata);

    return 0;
}