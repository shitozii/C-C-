#include <iostream>
#include <string>
#include <stack>
using namespace std;
bool is_pair(char c1,char c2)
{
    if(c1=='('&&c2==')')
        return true;
    else if(c1=='['&&c2==']')
        return true;
    else if(c1=='{'&&c2=='}')
        return true;
    return false;
}
bool check_par(string s)
{
    stack <char> par;
    for(long i=0;i<(long)(s.length());i++)
    {
        if(s[i]=='('||s[i]=='['||s[i]=='{')
            par.push(s[i]);
        else if(s[i]==')'||s[i]==']'||s[i]=='}')
        {
            if(is_pair(par.top(),s[i]))
                par.pop();
            else
              return false;

        }
    }
    if(!par.empty())
        return false;
    return true;
}
int main()
{
    string s;
    int num,tmp;
    cin >>num;
    tmp=num;
    cin.ignore();
    while(tmp--)
    {
        getline(cin,s);
        cout<<(int)check_par(s)<<endl;
    }



}
