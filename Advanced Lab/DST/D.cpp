#include <iostream>
#include <algorithm>
#include <numeric>

using namespace std;

int solution(int _from,int _to,int c)
{
    int step=1;
    int from=_from;
    int to=0;
    while(from!=c&&to!=c)
    {
        int tmp=min(from,_to-to);
        to+=tmp;
        from-=tmp;
        step++;
        if(from==c||to==c)
            break;
        if(from==0)
        {
            from=_from;
            step++;

        }
        if(to==_to)
        {

            to=0;
            step++;
        }
    }
    return step;
}
int main()
{
    int a,b,c;
    cin>>a>>b>>c;
    if(c>max(a,b)||(c%__gcd(a,b))!=0)
        cout<<-1<<endl;
    else
    {
        cout<<min(solution(a,b,c),solution(b,a,c));

    }


}
