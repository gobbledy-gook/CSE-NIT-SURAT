#include <stdio.h>
#include <stdlib.h>

struct node{
    int data;
    struct node * next;
};

void display(int arr[], struct node *arrNodes[], int N){
    printf("The Hash Table is -->\n");
    for(int i=0;i<N;i++){
        printf("%d ", arr[i]);
    }
    printf("\n");

    if(arrNodes != NULL){
       printf("\nThe Linked Table is -->\n");
        for(int i=0;i<N;i++){
            printf("\n%p", arrNodes[i]);
            if(arrNodes[i] != NULL){
                struct node * curr;
                curr = arrNodes[i];
                while(curr != NULL){
                    printf(" -> %d ", curr->data);
                    curr = curr->next;
                }
            }
        }
        printf("\n"); 
    }
}

int hash(int val, int N){
    int h;
    h = val % N;
    return h;
}

void chaining(int val, struct node * arrNodes[], int N){
    int h = hash(val, N);
    struct node * temp;
    struct node * curr;
    temp = (struct node *)malloc(sizeof(struct node));
    temp->data = val;
    temp->next = NULL;
    if(arrNodes[h] == NULL){
        arrNodes[h] = temp;
    }
    else{
        curr = arrNodes[h];
        while(curr->next != NULL){
            curr = curr->next;
        }
        curr->next = temp;
    }
}

int linear(int val, int arr[], int N){
    int h = hash(val, N);
    int i = 1;
    while(i!=N){
        if(arr[(h+i)%N] != 0){
            i++;
        }
        else{
            break;
        }
    }
    if(i==N){
        return -1;
    }
    else{
        return ((h+i)%N);
    }
}


int quadratic(int val, int arr[], int N){
    int h = hash(val, N);
    int i = 1;
    while((i*i)<=N){
        if(arr[(h+(i*i))%N] != 0){
            i++;
        }
        else{
            break;
        }
    }
    if((i*i)>N){
        return -1;
    }
    else{
        return ((h+(i*i))%N);
    }
}


int main(){
    int N, x=1;
    printf("Enter the length of the Hash Table - ");
    scanf("%d", &N);
    int arr[N]; 
    for(int i=0;i<N;i++){
        arr[i] = 0;
    }

    struct node * arrNodes[N];
    for(int i=0;i<N;i++){
        arrNodes[i] = NULL;
    }


    while(x){
        printf("\n1. Add Value\n2. Open Hashing [Chain Method]\n3. Linear Probing\n4. Quadratic Probing\n5. Display\n0. Exit\n--> ");
        int a, i, value, l, q;
        scanf("%d", &a);
        switch(a){

            case 1:
                printf("\nEnter the value to add - ");
                scanf("%d", &value);
                i = hash(value, N);
                if(arr[i] != 0){
                    printf("Collision Occured. Choose a resolving technique.\n");
                }
                else{
                    arr[i] = value;
                }
                break;

            case 2:
                chaining(value, arrNodes, N);
                break;

            case 3:
                l = linear(value, arr, N);
                if(l == -1){
                    printf("No position found !\n");
                }
                else{
                    arr[l] = value;
                    printf("Placed at %d in the array\n", l);
                }
                break;

            case 4:
                q = quadratic(value, arr, N);
                if(l == -1){
                    printf("No position found !\n");
                }
                else{
                    arr[l] = value;
                    printf("Placed at %d in the array\n", l);
                }
                break;

            case 5:
                display(arr, arrNodes, N);
                break;
            
            case 0:
                x=0;
                break;

            default:
                break;    
        }
        
    }

}



#include <stdio.h>
#include<stdlib.h>

void swap(int* x, int* y)
{

	int temp = *x;
	*x = *y;
	*y = temp;
}

// To heapify a subtree rooted with node i
// which is an index in arr[].
// n is size of heap
void heapify(int arr[], int N, int i)
{
	// Find largest among root, left child and right child

	// Initialize largest as root
	int largest = i;

	// left = 2*i + 1
	int left = 2 * i + 1;

	// right = 2*i + 2
	int right = 2 * i + 2;

	// If left child is larger than root
	if (left < N && arr[left] > arr[largest])

		largest = left;

	// If right child is larger than largest
	// so far
	if (right < N && arr[right] > arr[largest])

		largest = right;

	// Swap and continue heapifying if root is not largest
	// If largest is not root
	if (largest != i) {

		swap(&arr[i], &arr[largest]);

		// Recursively heapify the affected
		// sub-tree
		heapify(arr, N, largest);
	}
}


void heapSort(int arr[], int N)
{
	for (int i = N / 2 - 1; i >= 0; i--)

		heapify(arr, N, i);
	for (int i = N - 1; i >= 0; i--) {

		swap(&arr[0], &arr[i]);
		heapify(arr, i, 0);
	}
}

void printArray(int arr[], int N)
{
	for (int i = 0; i < N; i++)
		printf("%d ", arr[i]);
	printf("\n");
}
int main()
{
	int arr[] = { 12, 11, 13, 5, 6, 7 };
	int n = sizeof(arr) / sizeof(arr[0]);
	heapSort(arr, n);
	printf("Sorted array is\n");
	printArray(arr, n);
}