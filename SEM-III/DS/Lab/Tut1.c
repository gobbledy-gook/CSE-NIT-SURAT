#include <stdio.h>
// int main(){
//     printf("Size of int - %lu\n", sizeof(int));
//     printf("Size of Unsigned Int - %lu\n", sizeof(unsigned int));
//     printf("Size of Short Int - %lu\n", sizeof(short int));
//     printf("Size of Unsigned Short Int - %lu\n", sizeof(unsigned short int));
//     printf("Size of long int - %lu\n", sizeof(long int));
//     printf("Size of unsigned long int - %lu\n", sizeof(unsigned long int));
//     printf("Size of float - %lu\n", sizeof(float));
//     printf("Size of double - %lu\n", sizeof(double));
//     printf("Size of long double - %lu\n", sizeof(long double));
//     printf("Size of char - %lu\n", sizeof(char));
//     printf("Size of unsigned char - %lu\n", sizeof(unsigned char));
// }

void change(int *num){
    printf("%p\n", num);
    printf("%p\n", &num);
    (*num) += 100;
    printf("%p\n", num);
    printf("%p\n", &num);
}
int main(){
    int x = 100;
    printf("%d\n", x);
    printf("%p\n", &x);
    change(&x);
    return 0;
}