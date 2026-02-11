

#include <cs50.h>
#include <stdio.h>

int main(void)
{
    int height, row, column, space;

    // prompt the question
    do
    {
        height = get_int("what is the height of the pyramid? ");
    }
    while (height < 1 || height > 8);

    // for each row
    for (row = 0; row < height; row++)
    {
        // space
        for (space = 0; space < height - row - 1; space++)
        {
            printf(" ");
        }

        // hash
        for (column = 0; column <= row; column++)
        {
            printf("#");
        }

        // move line
        printf("\n");
    }
}
