/*
Problem:
A secret system stores code names in forward order.
Transform the given code name so that its characters
appear in the opposite (mirror) order.
*/

#include <stdio.h>
#include <string.h>

int main() {
    char str[100];

    printf("Enter the code name: ");
    scanf("%s", str);

    int left = 0;
    int right = strlen(str) - 1;

    // Reverse using two-pointer approach
    while (left < right) {
        char temp = str[left];
        str[left] = str[right];
        str[right] = temp;

        left++;
        right--;
    }

    printf("Mirrored code name: %s\n", str);

    return 0;
}
