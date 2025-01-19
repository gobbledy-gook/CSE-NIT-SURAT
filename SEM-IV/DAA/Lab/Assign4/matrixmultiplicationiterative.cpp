#include<iostream>
#include<vector>
#include <algorithm>
using namespace std;
void mat_mul (int a[3][3],int b[3][3])
{
    int c[3][3]= {0};
    int n=3;
    int i,j,k;
    for(i=0;i<n;i++)
    {
        for(j=0;j<n;j++)
        {
            c[i][j]=0;
            for(k=0;k<n;k++)
            {
                c[i][j]+=a[i][k]*b[k][j];

            }
            cout<<c[i][j]<<"\t";

        }
        cout<<endl;
    }
    return;
}
int main()
{
    int a[3][3],b[3][3];
    int n=3;
    int i,j;
    for(i=0;i<n;i++)
    {
        for(j=0;j<n;j++)
        {
            cout<<"enter a["<<i<<"]["<<j<<"]:"<<endl;
            cin>>a[i][j];
        }
    }
    for(i=0;i<n;i++)
    {
        for(j=0;j<n;j++)
        {
            cout<<"enter b["<<i<<"]["<<j<<"]:"<<endl;
            cin>>b[i][j];
        }
    }
    mat_mul(a,b);
    return 0;
}
