#include <stdio.h>
int main()
{
    int counter = 1;
    while (counter <= 10)
    {
        printf("Current count: %d\n", counter);
        if (counter == 5)
        {
            break; // Exit the loop
        }
        counter++;
    }
    printf("Loop stopped at %d.\n", counter);
    return 0;
}