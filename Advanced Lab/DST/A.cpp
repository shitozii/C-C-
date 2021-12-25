#include <iostream>
#include <stack>
#include <algorithm>
#include<utility>

using namespace std;

int main()
{
    long long max_area=0;
    pair<long long,long long> tmp;
    long long height;
    long long num_of_rect;
    do
    {
        stack <pair<int,long long>> rect;
        max_area=0;
        cin>>num_of_rect;
        if(num_of_rect==0)
            break;
        for(int i=0;i<num_of_rect;i++)
        {
            long long start=i;
            cin>>height;
            while(!rect.empty()&&rect.top().second>height)
            {
                tmp=rect.top();
                max_area=max(max_area,tmp.second*(i-tmp.first));
                rect.pop();
                start=tmp.first;
            }
            rect.push(make_pair(start,height));


        }
        while(!rect.empty())
        {
            max_area=max(max_area,rect.top().second*((num_of_rect)-rect.top().first));
            rect.pop();
        }
        cout<<max_area<<endl;
        cin.ignore();


    }
    while(num_of_rect!=0);

}
