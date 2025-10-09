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

char validate(char position)
{
    char check = 'N';

    for(int i = 0; i < 3; i++)
    {
        for(int j = 0; j < 3; j++)
        {
            if(position == table[i][j])
            {
                check = 'S';
            }
        }
    }

    return check;
}

void insert_table(char position, char symbol)
{
    for(int i = 0; i < 3; i++)
    {
        for(int j = 0; j < 3; j++)
        {
            if(table[i][j] == position)
            {
                table[i][j] = symbol;
            }
        }
    }
}

char jogada(char symbol)
{
    char position;

    do
    {
        printf("Jogador [%c]: ", symbol);
        scanf(" %c", &position);
    }while(validate(position) == 'N');

    return position;
}

void game()
{
    create_table();
    int c = 0;
    char position;
    char symbol;

    while(1)
    {
        symbol = (c % 2 == 0) ? 'X' : 'O';
        show_table();
        position = jogada(symbol);
        insert_table(position, symbol);
        system("clear");
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
