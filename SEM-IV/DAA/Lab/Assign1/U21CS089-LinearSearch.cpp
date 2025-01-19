#include <iostream>
#include <time.h>
using namespace std;

int linearSearch(int val, FILE *fptr)
{
    int n;
    // fscanf(fptr, "%d", &n);
    while(fscanf(fptr, "%d", &n) != EOF)
    {
        if (n == val)
        {
            return (1);
        }
        fscanf(fptr, "%d", &n);
    }
    return (0);
}

int main()
{
    clock_t t1, t2;
    int val=57134;
    char path[100];
    double sum = 0;
    FILE *fptr0, *fptr2;
    fptr0 = fopen("Assignment 1/Files/File 10.txt", "r");
    fptr2 = fopen("Doc1.txt", "a");
    fprintf(fptr2, "%s %d\n", "File ", 10);
    fclose(fptr2);

    // --------------------------------------------------------Best Case
    for (int i = 0; i < 100; i++)
    {
        rewind(fptr0);
        t1 = clock();
        linearSearch(val, fptr0);
        t2 = clock();
        sum += ((double)t2 - (double)t1) / CLOCKS_PER_SEC;
    }
    cout << sum << endl;
    double time_taken = sum/100;
    cout << "Best Case Time Taken: " << time_taken << endl;
    fptr2 = fopen("Doc1.txt", "a");
    fprintf(fptr2, "%s", "Best Case: ");
    fprintf(fptr2, "%f\n", time_taken);
    fclose(fptr2);


    // --------------------------------------------------------Worst Case
    sum = 0;
    time_taken = 0;
    val = 999999;
    for (int i = 0; i < 100; i++)
    {
        rewind(fptr0);
        t1 = clock();
        linearSearch(val, fptr0);
        t2 = clock();
        sum += ((double)t2 - (double)t1) / CLOCKS_PER_SEC;
    }
    fclose(fptr0);
    time_taken = sum/100;
    cout << "Worst Case Time Taken: " << time_taken << endl;
    fptr2 = fopen("Doc1.txt", "a");
    fprintf(fptr2, "%s", "Worst Case: ");
    fprintf(fptr2, "%f\n\n", time_taken);
    fclose(fptr2);
}
