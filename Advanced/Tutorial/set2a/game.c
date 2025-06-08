#include<stdio.h>

int score(long game);
int consec_strikes(long game);
int pins_felled(long game);

int main()
{
    int sc = score(9999999999);
    printf("Number of pins is %d", pins_felled(8985));
    printf("\nscore is %d", sc);
    printf("\nMax consecutive strikes: %d", consec_strikes(999939459679));

    return 0;
}

int pins_felled(long game)
{
    int result = 0;

    while(game != 0)
    {
        result = result + (game%10);
        game = game / 10;
    }

    return result;
}

int score(long game)
{
    int digitcount = 0, temp = game, result = 0;

    while(temp != 0)
    {
        temp = temp / 10;
        digitcount++;
    }

    int arr[digitcount], i;
    for(i = digitcount;i>0;i--)
    {
        arr[i-1] = game % 10;
        game = game / 10;
    }

    for(i=0;i<digitcount;i++)
    {
        if(arr[i] == 9 && i != digitcount-1) result = result + arr[i] + arr[i+1];
        else result = result + arr[i];
    }

    return result;
}

int consec_strikes(long game)
{
    int cons = 0, flag = 0, max = 0;

    while(game != 0)
    {
        
        if(game % 10 == 9) 
        {
            cons++;
            if(cons > max) max = cons;
        }
        else
        {
            cons = 0;
        }

        game = game / 10;
    }
    return max;
}