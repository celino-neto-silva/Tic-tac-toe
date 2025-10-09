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

char check_winner()
{
    char check = '\0';

    while(1)
    {
        for(int i = 0; i < 3; i++)
        {
            if(table[i][0] == table[i][1] & table[i][1] == table[i][2])
            {
                check = table[i][0];
                break;
            }
        }

        if(check == 'X' || check == 'O')
        {
            break;
        }

        for(int i = 0; i < 3; i++)
        {
            if(table[0][i] == table[1][i] & table[1][i] == table[2][i])
            {
                check = table[0][i];
                break;
            }
        }

        if(check == 'X' || check == 'O')
        {
            break;
        }

        for(int i = 0; i < 3; i++)
        {
            if(table[0][0] == table[1][1] & table[1][1] == table[2][2])
            {
                check = table[0][0];
                break;
            }
        }

        if(check == 'X' || check == 'O')
        {
            break;
        }

        for(int i = 0; i < 3; i++)
        {
            if(table[0][2] == table[1][1] & table[1][1] == table[2][0])
            {
                check = table[0][2];
                break;
            }
        }

        if(check == 'X' || check == 'O')
        {
            break;
        }
        else
        {
            break;
        }
    }
    return check;
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
        if(c > 4)
        {
            char winner = check_winner();

            if(winner == 'X' || winner == 'O')
            {
                printf("Jogador %c! O vencedor\n", winner);
                break;
            }
        }
        else if(c == 9)
        {
            printf("Velha!\n");
            break;
        }
        c++;
    }
}

int main(void)
{
    game();
    return 0;
}
