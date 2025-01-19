#include <stdlib.h>
#include <stdio.h>


int length(char a[]){
int count=0,i=0;
    while(a[count]!='\0'){
        count++;    
    }
    return count;
}

char * concat(char b[],char c[]){
    
    int count=0;
    for(int i=0;b[i]!='\0';i++){
        count++;
    }
    for(int i=0;c[i]!='\0';i++){
        b[count]=c[i];
        count++;
    }
    return b;
}

char * copy(char c[],char a[]){
    int j=0;
    // char x[100];
    char * x;
    x = (char *)calloc(sizeof(char), 100);
    for(int i=0;a[i]!='\0';i++){
       c[i]=a[i]; 
    }
    for(int i=0;c[i]!='\0';i++){
       x[i]=c[i]; 
    }
    return x;
    // for(int i=0;b[i]!='\0';i++){
    //     printf("%c",a[i]);
    // }
}

int cmp(char x[],char y[]){
    int i,j=0;
    int len1,len2,max;
    len1=length(x);
    len2=length(y);
    if (len1!=len2){
        return 0;
    }
    else{
        for(i=0;i<len1;i++){
            if(x[i]==y[i]){
             j++;
            }
        }
        if(j==len1){
            return 1;
        }
        else{
            return 0;

        }
    }
}

int src (char x[], int len){               //Search 'c'
    int j, flag=0;
    for(int i=0;x[i]!='\0';i++){
        if(x[i]=='c'){
            j=i+1;
            flag=1;
            break;
        }
    }
    if(flag == 0){
        return -1;
    }
    else{
        return j;
    }
}

void reverse(char x[]){
    char temp;
    int j=length(x);
    for(int i=0;i<j/2;i++){
        temp = x[i];
        x[i]=x[j-i-1];
        x[j-i-1] = temp;
    }
    for(int m=0;x[m]!='\0';m++){
        printf("%c",x[m]);
    }
}

void replace(char x[]){
    for(int i=0;i<length(x);i++){
        if(x[i]=='a'||x[i]=='e'||x[i]=='i'||x[i]=='o'||x[i]=='u'){
            x[i]='*';
        }else{
            x[i]='#';
        }
        printf("%c",x[i]);
    }
}

void substr(char s[],char search[]){
    int count1=0,count2=0,i,j,flag;
    count1=length(s);
    count2=length(search);
    for (i = 0; i <= count1 - count2; i++)
    {
        for (j = i; j < i + count2; j++)
        {
            flag = 1;
            if (s[j] != search[j - i])
            {
                flag = 0;
                break;
            }
        }
        if (flag == 1)
            break;
    }
    if (flag == 1)
        printf("1");
    else
        printf("0");
}

char * trans(char a[]){
    for(int i =0;a[i]!='\0';i++){
        if((a[i] == 'a')||(a[i] == 'e')||(a[i] == 'i')||(a[i] == 'o')||(a[i] == 'u')){
            a[i] = '*';
        }
        else if(a[i] == ' '){
            a[i] = ' ';
        }
        else{
            a[i] = '#';
        }
    }
    return a;
}