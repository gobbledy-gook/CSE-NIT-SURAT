#include <stdio.h>
#include <stdlib.h>
#include <math.h>


void int2bin(int N, int pos){
    int i = 0;
    long int bin = 0, pow=1;
    while(N>0){
        if(N % 2 != 0){
            bin = bin + 1*pow;
        }
        // printf("%ld\n", bin);
        N = N/2;
        pow *= 10;
        i+=1;
    }
    if(pos == 2){
        i = 8 - i;
        while(i--){
            printf("0");
        }
        printf("%ld", bin);
    }
    else if(pos == 3){
        i = 23 - i;
        printf("%ld", bin);
        while(i--){
            printf("0");
        }
    }
}

int main(){
    float in=0, F;
    int s, m=1, e=0, I, f=0, l1=1;
    printf("Enter the decimal number to be displayed in 32 IEEE Format - ");
    scanf("%f", &in);
    I = fabs(in);
    m = I;
    F = fabs(in) - I;

     

    if(in > 0){
        s = 0;
    }
    else{
        s = 1;
    }

    while(I>0){
        I = I/2;
        e+=1;
    }
    e = e-1;

    if(F>0){
       for(int i =0;i<3;i++){
            F *=10.0;
            f = F;
            l1*=10;
        } 
    }
    m = m*l1 + f;
    e = 127 - e;

    printf("%d %d %d\n", s, e, m);
    printf("%d | ",s); 
    int2bin(e, 2);
    printf(" | ");
    int2bin(m, 3);
}

