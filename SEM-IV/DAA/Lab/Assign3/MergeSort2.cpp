#include <iostream>
#include <fstream>
#include <time.h>
#include <vector>
#include <math.h>
using namespace std;

void printVector(vector <int> *v, long int start, long int i){
    for(long int j = start; j<=i; j++){
        cout << (*v)[j] << " ";
    }
    cout << "\n";
}

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

void merge(vector <int> *v, long int start, long int q1, long int q2, long int i){
    vector <int> b;
    vector <int> c;
    vector <int> d;
    long int k =0, j = 0, l = 0, x=start;
    for(k = start; k<=q1;k++){
        b.push_back((*v)[k]);
    }
    b.push_back(21474836);
    for(k = q1+1; k<=q2;k++){
        c.push_back((*v)[k]);
    }
    c.push_back(21474836);
    for(k = q2+1; k<=i;k++){
        d.push_back((*v)[k]);
    }
    d.push_back(21474836);
    k=0;
    while(b[k] != 21474836 || c[j] != 21474836 || d[l] != 21474836){
        if(b[k] <= c[j] && b[k] <= d[l]){
            (*v)[x] = b[k];
            k++;
        }
        else if(c[j] <= b[k] && c[j] <= d[l]){
            (*v)[x] = c[j];
            j++;
        }
        else{
            (*v)[x] = d[l];
            l++;
        }
        x++;
    }
}

void mergeSort(vector <int> *v, long int start, long int i){
    if(start >= i){
        return;
    }
    long int q1 = start + (i-start)/3;
    long int q2 = start + 2*(i - start)/3 + 1;
    mergeSort(v, start, q1);
    mergeSort(v, q1+1, q2);
    mergeSort(v, q2+1, i);
    merge(v, start, q1, q2, i);
}

int main(){
    ofstream fptr2;
    vector <int> v;
    clock_t t1, t2;
    double sum = 0;
    long int  i = inputArr("/Users/garvitshah/Desktop/College/Current Sem/Subjects/DAA/Lab/Assignment 1/Files/File 10.txt", &v);
    for(int j =0; j<1; j++){
        t1 = clock();
        mergeSort(&v,0, i-1);
        t2 = clock();
        sum += ((double)t2 - (double)t1) / CLOCKS_PER_SEC;
    }
    cout << sum << endl;
    double time_taken = sum;
    // double log(double);
    // int x = 16384;
    // double time_taken = 4.037073579332

    // printVector(&v, 0, i-1);
    cout << "Time taken: " <<time_taken <<endl;
    fptr2.open("/Users/garvitshah/Desktop/College/Current Sem/Subjects/DAA/Lab/Doc1.txt", ios::app);
    fptr2 << "File-10 & " << i << " & " << time_taken <<  " \\\\ \n"; 
    return 0;
}