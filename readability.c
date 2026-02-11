
#include <cs50.h>
#include <ctype.h>
#include <math.h>
#include <stdio.h>
#include <string.h>

#define COLEMAN_LIAU_L 0.0588
#define COLEMAN_LIAU_S 0.296
#define COLEMAN_LIAU_CONST 15.8

int main(void)
{
    // Prompt the user for some text
    string text = get_string("Text: ");

    // Count letters, words, and sentences
    int letters = 0, words = 1, sentences = 0;

    for (int i = 0, n = strlen(text); i < n; i++)
    {
        if (text[i] == ' ')
        {
            words++;
        }
        else if (text[i] == '.' || text[i] == '?' || text[i] == '!')
        {
            sentences++;
        }
        else if (isalpha(text[i]))
        {
            letters++;
        }
    }

    // Compute the Coleman-Liau index
    int index = (int) round(COLEMAN_LIAU_L * letters / words * 100 -
                            COLEMAN_LIAU_S * sentences / words * 100 - COLEMAN_LIAU_CONST);

    // Print the grade level
    if (index < 1)
    {
        printf("Before Grade 1\n");
    }
    else if (index >= 16)
    {
        printf("Grade 16+\n");
    }
    else
    {
        printf("Grade %d\n", index);
    }
}
