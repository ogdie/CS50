#include <stdio.h>
#include <cs50.h>

int main(void)
{
    int input;
    do
    {
        input = get_int("Digite o tamanho da pirâmide: ");
    }
    while (input < 1 || input > 8);

    for (int i = 0; i < input; i++)
    {
        for (int j = 0; j < input; j++)
        {
            if (input - i - 2 < j)
            {
                printf("#");
            }
            else
            {
                printf(" ");
            }
        }
        printf("\n");
    }
}
