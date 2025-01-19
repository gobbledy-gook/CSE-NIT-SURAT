// Q1
// #include <stdio.h>
// float power(float x, float y);

// int main(){
//     float x, y, a;
//     printf("\nEnter the base: ");
//     scanf("%f", &x);
//     printf("\nEnter the power: ");
//     scanf("%f", &y);
//     a = power(x, y);
//     printf("%f to the power of %f is %f", x, y, a);
// }

// float power(float x, float y){
//     if (y == 0){
//         return 1;
//     }
//     else{
//         return x*power(x, y-1);
//     }
// }

// Q2
// #include <stdio.h>
// void matrix_diagonal(int n);

// void matrix_diagonal(int n){
//     int i, j;
//     float m[n][n], sumD = 0;
//     for(i=0;i<n;i++){
//         for(j = 0;j<n;j++){
//             scanf("%f", &m[i][j]);
//             if(i==j){
//                 sumD += m[i][j];
//             }
//         }
//     }
//     printf("Sum of the main diagonal is %f", sumD);
// }

// int main(){
//     int n;
//     printf("Enter the order of the matrix - ");
//     scanf("%d", &n);
//     matrix_diagonal(n);
// }

// Q3
// #include <stdio.h>
// #include <string.h>

// void insertWord(char str1[], char word[], int p){
//     int a = 0, i=0, j=0;
//     char str2[100];
//     while(i!=(p-1)){
//         str2[i] = str1[i];
//         i+=1;
//     }
//     if (((str1[p-1]) == ' ') || ((str1[p-1]) == '\0')){
//         str2[i] = ' ';
//         i+=1;
//     }

//     while(word[j] != '\0'){
//         str2[i] = word[j];
//         j+=1;
//         i+=1;
//         a+=1;
//     }
//     str2[i] = ' ';
//     j = i;
//     j+=1;
//     i-=a;
//     while(str1[i] != '\0'){
//         str2[j] = str1[i];
//         j+=1;
//         i+=1;
//     }
//     str2[j] = '\0';
//     printf("\n%s", str2);

// }

// int main(){
//     int p;
//     char str1[100], word[100];
//     printf("\nEnter the string - \n");
//     gets(str1);
//     printf("\nEnter the word to insert - ");
//     scanf("%s", word);
//     printf("\nEnter the position - ");
//     scanf("%d", &p);
//     insertWord(str1, word, p);
// }

// Q4
// #include <stdio.h>
// #include <math.h>
// void reversify(long long int number, int n);
// int main()
// {
//     long long int num;
//     printf("Enter the number:");
//     scanf("%lld", &num);

//     int N;
//     printf("Enter the N:");
//     scanf("%d", &N);
//     reversify(num, N);
//     // printf("\n Final - %d", result);
// }
// void reversify(long long int number, int n)
// {
//     long long int num = number/pow(10, n);
//     num*= pow(10,n);
//     long long int rem = number - num;
//     long long int rem1 =0;
//     for(int i=(n-1);rem>0;i--){
//         int k=0;
//         k = rem%10;
//         k=k*pow(10, i);
//         rem1 += k;
//         rem = rem/10;
//     }
//     num += rem1;
//     printf("%lld", num);
// }

// Q5
// #include <stdio.h>
// int series(int x);
// int main()
// {
//     int a;
//     printf("Enter the number of terms in series:");
//     scanf("%d", &a);
//     printf("The value of the given series is:%d", series(a));
//     return 0;
// }
// int series(int x)
// {
//     int i, j = 1, fact = 1;
//     for (int i = 2; i <= x; i++)
//     {
//         fact = fact * (i);
//         j = j + (fact / i);
//     }

//     return j;
// }

// Q6
#include <stdio.h>
int *max_min(int array[], int z);
int main()
{

    int i, n;
    int arr[100];
    int *p;
    printf("Enter the number of input values:");
    scanf("%d", &n);
    printf("The input values are below:\n");
    for (i = 0; i < n; i++)
    {
        scanf("%d", &arr[i]);
    }
    p = max_min(arr, n);

    printf("The maximum value of all is: %d\n", p[0]);
    printf("The minimum value of all is: %d", p[1]);
}
int *max_min(int array[], int z)
{
    int i;
    static int mm[2];
    mm[0] = array[0];
    mm[1] = array[0];
    for (i = 1; i < z; i++)
    {
        if (mm[0] < array[i])
        {
            mm[0] = array[i];
        }
        if (mm[1] > array[i])
        {
            mm[1] = array[i];
        }
    }
    return &mm[0];
}