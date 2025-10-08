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

int main(void)
{
    return 0;
}