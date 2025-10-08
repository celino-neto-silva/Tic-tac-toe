#include<stdio.h>
#include<stdlib.h>

char table[3][3];

void create_table()
{
    int value_ascii = 49;
    for(int i = 0; i < 3; i++)
    {
        for(int j = 0; j < 3; j++)
        {
            table[i][j] = (char) value_ascii;
            value_ascii++;
        }
    }
}

void show_table()
{
    for(int i = 0; i < 3; i++)
    {
        for(int j = 0; j < 3; j++)
        {
            printf("|   %c  ", table[i][j]);
        }
        printf("|");
        printf("\n");
        printf("----------------------\n");
    }
}

void game()
{
    create_table();
    int c = 0;
    char symbol;

    while(1)
    {
        symbol = (c % 2 == 0) ? 'X' : 'O';
        show_table();
        jogada(symbol);
        system("cls");
        c++;
        if(c == 5)
            break;
    }
}

int main(void)
{
    game();
    return 0;
}