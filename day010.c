/*
Problem:
Read a string and check if it is a palindrome
using two-pointer comparison.
*/

#include <stdio.h>
#include <string.h>

int main() {
    char str[100];

    printf("Enter the string: ");
    scanf("%s", str);

    int left = 0;
    int right = strlen(str) - 1;
    int isPalindrome = 1;

    // Two-pointer comparison
    while (left < right) {
        if (str[left] != str[right]) {
            isPalindrome = 0;
            break;
        }
        left++;
        right--;
    }

    if (isPalindrome)
        printf("YES\n");
    else
        printf("NO\n");

    return 0;
}
