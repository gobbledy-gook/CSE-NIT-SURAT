//Q1
// #include <stdio.h>
// int main(){
// 	int m;
// 	float sum=0;
// 	printf("Enter the length of the arrays - ");
// 	scanf("%d", &m);	
// 	int n1[m], n2[m], n3[m], i=0;
// 	printf("Enter the first array - \n");
// 	for (i=0; i<m; i++){
// 		scanf("%d", &n1[i]);	
// 	}

// 	printf("Enter the second array - \n");
// 	for (i=0; i<m; i++){
// 		scanf("%d", &n2[i]);	
// 	}
// 	i=0;
// 	for (i=0; i<m; i++){
// 		n3[i] = n1[i] + n2[i];
// 	}
	
// 	printf("Addition is - ");
// 	for (i=0; i<m; i++){
// 		printf("%d ", n3[i]);
// 		sum += n3[i];	
// 	}
// 	printf("\nAverage is %f", sum/m);
// }


//Q2
// #include <stdio.h>
// int main(){
// 	int m;
// 	printf("Enter the length of the array - ");
// 	scanf("%d", &m);
// 	int arr1[m], i, j, k, a;
// 	printf("Enter the array - \n");
// 	for (i=0;i<m;i++){
// 		scanf("%d", &arr1[i]);
// 	}
// 	for(a=1;a<m;a++){
// 		for (i=0; i<m-1; i++){
// 			if (arr1[i]<arr1[i+1]){
// 				j = arr1[i];
// 				arr1[i] = arr1[i+1];
// 				arr1[i+1] = j;
// 			}
// 		}
// 	}
// 	printf("Sorted Array - ");
// 	for (k=0;k<m;k++){
// 		printf("%d ", arr1[k]);
// 	}
// 	return 0;
// }
			

//Q3
// #include <stdio.h>
// int main(){
//    int m;
//    printf("\nEnter the length of the array - ");
// 	scanf("%d", &m);
//    int e=0, o=0, arr[m], i;
// 	printf("Enter the array - \n");
// 	for (i = 0; i<m; i++){
// 	    scanf("%d", &arr[i]);
// 	}
// 	for (i=0; i<m;i++){
// 	    if ((arr[i]%2) == 0){
// 	        e += 1;
// 	    }
// 	    else{
// 	        o+=1;
// 		}
// 	}
// 	printf("\nThe array is\n>> ");
// 	for (i = 0; i<m ; i++){
// 	    printf("%d ", arr[i]);
// 	}
// 	printf("\n\nNo. of Even Numbers are - %d\n", e);
// 	printf("No. of Odd Numbers are - %d\n", o);
// 	return 0;
// }	


//Q4	
// #include <stdio.h>
// int main() {
//    int m, k, i, j;
//    printf("\nEnter the length of the array - ");
//    scanf("%d", &m);
// 	int arr[m], arr1[m];
// 	printf("Enter the array - \n");
// 	for (i=0; i<m; i++){
// 	    scanf("%d", &arr[i]);
// 	    arr1[i] = arr[i];
// 	}
	
// 	for(k=1;k<m;k++){
// 		for (i=0; i<m-1; i++){
// 			if (arr[i]<arr[i+1]){
// 				j = arr[i];
// 				arr[i] = arr[i+1];
// 				arr[i+1] = j;
// 			}
// 		}
// 	}
	
// 	for (i=0; i<m; i++){
// 	    if (arr1[i] == arr[0]){
// 	        arr1[i] = arr[m-1];
// 	    }
// 	    else if (arr1[i] == arr[m-1]){
// 	        arr1[i] = arr[0];
// 	    }
// 	}
// 	printf("\nArray with values exchanged - \n");
// 	for (i = 0; i<m; i++){
// 	    printf("%d ", arr1[i]);
// 	}
// 	printf("\n");
// 	return 0;
// }


//Q5
// #include <stdio.h>
// int main(){
//    int m;
//    printf("\nEnter the length of the array - ");
//    scanf("%d", &m);
   
//    int arr[m], ele, i, arr1[m-1], k;
//    printf("Enter the array - \n");
//    for (i=0; i<m;i++){
//        scanf("%d", &arr[i]);
//    }
   
//    printf("\nEnter the value to be deleted - ");
//    scanf("%d", &ele);
//    for (i=0; i<m; i++){
//        if (ele == arr[i]){
//            k = i;
//            break;
//        }
//    }
   
//    for (i = 0; i<m; i++){
//        if (i<k){
//            arr1[i] = arr[i];
//        }
//        else{
//            arr1[i] = arr[i+1];
//        }
//    }
   
//    printf("\n");
   
//    for (i = 0; i<m-1; i++){
//        printf("%d ", arr1[i]);
//    }

//    return 0;
// }


//Q6
// #include <stdio.h>
// int main(){
//    int m;
//    printf("Enter the length of the array - ");
//    scanf("%d", &m);
   
//    int arr[m], ele, i, arr1[m-1], k;
//    printf("Enter the array - \n");
//    for (i=0; i<m;i++){
//        scanf("%d", &arr[i]);
//    }
   
//    printf("\nEnter the value to be inserted - ");
//    scanf("%d", &ele);
//    printf("Enter the position - ");
//    scanf("%d", &k);
//    for (i = 0; i<m+1; i++){
//        if (i<(k-1)){
//            arr1[i] = arr[i];
//        }
//        else if (i == (k-1)){
//            arr1[i] = ele;
//        }
//        else{
//            arr1[i] = arr[i-1];
//        }
//    }   
//    printf("\n");
//    for (i = 0; i<m+1; i++){
//        printf("%d ", arr1[i]);
//    }

//    return 0;
// }


//Q7
// #include <stdio.h>
// int main(){
//    int m;
//    printf("\nEnter the length of the array - ");
//    scanf("%d", &m);
   
//    int arr[m], i, j, sum=0;
//    printf("Enter the array - \n");
//    for (i = 0; i<m; i++){
//        scanf("%d", &arr[i]);
//    }
//    for(i=0; i<m; i++){
//        for (j=0; j<m; j++){
//            if (arr[j] != 0){
//                sum += arr[i]%arr[j];
//            }
//        }
//    }
   
//    printf("Sum is - %d", sum);
   
//    return 0;
// }


//Q8
// #include <stdio.h>
// int main(){
//    int M1[3][3], M2[3][3], M3[3][3], i, j, k;
//    printf("Enter the 1st matrix - \n");
//    for (i=0; i<3; i++){
// 		printf("Enter the row-%d : ", i+1);
//         for (j=0; j<3; j++){
//            scanf("%d", &M1[i][j]);
//        }
//    }
//    printf("\n\n");
//    printf("Enter the 2nd matrix - \n");
//    for (i=0; i<3; i++){
// 		printf("Enter the row-%d : ", i+1);
//         for (j=0; j<3; j++){
//            scanf("%d", &M2[i][j]);
//        }
//    }
   

//    for(i = 0; i<3; i++){
// 		printf("Row-%d : ", i+1);
//        for (j = 0; j<3; j++){
//            int sum= 0;
//            for(k=0; k<3; k++){
//                sum += M1[i][k]*M2[k][j];
//            }
//            printf("%d ", sum);
//        }
//        printf("\n");
//    }
//    return 0;
// }


//Q9
// #include <stdio.h>
// int main(){
//     int m;
//     printf("\nEnter the length - ");
//     scanf("%d", &m);
//     int arr[m],x=0, i;
//     printf("Enter the array -\n");
//     for (i = 0; i<m; i++){
//         scanf("%d", &arr[i]);    
//     }

//     for (i = 0; i<m; i++){
//         if (arr[i] == arr[m-1-i]){
//             x+=1;
//         }
//     }


//     if (x == m){
//         for (i = 0; i<m; i++){
//             printf("%d ", arr[i]);    
//         }
//         printf(" is a Palindromic Array");
//     }
//     else{
// 		for (i = 0; i<m; i++){
// 			printf("%d ", arr[i]);    
// 		}
//         printf(" Not Palindromic Array");
// 		}
// }


//Q10
#include <stdio.h>
int main(){
	int array1[50], array2[50], array3[100], m, n, i, j, k = 0; 
	printf("\n Enter size of array Array 1: "); 
	scanf("%d", &m);
	printf("\n Enter sorted elements of array 1: \n"); 
	for (i = 0; i < m; i++){
		scanf("%d", &array1[i]);
	}
	printf("\n Enter size of array 2: "); 
	scanf("%d", &n);
	printf("\n Enter sorted elements of array 2: \n"); 
	for (i = 0; i < n; i++){
		scanf("%d", &array2[i]);
	}
	i = 0; j = 0;
	while (i < m && j < n){ 
		if (array1[i] < array2[j]){ 
			array3[k] = array1[i]; 
			i++;
		}
		else{ 
			array3[k] = array2[j]; 
			j++;
			}
		k++;
	}
	if (i >= m){ 
		while (j < n){ 
			array3[k] = array2[j]; 
			j++; 
			k++;
		}
	}
	if (j >= n){ 
		while (i < m){ 
			array3[k] = array1[i]; i++; k++;
		}
	}
	printf("\n After merging: \n"); 
	for (i = 0; i < m + n; i++){ 
		printf("%d ", array3[i]);
	}
}

//Q11
// #include <stdio.h>
// int main(){
// 	int M1[3][3], M2[3][3], M3[3][3], i,j;
// 	printf("Enter the 1st Matrix - \n");
// 	for(i = 0; i<3; i++){
// 		printf("Row - %d : ", i+1);
// 		for(j=0;j<3;j++){
// 			scanf("%d", &M1[i][j]);
// 		}
// 	}
// 	printf("Enter the 2nd Matrix - \n");
// 	for(i = 0; i<3; i++){
// 		printf("Row - %d : ", i+1);
// 		for(j=0;j<3;j++){
// 			scanf("%d", &M2[i][j]);
// 			M3[i][j] = M1[i][j] - M2[i][j]; 
// 		}
// 	}
// 	printf("Enter the resultant matrix - \n");
// 	for(i=0;i<3;i++){
// 		printf("Row - %d : ", i+1);
// 		for(j=0;j<3;j++){
// 			printf("%d ", M3[i][j]);
// 		}
// 		printf("\n");
// 	}

// }