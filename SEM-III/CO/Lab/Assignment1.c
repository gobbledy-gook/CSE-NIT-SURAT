#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include "u21cs089.h"

int main(){
    float num;
    int i =0, F, m=0;
    char bin[100], bin1[100], bin2[100];
    char dot;

    // printf("\nEnter decimal to convert to binary - \n");
    // scanf("%f", &num);
    // intToBin(num);

    // printf("\nEnter the binary to convert to decimal - \n");
    // gets(bin);
    // printf("%f", binToInt(bin));

    // printf("\nEnter the number to find factorial - ");
    // scanf("%d", &F);
    // printf("%d", fact(F));5


    // printf("\nEnter two unsigned binary number: \n");
    // printf("\n1st no. >> ");
    // gets(bin1);
    // printf("\n2nd no. >> ");
    // gets(bin2);
    // addition_unsigned_binary_numbers_U22CS089(bin1, bin2);

    printf("\nEnter two signed binary number: \n");
    printf("\n1st no. >> ");
    gets(bin1);
    printf("\n2nd no. >> ");
    gets(bin2);
    addition_signed_binary_numbers_U22CS089(bin1, bin2);
}