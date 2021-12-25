#include <bits/stdc++.h>
using namespace std;
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    long long n,m;
    long long max_height;
    cin>>n>>m;
    long long arr[n];
    long long num_of_woods;

    max_height=m;
    cin.ignore();

    for(int i=0;i<n;i++)
    {
        cin>>arr[i];
        max_height=max(max_height,arr[i]);

    }
    long long low=0;
    long long high=max_height;
    while(high-low>1)
    {
        long long mid=(low+high)/2;
        num_of_woods=0;
        for(int i=0;i<n;i++)
        {
            if(arr[i]>mid)
                num_of_woods+=arr[i]-mid;
        }
        if(num_of_woods>=m)
            low=mid;
        else
            high=mid;


    }
    cout<<low<<endl;


}
