#include <iostream>
#include <algorithm>
using namespace std;
int main()
{

    unsigned long long a,b;
    cin>>a>>b;
    long long c=1000000007;
    cout<<((a%c+b%c))%c;

}