#include <stdlib.h>
#include <stdio.h>

// ashr(int A[], int Q[], int Qn1, int N){

// }

void comp(int B[], int len){
    int i=0;
    while(i<=len){
        if(B[i] == 0){
            B[i] = 1;
        }
        else{
            B[i] = 0;
        }
        i++;
    }
    i=0;
    while(i<=len){
        if(B[i] == 0){
            B[i] = 1;
            break;
        }
        else{
            B[i] = 0;
        }
        i++;
    }
}

void bin_add(int A[], int B[], int len){
    int carr = 0;
    for(int i=0;i<=len;i++){
        if((A[i] == 0 && B[i] == 1)||(A[i] == 1 && B[i] == 0)){
            if(carr == 0){
                A[i] = 1;
            }
            else{
                A[i] = 0;
                carr = 1;
            }
        }
        else if(A[i] == 1 && B[i] == 1){
            if(carr == 0){
                A[i] = 0;
                carr = 1;
            }
            else{
                A[i] = 1;
                carr = 1;
            }
        }
        else{
            if(carr == 0){
                A[i] = 0;
            }
            else{
                A[i] = 1;
            }
        }
    }
}

int int_to_bin(int n, int B[]){
    int m, i=0;
    m = abs(n);
    while(m>0){
        B[i] = m%2;
        // printf("%d ", B[i]);
        m = m /2;
        i++;
    }
    B[i] = 0;
    return i;
}

void padding(int bin[], int oglen, int extralen){
    int zeroes = extralen - oglen;
    for(int i=oglen;i<=extralen;i++){
        bin[i] = 0;
    }
}

void print(int bin[], int len){
    int i=len;
    while(i>=0){
        printf("%d ", bin[i]);
        i--;
    }
    // printf("%d", bin[i]);
    printf("\n");
}

int main(){
    int N, SC, *Qn, Qn1, m1, m2, l1, l2;
    int A[10], Q[10], B[10], B_[10];
    printf("Enter Multiplicand - ");
    scanf("%d", &m1);
    printf("Enter Multiplier - ");
    scanf("%d", &m2);

    l1 = int_to_bin(abs(m1),B);
    int_to_bin(abs(m1), B_);
    l2 = int_to_bin(abs(m2),Q);
 
    // Setting SC
    if(abs(m1) > abs(m2)){
        N = l1;
        padding(Q, l2, l1);
    }
    else{
        N = l2;
        padding(B, l1, l2);
        padding(B_, l1, l2);
    }
    SC = N;

    // printf("Multiplicand - ");
    // print(B, N);
    // printf("Multiplier - ");
    // print(Q, N);

    // Setting A to 0 & Qn1 to 0
    for(int i=0;i<=SC;i++){
        A[i] = 0;
    }
    Qn1 = 0;
    Qn = &Q[0];

    // Taking Complement
    comp(B_, N);
    if(m1 < 0){
        comp(B, N);
        comp(B_, N);
    }
    if(m2 < 0){
        comp(Q, N);
    }

    // ---------------------
    printf("Multiplicand(B) - ");
    print(B, N);
    printf("Complement of B - ");
    print(B_, N);
    printf("Multiplier(Q) - ");
    print(Q, N);

    // -----------------------
    while(SC--){
        if(*Qn == 0 & Qn1 == 1){
            bin_add(A, B, N);
            printf("A <- A + B: ");
            print(A, N);
        }
        else if(*Qn == 1 & Qn1 == 0){
            bin_add(A, B_, N);
            printf("A <- A + B' + 1");
            print(A, N);
        }
        ashr(A, Q, Qn1, N);
    }
    if()

}
