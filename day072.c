/* Find the first repeated character where the second occurrence has the smallest index. */

#include <stdio.h>
#include <string.h>

int main() {
    char s[1000];
    int hash[256] = {0}; // Saare characters ki frequency store karne ke liye

    printf("Enter the string: ");
    if (scanf("%s", s) != 1) return 0;

    int found = 0;
    for (int i = 0; s[i] != '\0'; i++) {
        // Character ko as an index treat karke count badhao
        hash[(unsigned char)s[i]]++;

        // Agar count 1 se zyada ho gaya, matlab yeh pehla character hai 
        // jiski second occurrence mili hai
        if (hash[(unsigned char)s[i]] > 1) {
            printf("%c\n", s[i]);
            found = 1;
            break;
        }
    }

    if (!found) {
        printf("-1\n");
    }

    return 0;
}