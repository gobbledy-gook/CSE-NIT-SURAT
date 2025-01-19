#include <iostream>
#include <vector>
#include <algorithm>
#include <math.h>
using namespace std;

long long int mul(long int a, long int b, int base){
    if(base == 1){
        int c = a*b;
        cout << a << " | " << b << " | " << c << endl; 
        return c;
    }
    else{
        long int m=1;
        m = pow(10, base/2);
        long int x1 = a / m;
        long int y1 = a % m;
        long int x2 = b /m;
        long int y2 = b % m;
        cout << x1 << " " << y1 << " " << x2 << " " << y2 << endl;
        long int p1 = mul(x1, x2, base/2);
        long int p3 = mul(y1, y2, base/2);
        long int p4 = mul(x1 + y1, x2 + y2, base/2);
        long int p2 = p4 - p1 - p3;
        return p1*pow(10, base) + p2*pow(10, base/2) + p3;
    }
}

int main(){
    int a, b, N = 0, c;
    printf("Enter num1: ");
    cin >> a;
    printf("Enter num2: ");
    cin >> b;
    if(a > b){
        c = a;
    }
    else{
        c = b;
    }
    while(c> 0){
        c = c/10;
        N++;
    }
    cout << "Prdouct: " << mul(a,b,N);
    return 0;
}