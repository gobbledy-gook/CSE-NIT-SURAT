//Q1
// #include <stdio.h>
// int main(){
// 	int i, n, sum=1, k;
// 	printf("Enter no. of terms - ");
// 	scanf("%d", &n);
// 	for (i=2; i<=n; i++){
// 		if (i%2 == 0){
// 			k = 1;
// 		}
// 		else{
// 			k = -1;
// 		}
// 		sum = sum + k*i*i;		
// 	}
// 	printf("Sum of series 1 + 4 - 9 + 16 - 25 + 36 + n^2(-1)^n upto %d terms is %d", n, sum);
// }

//Q1-b
// #include <stdio.h>
// int main(){
// 	int i, n, sum=0;
// 	printf("Enter no. of terms - ");
// 	scanf("%d", &n);
// 	for (i=1; i<=n; i++){
// 		sum = sum + i*i;
// 	}
// 	printf("Sum of series: 1^2 + 2^2 + 3^2 + 4^2 + ... + n^2 upto %d terms is %d", n, sum);
// }

//Q1-c
// #include <stdio.h>
// int main(){
// 	int i, j, t, n, k=1;
// 	float x, fact=1, sum=0;
// 	printf("Enter no. of terms (n) - ");
// 	scanf("%d", &n);
// 	printf("Enter the value of x - ");
// 	scanf("%f", &x);
// 	for(i=1; i<=n; i++){
// 		t = 2*i - 1;
// 		for(j=1; j<t; j++){
// 			x = x*x;
// 			fact = fact*(j+1);
// 		}
// 		sum += k*(x/fact);
// 		k = k*(-1);
// 	}
// 	printf("Sum of Series: x - x^3/3! + x^5/5! - x^7/7! + x^9/9! upto %d terms is %f", n, sum);
// }


//Q1-d
// #include <stdio.h>
// int main(){
// 	int i;
// 	float num, num1, num2 = 0;
// 	printf("Enter a number to check if its Armstrong or Not - ");
// 	scanf("%f", &num);
// 	num1 = num;
// 	for (i=num1; i>0; i = num1){
// 		i = i%10;
// 		num2 = num2 + i*i*i;
// 		num1 = num1/10;
// 	}
// 	if (num2 == num){
// 		printf("YES. ARMSTRONG !");
// 	}
// 	else {
// 		printf("NO !!");
// 	}
// }


//Q1-e
// #include <stdio.h>
// int main(){
// 	int k, i, m=0, fact, n;
// 	printf("Enter the number to check - ");
// 	scanf("%d", &n);
// 	k = n;
// 	while(n > 0){
// 		fact = 1;
// 		for(i=1; i<=(n%10); i++){
// 			fact *= i;
// 		}
// 		m += fact;
// 		n = n/10;
// 	}
//     if(m == k){
// 		printf("%d is a Strong Number", k);
// 	}
// 	else{
// 		printf("%d is not a Strong Number", k);
// 	}
// }


//Q2-a
// #include <stdio.h>
// int main(){
//     int n, i, j, k;
//     printf("Enter the length - ");
//     scanf("%d", &n);
//     for (i = 1; i <= n; i++){
//         for (j = 0; j <= n-i; j++){
//             printf(" ");
//         }
//         for (k = 1; k<=i ; k++){
//             printf("* ");
//         }
//         printf("\n");
//     }
// }


//Q2-b
// #include <stdio.h>
// int main(){
//     int n, i, j;
//     printf("Enter the length - ");
//     scanf("%d", &n);
//     for (i=0; i< n; i++){
//         for (j = 1; j <= n-i; j++){
//             printf("%d", j);
//         }
//         printf("\n");
//     }
// }


//Q2-c
// #include <stdio.h>
// int main(){
//     int n, i, j;
//     printf("Enter the length - ");
//     scanf("%d", &n);
//     for (i = 1; i <= n; i++){
//         for (j = i; j >= 1; j--){
//             printf("%d ",j*j);
//         }
//         printf("\n");
//     }
// } 


//Q2-d
// #include <stdio.h>
// int main(){
//     int n, i, j;
//     printf("Enter the length - ");
//     scanf("%d", &n);
//     for (i = 1; i <= n; i++){
//         for (j = 1; j <= i; j++){
//             printf("%d", j);
//         }
//         for (j = 0; j <= 2*(n - i); j++){
//             printf(" ");
//         }
//         for (j = i; j > 0; j--){
//             printf("%d", j);
//         }
//         printf("\n");
//     }
// }

// //Q2-e
// #include <stdio.h>
// int main(){
//     int n, i, j;
//     printf("Enter the length - ");
//     scanf("%d", &n);
//     for (i = 1; i <= n; i++){
//         for (j = 1; j <= i; j++){
//             printf("%d ", j);
//         }
//         printf("\n");
//     }
//     for (i = 1; i <= n-1; i++){
//         for(j = 1; j <= n-i; j++){
//             printf("%d ", j);
//         }
//         printf("\n");
//     }     
// }

//Q2-f
// #include <stdio.h>
// int main(){
//     int n, i, j;
//     printf("Enter the length - ");
//     scanf("%d", &n);
//     for (i = 1; i <= n; i++){
//         for (j = 1; j <= 2*(n-i); j++){
//             printf(" ");
//         }
//         for (j = 0; j < (2*i-1); j++){
//             printf("%c ", 65 + 2*j);
//         }
//         printf("\n");
//     }
//     for (i = n-1; i > 0; i--){
//         for (j = 1; j <= 2*(n-i); j++){
//             printf(" ");
//         }
//         for (j = 0; j < (2*i-1); j++){
//             printf("%c ", 65 + 2*j);
//         }
//         printf("\n");
//     }    
// }


//Q3
// #include <stdio.h>
// int main(){
//     int total = 0, i, n1, n2;
//     printf("Enter two numbers - \n");
//     scanf("%d", &n1);
//     scanf("%d", &n2);
//     for (i = n1; i<=n2; i++){
//         if (i%2 == 0){
//             printf("%d\n", i);
//             total += 1;
//         }
//     }
//     printf("Total Even Numbers are - %d", total);    
// }


//Q4
// #include <stdio.h>
// int main(){
//     int n, sum=0;
//     printf("Enter the number - ");
//     scanf("%d", &n);
//     while(n>0){
//         sum += (n%10)*(n%10);
//         n = n/10;
//     }
//     printf("Sum of Square is %d", sum);
// }


//Q5
// #include <stdio.h>
// int main(){
//     int n1, n2, sum= 0;
//     printf("Enter two numbers - ");
//     scanf("%d", &n1);
//     scanf("%d", &n2);
//     while ((n1>0) && (n2>0)){
//         sum += (n1%10)*(n2%10);
//         n1 = n1/10;
//         n2 = n2/10;
//     }
//     printf("The sum is %d", sum);
// }


//Q6
// #include <stdio.h>

// int distinct(int);

// int main(){
//     int L, R, P, l, r;
//     printf("Enter two numbers - \n1st - ");
//     scanf("%d", &L);
//     printf("2nd - ");
//     scanf("%d", &R);

//     P = (L+R)/2;
//     l = P;
//     r = P;
//     if (distinct(P) == 1){
//         printf("Answer is %d", P);
//     }
//     else{
//         while ((l!=L) && (r!=R)){
//             if (distinct(l) == 1){
//                 printf("Answer is %d\n", l);
//                 break; 
//             }
//             else{
//                 l -= 1;
//             }
//             if (distinct(r) == 1){
//                 printf("Answer is %d", r);
//                 break;
//             }
//             else{
//                 r += 1;
//             } 
//         }
//         if ((r == R) && (l == L)){
//             printf("Answer does not EXIST !");
//         }
//     } 
// }


// int distinct(int n){
//     int a, m, i, x;
//     m = n;                   
//     while (n>0){
//         i = n%10;
//         a = m;
//         x = 0;
//         while(a>0){
//             if (i == (a%10)){
//                x +=1; 
//             }
//             if (x >1){
//                 x = -1;      // x = -1 for non-distinct 
//                 break;
//             }
//             a = a/10;
//         }
//         n = n/10;
//     }
//     return x; 
// }


//Q7
#include <stdio.h>
int main(){
    int A, B, C, a, b, c, pairs=0;
    scanf("%d %d %d", &A, &B, &C);
    if (A*C <= B*B){
        printf("Invalid Input !");
    }
    else{
        for (b = 0; b<=B; b++){
            for (a = 0; a<=A; a++){
                for (c = 0; c <= C; c++){
                    if ((a*c) > (b*b)){
                        pairs += 1;
                    }
                }
            }
        }
    printf("No. of ordered triplets are - %d", pairs);
    }
}
