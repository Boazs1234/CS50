
#include <cs50.h>
#include <stdio.h>

int calculate_quarters(int cents);
int calculate_dimes(int cents);
int calculate_nickels(int cents);
int calculate_pennies(int cents);

int main(void)
{

    // prompt the question
    int cents;
    do
    {
        cents = get_int(" change owe: ");
    }
    while (cents < 0);

    // calculate quarters
    int quarters = calculate_quarters(cents);
    cents = cents - quarters * 25;

    // calculate dimes
    int dimes = calculate_dimes(cents);
    cents = cents - dimes * 10;

    // calculate nickles
    int nickles = calculate_nickels(cents);
    cents = cents - nickles * 5;

    // calculate pennies
    int pennies = calculate_pennies(cents);
    cents = cents - pennies * 1;

    // sum coins
    int coins = quarters + dimes + nickles + pennies;

    // print coins
    printf("%i\n", coins);
}

// calculate quarters
int calculate_quarters(int cents)
{
    int quarters = 0;

    while (cents >= 25)
    {
        cents = cents - 25;
        quarters++;
    }
    return quarters;
}

// calculate dimes
int calculate_dimes(int cents)
{
    int dimes = 0;

    while (cents >= 10)
    {
        cents = cents - 10;
        dimes++;
    }
    return dimes;
}

// calculate nickels
int calculate_nickels(int cents)
{
    int nickels = 0;

    while (cents >= 5)
    {
        cents = cents - 5;
        nickels++;
    }
    return nickels;
}

// calculate pennies
int calculate_pennies(int cents)
{
    int pennies = 0;

    while (cents >= 1)
    {
        cents = cents - 1;
        pennies++;
    }
    return pennies;
}
