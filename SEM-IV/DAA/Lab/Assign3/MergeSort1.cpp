#include <iostream>
#include <fstream>
#include <time.h>
#include <vector>
using namespace std;

void printVector(vector<int> *v, long int p, long int i)
{
    for (long int j = p; j <= i; j++)
    {
        cout << (*v)[j] << " ";
    }
    cout << "\n";
}

int inputArr(string path, vector<int> *v)
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

void merge(vector<int> *v, long int p, long int q, long int i)
{
    vector<int> b;
    vector<int> c;
    long int k = 0, j = 0, x = p;
    for (k = p; k <= q; k++)
    {
        b.push_back((*v)[k]);
    }
    b.push_back(21474836);
    for (k = q + 1; k <= i; k++)
    {
        c.push_back((*v)[k]);
    }
    c.push_back(21474836);
    k = 0;
    while (b[k] != 21474836 || c[j] != 21474836)
    {
        if (b[k] < c[j])
        {
            (*v)[x] = b[k];
            k++;
        }
        else
        {
            (*v)[x] = c[j];
            j++;
        }
        x++;
    }
}

void mergeSort(vector<int> *v, long int p, long int i)
{
    if (p >= i)
    {
        return;
    }
    long int q = ((p + i) / 2);
    mergeSort(v, p, q);
    mergeSort(v, q + 1, i);
    merge(v, p, q, i);
}

int main()
{
    ofstream fptr2;
    vector<int> v;
    clock_t t1, t2;
    double sum = 0;
    string path = "/Users/garvitshah/Desktop/College/Current Sem/Subjects/DAA/Lab/Assignment 1/Files/File 10.txt";
    long int i = inputArr(path, &v);
    for (int j = 0; j < 1; j++)
    {
        t1 = clock();
        mergeSort(&v, 0, i - 1);
        t2 = clock();
        sum += ((double)t2 - (double)t1) / CLOCKS_PER_SEC;
    }
    cout << sum << endl;
    double time_taken = sum;
    // int x = 16777216;
    // double time_taken = 0.0000039622769632924*x - 0.0003499;
    // printVector(&v, 0, i-1);
    cout << "Time taken: " << time_taken << endl;
    // 4.09044

    fptr2.open("/Users/garvitshah/Desktop/College/Current Sem/Subjects/DAA/Lab/Doc1.txt", ios::app);
    fptr2 << "File-10 & " << i << " & " << time_taken <<  " \\\\ \n"; 
    return 0;
}