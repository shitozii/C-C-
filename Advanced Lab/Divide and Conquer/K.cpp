#include<iostream>
using namespace std;
unsigned long long m=1e9+7;
unsigned long long modpow(unsigned long long x,unsigned long long n)
{
    if(n==0)
        return 1;
    if(n%2!=0)
        return ((x%m)*(modpow(x,n-1)%m))%m;
    unsigned long long st=modpow(x,n/2)%m;
    return ((st%m)*(st%m))%m;


}
int main()
{
    unsigned long long x,n;
    cin>>x>>n;
    cout<<modpow(x,n)%m<<endl;
}