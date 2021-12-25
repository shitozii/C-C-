#include <iostream>
using namespace std;
int main()
{
    unsigned long long a;
    unsigned long long b;
    unsigned long long sum=0;
    unsigned long long c=1000000007;
    cin>>a;
    cin.ignore();
    while(a--)
    {
        cin>>b;
        sum=(sum%c+b%c)%c;

    }
    cout << sum<<endl;

}
