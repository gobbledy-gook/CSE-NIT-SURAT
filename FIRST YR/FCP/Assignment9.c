// Q1
// #include <stdio.h>

// struct books{
//         long long int ISBN;
//         char title[100];
//         float price;
//     };

// int main(){
//     int n, i=0;
//     printf("Enter the no. of books to store - ");
//     scanf("%d", &n);
//     struct books book[n];
//     for(i=0;i<n;i++){
//         printf("ISBN No. - ");
//         scanf("%lld", &book[i].ISBN);
//         printf("Price - ");
//         scanf("%f", &book[i].price);
//         printf("Title - ");
//         scanf("%s", book[i].title);
//     }
//     printf("\n\n");
//     for(i=0;i<n;i++){
//         printf("ISBN No. - %lld\n", book[i].ISBN);
//         printf("Title - %s\n", book[i].title);
//         printf("Price - %f\n--------------------\n", book[i].price);
//     }

// }


// Q2
// #include <stdio.h>
// struct items{
//     char item_name[100];
//     int quantity;
//     float price;
//     float amount;
// };

// void itemAmount(struct items item[], int n){
//     int i = 0;
//     for(i =0; i<n;i++){
//         printf("\nItem name - %s\n", item[i].item_name);
//         printf("Quantity - %d\n", item[i].quantity);
//         printf("Price - %f\n", item[i].price);
//         printf("Amount - %f\n-----------------\n", item[i].quantity*item[i].price);
//     }
// }

// int main(){
//     int n, i=0;
//     printf("Enter the no. of items - ");
//     scanf("%d", &n);
//     struct items item[n];
//     for(i =0; i<n;i++){
//         printf("Item name - ");
//         scanf("%s", item[i].item_name);
//         printf("Quantity - ");
//         scanf("%d", &item[i].quantity);
//         printf("Price - ");
//         scanf("%f", &item[i].price);
//         printf("\n-------------\n");
//     }
//     printf("\n----------Result----------\n");
//     itemAmount(item, n);
// }


// Q3
#include <stdio.h>

struct Time{
    int seconds;
    int minutes;
    int hours;
};

void timeDiff(struct Time t[]){
    int diff=0, H, M, S;
    diff = (t[1].hours*60 - t[0].hours*60 + t[1].minutes - t[0].minutes)*60 + t[1].seconds - t[0].seconds;
    if (diff <0){
        diff = diff*(-1);
    }
    H = diff/3600;
    M = (diff - H*3600)/60;
    S = diff - M*60 - H*3600;
    printf("Time difference is %d hr %d min %d s", H, M, S);
}

int main(){
    struct Time t[2];
    printf("\nAbout the START time:\n");
    printf("Hours - ");
    scanf("%d", &t[0].hours);
    printf("Minutes - ");
    scanf("%d", &t[0].minutes);
    printf("Seconds - ");
    scanf("%d", &t[0].seconds);

    printf("\nAbout the END time:\n");
    printf("Hours - ");
    scanf("%d", &t[1].hours);
    printf("Minutes - ");
    scanf("%d", &t[1].minutes);
    printf("Seconds - ");
    scanf("%d", &t[1].seconds);
    timeDiff(t);
}