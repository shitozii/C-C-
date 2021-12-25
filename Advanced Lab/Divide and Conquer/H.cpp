#include<bits/stdc++.h>
using namespace std;
int n,l;
int arr[1001];
bool check(double mid)
{
    double previous=0.0;
    for(int i=0;i<n;i++)
    {
        if(arr[i]-mid<=previous)
        {
            previous=arr[i]+mid;
        }
        else
            return false;
        if(previous>=l)
            return true;
    }
    return false;
}
int main()
{

    cin>>n>>l;
    for(int i=0;i<n;i++)
    {
        cin>>arr[i];
    }
    sort(arr,arr+n);
    double low=0;
    double high=l;
    double mid;
    while(high-low>=1e-10)
    {
        mid=low/2+high/2;
        if(check(mid)==true)
            high=mid;
        else
            low=mid;
    }
    printf("%.10lf\n",mid);

}