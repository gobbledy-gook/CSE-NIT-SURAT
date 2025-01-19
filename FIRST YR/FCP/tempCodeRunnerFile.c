// Q3
#include <stdio.h>
#include <string.h>

void insertWord(char str1[], char word[], int p){
    int a = 0, i=0, j=0;
    char str2[100];     
    while(i!=(p-1)){
        str2[i] = str1[i];
        i+=1;
    }
    if (((str1[p-1]) == ' ') || ((str1[p-1]) == '\0')){
        str2[i] = ' ';
        i+=1;
    }

    while(word[j] != '\0'){
        str2[i] = word[j];
        j+=1;
        i+=1;
        a+=1;
    }
    str2[i] = ' ';
    j = i;
    j+=1;
    i-=a;
    while(str1[i] != '\0'){
        str2[j] = str1[i];
        j+=1;
        i+=1;
    }
    str2[j] = '\0';
    printf("\n%s", str2);

}


int main(){
    int p;
    char str1[100], word[100];
    printf("\nEnter the string - \n");
    gets(str1);
    printf("\nEnter the word to insert - ");
    scanf("%s", word);
    printf("\nEnter the position - ");
    scanf("%d", &p);
    insertWord(str1, word, p);
}