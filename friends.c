#include <cs50.h>
#include <stdio.h>

int main(void)
{
    // name
    string name = get_string("what is your name? ");

    // age
    int age = get_int("what is your age? ");

    // hometown
    string hometown = get_string("what is your home town? ");

    // phone number
    string number = get_string("what is your phone number? ");

    printf("My new friend's name is %s, %i, they are from %s and their phone number is %s\n", name, age, hometown, number );
}
