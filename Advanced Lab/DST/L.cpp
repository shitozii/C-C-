#include <iostream>
#include <algorithm>
#include <vector>


using namespace std;
int main()
{
    int num;
    vector <long long> pos,neg,zero;
    long long tmp;
    cin>>num;
    cin.ignore();
    for(int i=0;i<num;i++)
    {
        cin>>tmp;
        if(tmp>0)
        pos.push_back(tmp);
        else if(tmp==0)
        zero.push_back(tmp);
        else
        neg.push_back(tmp);


    }
    if(pos.size()==0&&neg.size()>2)
    {
        pos.push_back(neg.back());
        neg.pop_back();
        pos.push_back(neg.back());
        neg.pop_back();
    }
    if(neg.size()%2==0)
    {
        zero.push_back(neg.back());
        neg.pop_back();
    }
    cout<<neg.size()<<" ";
    for(int i=0;i<neg.size();i++)
    cout<<neg[i]<<" ";
    cout<<endl;
    cout<<pos.size()<<" ";
    for(int i=0;i<pos.size();i++)
        cout<<pos[i]<<" ";
    cout<<endl;
      cout<<zero.size()<<" ";
    for(int i=0;i<zero.size();i++)
        cout<<zero[i]<<" ";
    cout<<endl;

}
