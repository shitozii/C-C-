#include <bits/stdc++.h>
using namespace std;
int n,c;
int arr[100010];
bool check(int mid)
{
    int cur=0,total=1,dis;
    for(int i=1;i<n;i++)
    {
        dis=arr[i]-arr[cur];
        if(dis>=mid)
        {
            cur=i;
            total++;
        }
        if(total==c)
            return true;
    }
    return false;
}
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    int test;
    int low,high,mid;
    cin>>test;

    while(test--)
    {
        cin>>n>>c;
        for(int i=0;i<n;i++)
        {
            cin>>arr[i];
        }
        sort(arr,arr+n);
        low=1;
        high=arr[n-1]-arr[0];
        while(high-low>1)
        {
            mid=(low+high)/2;
            if(check(mid)==true)
             low=mid;
            else high=mid-1;
        }
        mid=high;
        if(check(mid)==false)
            mid=low;
        cout<<mid<<endl;

    }
}
