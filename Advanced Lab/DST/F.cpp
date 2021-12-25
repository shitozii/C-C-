#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
int main()
{
    long long n,b;
    bool check=false;
    cin>>n>>b;
    cin.ignore();
    long long arr[n];
    vector <long long> candidate;
    for(long long i=0;i<n;i++)
        cin>>arr[i];
    if(n<=2||n>200000||b<1||b>50)
    {
        cout<<-1<<endl;
        exit(1);
    }
    long long mark_max[n];
    mark_max[0]=-1;

    for(long long i=1;i<n;i++)
        mark_max[i]=max(mark_max[i-1],arr[i-1]);
    long long mark_right=-1;
    for(long long i=n-1;i>=0;i--)
    {
        if(mark_max[i]>=arr[i]+b&&mark_right>=arr[i]+b)
            {
                candidate.push_back(mark_max[i]+mark_right-2*arr[i]);
                check=true;
            }
            mark_right=max(mark_right,arr[i]);
    }
    if(check==false)
      cout<<-1<<endl;
    else
    {
        sort(candidate.begin(),candidate.end());
        cout<<candidate.back()<<endl;

    }


}
