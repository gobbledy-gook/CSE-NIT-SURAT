#include <stdio.h>
#include <stdlib.h>

int list1[7] = {40, 60, 1, 200, 9, 83, 17};
int list2[6] = {11, 9, 7, 5, 3, 2};
int list3[6] = {12, 16, 20, 40, 50, 70};

void display(int list[]){
    int i=0;
    printf("Sorted List : ");
    while(list[i]!='\0'){
        printf("%d ", list[i]);
        i++;
    }
    printf("\n");
}

void bubblesort(int list[]){
    int len=0;
    while(list[len]!='\0'){
        len+=1;
    }
    for(int i=0;i<len;i++){
        for(int j = 0;j<len-1;j++){
            int temp;
            if(list[j] > list[j+1]){
                temp = list[j];
                list[j] = list[j+1];
                list[j+1] = temp;
            }
        }
    }
}

void swap(int list[], int i, int j){
    int temp = list[i];
    list[i] = list[j];
    list[j] = temp;
}

void shiftright(int list[], int i, int k){
    int temp1 = list[i];
    int temp2;
    list[i] = list[k];
    while(list[i]!='\0'){
        temp2 = list[i+1];
        list[i+1] = temp1;
        temp1 = temp2;
    }
}

void selectionsort(int list[], int l){
    if(list[l]=='\0'){
        return;
    }
    int min=l, j=l;
    while(list[j]!='\0'){
        if(list[min] > list[j]){
            min = j;
        }
        j++;
    }
    swap(list, l, min);
    selectionsort(list, l+1);

}

void insertionsort(int list[], int l){
    int i =0;
    while(list[i]!='\0'){
        
    }
}

int main(){
    // bubblesort(list1);
    // display(list1);
    // bubblesort(list2);
    // display(list2);
    // bubblesort(list3);
    // display(list3);

    // selectionsort(list1, 0);
    // display(list1);

    
}