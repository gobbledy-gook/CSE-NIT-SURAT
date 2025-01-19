#include <stdlib.h>
#include <stdio.h>


void fileAppend(){
    FILE * fptr;
    int age, count = 1;
    char fname[10], lname[10], g[1], area[10], date[10];
    fptr = fopen("/Users/garvitshah/Desktop/College/Current Sem/Subjects/DBMS/lab/Patients.txt", "a");
    printf("Enter First Name - ");
    scanf("%s", fname);
    printf("Enter Last Name - ");
    scanf("%s", lname);
    printf("Enter Age - ");
    scanf("%d", &age);
    printf("Enter date in DD-MM-YYYY format - ");
    scanf("%s", date);
    printf("Enter Gender - ");
    scanf("%s", g);
    printf("Enter Area - ");
    scanf("%s", area);
    fprintf(fptr, "%d | %s | %s | %d | %s | %s | %s\n", count, fname, lname, age, date, g, area);
    fclose(fptr);
}

int main(){
    // char path[] = "/Users/garvitshah/Desktop/College/Current Sem/Subjects/DBMS/lab/Patients.txt";
    int n;
    while(1){
        printf("\n---------COVID PATIENTS DATA----------\n1. Add Record\n2. Delete a Record\n3. Modify a Record");
        printf("\n4. Summary By\n5. Ascending Order By\n6. Descending Order By\n7. Display By Range\n0. Exit\n--> ");
        scanf("%d", &n);
        if(n == 1){
            fileAppend();
        }
        // else if(n == 2){
        //     deleteRecord(path);
        // }
        // else if(n == 3){
        //     modify(path);
        // }
        // else if(n == 4){
        //     summary(path);
        // }
        // else if(n == 5){
        //     AscOrder(path);
        // }
        // else if(n == 6){
        //     DescOrder(path);
        // }
        // else if(n == 7){
        //     Display(path);
        // }
        else if(n == 0){
            break;
        }
        else{
            break;
        }
    }
}