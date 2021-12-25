#include<iostream>
using namespace std;
long long arr[1001][1001];
long long ckn(long long k,long long n)
{
    if(k==0||k==n)
        arr[k][n]=1;
    else if(arr[k][n]<0)
    {
        arr[k][n]=ckn(k-1,n-1)%1000000007+ckn(k,n-1)%1000000007;

    }
    return arr[k][n];

}
int main()
{

    long long n;
    long long k;
    cin>>k>>n;
    for (int i=0;i<1001;i++)
        for(int j=0;j<1001;j++)
        arr[i][j]=-1;
    cout<<ckn(k,n)%1000000007<<endl;

}
