#include <cs50.h>
#include <ctype.h>
#include <stdio.h>
#include <string.h>

int testKey(string key)
{
    if (strlen(key) != 26)
    {
        return 1;
    }

    for (int i = 0; i < strlen(key); i++)
    {
        if (!isalpha(key[i]))
        {
            return 1;
        }
        key[i] = toupper(key[i]);
    }
    for (int k = 0; k < strlen(key); k++)
    {
        for (int j = 0; j < strlen(key); j++)
        {
            if (key[k] == key[j] && k != j)
            {
                return 1;
            }
        }
    }
    return 0;
}

int main(int argc, string argv[])
{
    if (argc != 2)
    {
        printf("Failure\n");
        return 1;
    }
    string text = argv[1];
    if (testKey(text))
    {
        printf("Key must contain 26 chars");
        return 1;
    }


    string plainText = get_string("Plain text: ");
    string cipherText = plainText;
    int j = 0;

    for (int i = 0; i < strlen(plainText); i++)
    {
        if (isalpha(plainText[i]))
        {
            int offset = isupper(plainText[i]) ? 65 : 97;
            cipherText[i] = text[plainText[i] - offset];

            if (islower(plainText[i]))
            {
            cipherText[i] = tolower(cipherText[i]);
            }
        }
        else
        {
            cipherText[i] = plainText[i];
        }
    }
    printf("Cipher Text: %s\n", cipherText);

    return 0;
}
