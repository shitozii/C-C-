#include <iostream>
#include <algorithm>
using namespace std;
int main()
{
    long long num,a0,a;
    cin >> num;
    cin.ignore();
    cin>> a0;
    long long smax=a0;
    long long ei=a0;
    for(int i=1;i<=num-1;i++)
    {
        cin>>a;
        ei=max(a,a+ei);
        smax=max(ei,smax);
    }
    cout<<smax<<endl;

}