#include <iostream>
#include <fstream>
#include <time.h>
#include <vector>
using namespace std;

int inputArr(string path, vector <int> *v)
{
    ifstream fptr;
    fptr.open(path);
    int n;
    long int i = 0;
    if (fptr.is_open())
    {
        while (fptr.good())
        {
            fptr >> n;
            (*v).push_back(n);
            i++;
        }
    }
    fptr.close();
    return i;
}

void bsort(vector <int> *v, long int *i)
{
    for (long int j = 0; j < *i - 1; j++)
    {
        for (long int k = 0; k < *i - j - 1; k++)
        {
            if ((*v)[k] > (*v)[k + 1])
            {
                int temp = (*v)[k];
                (*v)[k] = (*v)[k + 1];
                (*v)[k + 1] = temp;
            }
        }
    }
}

int main()
{
    long int x = 2097152;
    FILE *fptr2;
    vector <int> v;
    clock_t t1, t2;
    double sum = 0;

    //Change file path accordingly
    long int  i = inputArr("/Users/garvitshah/Desktop/College/Current Sem/Subjects/DAA/Lab/Assignment 1/Files/File 3.txt", &v);

    for (int k = 0; k < 100; k++)
    {   
        t1 = clock();
        bsort(&v, &i);
        t2 = clock();
        sum += ((double)t2 - (double)t1) / CLOCKS_PER_SEC;
    }
    cout << sum << endl;
    double time_taken = sum / 100;
    cout << "Worst Case Time Taken: " << time_taken << endl;

    // ----------------------------------------------
    sum = 0;
    time_taken = 0;
    for (int k = 0; k < 100; k++)
    {   
        t1 = clock();
        bsort(&v, &i);
        t2 = clock();
        sum += ((double)t2 - (double)t1) / CLOCKS_PER_SEC;
    }
    cout << sum << endl;
    time_taken = sum / 100;
    // double time_taken = 0.0000000033062222798665*x*x + 0.00000002229166666662*x - 0.0000005119999999456;
    cout << "Best Case Time Taken: " << time_taken << endl;
    // fptr2 = fopen("Doc1.txt", "a");
    // fprintf(fptr2, "%s & %d & %ld & %f \\\\ \n", "File-", 10, x, time_taken);
    // fclose(fptr2);
}
