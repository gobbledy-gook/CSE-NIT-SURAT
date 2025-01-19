//Q1-a
// #include <stdio.h>
// int main(){
//     char str1[100], str[100], i=0;
//     printf("Enter the string - \n");
//     scanf("%[^\n]", str1);
//     printf("\nCopied String - \n");
//     while(str1[i]!='\0'){
//         str[i] = str1[i];
//         printf("%c", str[i]);
//         i+=1;
//     }
// }    


//Q1-b
// #include <stdio.h>
// int main(){
//     int a, b;
//     char str1[100], str2[100], i=0, l1=0, l2=0;
//     printf("\nEnter the 1st string - \n");
//     gets(str1);
//     while(str1[i] != '\0'){
//         l1 += 1;
//         i+=1;
//     }

//     printf("\nEnter the 2nd string - \n");
//     gets(str2);
//     i=0;
//     while(str2[i] != '\0'){
//         l2 += 1;
//         i+=1;
//     }
//     printf("%d %d\n", l1, l2);
//     i=0;
//     while((str1[i] != '\0') && (str2[i] != '\0')){
//         if (str1[i] == str2[i]){
//             i+=1;
//         }
//         else{
//             break;
//         }
//     }
//     printf("%d\n", i);
//     if((i == l1) && (i == l2)){
//         printf("Strings are Equal !");
//     }
//     else if((i == l1) || (i == l2)){
//         printf("Only starting %d letters are same", i);
//     }
//     else{
//         printf("Strings are NOT equal !");
//     } 
// }


//Q1-c
// #include <stdio.h>
// int main(){
//     char str1[100], str2[100], i=0, l1=0;
//     printf("\nEnter the 1st string - \n");
//     gets(str1);
//     while(str1[i] != '\0'){
//         l1 += 1;
//         i+=1;
//     }
//     printf("\nEnter the 2nd string - \n");
//     gets(str2);
//     i=0;
//     while(str2[i] != '\0'){
//         str1[l1+i] = str2[i];
//         i++;
//     }
//     printf("\nConcatenated String - \n%s", str1);
// }


//Q1-d
// #include <stdio.h>
// int main(){
//     char str1[100], str2[100], i=0, l1=0;
//     printf("\nEnter the 1st string - \n");
//     gets(str1);
//     while(str1[i] != '\0'){
//         l1 += 1;
//         i+=1;
//     }
//     i=0;
//     while(str1[i] != '\0'){
//         str2[i] = str1[l1-1-i];
//         i++;
//     }
//     printf("\nReversed String - \n%s", str2);
// }


//Q2
// #include <stdio.h>
// int main(){
//     char str1[100], str2[100];
//     int i=0, sum = 0;
//     printf("\nEnter the 1st string - \n");
//     gets(str1);
//     while(str1[i] != '\0'){
//         sum += str1[i];
//         i++;
//     }
//     printf("\nEquivalent ASCII Code - %d", sum);
// }

//Q3
// #include <stdio.h>
// int main(){
//     char str1[100], str2[100], k;
//     int i=0, j=0;
//     printf("\nEnter the string - ");
//     gets(str1);
//     while(str1[i] != '\0'){
//         while(str1[j] != '\0'){
//             if(str1[i] > str1[j]){
//                 k = str1[j];
//                 str1[j] = str1[i];
//                 str1[i] = k;
//             }
//             j+=1;
//         }
//         i+=1;
//     }
//     printf("\nAlphabetically Sorted String - \n%s", str1);
// }


//Q4
// #include <stdio.h>
// int main(){
//     int i=0, m, l1=0;
//     char str1[100], str2[100], str3[100];
//     printf("\nEnter the 1st string - \n");
//     gets(str1);
//     while(str1[l1] != '\0'){
//         l1+=1;
//     }
//     printf("\nEnter the 2nd string - \n");
//     gets(str2);
//     printf("\nMerged String - ");
//     while(str1[i]!='\0'){
//         str3[i] = str1[i];
//         printf("%c", str3[i]);
//         i+=1;
//     }
//     i = 0;
//     printf("%c", ' ');
//     while(str2[i] != '\0'){
//         str3[l1+i] = str2[i];
//         printf("%c", str3[l1+ i]);
//         i+=1;
//     }  
// }


//Q5
// #include <stdio.h>
// int main(){
//     int i=0, num = 0, x=1, l=0, j=0, k=0;
//     char str1[100], str2[100];
//     printf("\nEnter the string - \n");
//     gets(str1);
//     printf("\nEnter the word to find - \n");
//     gets(str2);
//     while(str2[l]!='\0'){
//         l+=1;
//     }
//     while(str1[i] != '\0'){
//         j=0;
//         k=0;
//         while((str1[i]!=' ') && (str1[i] != '\0')){
//             if (str1[i] == str2[j]){
//                 k+=1;
//             }
//             j+=1;
//             i+=1;
//         }
//         if(k == l){
//             num+=1;
//         }
//         i+=1;
//     }
//     printf("\nTotal no. of occurrences of %s - %d", str2, num);
// }


//Q6
// #include <stdio.h>
// int main(){
//     int i=0, j=0, k=0, m=0, p=0, l2=0, l3=0;
//     char str1[300], str2[100], str3[100], str4[300];
//     printf("\nEnter the sentence - \n");                    // Getting the Statement
//     gets(str1);
//     printf("\nEnter the word to replace - \n");             // Getting the word1 to replace
//     gets(str2);
//     while(str2[l2] != '\0'){                                // Counting the length of the word1
//         l2+=1;
//     }
//     printf("\nEnter the new word to replace with - \n");    // Getting the word2 to replace with
//     gets(str3);
//     while(str3[l3] != '\0'){                                // Counting the length of the word2
//         l3+=1;   
//     }
//     while(str1[i] != '\0'){
//         j=0;
//         k=0;

//         while((str1[i]!=' ') && (str1[i] != '\0')){        // Going Through each word 
//             str4[m] = str1[i];                             // Assigning letter by letter to new string. "m" is the counter for new string into which the original string is getting stored 
//             if (str1[i] == str2[j]){                       // Checking if the letters are matching to the word1
//                 k+=1;                                      // Counting the no. of matching letters 
//             }
//             j+=1;
//             i+=1;
//             m+=1;
//         }

//         str4[m] = str1[i];
//         p=0;

//         if(k == l2){                                       // Checking if count is equal to the no. of letters of the word
//             m -= l2;                                       // if k matches the no. of letters of the word, then take "m" back to the index where the matching of the word began.
//             while(str3[p] != '\0'){                        // Since we took the index back, now re-assigning begins for the new word.
//                 str4[m] = str3[p];
//                 p+=1;
//                 m+=1;
//             }
//             str4[m] = ' ';                                 // Adding the space.
//         }
//         i+=1;
//         m+=1;
//     }
//     printf("\n\nThe string with replaced word - \n%s", str4);
// }

