/*
Problem:
Given integers a and b, compute a^b using recursion
without using the pow() function.
*/

#include <stdio.h>

// Recursive function to calculate power
int power(int a, int b) {
    if (b == 0)
        return 1;          // Base case: a^0 = 1

    return a * power(a, b - 1);
}

int main() {
    int a, b;

    printf("Enter values of a and b: ");
    scanf("%d %d", &a, &b);

    printf("Result = %d\n", power(a, b));

    return 0;
}
