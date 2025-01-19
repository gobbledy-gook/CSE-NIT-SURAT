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
//     int arr2[] = {11,9,7,5,3,2};
//     int arr3[] = {12,16,20,40,50,90};

// 	int n = sizeof(arr) / sizeof(arr[0]);
//     printArray(arr, n);
// 	bubbleSort(arr, n);
// 	printf("Sorted array1: \n");
// 	printArray(arr, n);

//     printf("\n");
//     n = sizeof(arr2) / sizeof(arr2[0]);
//     printArray(arr2, n);
//     bubbleSort(arr2, n);
// 	printf("Sorted array2: \n");
// 	printArray(arr2, n);

//     printf("\n");
//     n = sizeof(arr3) / sizeof(arr3[0]);
//     printArray(arr3, n);
//     bubbleSort(arr3, n);
// 	printf("Sorted array3: \n");
// 	printArray(arr3, n);
// 	return 0;
// }

// -----------------------------------------------------

#include <stdio.h>

void swap(int* xp, int* yp)
{
	int temp = *xp;
	*xp = *yp;
	*yp = temp;
}


void selectionSort(int arr[], int n)
{
	int i, j;
    int count;
	for (i = 0; i < n ; i++)
    {
        count=i;
		for(j=i+1;j<n;j++){
            if(arr[j]<arr[count]){
                count=j;
            }
}
    swap(&arr[i],&arr[count]);
    }
		
}


void printArray(int arr[], int size)
{
	int i;
	for (i = 0; i < size; i++)
		printf("%d ", arr[i]);
	printf("\n");
}

// Driver program to test above functions
int main()
{
	int arr[] = { 64,25,12,22,11 };
    int arr2[] = {11,9,7,5,3,2};
    int arr3[] = {12,16,20,40,50,90};    
	int n = sizeof(arr) / sizeof(arr[0]);
    printArray(arr, n);
	selectionSort(arr, n);
	printf("Sorted array: \n");
	printArray(arr, n);

    printf("\n");
    n = sizeof(arr2) / sizeof(arr[0]);
    printArray(arr2, n);
	selectionSort(arr2, n);
	printf("Sorted array: \n");
	printArray(arr2, n);

    printf("\n");
    n = sizeof(arr3) / sizeof(arr[0]);
    printArray(arr3, n);
	selectionSort(arr3, n);
	printf("Sorted array: \n");
	printArray(arr3, n);
	return 0;
}

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


// #include <stdio.h>
// void b_sort(int a[], int n)
// {
//     int temp;
//     int issorted = 0;
//     for (int i = 0; i < n; i++)
//     {
//         for (int j = 0; j < n - 1 - i; j++)
//         {

//             if (a[j] > a[j + 1])
//             {
//                 temp = a[j + 1];
//                 a[j + 1] = a[j];
//                 a[j] = temp;
//             }
//         }
//     }
//     printf("small sorted array:");
//     for (int i = 0; i < n; i++)
//     {
//         printf("%d ", a[i]);
//     }
//     printf("\n");
// }
// void merge(int a[], int b[], int n, int m)
// {
//     int size, k, c1 = 0, c2 = 0;
//     size = n + m;
//     int c[size];
//     for (int i = 0; i < size; i++)
//     {
//         if (c1 != n && c2 != m)
//         {
//             if (a[c1] > b[c2])
//             {
//                 c[i] = b[c2];
//                 c2++;
//             }
//             else
//             {
//                 c[i] = a[c1];
//                 c1++;
//             }
//         }
//         else
//         {
//             if (c1 == n)
//             {
//                 c[i] = b[c2];
//                 c2++;
//             }
//             else if (c2 == m)
//             {
//                 c[i] = a[c1];
//                 c1++;
//             }
//         }
//     }
//     printf("sorted array is=");
//     for (int k = 0; k < size; k++)
//     {
//         printf(" %d ", c[k]);
//     }
// }
// int main()
// {
//     int n, m;
//     int x, y;
//     printf("enter size of first array\n");
//     scanf("%d", &n);
//     int a[n];
//     printf("enter elements that need to be sorted\n");
//     for (int i = 0; i < n; i++)
//     {
//         scanf("%d", &x);
//         a[i] = x;
//     }
//     printf("enter size of second array\n");
//     scanf("%d", &m);
//     int b[m];
//     printf("enter elements that need to be sorted\n");
//     for (int i = 0; i < m; i++)
//     {
//         scanf("%d", &y);
//         b[i] = y;
//     }
//     b_sort(a, n);
//     b_sort(b, m);
//     merge(a, b, n, m);
// }





