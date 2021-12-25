#include <bits/stdc++.h>
using namespace std;
long long arr[510];
long long tmp[510];
int n;
int m;
bool check(long long max_value)
{
    int num=1;
    long long sum=0;
    for(int i=n-1;i>=0;i--)
    {
        if(sum+arr[i]>max_value)
        {
            sum=arr[i];
            num++;
            if(num>m)
                return false;

        }
        else
        {
            sum+=arr[i];
        }
    }
    return true;


}
void print_ans(long long max_value)
{
    int num=1;
    long long sum=0;
    for(int i=n-1;i>=0;i--)
    {
        if(sum+arr[i]>max_value)
        {
            sum=arr[i];
            tmp[i]=1;
            num++;

        }
        else
        {
            sum+=arr[i];
        }
        if(m-num==i+1)
        {
            for(int j=0;j<=i;j++)
                tmp[j]=1;
            break;
        }
    }
    for(int i=0;i<n;i++)
    {
        if(i==n-1)
            cout<<arr[i]<<endl;
        else
        {
        cout<<arr[i]<<" ";
        if(tmp[i]==1)
            cout<<"/ ";
        }

    }

}
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    long long low=-1,high=0;
    int test;
    cin>>test;
    cin.ignore();
    while(test--)
    {
        memset(tmp,0,sizeof(tmp));
        low=-1;
        high=0;
        cin>>n>>m;
        for(int i=0;i<n;i++)
        {
            cin>>arr[i];
            low=max(low,arr[i]);
            high+=arr[i];

        }
        while(low<=high)
        {
            long long mid=(low+high)/2;
            if(check(mid)==true)
                high=mid-1;
            else
                low=mid+1;
        }
        print_ans(low);

    }
}
