//Q1
// #include <stdio.h>
// #include<ctype.h>
// int main(){
//     int i=0, n=0, max1=0, max2=0, max=0, j=0, p, q;
//     int hash[256];
//     char str[100], a;
//     printf("\nEnter the string - \n");
//     gets(str);
//     for(i=0;i<256;i++){
//         hash[i] = 0;
//     }
//     i=0;
//     while(str[i] != '\0'){
//         n = str[i];
//         if (hash[n] < 1){
//             hash[n] = 1;
//         }
//         else{
//            hash[n] += 1; 
//         }
//         i+=1;
//     }

//     for(i=65;i<=90; i++){
//         if(hash[i] > max1){
//             max1 = hash[i];
//             p=i;
//         }
//     }

//     for(i=97;i<=122; i++){
//         if(hash[i] > max2){
//             max2 = hash[i];
//             q=i;
//         }
//     }

//     if(max1 > max2){
//         max = max1;
//         a = p;
//     }
//     else{
//         max = max2;
//         a = q;
//     }
//     printf("\nCharacter %c occurs maximum with frequency of %d", a, max);   
// }

//Q2
// #include <stdio.h>
// int main(){
//     char str1[200], str2[100];
//     int i=0, j=0, k=0, l2=0;
//     printf("\nEnter the string - \n");
//     gets(str1);
//     printf("\nEnter the substing to check for - \n");
//     gets(str2);
//     while(str2[l2] != '\0'){
//         l2+=1;
//     }
//     while(str1[i] != '\0'){
//         j=0;
//         k=0;
//         while(str1[i] == str2[j]){
//             k+=1;
//             i+=1;
//             j+=1;
//         }
//         if (k == l2){
//             printf("\n %s - is present in: %s \n", str2, str1);
//         }
//         i+=1;
//     }
// }


//Q3
// #include <stdio.h>
// #include <ctype.h>
// int main(){
//     char str1[100], str2[100];
//     int i=0, j=0, k=0;
//     printf("\nEnter the string - \n");
//     gets(str1);
//     while(str1[i] != '\0'){
//         if (isdigit(str1[i]) == 0){
//             k = 0;
//             str2[j] = str1[i];
//             j+=1;
//             i+=1;
//         }
//         else{
//             i+=1;
//             k+=1;
//         }
//     }
//     printf("\nEdited String: \n%s", str2);
// }


//Q4
// #include <stdio.h>
// int main(){
//     int i=0, j=0, max=0, min=100, k=0, n=0;
//     char str1[100], Mword[50], mword[50];
//     printf("\nEnter the sentence - ");
//     gets(str1);
//     while(str1[i] != '\0'){
//         k=0;

//         while((str1[i] != ' ') &&(str1[i] != '\0')){
//             k+=1;
//             i+=1;
//         }

//         if (k > max){
//             max = k;
//             for(n=0;n<max;n++){
//                 Mword[n] = str1[i-k];
//                 i+=1;
//             }
//             Mword[n] = '\0';
//             i-=k;
//         }
        
//         if ((k< min)&&(k!=0)){
//             min = k;
//             for(n=0;n<min;n++){
//                 mword[n] = str1[i-k];
//                 i+=1;
//             }
//             mword[n] = '\0';
//             i-=k;
//         }
//         i+=1;
//     }
//     printf("\nMaximum Length of the word - %d : %s\nMinimum Length of the word - %d : %s", max, Mword, min, mword);
// }


//Q5
// #include <stdio.h>
// int main(){
//     int i=0, j=0;
//     char str1[100], str2[100];
//     printf("\nEnter the string - ");
//     gets(str1);
//     while(str1[i] != '\0'){
//         if((str1[i] != ' ') && (str1[i] != '\0')){
//             str2[j] = str1[i];
//             i+=1;
//             j+=1;
//         }
//         else{
//             i+=1;
//         }
//     }
//     printf("\nSpaces Removed: %s", str2);
// }


//Q6
#include <stdio.h>
#include <ctype.h>
int main(){
    char str1[100];
    int arr1[3], i=0;
    printf("\nEnter the string - ");
    gets(str1);
    arr1[0] = 0;
    arr1[1] = 0;
    arr1[2] = 0;
    while(str1[i]!='\0'){
        if (isdigit(str1[i]) == 1){
            arr1[1] +=1;
        }
        else if(((str1[i]>=65) && (str1[i] <=90)) || ((str1[i]>=97) && (str1[i] <=122))){
            arr1[0] +=1;
        }
        else{
            arr1[2] +=1;
        }
        i+=1;
    }
    printf("\nNo. of Alphabets - %d\nNo. of Digits - %d\nNo. of Special Characters - %d", arr1[0], arr1[1], arr1[2]);
}



// ---------------------------------------------------------------


//Evaluation
// #include <stdio.h>
// int main(){
//     char str1[100], str2[100], str3[100];
//     int i=0, j=0, p=0, k=0, l=0;
//     printf("\nEnter the string - \n");
//     gets(str1);
//     printf("\nEnter the substring to remove - \n");
//     gets(str2);
//     while(str2[l] != '\0'){
//         l+=1;
//     }
//     while(str1[i] != '\0'){
//         j = 0;
//         k = 0;
//         while((str1[i] == str2[j]) && (str2[j] != '\0')){
//             k+=1;
//             j+=1;
//             i+=1;
//             p+=1;
//         }
//         if (k == l){
//             p = p - k - 1;
//             k=0;
//         }
//         else if((k > 0) && (k!=l)){
//             p = p-k;
//             i = i-k;
//             k=0;
//         }
//         str3[p] = str1[i];
//         // printf("\n%d : %d - %d : %c", j,i, p, str3[p]);
//         // printf("%c", str3[p]);
//         i+=1;
//         p+=1;
//     }
//     str3[p] = '\0';
//     printf("\n%s", str3);
// }