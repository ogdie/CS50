#include <cs50.h>
#include <stdio.h>

int main(void)
{
    char *str = get_string("Qual o seu nome? ");
    printf("Hello, %s\n", str);
    return 0;
}
