#include "mystring.h"
#include <stdio.h>


int main(){
    char a[100], b[100], c[100];
    printf("\nEnter the string - ");
    gets(a);
    printf("\nLength of the array - %d\n", length(a));
    printf("\nEnter the 2nd String - ");
    gets(b);
    printf("\nConcatenated String - %s\n", concat(a, b));
    printf("\nCopied String: %s\n", copy(c, b));
    printf("\nComparing : %s | %s : %d\n", a, b, cmp(a,b));
    printf("\nIndex of 'c': %d\n", src(a, length(a)));
    printf("\nFinding 2nd string in 1st string String - ");
    substr(a,b);
    printf("\nReversed 1st string - ");
    reverse(a);
    printf("\n* with Vowel & # with Consonants - \n%s", trans(a));
}