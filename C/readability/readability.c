#include <cs50.h>
#include <stdio.h>
#include <math.h>
#include <string.h>

int main()
{
    int counter_words = 0;
    int counter_letter = 0;
    int counter_sentence = 0;

    string text = get_string("Text: ");

    for (int i = 0; i < strlen(text); i++)
    {
        if ((text[i] >= 'a' && text[i] <= 'z') || (text[i] >= 'A' && text[i] <= 'Z'))
        {
            counter_letter++;
        }

        counter_words = text[i] == ' ' ? counter_words + 1 : counter_words;
        counter_sentence = (text[i] == '.' || text[i] == '!' || text[i] == '?') ? counter_sentence + 1 : counter_sentence;
    }
    counter_words++;

    float L = (float)counter_letter * 100 / (float)counter_words;
    float S = (float)counter_sentence * 100 / (float)counter_words;
    float index = 0.0588 * L - 0.296 * S - 15.8;

    if (index >= 16)
    {
        printf("Grade 16+\n");
    }
    else
    {
        if (index <= 1)
        {
            printf("Before grade 1\n");
        }
        else
        {
            printf("Grade %i\n", (int)round(index));
        }
    }
    return 0;
}
