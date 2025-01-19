// #include <stdio.h>

// void swap(int* xp, int* yp)
// {
// 	int temp = *xp;
// 	*xp = *yp;
// 	*yp = temp;
// }


// void bubbleSort(int arr[], int n)
// {
// 	int i, j;
// 	for (i = 0; i < n - 1; i++)

		
// 		for (j = 0; j < n - i - 1; j++)
// 			if (arr[j] > arr[j + 1])
// 				swap(&arr[j], &arr[j + 1]);
// }


// void printArray(int arr[], int size)
// {
// 	int i;
// 	for (i = 0; i < size; i++)
// 		printf("%d ", arr[i]);
// 	printf("\n");
// }

// // Driver program to test above functions
// int main()
// {
// 	int arr[] = { 40,60,1,200,9,83,17 };
// 	int n = sizeof(arr) / sizeof(arr[0]);
// 	bubbleSort(arr, n);
// 	printf("Sorted array: \n");
// 	printArray(arr, n);
// 	return 0;
// }

// -------------------------------------------------------

// #include <stdio.h>

// void swap(int* xp, int* yp)
// { 
// 	int temp = *xp;
// 	*xp = *yp;
// 	*yp = temp;
// }


// void selectionSort(int arr[], int n)
// {
// 	int i, j;
//     int count;
// 	for (i = 0; i < n ; i++)
//     {
//         count=i;
// 		for(j=i+1;j<n;j++){
//             if(arr[j]<arr[count]){
//                 count=j;
//             }
// }
//     swap(&arr[i],&arr[count]);
//     }
		
// }


// void printArray(int arr[], int size)
// {
// 	int i;
// 	for (i = 0; i < size; i++)
// 		printf("%d ", arr[i]);
// 	printf("\n");
// }

// // Driver program to test above functions
// int main()
// {
// 	int arr[] = { 64,25,12,22,11 };
// 	int n = sizeof(arr) / sizeof(arr[0]);
// 	selectionSort(arr, n);
// 	printf("Sorted array: \n");
// 	printArray(arr, n);
// 	return 0;
// }

// ---------------------------------------------------

// #include<stdio.h>
// #include<math.h>

// void insertionSort(int arr[], int n){
//     int i,j,key;
//     for(int i=0;i<n;i++){
//         key=arr[i];
//         j=i-1;
//         while(j>=0 && arr[j]>key){
//             arr[j+1]=arr[j];
//             j--;
//         }
//         arr[j+1]=key;
//     }

// }

// void print(int arr[],int n){
//     for(int i=0;i<n;i++){
//         printf("%d ",arr[i]);
//     }
// }


// int main(){

//     int arr[]={12,11,13,5,6};
//     int n =sizeof(arr)/sizeof(arr[0]);
//     insertionSort(arr,n);
//     print(arr,n);
// }

// --------------------------------------------------

// #include<stdio.h>
// void swap(int *a,int *b){
//     int temp= *a;
//     *a=*b;
//     *b=temp;

// }
//     int partition(int arr[],int low,int high){
//         int pivot=arr[high];
//         int i=low-1;
//         for(int j=low;j<=high-1;j++){
//             if(arr[j]<pivot){
//                 i++;
//                 swap(&arr[i],&arr[j]);
//             }
//         }
//         swap (&arr[i+1],&arr[high]);
//         return i+1;

//     }
//     void quicksort(int arr[],int low,int high){
//          if (low < high) {
        
//         int pi = partition(arr, low, high);
  
        
//         quicksort(arr, low, pi - 1);
//         quicksort(arr, pi + 1, high);
//     }
// }
//     void printarray(int arr[],int n){
//         for(int i=0;i<n;i++){
//             printf("%d ",arr[i]);
//         }
//     }


// int main(){

// int arr[]={22,31,12,10,6,45,65,55};
// int n=sizeof(arr)/sizeof(arr[0]);
// quicksort(arr,0,n-1);
// printf("Sorted array is: ");
// printarray(arr,n);

//     return 0;
// }

// ----------------------------------------------

#include <stdio.h>
void b_sort(int a[], int n)
{
    int temp;
    int issorted = 0;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n - 1 - i; j++)
        {

            if (a[j] > a[j + 1])
            {
                temp = a[j + 1];
                a[j + 1] = a[j];
                a[j] = temp;
            }
        }
    }
    printf("small sorted array:");
    for (int i = 0; i < n; i++)
    {
        printf("%d ", a[i]);
    }
    printf("\n");
}
void merge(int a[], int b[], int n, int m)
{
    int size, k, c1 = 0, c2 = 0;
    size = n + m;
    int c[size];
    for (int i = 0; i < size; i++)
    {
        if (c1 != n && c2 != m)
        {
            if (a[c1] > b[c2])
            {
                c[i] = b[c2];
                c2++;
            }
            else
            {
                c[i] = a[c1];
                c1++;
            }
        }
        else
        {
            if (c1 == n)
            {
                c[i] = b[c2];
                c2++;
            }
            else if (c2 == m)
            {
                c[i] = a[c1];
                c1++;
            }
        }
    }
    printf("sorted array is=");
    for (int k = 0; k < size; k++)
    {
        printf(" %d ", c[k]);
    }
}
int main()
{
    int n, m;
    int x, y;
    printf("enter size of first array\n");
    scanf("%d", &n);
    int a[n];
    printf("enter elements that need to be sorted\n");
    for (int i = 0; i < n; i++)
    {
        scanf("%d", &x);
        a[i] = x;
    }
    printf("enter size of second array\n");
    scanf("%d", &m);
    int b[m];
    printf("enter elements that need to be sorted\n");
    for (int i = 0; i < m; i++)
    {
        scanf("%d", &y);
        b[i] = y;
    }
    b_sort(a, n);
    b_sort(b, m);
    merge(a, b, n, m);
}


// -----------------------------------------------------------

// #include <stdio.h>
// #include<stdlib.h>

// int getMax(int arr[], int n)
// {
// 	int mx = arr[0];
// 	for (int i = 1; i < n; i++)
// 		if (arr[i] > mx)
// 			mx = arr[i];
// 	return mx;
// }

// // A function to do counting sort of arr[] according to
// // the digit represented by exp.
// void countSort(int arr[], int n, int exp)
// {
// 	int output[n]; // output array
// 	int i, count[10] = { 0 };


// 	for (i = 0; i < n; i++)
// 		count[(arr[i] / exp) % 10]++;

// 	// Change count[i] so that count[i] now contains actual
// 	// position of this digit in output[]
// 	for (i = 1; i < 10; i++)
// 		count[i] += count[i - 1];


// 	for (i = n - 1; i >= 0; i--) {
// 		output[count[(arr[i] / exp) % 10] - 1] = arr[i];
// 		count[(arr[i] / exp) % 10]--;
// 	}

// 	// Copy the output array to arr[], so that arr[] now
// 	// contains sorted numbers according to current digit
// 	for (i = 0; i < n; i++)
// 		arr[i] = output[i];
// }

// // The main function to that sorts arr[] of size n using
// // Radix Sort
// void radixsort(int arr[], int n)
// {
// 	// Find the maximum number to know number of digits
// 	int m = getMax(arr, n);

// 	// Do counting sort for every digit. Note that instead
// 	// of passing digit number, exp is passed. exp is 10^i
// 	// where i is current digit number
// 	for (int exp = 1; m / exp > 0; exp *= 10)
// 		countSort(arr, n, exp);
// }
// void print(int arr[], int n)
// {
// 	for (int i = 0; i < n; i++)
// 		printf("%d ",arr[i]);
// }
// int main()
// {
// 	int arr[] = { 170, 45, 75, 90, 802, 24, 2, 66 };
// 	int n = sizeof(arr) / sizeof(arr[0]);
	
// 	// Function Call
// 	radixsort(arr, n);
// 	print(arr, n);
// 	return 0;
// }

// ----------------------------------------------------------------------

// #include <stdio.h>
// #include<stdlib.h>

// void swap(int* x, int* y)
// {

// 	int temp = *x;
// 	*x = *y;
// 	*y = temp;
// }

// // To heapify a subtree rooted with node i
// // which is an index in arr[].
// // n is size of heap
// void heapify(int arr[], int N, int i)
// {
// 	// Find largest among root, left child and right child

// 	// Initialize largest as root
// 	int largest = i;

// 	// left = 2*i + 1
// 	int left = 2 * i + 1;

// 	// right = 2*i + 2
// 	int right = 2 * i + 2;

// 	// If left child is larger than root
// 	if (left < N && arr[left] > arr[largest])

// 		largest = left;

// 	// If right child is larger than largest
// 	// so far
// 	if (right < N && arr[right] > arr[largest])

// 		largest = right;

// 	// Swap and continue heapifying if root is not largest
// 	// If largest is not root
// 	if (largest != i) {

// 		swap(&arr[i], &arr[largest]);

// 		// Recursively heapify the affected
// 		// sub-tree
// 		heapify(arr, N, largest);
// 	}
// }


// void heapSort(int arr[], int N)
// {
// 	for (int i = N / 2 - 1; i >= 0; i--)

// 		heapify(arr, N, i);
// 	for (int i = N - 1; i >= 0; i--) {

// 		swap(&arr[0], &arr[i]);
// 		heapify(arr, i, 0);
// 	}
// }

// void printArray(int arr[], int N)
// {
// 	for (int i = 0; i < N; i++)
// 		printf("%d ", arr[i]);
// 	printf("\n");
// }
// int main()
// {
// 	int arr[] = { 12, 11, 13, 5, 6, 7 };
// 	int n = sizeof(arr) / sizeof(arr[0]);
// 	heapSort(arr, n);
// 	printf("Sorted array is\n");
// 	printArray(arr, n);
// }





