#include<stdio.h>
#include<stdlib.h>
#define seed 11

typedef struct card
{
    int rank;
    int suit;
}card;

void swap(card a, card b);
void shuffling(card deck[]);

int main()
{
    card deck[52];


}

void shuffling(card deck[])
{
    srand(seed);
    int i, tar;

    for(i=0;i<51;i++)
    {
        tar = rand() % (51 - i) + i + 1;

        swap(deck[i], deck[tar]);
    }
}

