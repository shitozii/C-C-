#include <iostream>
#include <stack>
#include <string>
using namespace std;
int main()
{
    stack <char> s;
    string str;
    getline(cin,str);
    long long len=str.length();
    for(long long i=0;i<len;i++){
        if(s.empty())
            s.push(str[i]);
        else
        {
            if(s.top()==str[i])
                s.pop();
            else s.push(str[i]);
        }
    }

    if(s.empty())
        cout<<"Yes"<<endl;
    else
        cout<<"No"<<endl;
}
