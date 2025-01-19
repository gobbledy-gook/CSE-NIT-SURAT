#include <stdlib.h>
#include <stdio.h>

struct Node{
    int data;
    struct Node* next;
};

struct Node* create(struct Node* start){
    int n;
    struct Node* curr = start;
    printf("Enter the no. of elements - ");
    scanf("%d", &n);
    for(int i=0;i<n;i++){
        struct Node* temp;
        temp = (struct Node*)malloc(sizeof(struct Node));
        scanf("%d", &(temp->data));
        temp->next = NULL;
        if(i ==0){
            start = temp;
            curr = temp;
        }
        else{
            curr->next = temp;
            curr = temp;
        }
    }
    return curr;
}

void insert(){

}

void display(struct Node* start){
    struct Node* temp = start;
    while(temp != NULL){
        printf("%d -> ", temp->data);
        temp = temp->next;
    }
}

int main(){
    struct Node* start1, *curr1;
    struct Node* start2, *curr2;
    start1 = (struct Node*)malloc(sizeof(struct Node));
    start2 = (struct Node*)malloc(sizeof(struct Node));
    printf("Enter the elements for first linked list - ");
    curr1 = create(start1);
    curr2 = create(start1);
}